#include "MessengerAltitude.h"
#include "IMetMath.h"
#include <ctime>
#include <cstdint>
#include <cmath>
#include "QDebug"
#include "qdir.h"
#include <QFileInfo>
#include <QStandardPaths>
#include "QGCApplication.h"
#include "SettingsManager.h"

#define _CRT_SECURE_NO_WARNINGS

const MessengerAltitude::WindProps MessengerAltitude::calcWindProps() const {
    WindProps props;

    assert(source && "AltitudeMessenger.source was null during calcWindProps");
    if (!source) {
        /* if not source, QGC or hardware has shit the bed, perhaps this would be a good time to except or log the error to a file and flush? */
        qDebug() << "Fatal error";
        return props;
    }

    /* Magic numbers from Tony Segales' paper */
    constexpr double a = 39.4;
    constexpr double b = 5.71;

    const double rolldegrees = source->rollDegrees()->rawValue().toDouble();
    const double pitchdegrees = source->pitchDegrees()->rawValue().toDouble();
    const double yawdegrees = source->yawDegrees()->rawValue().toDouble();

    IMetMath::SResult croll_r = IMetMath::DegreesToRadians(rolldegrees);
    assert(croll_r.result == IMetMath::Result::_SUCCESS || croll_r.result == IMetMath::Result::_INPUT_EXCEEDS_RANGE);
    const double croll = cos(croll_r.value);

    IMetMath::SResult sroll_r = IMetMath::DegreesToRadians(rolldegrees);
    assert(sroll_r.result == IMetMath::Result::_SUCCESS || sroll_r.result == IMetMath::Result::_INPUT_EXCEEDS_RANGE);
    const double sroll = sin(sroll_r.value);

    IMetMath::SResult cpitch_r = IMetMath::DegreesToRadians(pitchdegrees);
    assert(cpitch_r.result == IMetMath::Result::_SUCCESS || cpitch_r.result == IMetMath::Result::_INPUT_EXCEEDS_RANGE);
    const double cpitch = cos(cpitch_r.value);

    IMetMath::SResult spitch_r = IMetMath::DegreesToRadians(pitchdegrees);
    assert(spitch_r.result == IMetMath::Result::_SUCCESS || spitch_r.result == IMetMath::Result::_INPUT_EXCEEDS_RANGE);
    const double spitch = sin(spitch_r.value);

    IMetMath::SResult cyaw_r = IMetMath::DegreesToRadians(yawdegrees);
    assert(cyaw_r.result == IMetMath::Result::_SUCCESS || cyaw_r.result == IMetMath::Result::_INPUT_EXCEEDS_RANGE);
    const double cyaw = cos(cyaw_r.value);

    IMetMath::SResult syaw_r = IMetMath::DegreesToRadians(yawdegrees);
    assert(syaw_r.result == IMetMath::Result::_SUCCESS || syaw_r.result == IMetMath::Result::_INPUT_EXCEEDS_RANGE);
    const double syaw = sin(syaw_r.value);

    const double dirRads = atan2(-croll * spitch * syaw + sroll * cyaw, -sroll * syaw - croll * spitch * cyaw);

    IMetMath::SResult dirDegrees_r = IMetMath::RadiansToDegrees(dirRads);
    assert(dirDegrees_r.result == IMetMath::Result::_SUCCESS || dirDegrees_r.result == IMetMath::Result::_INPUT_EXCEEDS_RANGE);

    props.dir = static_cast<int32_t>(fmod(dirDegrees_r.value + 360., 360.));

    /* Can still yield 0.0 and +inf, however these are appropriate given the algorithm. */
    props.speed = fmax(0., a * sqrt(tan(acos(std::clamp(croll * cpitch, -1., +1.)))) - b);

    return props;
}

void MessengerAltitude::buildUTCDateStr(){
    std::string YY = std::to_string(static_cast<int>((pt->tm_year + 1900) % 100));
    std::string MM = std::to_string(static_cast<int>(pt->tm_mon + 1));
    std::string DD = std::to_string(static_cast<int>(pt->tm_mday));
    std::string s = std::string("/");
    std::string str = YY + s + MM + s + DD;
    data->uTCDate()->setRawValue(QVariant(str.c_str()));
}

