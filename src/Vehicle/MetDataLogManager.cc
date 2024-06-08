#include "QGCApplication.h"
#include "MetDataLogManager.h"
#include "SettingsManager.h"
#include "MetFlightDataRecorderController.h"
#include "Vehicle.h"
#include <libs/netcdf-cxx4/cxx4/netcdf>

using namespace std;
using namespace netCDF;
using namespace netCDF::exceptions;

MetDataLogManager::MetDataLogManager(QGCApplication* app, QGCToolbox* toolbox) : QGCTool(app, toolbox)
{
    connect(&_metRawCsvTimer, &QTimer::timeout, this, &MetDataLogManager::_writeMetRawCsvLine);
    connect(&_metAlmCsvTimer, &QTimer::timeout, this, &MetDataLogManager::_writeMetAlmCsvLine);
    connect(&_metNetCdfTimer, &QTimer::timeout, this, &MetDataLogManager::_writeMetNetCdfLine);
    _metRawCsvTimer.start(20); // set below nyquist rate for 50ms balancedDataFrequency to ensure no data is missed
    _metAlmCsvTimer.start(20); // set below nyquist rate for 50ms balancedDataFrequency to ensure no data is missed
    _metNetCdfTimer.start(20); // timing for NetCDF messages should always be the same as the ALM messages
}

MetDataLogManager::~MetDataLogManager()
{
    _metRawCsvFile.close();

    if(_metAlmCsvFile.isOpen()) {
        _metAlmCsvFile.close();
    }

    if(!_metNetCdfFile.isNull()) {
        _metNetCdfFile.close();
    }
}

void MetDataLogManager::_initializeMetRawCsv()
{
    QString now = QDateTime::currentDateTime().toString("MM-dd-yyyy_hh-mm-ss");
    QString metRawFileName = QString("RAW_%1.txt").arg(now);
    QDir saveDir(qgcApp()->toolbox()->settingsManager()->appSettings()->messagesRawSavePath());
    _metRawCsvFile.setFileName(saveDir.absoluteFilePath(metRawFileName));

    if (!_metRawCsvFile.open(QIODevice::Append)) {
        qCWarning(VehicleLog) << "unable to open raw message file for text logging, Stopping text logging!";
        return;
    }

    QTextStream stream(&_metRawCsvFile);

    stream << metRawFactHeaders.join(",") << "\r\n";
    stream << metRawFactUnits.join(",") << "\r\n";
}

void MetDataLogManager::_writeMetRawCsvLine()
{
    // Only save the logs after the the vehicle gets armed, unless "Save logs even if vehicle was not armed" is checked
    Vehicle* _activeVehicle = qgcApp()->toolbox()->multiVehicleManager()->activeVehicle();
    if(!_metRawCsvFile.isOpen() && _activeVehicle && _activeVehicle->armed()) {
        _initializeMetRawCsv();
    }

    if(!_metRawCsvFile.isOpen() || !_activeVehicle || !_activeVehicle->armed()) {
        return;
    }

    QStringList metFactValues;
    QTextStream stream(&_metRawCsvFile);

    FactGroup* factGroup = nullptr;
    factGroup = _activeVehicle->getFactGroup("temperature");

    if (!factGroup) {
        return;
    }

    // make sure we're not logging the same data again
    QString timestamp = factGroup->getFact("timeUnixSeconds")->rawValueString();
    if (timestamp == _latestRawTimestamp) {
        return;
    } else {
        _latestRawTimestamp = timestamp;
    }

    for (const auto &factName : metRawFactNames) {
        if(!factGroup->factExists(factName)) {
            qCWarning(VehicleLog) << "Fact does not exist: " << factName;
            continue;
        }
        metFactValues << factGroup->getFact(factName)->rawValueString();
    }

    stream << metFactValues.join(",") << "\r\n";
}

void MetDataLogManager::setAscentNumber(int number)
{
    _ascentNumber = number;
    // close the file to allow next logging to start with new ascent number
    if(_metAlmCsvFile.isOpen()) {
        _metAlmCsvFile.close();
    }

    if(!_metNetCdfFile.isNull()) {
        _metNetCdfFile.close();
    }
}

