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
{
    // Initialize the timer
    logTimer = new QTimer(this);
    connect(logTimer, &QTimer::timeout, this, &DataHubPlugin::logDataToFile);
    logTimer->start(5000); // 5000 milliseconds = 5 seconds
}

DataHubPlugin::~DataHubPlugin()
{
    // Clean up
    logTimer->stop();
    delete logTimer;
}

bool DataHubPlugin::mavlinkMessage(Vehicle* vehicle, LinkInterface* link, mavlink_message_t message)
{
    (void)hub.parseMessage(message);
    return true;
}

void DataHubPlugin::logDataToFile()
{
    // Create a log file in a known location
    QString logFilePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)
                          + "/QGroundControl/temp datahub log.txt";

    // Make sure directory exists
    QFileInfo fileInfo(logFilePath);
    QDir().mkpath(fileInfo.absolutePath());

    QFile file(logFilePath);
    // Open the file in append mode, create if it doesn't exist
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);

        // Add timestamp
        stream << "--- Log Entry: " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " ---\n";

        // Log each fact value
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

        stream << "\n"; // Add a blank line between log entries

        file.close();
    }
}