void MessengerAltitude::buildUTCTimeStr(){
    std::string hh = std::to_string(static_cast<int>(pt->tm_hour));
    std::string mm = std::to_string(static_cast<int>(pt->tm_min));
    std::string ss = std::to_string(static_cast<int>(pt->tm_sec));
    std::string c = std::string(":");
    std::string str = hh + c + mm + c + ss;
    data->uTCTime()->setRawValue(QVariant(str.c_str()));
}

void MessengerAltitude::buildFilename(){
    std::string alm = std::string("ALM");
    std::string srn = std::to_string(data->droneSerial()->rawValue().toInt());
    std::string YYYY = std::to_string(data->year()->rawValue().toUInt());
    std::string MM = std::to_string(data->month()->rawValue().toUInt());
    std::string DD = std::to_string(data->day()->rawValue().toUInt());
    std::string HH = std::to_string(data->hour()->rawValue().toUInt());
    std::string Mm = std::to_string(data->minute()->rawValue().toUInt());
    std::string ss = std::to_string(data->second()->rawValue().toUInt());
    std::string str = data->string()->rawValueString().toStdString();
    std::string csv = std::string(".csv");
    std::string _ = std::string("_");
    std::string filename = alm + _ + srn + _ + YYYY + MM + DD + _ + HH + Mm + ss + _ + str + csv;
    data->rawDataFilename()->setRawValue(QVariant(filename.c_str()));
}

void MessengerAltitude::getStringFromUser(){
    const char* s = ""; /* TODO: read a file or GUI, don't know what file to read yet tho. */
    data->string()->setRawValue(QVariant(s));
}

void MessengerAltitude::updateTime(){
    std::time_t t = static_cast<std::time_t>(source->timeUnixSeconds()->rawValue().toDouble());
    pt = std::gmtime(&t);

    if (!pt){
        /* Technically gmtime may be able to fail, so we should probably handle that somehow, but I don't think it can in practise. And if it's null, we just don't
            update the time facts, which have defaults anyway, so no crash, just 00 for the time facts. */
    }
}

void MessengerAltitude::updateConstantData(){
    static bool init = false;
    if (init) return;

    int32_t srn = source->droneSerialNumber()->rawValue().toInt();
    data->droneSerial()->setRawValue(QVariant(srn));

    uint16_t YYYY = static_cast<uint16_t>(pt->tm_year + 1900);
    data->year()->setRawValue(QVariant(YYYY));

    uint8_t MM = static_cast<uint8_t>(pt->tm_mon + 1);
    data->month()->setRawValue(QVariant(MM));

    uint8_t DD = static_cast<uint8_t>(pt->tm_mday);
    data->day()->setRawValue(QVariant(DD));

    uint8_t HH = static_cast<uint8_t>(pt->tm_hour);
    data->hour()->setRawValue(QVariant(HH));

    uint8_t Mm = static_cast<uint8_t>(pt->tm_min);
    data->minute()->setRawValue(QVariant(Mm));

    uint8_t ss = static_cast<uint8_t>(pt->tm_sec);
    data->second()->setRawValue(QVariant(ss));

    getStringFromUser(); /* Not yet implemented, need to know what file to read. */

    /* Message_Version doesn't need to be updated here because the default value set in MessageAltitudeFactGroup.cc is all sufficient. */

    int32_t poweredAge = source->poweredAgeSeconds()->rawValue().toInt();
    data->dronePoweredAge()->setRawValue(QVariant(poweredAge));

    int32_t armedAge = source->armedAgeSeconds()->rawValue().toInt();
    data->droneArmedAge()->setRawValue(QVariant(armedAge));

    buildFilename();

    double time = source->timeUnixSeconds()->rawValue().toDouble();
    data->unixStartTime()->setRawValue(QVariant(static_cast<int32_t>(time)));

    double groundWindSpd = source->groundWindSpeedMetersPerSecond()->rawValue().toDouble();
    data->groundWindSpeed()->setRawValue(QVariant(groundWindSpd));

    int32_t groundWindDir = source->groundWindDirectionDegrees()->rawValue().toInt();
    data->groundWindDirection()->setRawValue(QVariant(groundWindDir));

    double groundAirTemp = source->groundAirTemperatureCelsius()->rawValue().toDouble();
    data->groundAirTemperature()->setRawValue(QVariant(groundAirTemp));

    double groundHum = source->groundHumidity()->rawValue().toDouble();
    data->groundHumidity()->setRawValue(QVariant(groundHum));

    double groundPressure = source->groundPressureMillibars()->rawValue().toDouble();
    data->groundPressure()->setRawValue(QVariant(groundPressure));

    double homeLat = source->homePositionLatitudeDegrees()->rawValue().toDouble();
    data->homePositionLatitude()->setRawValue(QVariant(homeLat));

    double homeLon = source->homePositionLongitudeDegrees()->rawValue().toDouble();
    data->homePositionLongitude()->setRawValue(QVariant(homeLon));

    double homeAlt = source->homePositionAltitudeMeters()->rawValue().toDouble();
    data->homePositionAltitude()->setRawValue(QVariant(homeAlt));

    init = true;
}

