#include "QGCApplication.h"
#include "MetDataLogManager.h"
#include "SettingsManager.h"
#include "MetFlightDataRecorderController.h"
#include "Vehicle.h"
#include <QtMath>
#include <QDebug>
#include <libs/netcdf-cxx4/cxx4/netcdf>

using namespace std;
using namespace netCDF;
using namespace netCDF::exceptions;

MetDataLogManager::MetDataLogManager(QGCApplication* app, QGCToolbox* toolbox) : QGCTool(app, toolbox)
{
    connect(&_metRawCsvTimer, &QTimer::timeout, this, &MetDataLogManager::_writeMetRawCsvLine);
    connect(&_metAlmCsvTimer, &QTimer::timeout, this, &MetDataLogManager::_writeMetAlmCsvLine);
    connect(&_metNetCdfTimer, &QTimer::timeout, this, &MetDataLogManager::_writeMetNetCdfLine);
    connect(&_metConfigTimer, &QTimer::timeout, this, &MetDataLogManager::_initializeOrReadConfigFile);
    _metRawCsvTimer.start(20); // set below nyquist rate for 50ms balancedDataFrequency to ensure no data is missed
    _metAlmCsvTimer.start(20); // set below nyquist rate for 50ms balancedDataFrequency to ensure no data is missed
    _metNetCdfTimer.start(20); // timing for NetCDF messages should always be the same as the ALM messages
    _metConfigTimer.start(20); // temporary
}

