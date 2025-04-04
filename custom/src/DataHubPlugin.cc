#include <QtQml>
#include <QQmlEngine>
#include <QDateTime>
#include "DataHubPlugin.h"
#include "MultiVehicleManager.h"
#include "QGCApplication.h"

DataHubPlugin::DataHubPlugin(QGCApplication *app, QGCToolbox* toolbox)
    : QGCCorePlugin(app, toolbox)
    , dataFactGroup()
    , hub(&dataFactGroup)
    , messageRawFactGroup()
    , messengerRaw(&dataFactGroup, &messageRawFactGroup)
    , messageAltitudeFactGroup()
    , messengerAltitude(&messageRawFactGroup, &messageAltitudeFactGroup)
    , messageTimeFactGroup()
    , messengerTime(&messageRawFactGroup, &messageTimeFactGroup)
{
    messengerRaw.dataHub = &hub;
    messengerRaw.subscribers.push_back(&messengerAltitude);
    messengerRaw.subscribers.push_back(&messengerTime);
    logTimer = new QTimer(this);
    connect(logTimer, &QTimer::timeout, this, &DataHubPlugin::logDataToFile);
    logTimer->start(5000);
}

DataHubPlugin::~DataHubPlugin()
{
    logTimer->stop();
    delete logTimer;
}

bool DataHubPlugin::mavlinkMessage(Vehicle* vehicle, LinkInterface* link, mavlink_message_t message)
{
    (void)hub.parseMessage(message);
    if (messengerRaw.criteriaMet()) {
        messengerRaw.publish();
        qDebug() << "published a raw message";
        logRawMessagesToFile();
    }
    return true;
}

void DataHubPlugin::logDataToFile()
{
    QString logFilePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
                          + "/QGroundControl/temp datahub log.txt";

    QFileInfo fileInfo(logFilePath);
    QDir().mkpath(fileInfo.absolutePath());

    QFile file(logFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);

        stream << "--- Log Entry: " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " ---\n";

        stream << "timeUnixMicroseconds: " << dataFactGroup.timeUnixMicroseconds()->rawValue().toULongLong() << "\n";
        stream << "altitudeMillimetersMSL: " << dataFactGroup.altitudeMillimetersMSL()->rawValue().toInt() << "\n";
        stream << "absolutePressureMillibars: " << dataFactGroup.absolutePressureMillibars()->rawValue().toDouble() << "\n";
        stream << "temperature0Kelvin: " << dataFactGroup.temperature0Kelvin()->rawValue().toDouble() << "\n";
        stream << "temperature1Kelvin: " << dataFactGroup.temperature1Kelvin()->rawValue().toDouble() << "\n";
        stream << "temperature2Kelvin: " << dataFactGroup.temperature2Kelvin()->rawValue().toDouble() << "\n";
        stream << "relativeHumidity0: " << dataFactGroup.relativeHumidity0()->rawValue().toDouble() << "\n";
        stream << "relativeHumidity1: " << dataFactGroup.relativeHumidity1()->rawValue().toDouble() << "\n";
        stream << "relativeHumidity2: " << dataFactGroup.relativeHumidity2()->rawValue().toDouble() << "\n";
        stream << "latitudeDegreesE7: " << dataFactGroup.latitudeDegreesE7()->rawValue().toInt() << "\n";
        stream << "longitudeDegreesE7: " << dataFactGroup.longitudeDegreesE7()->rawValue().toInt() << "\n";
        stream << "rollRadians: " << dataFactGroup.rollRadians()->rawValue().toDouble() << "\n";
        stream << "pitchRadians: " << dataFactGroup.pitchRadians()->rawValue().toDouble() << "\n";
        stream << "yawRadians: " << dataFactGroup.yawRadians()->rawValue().toDouble() << "\n";
        stream << "rollRateRadiansPerSecond: " << dataFactGroup.rollRateRadiansPerSecond()->rawValue().toDouble() << "\n";
        stream << "pitchRateRadiansPerSecond: " << dataFactGroup.pitchRateRadiansPerSecond()->rawValue().toDouble() << "\n";
        stream << "yawRateRadiansPerSecond: " << dataFactGroup.yawRateRadiansPerSecond()->rawValue().toDouble() << "\n";
        stream << "xVelocityMetersPerSecond: " << dataFactGroup.xVelocityMetersPerSecond()->rawValue().toDouble() << "\n";
        stream << "yVelocityMetersPerSecond: " << dataFactGroup.yVelocityMetersPerSecond()->rawValue().toDouble() << "\n";
        stream << "zVelocityMetersPerSecond: " << dataFactGroup.zVelocityMetersPerSecond()->rawValue().toDouble() << "\n";
        stream << "customModeHeartbeat: " << dataFactGroup.customModeHeartbeat()->rawValue().toUInt() << "\n";
        stream << "dataQuality: " << dataFactGroup.dataQuality()->rawValue().toInt() << "\n";
        stream << "satellites: " << dataFactGroup.satellites()->rawValue().toUInt() << "\n";
        stream << "horizontalDilutionOfPosition: " << dataFactGroup.horizontalDilutionOfPosition()->rawValue().toUInt() << "\n";
        stream << "\n";

        file.close();
    }
}