void MessengerAltitude::updateData(){
    double alt = source->altitudeMetersASL()->rawValue().toDouble();
    data->altitudeASL()->setRawValue(QVariant(alt));

    updateTime();
    buildUTCDateStr();
    buildUTCTimeStr();

    double now = source->timeUnixSeconds()->rawValue().toDouble();
    double start = static_cast<double>(data->unixStartTime()->rawValue().toInt());
    data->timeSinceStart()->setRawValue(QVariant(now - start));

    double pres = source->absolutePressureMillibars()->rawValue().toDouble();
    data->pressure()->setRawValue(QVariant(pres));

    double t0 = source->temperature0Celsius()->rawValue().toDouble();
    double t1 = source->temperature1Celsius()->rawValue().toDouble();
    double t2 = source->temperature2Celsius()->rawValue().toDouble();
    data->airTemp()->setRawValue(QVariant((t0 + t1 + t2) / 3.));

    double h0 = source->relativeHumidity0()->rawValue().toDouble();
    double h1 = source->relativeHumidity1()->rawValue().toDouble();
    double h2 = source->relativeHumidity2()->rawValue().toDouble();
    data->relHum()->setRawValue(QVariant((h0 + h1 + h2) / 3.));

    uint16_t satellites = source->satellites()->rawValue().toUInt();
    data->satellites()->setRawValue(QVariant(satellites));

    const WindProps windProps = calcWindProps();
    data->windDirection()->setRawValue(QVariant(windProps.dir));
    data->windSpeed()->setRawValue(QVariant(windProps.speed));

    double lat = source->latitudeDegrees()->rawValue().toDouble();
    data->latitude()->setRawValue(QVariant(lat));

    double lon = source->longitudeDegrees()->rawValue().toDouble();
    data->longitude()->setRawValue(QVariant(lon));

    double roll = source->rollDegrees()->rawValue().toDouble();
    data->roll()->setRawValue(QVariant(roll));

    double pitch = source->pitchDegrees()->rawValue().toDouble();
    data->pitch()->setRawValue(QVariant(pitch));

    double yaw = source->yawDegrees()->rawValue().toDouble();
    data->yaw()->setRawValue(QVariant(yaw));

    double rollRate = source->rollRateDegreesPerSecond()->rawValue().toDouble();
    data->rollRate()->setRawValue(QVariant(rollRate));

    double pitchRate = source->pitchRateDegreesPerSecond()->rawValue().toDouble();
    data->pitchRate()->setRawValue(QVariant(pitchRate));

    double yawRate = source->yawRateDegreesPerSecond()->rawValue().toDouble();
    data->yawRate()->setRawValue(QVariant(yawRate));

    double ascentRate = -source->zVelocityMetersPerSecond()->rawValue().toDouble();
    data->ascentRate()->setRawValue(QVariant(ascentRate));

    double vx = source->xVelocityMetersPerSecond()->rawValue().toDouble();
    double vy = source->yVelocityMetersPerSecond()->rawValue().toDouble();
    double groundSpeed = std::max(0., std::hypot(vx, vy));
    data->speedOverGround()->setRawValue(QVariant(groundSpeed));

    double hdop = source->horizontalDilutionOfPositionFloat()->rawValue().toDouble();
    data->hDOP()->setRawValue(QVariant(hdop));

    int32_t dataQuality = source->dataQuality()->rawValue().toInt();
    data->dataQuality()->setRawValue(QVariant(dataQuality));
}

bool MessengerAltitude::criteriaMet(){
    updateTime();
    updateConstantData();
    updateData();
    if (!passedThreshold()) return false;
    return true;
}