void MetDataLogManager::setFlightFileName(QString flightName)
{
    // allow next logging to start with new flight name
    if(_metAlmCsvFile.isOpen()) {
        _metAlmCsvFile.close();
    }

    if(!_metNetCdfFile.isNull()) {
        _metNetCdfFile.close();
    }

    _flightName = flightName;
    setAscentNumber(1);
}

void MetDataLogManager::_initializeMetAlmCsv()
{
    int copyNumber = 1;
    QString metAlmFileName = QString("%1_%2_%3.txt").arg(_flightName).arg(copyNumber).arg(_ascentNumber);
    QDir saveDir(qgcApp()->toolbox()->settingsManager()->appSettings()->messagesAltLevelSavePath());
    _metAlmCsvFile.setFileName(saveDir.absoluteFilePath(metAlmFileName));

    while (_metAlmCsvFile.exists()) {
        copyNumber++;
        metAlmFileName = QString("%1_%2_%3.txt").arg(_flightName).arg(copyNumber).arg(_ascentNumber);
        _metAlmCsvFile.setFileName(saveDir.absoluteFilePath(metAlmFileName));
    }

    if (!_metAlmCsvFile.open(QIODevice::Append)) {
        qCWarning(VehicleLog) << "unable to open ALM message file for text logging, Stopping text logging!";
        return;
    }
    QTextStream stream(&_metAlmCsvFile);

    qCDebug(VehicleLog) << "Facts logged to csv:" << metAlmFactHeaders;
    stream << metAlmFactHeaders.join(",") << "\r\n";
    stream << metAlmFactUnits.join(",") << "\r\n";
}

void MetDataLogManager::_writeMetAlmCsvLine()
{
    FactGroup* factGroup = nullptr;
    Vehicle* _activeVehicle = qgcApp()->toolbox()->multiVehicleManager()->activeVehicle();
    if(!_activeVehicle || !_activeVehicle->armed()) {
        return;
    }
    factGroup = _activeVehicle->getFactGroup("temperature");

    if (!factGroup) {
        return;
    }

    // make sure we're not logging the same data again
    QString timestamp = factGroup->getFact("time")->rawValueString();
    if (timestamp == _latestAlmTimestamp) {
        return;
    } else {
        _latestAlmTimestamp = timestamp;
    }

    // only capture ALM data during ascent
    if(factGroup->getFact("ascending")->rawValue().toBool() == false) {
        if(_metAlmCsvFile.isOpen()) {
            _metAlmCsvFile.close();
        }
        return;
    }

    if(!_metAlmCsvFile.isOpen()) {
        _initializeMetAlmCsv();
    }



    QStringList metFactValues;
    QTextStream stream(&_metAlmCsvFile);

    for (const auto &factName : metAlmFactNames) {
        if(!factGroup->factExists(factName)) {
            qCWarning(VehicleLog) << "Fact does not exist: " << factName;
            continue;
        }
        metFactValues << factGroup->getFact(factName)->rawValueString();
    }

    stream << metFactValues.join(",") << "\r\n";
}

