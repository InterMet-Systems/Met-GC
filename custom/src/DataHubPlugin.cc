#include <QtQml>
#include <QQmlEngine>
#include <QDateTime>
#include "DataHubPlugin.h"
#include "MultiVehicleManager.h"
#include "QGCApplication.h"

// herelink specific includes
#include "AutoConnectSettings.h"
#include "VideoSettings.h"
#include "AppSettings.h"
#include "QGCToolbox.h"
#include "MultiVehicleManager.h"
#include "JoystickManager.h"
#include "HorizontalFactValueGrid.h"
#include "InstrumentValueData.h"
#include <list>

// herelink
QGC_LOGGING_CATEGORY(HerelinkCorePluginLog, "HerelinkCorePluginLog")

DataHubPlugin::DataHubPlugin(QGCApplication *app, QGCToolbox* toolbox)
    : QGCCorePlugin(app, toolbox)
    , dataFactGroup()
    , hub(&dataFactGroup, 1, 1000)
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
        // qDebug() << "published a raw message";
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

        stream << "timeUnixSeconds: " << messageRawFactGroup.timeUnixSeconds()->rawValue().toDouble() << "\n";
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

void DataHubPlugin::setToolbox(QGCToolbox* toolbox)
{
    QGCCorePlugin::setToolbox(toolbox);

    _herelinkOptions = new HerelinkOptions(this, nullptr);

    auto multiVehicleManager = qgcApp()->toolbox()->multiVehicleManager();
    connect(multiVehicleManager, &MultiVehicleManager::activeVehicleChanged, this, &DataHubPlugin::_activeVehicleChanged);
}

bool DataHubPlugin::overrideSettingsGroupVisibility(QString name)
{
    // Hide all AutoConnect settings
    return name != AutoConnectSettings::name;
}

bool DataHubPlugin::adjustSettingMetaData(const QString& settingsGroup, FactMetaData& metaData)
{
    if (settingsGroup == AppSettings::settingsGroup) {
        //-- Default herelink fontsize of 10, it is a nice starting point
        if (metaData.name() == AppSettings::appFontPointSizeName) {
            uint32_t fontSize = 10;
            metaData.setRawDefaultValue(fontSize);
            // Show setting in ui
            return true;
        }
        //-- Default Palette Dark
        if (metaData.name() == AppSettings::indoorPaletteName) {
            QVariant outdoorPalette;
            outdoorPalette = 1;
            metaData.setRawDefaultValue(outdoorPalette);
            // Show setting in ui
            return true;
        }
    }
    if (settingsGroup == AutoConnectSettings::settingsGroup) {
        // We have to adjust the Herelink UDP autoconnect settings for the AirLink
        if (metaData.name() == AutoConnectSettings::udpListenPortName) {
            metaData.setRawDefaultValue(14551);
        } else if (metaData.name() == AutoConnectSettings::udpTargetHostIPName) {
            metaData.setRawDefaultValue(QStringLiteral("127.0.0.1"));
        } else if (metaData.name() == AutoConnectSettings::udpTargetHostPortName) {
            metaData.setRawDefaultValue(15552);
        } else {
            // Disable all the other autoconnect types
            const std::list<const char *> disabledAndHiddenSettings = {
                AutoConnectSettings::autoConnectPixhawkName,
                AutoConnectSettings::autoConnectSiKRadioName,
                AutoConnectSettings::autoConnectPX4FlowName,
                AutoConnectSettings::autoConnectRTKGPSName,
                AutoConnectSettings::autoConnectLibrePilotName,
                AutoConnectSettings::autoConnectNmeaPortName,
                AutoConnectSettings::autoConnectZeroConfName,
            };
            for (const char * disabledAndHiddenSetting : disabledAndHiddenSettings) {
                if (disabledAndHiddenSetting == metaData.name()) {
                    metaData.setRawDefaultValue(false);
                }
            }
        }
    } else if (settingsGroup == VideoSettings::settingsGroup) {
        if (metaData.name() == VideoSettings::rtspTimeoutName) {
            metaData.setRawDefaultValue(60);
        } else if (metaData.name() == VideoSettings::videoSourceName) {
            metaData.setRawDefaultValue(VideoSettings::videoSourceHerelinkAirUnit);
        }
    } else if (settingsGroup == AppSettings::settingsGroup) {
        if (metaData.name() == AppSettings::androidSaveToSDCardName) {
            metaData.setRawDefaultValue(true);
        }
    }

    return true; // Show all settings in ui
}

