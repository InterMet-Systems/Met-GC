#include "MessengerTime.h"

bool MessengerTime::criteriaMet(){
    updateTime();
    updateConstantData();
    updateData();
    if (!timer()) return false;
    return true;
}

void MessengerTime::publish(){
    QString logFilePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
                          + "/QGroundControl/temp tlm log.txt";

    QFileInfo fileInfo(logFilePath);
    QDir().mkpath(fileInfo.absolutePath());

    QFile file(logFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);

        stream << "--- Log Entry: " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " ---\n";
        stream << "drone serial: " << data->droneSerial()->rawValue().toInt() << "\n";
        stream << "message version: " << data->messageVersion()->rawValue().toString() << "\n";
        stream << "drone powered age: " << data->dronePoweredAge()->rawValue().toInt() << "\n";
        stream << "drone armed age: " << data->droneArmedAge()->rawValue().toInt() << "\n";
        stream << "raw data filename: " << data->rawDataFilename()->rawValue().toString() << "\n";
        stream << "unix start time: " << data->unixStartTime()->rawValue().toULongLong() << "\n";
        stream << "ground wind speed: " << data->groundWindSpeed()->rawValue().toDouble() << "\n";
        stream << "ground wind direction: " << data->groundWindDirection()->rawValue().toInt() << "\n";
        stream << "ground air temperature: " << data->groundAirTemperature()->rawValue().toDouble() << "\n";
        stream << "ground humidity: " << data->groundHumidity()->rawValue().toDouble() << "\n";
        stream << "ground pressure: " << data->groundPressure()->rawValue().toDouble() << "\n";
        stream << "home position latitude: " << data->homePositionLatitude()->rawValue().toDouble() << "\n";
        stream << "home position longitude: " << data->homePositionLongitude()->rawValue().toDouble() << "\n";
        stream << "home position altitude: " << data->homePositionAltitude()->rawValue().toDouble() << "\n";
        stream << "altitude ASL: " << data->altitudeASL()->rawValue().toDouble() << "\n";
        stream << "UTC date: " << data->uTCDate()->rawValue().toString() << "\n";
        stream << "UTC time: " << data->uTCTime()->rawValue().toString() << "\n";
        stream << "time since start: " << data->timeSinceStart()->rawValue().toInt() << "\n";
        stream << "pressure: " << data->pressure()->rawValue().toDouble() << "\n";
        stream << "air temp: " << data->airTemp()->rawValue().toDouble() << "\n";
        stream << "rel hum: " << data->relHum()->rawValue().toDouble() << "\n";
        stream << "wind speed: " << data->windSpeed()->rawValue().toDouble() << "\n";
        stream << "wind direction: " << data->windDirection()->rawValue().toInt() << "\n";
        stream << "latitude: " << data->latitude()->rawValue().toDouble() << "\n";
        stream << "longitude: " << data->longitude()->rawValue().toDouble() << "\n";
        stream << "roll: " << data->roll()->rawValue().toDouble() << "\n";
        stream << "roll rate: " << data->rollRate()->rawValue().toDouble() << "\n";
        stream << "pitch: " << data->pitch()->rawValue().toDouble() << "\n";
        stream << "pitch rate: " << data->pitchRate()->rawValue().toDouble() << "\n";
        stream << "yaw: " << data->yaw()->rawValue().toDouble() << "\n";
        stream << "yaw rate: " << data->yawRate()->rawValue().toDouble() << "\n";
        stream << "ascent rate: " << data->ascentRate()->rawValue().toDouble() << "\n";
        stream << "speed over ground: " << data->speedOverGround()->rawValue().toDouble() << "\n";
        stream << "satellites: " << data->satellites()->rawValue().toInt() << "\n";
        stream << "hDOP: " << data->hDOP()->rawValue().toDouble() << "\n";
        stream << "data quality: " << data->dataQuality()->rawValue().toInt() << "\n";
        stream << "\n";

        file.close();
    }
}

void MessengerTime::buildFilename(){
    std::string filename = std::string("coming soon to a blockbuster near your");
    /* Yet to be implemented
    this is almost exactly the same as in the ALM, which is implemented, so I could just copy it. However, I don't like the approach I used there, and
    both need to be improved. Leaving this empty will make sure that it gets caught and I will come back and see this comment.
    */
    data->rawDataFilename()->setRawValue(QVariant(filename.c_str()));
}

void MessengerTime::updateTime(){
    std::time_t t = static_cast<std::time_t>(source->timeUnixSeconds()->rawValue().toDouble());
    pt = std::gmtime(&t);

    if (!pt){
        /* Technically gmtime may be able to fail, so we should probably handle that somehow, but I don't think it can in practise. And if it's null, we just don't
            update the time facts, which have defaults anyway, so no crash, just 00 for the time facts. */
    }
}

void MessengerTime::updateConstantData(){
    static bool init = false;
    if (init) return;

    int32_t srn = source->droneSerialNumber()->rawValue().toInt();
    data->droneSerial()->setRawValue(QVariant(srn));

    int32_t poweredAge = source->poweredAgeSeconds()->rawValue().toInt();
    data->dronePoweredAge()->setRawValue(QVariant(poweredAge));

    int32_t armedAge = source->armedAgeSeconds()->rawValue().toInt();
    data->droneArmedAge()->setRawValue(QVariant(armedAge));

    buildFilename();

    double time = source->timeUnixSeconds()->rawValue().toDouble();
    data->unixStartTime()->setRawValue(QVariant(static_cast<uint64_t>(time)));

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

void MessengerTime::updateData(){
    double alt = source->altitudeMetersASL()->rawValue().toDouble();
    data->altitudeASL()->setRawValue(QVariant(alt));

    updateTime();
    buildUTCDateStr();
    buildUTCTimeStr();

    double now = source->timeUnixSeconds()->rawValue().toDouble();
    double start = static_cast<double>(data->unixStartTime()->rawValue().toInt());
    data->timeSinceStart()->setRawValue(QVariant(static_cast<int32_t>(now - start)));

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

    /* We really should just make MessageAltitudeFactGroup the source for this, rather than MessageRawFactGroup. That's not the design I had intended, but
    the facts are almost 100% identical. We're just duplicating everything. We can't do exactly this, because we need the data organized differently.
    And I'm also not including another class for them both to inherit from, so I'm not sure what to do about this other than just duplicate the work... */

    uint16_t satellites = source->satellites()->rawValue().toUInt();
    data->satellites()->setRawValue(QVariant(satellites));
}

void MessengerTime::buildUTCDateStr(){
    std::string YY = std::to_string(static_cast<int>((pt->tm_year + 1900) % 100));
    std::string MM = std::to_string(static_cast<int>(pt->tm_mon + 1));
    std::string DD = std::to_string(static_cast<int>(pt->tm_mday));
    std::string s = std::string("/");
    std::string str = YY + s + MM + s + DD;
    data->uTCDate()->setRawValue(QVariant(str.c_str()));
}

void MessengerTime::buildUTCTimeStr(){
    std::string hh = std::to_string(static_cast<int>(pt->tm_hour));
    std::string mm = std::to_string(static_cast<int>(pt->tm_min));
    std::string ss = std::to_string(static_cast<int>(pt->tm_sec));
    std::string c = std::string(":");
    std::string str = hh + c + mm + c + ss;
    data->uTCTime()->setRawValue(QVariant(str.c_str()));
}

bool MessengerTime::timer() {
    double t = std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
    if (t - lastMessage >= (1 / frequency)) {
        lastMessage = t;
        return true;
    }
    return false;
}