void MetDataLogManager::_initializeMetNetCdf()
{
    int copyNumber = 1;
    QString netCdfFileName = QString("%1_%2_%3.nc").arg(_flightName).arg(copyNumber).arg(_ascentNumber);
    // TODO: change the save path to the NetCDF save path
    QDir saveDir(qgcApp()->toolbox()->settingsManager()->appSettings()->messagesNetCdfSavePath());
    QString _netCdfFullFilePath = saveDir.absoluteFilePath(netCdfFileName);

    while (QFile(_netCdfFullFilePath).exists()) {
        copyNumber++;
        netCdfFileName = QString("%1_%2_%3.nc").arg(_flightName).arg(copyNumber).arg(_ascentNumber);
        _netCdfFullFilePath = saveDir.absoluteFilePath(netCdfFileName);
    }

    // Create the file.
    _metNetCdfFile.open(_netCdfFullFilePath.toStdString(), NcFile::replace);

    // Define the dimensions.
    NcDim obsDim = _metNetCdfFile.addDim("obs");
    vector<NcDim> dims;
    dims.push_back(obsDim);

    // Define the variables.

    altitude             = _metNetCdfFile.addVar("altitude", ncFloat, dims);
    time                 = _metNetCdfFile.addVar("time", ncDouble, dims);
    pressure             = _metNetCdfFile.addVar("air_pressure", ncFloat, dims);
    airTemp              = _metNetCdfFile.addVar("air_temperature", ncFloat, dims);
    relHum               = _metNetCdfFile.addVar("relative_humidity", ncFloat, dims);
    windSpeed            = _metNetCdfFile.addVar("wind_speed", ncFloat, dims);
    windDirection        = _metNetCdfFile.addVar("wind_direction", ncFloat, dims);
    latitude             = _metNetCdfFile.addVar("lat", ncDouble, dims);
    longitude            = _metNetCdfFile.addVar("lon", ncDouble, dims);
    roll                 = _metNetCdfFile.addVar("platform_roll", ncFloat, dims);
    rollRate             = _metNetCdfFile.addVar("platform_roll_rate", ncFloat, dims);
    pitch                = _metNetCdfFile.addVar("platform_pitch", ncFloat, dims);
    pitchRate            = _metNetCdfFile.addVar("platform_pitch_rate", ncFloat, dims);
    yaw                  = _metNetCdfFile.addVar("platform_yaw", ncFloat, dims);
    yawRate              = _metNetCdfFile.addVar("platform_yaw_rate", ncFloat, dims);
    speedOverGround      = _metNetCdfFile.addVar("platform_speed_wrt_ground", ncFloat, dims);
    speedOverGroundUp    = _metNetCdfFile.addVar("platform_speed_wrt_ground_upward", ncFloat, dims);
    mixRatio             = _metNetCdfFile.addVar("Humidity_mixing_ratio", ncFloat, dims);

    // add attributes to each variable
    altitude.putAtt("units", "m ASL");
    altitude.putAtt("standard_name", "Altitude");
    altitude.putAtt("long_name", "Altitude (height)");
    altitude.putAtt("axis", "Z");

    time.putAtt("units", "seconds since UNIX epoch");
    time.putAtt("standard_name", "Time");
    time.putAtt("long_name", "Time");
    time.putAtt("axis", "T");

    pressure.putAtt("units", "Pa");
    pressure.putAtt("standard_name", "Air Pressure");
    pressure.putAtt("long_name", "Air Pressure");
    pressure.putAtt("axis", "Z");

    airTemp.putAtt("units", "K");
    airTemp.putAtt("standard_name", "Air Temperature");
    airTemp.putAtt("long_name", "Air Temperature");

    relHum.putAtt("units", "%");
    relHum.putAtt("standard_name", "Relative Humidity");
    relHum.putAtt("long_name", "Relative Humidity");

    windSpeed.putAtt("units", "m/s");
    windSpeed.putAtt("standard_name", "Wind Speed");
    windSpeed.putAtt("long_name", "Wind Speed");

    windDirection.putAtt("units", "deg");
    windDirection.putAtt("standard_name", "Wind Direction");
    windDirection.putAtt("long_name", "Wind Direction");

    latitude.putAtt("units", "deg");
    latitude.putAtt("standard_name", "Latitude");
    latitude.putAtt("long_name", "Latitude");
    latitude.putAtt("axis", "Y");

    longitude.putAtt("units", "deg");
    longitude.putAtt("standard_name", "Longitude");
    longitude.putAtt("long_name", "Longitude");
    longitude.putAtt("axis", "X");

    roll.putAtt("units", "deg");
    roll.putAtt("standard_name", "Roll");
    roll.putAtt("long_name", "Roll");

    rollRate.putAtt("units", "deg/s");
    rollRate.putAtt("standard_name", "Roll Rate");
    rollRate.putAtt("long_name", "Roll Rate");

    pitch.putAtt("units", "deg");
    pitch.putAtt("standard_name", "Pitch");
    pitch.putAtt("long_name", "Pitch");

    pitchRate.putAtt("units", "deg/s");
    pitchRate.putAtt("standard_name", "Pitch Rate");
    pitchRate.putAtt("long_name", "Pitch Rate");

    yaw.putAtt("units", "deg");
    yaw.putAtt("standard_name", "Yaw");
    yaw.putAtt("long_name", "Yaw");

    yawRate.putAtt("units", "deg/s");
    yawRate.putAtt("standard_name", "Yaw Rate");
    yawRate.putAtt("long_name", "Yaw Rate");

    speedOverGround.putAtt("units", "m/s");
    speedOverGround.putAtt("standard_name", "Speed Over Ground");
    speedOverGround.putAtt("long_name", "Speed Over Ground");

    speedOverGroundUp.putAtt("units", "m/s");
    speedOverGroundUp.putAtt("standard_name", "Ascent Rate");
    speedOverGroundUp.putAtt("long_name", "Ascent Rate");

    mixRatio.putAtt("units", "kg/kg");
    mixRatio.putAtt("standard_name", "Mixing Ratio");
    mixRatio.putAtt("long_name", "Humidity Mixing Ratio");

    // reset the index vector
    if(startp.size() == 0) {
        startp.push_back(0);
    } else {
        startp[0] = 0;
    }

    return;
}