MetDataLogManager::~MetDataLogManager()
{
    if(_metRawCsvFile.isOpen()) {
        _metRawCsvFile.close();
    }

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
    QString metRawFileName = QString("RAW_%1.csv").arg(now);
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
    // Acquire vehicle pointer
    Vehicle* _activeVehicle = qgcApp()->toolbox()->multiVehicleManager()->activeVehicle();
    if(_activeVehicle == NULL)
    {
        return;
    }

    // Only save the logs after the the vehicle gets armed, unless "Save logs even if vehicle was not armed" is checked
    if(!_metRawCsvFile.isOpen() && _activeVehicle->armed()) {
        _initializeMetRawCsv();
    }

    // close file if the drone is disarmed and the file is still open
    // safe to return here, as a closed file isn't going to receive data
    if(_metRawCsvFile.isOpen() && !_activeVehicle->armed()) {
        _metRawCsvFile.close();
        return;
    }

    // only record data when active vehcile is armed
    if(!_metRawCsvFile.isOpen() || !_activeVehicle->armed()) {
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

void MetDataLogManager::setOperatorId(QString operatorId)
{
    if(!_metNetCdfFile.isNull()) {
        _metNetCdfFile.close();
    }
    if(!(operatorId.trimmed().length() > 0)) {
        operatorId = DEFAULT_OPERATOR_ID;
    }
    qDebug() << "Operator ID: " << operatorId;
    _operatorId = operatorId;
}

void MetDataLogManager::setAirframeId(QString airframeId)
{
    if(!_metNetCdfFile.isNull()) {
        _metNetCdfFile.close();
    }
    if(!(airframeId.trimmed().length() > 0)) {
        airframeId = DEFAULT_AIRFRAME_ID;
    }
    qDebug() << "Airframe ID: " << airframeId;
    _airframeId = airframeId;
}

void MetDataLogManager::_initializeMetAlmCsv()
{
    int copyNumber = 1;
    QString metAlmFileName = QString("%1_%2_%3.csv").arg(_flightName).arg(copyNumber).arg(_ascentNumber);
    QDir saveDir(qgcApp()->toolbox()->settingsManager()->appSettings()->messagesAltLevelSavePath());
    _metAlmCsvFile.setFileName(saveDir.absoluteFilePath(metAlmFileName));

    while (_metAlmCsvFile.exists()) {
        copyNumber++;
        metAlmFileName = QString("%1_%2_%3.csv").arg(_flightName).arg(copyNumber).arg(_ascentNumber);
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

void MetDataLogManager::_initializeMetNetCdf(double timestamp)
{
    qint64 timestampInt = (qint64) timestamp;
    QDateTime datetime = QDateTime::fromSecsSinceEpoch(timestampInt);
    QString nowUtcString = datetime.toUTC().toString("yyyyMMddHHmmssZ");

    QString netCdfFileName = QString("UASDC_%1_%2_%3.nc").arg(_operatorId, _airframeId, nowUtcString);
    QDir saveDir(qgcApp()->toolbox()->settingsManager()->appSettings()->messagesNetCdfSavePath());
    QString _netCdfFullFilePath = saveDir.absoluteFilePath(netCdfFileName);

    // Create the file.
    _metNetCdfFile.open(_netCdfFullFilePath.toStdString(), NcFile::replace);

    // Add global attributes
    _metNetCdfFile.putAtt("Conventions", "CF-1.8, WMO-CF-1.0");
    _metNetCdfFile.putAtt("wmo__cf_profile", "FM 303-2024");
    _metNetCdfFile.putAtt("featureType", "trajectory");
    _metNetCdfFile.putAtt("platform_name", "CopterSonde 3");
    _metNetCdfFile.putAtt("processing_level", "c1");

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
    mixRatio             = _metNetCdfFile.addVar("humidity_mixing_ratio", ncDouble, dims);

    // add attributes to each variable
    altitude.putAtt("units", "m ASL");
    altitude.putAtt("standard_name", "Altitude");
    altitude.putAtt("long_name", "Altitude (height)");
    altitude.putAtt("axis", "Z");

    time.putAtt("units", "seconds since 1970-01-01T00:00:00");
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
        // ensure that file is closed at the end of the flight
        if(!_metNetCdfFile.isNull()) {
            _metNetCdfFile.close();
        }
        return;
    }
    factGroup = _activeVehicle->getFactGroup("temperature");

    if (!factGroup) {
        return;
    }

    // make sure we're not logging the same data again
    QString timestamp = factGroup->getFact("time")->rawValueString();
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

    double timeDouble = factGroup->getFact("time")->rawValue().toDouble();

    if(_metNetCdfFile.isNull()) {
        _initializeMetNetCdf(timeDouble);
    }

    // calculate the humidity mixing ratio
    float tempValC = factGroup->getFact("airTemp")->rawValue().toFloat();
    float relHumValPercent = factGroup->getFact("relHum")->rawValue().toFloat();
    float relHumValDec = relHumValPercent * 0.01;
    float airPressureValMb = factGroup->getFact("pressure")->rawValue().toFloat();
    float satPressureValMb = 6.112 * qExp((17.62 * tempValC) / (243.12 + tempValC));
    double mixRatioValue = 0.6219743 * relHumValDec * satPressureValMb / (airPressureValMb -  satPressureValMb);

    // other netcdf conversions
    float tempValK = tempValC + 273.15;
    float airPressureValPa = airPressureValMb * 100;

    altitude.putVar(         startp, factGroup->getFact("asl")->rawValue().toFloat());
    time.putVar(             startp, timeDouble);
    pressure.putVar(         startp, airPressureValPa);
    airTemp.putVar(          startp, tempValK);
    relHum.putVar(           startp, relHumValPercent);
    windSpeed.putVar(        startp, factGroup->getFact("windSpeed"      )->rawValue().toFloat());
    windDirection.putVar(    startp, factGroup->getFact("windDirection"  )->rawValue().toFloat());
    latitude.putVar(         startp, factGroup->getFact("latitude"       )->rawValue().toDouble());
    longitude.putVar(        startp, factGroup->getFact("longitude"      )->rawValue().toDouble());
    roll.putVar(             startp, factGroup->getFact("roll"           )->rawValue().toFloat());
    rollRate.putVar(         startp, factGroup->getFact("rollRate"       )->rawValue().toFloat());
    pitch.putVar(            startp, factGroup->getFact("pitch"          )->rawValue().toFloat());
    pitchRate.putVar(        startp, factGroup->getFact("pitchRate"      )->rawValue().toFloat());
    yaw.putVar(              startp, factGroup->getFact("yaw"            )->rawValue().toFloat());
    yawRate.putVar(          startp, factGroup->getFact("yawRate"        )->rawValue().toFloat());
    speedOverGround.putVar(  startp, factGroup->getFact("speedOverGround")->rawValue().toFloat());
    speedOverGroundUp.putVar(startp, factGroup->getFact("ascentRate"     )->rawValue().toFloat());
    mixRatio.putVar(         startp, mixRatioValue);

    // increment the index vector unlimited dimension
    startp[0]++;
    return;
}

void MetDataLogManager::_initializeOrReadConfigFile() {
    _metConfigTimer.stop();
    QString configFileName = QString("flightConfig.ini");
    QString configSaveDir = qgcApp()->toolbox()->settingsManager()->appSettings()->configSavePath();
    QDir saveDir(configSaveDir);
    QString _configFullFilePath = saveDir.absoluteFilePath(configFileName);
    _metConfigFile.setFileName(_configFullFilePath);
    qDebug() << "config file name: " << _configFullFilePath;
    // if file exists, read its values. Otherwise create it with default values
    if (_metConfigFile.exists()) {
        _metConfigFile.open(QIODevice::ReadWrite);
        QTextStream in(&_metConfigFile);
        QString fileContents = in.readAll();
        if(!iniParser.parseFile(fileContents)) {
            return;
        }
        QMap<QString, QMap<QString, QString>> fileData = iniParser.getSections();
        if(fileData.contains("FlightData") && fileData["FlightData"].contains("FlightName")) {
            MetDataLogManager::setFlightFileName(fileData["FlightData"]["FlightName"]);
        }
        if(fileData.contains("FlightData") && fileData["FlightData"].contains("AirframeId")) {
            MetDataLogManager::setAirframeId(fileData["FlightData"]["AirframeId"]);
        }
        if(fileData.contains("FlightData") && fileData["FlightData"].contains("OperatorId")) {
            MetDataLogManager::setOperatorId(fileData["FlightData"]["OperatorId"]);
        }
    } else {
        _metConfigFile.open(QIODevice::Append);
        QMap<QString, QMap<QString, QString>> defaultConfig;
        defaultConfig["FlightData"]["FlightName"] = _flightName;
        defaultConfig["FlightData"]["AirframeId"] = _airframeId;
        defaultConfig["FlightData"]["OperatorId"] = _operatorId;
        iniParser.setSections(defaultConfig);
        QString defaultConfigFileData = iniParser.print();
        QTextStream out(&_metConfigFile);
        out << defaultConfigFileData;
    }
}