void MessengerAltitude::publish(){
    log();

    // QString logFilePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
    //                       + "/QGroundControl/temp alm log.txt";

    // QFileInfo fileInfo(logFilePath);
    // QDir().mkpath(fileInfo.absolutePath());

    // QFile file(logFilePath);
    // if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
    //     QTextStream stream(&file);

    //     stream << "--- Log Entry: " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " ---\n";
    //     stream << "drone serial: " << data->droneSerial()->rawValue().toInt() << "\n";
    //     stream << "year: " << data->year()->rawValue().toInt() << "\n";
    //     stream << "month: " << data->month()->rawValue().toInt() << "\n";
    //     stream << "day: " << data->day()->rawValue().toInt() << "\n";
    //     stream << "hour: " << data->hour()->rawValue().toInt() << "\n";
    //     stream << "minute: " << data->minute()->rawValue().toInt() << "\n";
    //     stream << "second: " << data->second()->rawValue().toInt() << "\n";
    //     stream << "string: " << data->string()->rawValue().toString() << "\n";
    //     stream << "message version: " << data->messageVersion()->rawValue().toString() << "\n";
    //     stream << "drone powered age: " << data->dronePoweredAge()->rawValue().toInt() << "\n";
    //     stream << "drone armed age: " << data->droneArmedAge()->rawValue().toInt() << "\n";
    //     stream << "raw data filename: " << data->rawDataFilename()->rawValue().toString() << "\n";
    //     stream << "unix start time: " << data->unixStartTime()->rawValue().toULongLong() << "\n";
    //     stream << "ground wind speed: " << data->groundWindSpeed()->rawValue().toDouble() << "\n";
    //     stream << "ground wind direction: " << data->groundWindDirection()->rawValue().toInt() << "\n";
    //     stream << "ground air temperature: " << data->groundAirTemperature()->rawValue().toDouble() << "\n";
    //     stream << "ground humidity: " << data->groundHumidity()->rawValue().toDouble() << "\n";
    //     stream << "ground pressure: " << data->groundPressure()->rawValue().toDouble() << "\n";
    //     stream << "home position latitude: " << data->homePositionLatitude()->rawValue().toDouble() << "\n";
    //     stream << "home position longitude: " << data->homePositionLongitude()->rawValue().toDouble() << "\n";
    //     stream << "home position altitude: " << data->homePositionAltitude()->rawValue().toDouble() << "\n";
    //     stream << "altitude ASL: " << data->altitudeASL()->rawValue().toDouble() << "\n";
    //     stream << "UTC date: " << data->uTCDate()->rawValue().toString() << "\n";
    //     stream << "UTC time: " << data->uTCTime()->rawValue().toString() << "\n";
    //     stream << "time since start: " << data->timeSinceStart()->rawValue().toDouble() << "\n";
    //     stream << "pressure: " << data->pressure()->rawValue().toDouble() << "\n";
    //     stream << "air temp: " << data->airTemp()->rawValue().toDouble() << "\n";
    //     stream << "rel hum: " << data->relHum()->rawValue().toDouble() << "\n";
    //     stream << "wind speed: " << data->windSpeed()->rawValue().toDouble() << "\n";
    //     stream << "wind direction: " << data->windDirection()->rawValue().toInt() << "\n";
    //     stream << "latitude: " << data->latitude()->rawValue().toDouble() << "\n";
    //     stream << "longitude: " << data->longitude()->rawValue().toDouble() << "\n";
    //     stream << "roll: " << data->roll()->rawValue().toDouble() << "\n";
    //     stream << "roll rate: " << data->rollRate()->rawValue().toDouble() << "\n";
    //     stream << "pitch: " << data->pitch()->rawValue().toDouble() << "\n";
    //     stream << "pitch rate: " << data->pitchRate()->rawValue().toDouble() << "\n";
    //     stream << "yaw: " << data->yaw()->rawValue().toDouble() << "\n";
    //     stream << "yaw rate: " << data->yawRate()->rawValue().toDouble() << "\n";
    //     stream << "ascent rate: " << data->ascentRate()->rawValue().toDouble() << "\n";
    //     stream << "speed over ground: " << data->speedOverGround()->rawValue().toDouble() << "\n";
    //     stream << "satellites: " << data->satellites()->rawValue().toInt() << "\n";
    //     stream << "hDOP: " << data->hDOP()->rawValue().toDouble() << "\n";
    //     stream << "data quality: " << data->dataQuality()->rawValue().toInt() << "\n";
    //     stream << "\n";

    //     file.close();
    // }
}