void MetDataLogManager::_writeMetNetCdfLine()
{

    FactGroup* factGroup = nullptr;
    Vehicle* _activeVehicle = qgcApp()->toolbox()->multiVehicleManager()->activeVehicle();
    if(!_activeVehicle || !_activeVehicle->armed()) {
        return;
    }
    factGroup = _activeVehicle->getFactGroup("temperature");

    if (!factGroup) {
        return;
    }

    // make sure we're not logging the same data again
    QString timestamp = factGroup->getFact("timeUnixSeconds")->rawValueString();
    if (timestamp == _latestNetCdfTimestamp) {
        return;
    } else {
        _latestNetCdfTimestamp = timestamp;
    }

    // only capture netcdf data during ascent
    if(factGroup->getFact("ascending")->rawValue().toBool() == false) {
        if(!_metNetCdfFile.isNull()) {
            _metNetCdfFile.close();
        }
        return;
    }

    if(_metNetCdfFile.isNull()) {
        _initializeMetNetCdf();
    }

    altitude.putVar(startp, factGroup->getFact("altitudeMetersMSL")->rawValue().toFloat());
    time.putVar(startp, factGroup->getFact("timeUnixSeconds")->rawValue().toDouble());
    //TODO: check if the pressure is in millibars or pascals
    pressure.putVar(startp, factGroup->getFact("absolutePressureMillibars")->rawValue().toFloat());
    //TODO: check if the temperature is in Celsius or Kelvin
    airTemp.putVar(startp, factGroup->getFact("temperatureCelsius")->rawValue().toFloat());
    relHum.putVar(startp, factGroup->getFact("relativeHumidity")->rawValue().toFloat());
    windSpeed.putVar(startp, factGroup->getFact("windSpeedMetersPerSecond")->rawValue().toFloat());
    windDirection.putVar(startp, factGroup->getFact("windBearingDegrees")->rawValue().toFloat());
    latitude.putVar(startp, factGroup->getFact("latitudeDegrees")->rawValue().toDouble());
    longitude.putVar(startp, factGroup->getFact("longitudeDegrees")->rawValue().toDouble());
    roll.putVar(startp, factGroup->getFact("rollDegrees")->rawValue().toFloat());
    rollRate.putVar(startp, factGroup->getFact("rollRateDegreesPerSecond")->rawValue().toFloat());
    pitch.putVar(startp, factGroup->getFact("pitchDegrees")->rawValue().toFloat());
    pitchRate.putVar(startp, factGroup->getFact("pitchRateDegreesPerSecond")->rawValue().toFloat());
    yaw.putVar(startp, factGroup->getFact("yawDegrees")->rawValue().toFloat());
    yawRate.putVar(startp, factGroup->getFact("yawRateDegreesPerSecond")->rawValue().toFloat());
    speedOverGround.putVar(startp, factGroup->getFact("zVelocityMetersPerSecond")->rawValue().toFloat());
    speedOverGroundUp.putVar(startp, factGroup->getFact("zVelocityMetersPerSecondInverted")->rawValue().toFloat());
    //TODO: put in the real fact for mix ratio
    mixRatio.putVar(startp, factGroup->getFact("zVelocityMetersPerSecond")->rawValue().toFloat());
    qDebug() << "Wrote line to NetCDF file at index: " << startp[0] << "\n";
    // increment the index vector unlimited dimension
    startp[0]++;
    return;
}