void DataHubPlugin::_activeVehicleChanged(Vehicle* activeVehicle)
{
    if (activeVehicle) {
        QString herelinkButtonsJoystickName("gpio-keys");

        auto joystickManager = qgcApp()->toolbox()->joystickManager();
        if (joystickManager->activeJoystickName() != herelinkButtonsJoystickName) {
            if (!joystickManager->setActiveJoystickName(herelinkButtonsJoystickName)) {
                qgcApp()->showAppMessage("Warning: Herelink buttton setup failed. Buttons will not work.");
                return;
            }
        }
        activeVehicle->setJoystickEnabled(true);
    }
}

void DataHubPlugin::factValueGridCreateDefaultSettings(const QString& defaultSettingsGroup)
{
    HorizontalFactValueGrid factValueGrid(defaultSettingsGroup);

    bool        includeFWValues = factValueGrid.vehicleClass() == QGCMAVLink::VehicleClassFixedWing || factValueGrid.vehicleClass() == QGCMAVLink::VehicleClassVTOL || factValueGrid.vehicleClass() == QGCMAVLink::VehicleClassAirship;

    factValueGrid.setFontSize(FactValueGrid::MediumFontSize);

    factValueGrid.appendColumn();
    factValueGrid.appendColumn();
    factValueGrid.appendColumn();
    if (includeFWValues) {
        factValueGrid.appendColumn();
    }
    factValueGrid.appendRow();

    int                 rowIndex    = 0;
    QmlObjectListModel* column      = factValueGrid.columns()->value<QmlObjectListModel*>(0);

    InstrumentValueData* value = column->value<InstrumentValueData*>(rowIndex++);
    value->setFact("Vehicle", "AltitudeRelative");
    value->setIcon("arrow-thick-up.svg");
    value->setText(value->fact()->shortDescription());
    value->setShowUnits(true);

    value = column->value<InstrumentValueData*>(rowIndex++);
    value->setFact("Vehicle", "DistanceToHome");
    value->setIcon("bookmark copy 3.svg");
    value->setText(value->fact()->shortDescription());
    value->setShowUnits(true);

    rowIndex    = 0;
    column      = factValueGrid.columns()->value<QmlObjectListModel*>(1);

    value = column->value<InstrumentValueData*>(rowIndex++);
    value->setFact("Vehicle", "ClimbRate");
    value->setIcon("arrow-simple-up.svg");
    value->setText(value->fact()->shortDescription());
    value->setShowUnits(true);

    value = column->value<InstrumentValueData*>(rowIndex++);
    value->setFact("Vehicle", "GroundSpeed");
    value->setIcon("arrow-simple-right.svg");
    value->setText(value->fact()->shortDescription());
    value->setShowUnits(true);


    if (includeFWValues) {
        rowIndex    = 0;
        column      = factValueGrid.columns()->value<QmlObjectListModel*>(2);

        value = column->value<InstrumentValueData*>(rowIndex++);
        value->setFact("Vehicle", "AirSpeed");
        value->setText("AirSpd");
        value->setShowUnits(true);

        value = column->value<InstrumentValueData*>(rowIndex++);
        value->setFact("Vehicle", "ThrottlePct");
        value->setText("Thr");
        value->setShowUnits(true);
    }

    rowIndex    = 0;
    column      = factValueGrid.columns()->value<QmlObjectListModel*>(includeFWValues ? 3 : 2);

    value = column->value<InstrumentValueData*>(rowIndex++);
    value->setFact("Vehicle", "FlightTime");
    value->setIcon("timer.svg");
    value->setText(value->fact()->shortDescription());
    value->setShowUnits(false);

    value = column->value<InstrumentValueData*>(rowIndex++);
    value->setFact("Vehicle", "FlightDistance");
    value->setIcon("travel-walk.svg");
    value->setText(value->fact()->shortDescription());
    value->setShowUnits(true);
}