bool MessengerAltitude::passedThreshold(){
    Q_ASSERT(source);
    Fact* pFact = source->altitudeMetersASL();
    Q_ASSERT(pFact);
    double alt = pFact->rawValue().toDouble();

    bool armed = source->customModeHeartbeat()->rawValue().toBool();

    if (qIsNaN(lastAltBin)){
        return handleFirstAltitude(alt) && armed;
    }
    if (alt - lastAltBin >= altitudeBin  && armed){
        lastAltBin = alt;
        return true;
    }
    return false;
}

bool MessengerAltitude::handleFirstAltitude(const double alt){
    Q_ASSERT(source);
    Fact* pFact = source->homePositionAltitudeMeters();
    Q_ASSERT(pFact);
    double homeAlt = pFact->rawValue().toDouble();

    double minAltBound = minHomeAlt;
    double maxAltBound = maxHomeAlt;
    bool bHomeAlt = false;
    if ((bHomeAlt = !qIsNaN(homeAlt))){
        minAltBound = std::max(minAltBound, homeAlt - homeAltRange);
        maxAltBound = std::min(maxAltBound, homeAlt + homeAltRange);
    }

    if (alt >= minAltBound && alt <= maxAltBound){
        lastAltBin = alt;
        return true;
    }
#ifdef QT_DEBUG
    qDebug() << "Anomaly: Initial altitude out of range, ALM production halted.";
    if (bHomeAlt) {
        qDebug() << "Home altitude successfully read from file as: " << homeAlt;
    } else {
        qDebug() << "Home altitude not found in file.";
    }
    qDebug() << "Currently filtering initial altitude outside the range: " << minAltBound << "to " << maxAltBound;
    qDebug() << "Reported altitude was: " << alt;
#endif /* QT_DEBUG */
    return false;
}

void MessengerAltitude::log() {
    initLogFile();

    Vehicle* activeVehicle = qgcApp()->toolbox()->multiVehicleManager()->activeVehicle();
    if(!activeVehicle) return;

    if (!activeVehicle->armed() || !logFile.isOpen()){
        logFile.close();
        return;
    }
    QStringList metFactValues;
    QTextStream stream(&logFile);
    if (!data) return;
    QString timestamp = data->getFact("timeSinceStart")->rawValueString();
    if (timestamp == latestTimestamp) {
        return;
    } else {
        latestTimestamp = timestamp;
    }
    for (const auto &factName : logFactNames) {
        if(!data->factExists(factName)) {
            qCWarning(VehicleLog) << "Fact does not exist: " << factName;
            continue;
        }
        metFactValues << data->getFact(factName)->rawValueString();
    }

    stream << metFactValues.join(",") << "\r\n";
}

void MessengerAltitude::initLogFile(){
    static bool init = false;
    if (init) return;

    Vehicle* activeVehicle = qgcApp()->toolbox()->multiVehicleManager()->activeVehicle();
    if(!activeVehicle) return;
    if (!(activeVehicle->armed() || logOnConnect)) return;

    QString now = QDateTime::currentDateTime().toString("MM-dd-yyyy_hh-mm-ss");
    QString metRawFileName = QString("ALM_TEST__%1.csv").arg(now);
    QDir saveDir(qgcApp()->toolbox()->settingsManager()->appSettings()->messagesAltLevelSavePath());
    logFile.setFileName(saveDir.absoluteFilePath(metRawFileName));
    if (!logFile.open(QIODevice::Append)) {
        qCWarning(VehicleLog) << "unable to open alm message file for text logging, Stopping text logging!";
        return;
    }
    QTextStream stream(&logFile);

    int i;
    for (i = 0, i < logConstantNames.size(); i++;) {
        QString name = logConstantNames[i];
        QString unit = logConstantUnits[i];
        QString factName = logConstantFactNames[i];
        QString value;
        if (data && data->factExists(factName)) {
            value = data->getFact(factName)->rawValueString();
        } else {
            value = "N/A";
        }
        QString unitField = (unit == "N/A") ? "" : unit;
        stream << name << "," << value << "," << unitField << "\r\n";
    }

    stream << logHeaders.join(",") << "\r\n";
    stream << logUnits.join(",") << "\r\n";
    init = true;
}

#undef _CRT_SECURE_NO_WARNINGS