void DataHubPlugin::logRawMessagesToFile(){
    QString logFilePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
                          + "/QGroundControl/raw log.txt";

    QFileInfo fileInfo(logFilePath);
    QDir().mkpath(fileInfo.absolutePath());

    QFile file(logFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);

        stream << "--- Log Entry: " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " ---\n";

        stream << "timeUnixMicroseconds: " << messageRawFactGroup.timeUnixSeconds()->rawValue().toDouble() << "\n";
        stream << "altitudeMillimetersMSL: " << messageRawFactGroup.altitudeMetersASL()->rawValue().toDouble() << "\n";
        stream << "absolutePressureMillibars: " << messageRawFactGroup.absolutePressureMillibars()->rawValue().toDouble() << "\n";
        stream << "temperature0Kelvin: " << messageRawFactGroup.temperature0Celsius()->rawValue().toDouble() << "\n";
        stream << "temperature1Kelvin: " << messageRawFactGroup.temperature1Celsius()->rawValue().toDouble() << "\n";
        stream << "temperature2Kelvin: " << messageRawFactGroup.temperature2Celsius()->rawValue().toDouble() << "\n";
        stream << "relativeHumidity0: " << messageRawFactGroup.relativeHumidity0()->rawValue().toDouble() << "\n";
        stream << "relativeHumidity1: " << messageRawFactGroup.relativeHumidity1()->rawValue().toDouble() << "\n";
        stream << "relativeHumidity2: " << messageRawFactGroup.relativeHumidity2()->rawValue().toDouble() << "\n";
        stream << "latitudeDegreesE7: " << messageRawFactGroup.latitudeDegrees()->rawValue().toDouble() << "\n";
        stream << "longitudeDegreesE7: " << messageRawFactGroup.longitudeDegrees()->rawValue().toDouble() << "\n";
        stream << "rollRadians: " << messageRawFactGroup.rollDegrees()->rawValue().toDouble() << "\n";
        stream << "pitchRadians: " << messageRawFactGroup.pitchDegrees()->rawValue().toDouble() << "\n";
        stream << "yawRadians: " << messageRawFactGroup.yawDegrees()->rawValue().toDouble() << "\n";
        stream << "rollRateRadiansPerSecond: " << messageRawFactGroup.rollRateDegreesPerSecond()->rawValue().toDouble() << "\n";
        stream << "pitchRateRadiansPerSecond: " << messageRawFactGroup.pitchRateDegreesPerSecond()->rawValue().toDouble() << "\n";
        stream << "yawRateRadiansPerSecond: " << messageRawFactGroup.yawRateDegreesPerSecond()->rawValue().toDouble() << "\n";
        stream << "xVelocityMetersPerSecond: " << messageRawFactGroup.xVelocityMetersPerSecond()->rawValue().toDouble() << "\n";
        stream << "yVelocityMetersPerSecond: " << messageRawFactGroup.yVelocityMetersPerSecond()->rawValue().toDouble() << "\n";
        stream << "zVelocityMetersPerSecond: " << messageRawFactGroup.zVelocityMetersPerSecond()->rawValue().toDouble() << "\n";
        stream << "customModeHeartbeat: " << messageRawFactGroup.customModeHeartbeat()->rawValue().toUInt() << "\n";
        stream << "dataQuality: " << messageRawFactGroup.dataQuality()->rawValue().toInt() << "\n";
        stream << "homePositionLatitude: " << messageRawFactGroup.homePositionLatitudeDegrees()->rawValue().toDouble() << "\n";
        stream << "homePositionLongitude: " << messageRawFactGroup.homePositionLongitudeDegrees()->rawValue().toDouble() << "\n";
        stream << "homePositionAltitude: " << messageRawFactGroup.homePositionAltitudeMeters()->rawValue().toDouble() << "\n";
        stream << "droneSerialNumber: " << messageRawFactGroup.droneSerialNumber()->rawValue().toInt() << "\n";
        stream << "groundSpeed: " << messageRawFactGroup.groundWindSpeedMetersPerSecond()->rawValue().toDouble() << "\n";
        stream << "groundWindDirection: " << messageRawFactGroup.groundWindDirectionDegrees()->rawValue().toInt() << "\n";
        stream << "groundAirTemperature: " << messageRawFactGroup.groundAirTemperatureCelsius()->rawValue().toDouble() << "\n";
        stream << "groundHumidity: " << messageRawFactGroup.groundHumidity()->rawValue().toDouble() << "\n";
        stream << "groundPressure: " << messageRawFactGroup.groundPressureMillibars()->rawValue().toDouble() << "\n";
        stream << "poweredAge: " << messageRawFactGroup.poweredAgeSeconds()->rawValue().toInt() << "\n";
        stream << "armedAge: " << messageRawFactGroup.armedAgeSeconds()->rawValue().toInt() << "\n";
        stream << "satellites: " << messageRawFactGroup.satellites()->rawValue().toUInt() << "\n";
        stream << "horizontalDilutionOfPosition: " << messageRawFactGroup.horizontalDilutionOfPositionFloat()->rawValue().toDouble() << "\n";
        stream << "filenameStr: " << messageRawFactGroup.filename()->rawValue().toString() << "\n";

        stream << "\n";

        file.close();
    }
}

