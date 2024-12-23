/****************************************************************************
 *
 * (c) 2009-2019 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 *   @brief Custom QGCCorePlugin Implementation
 *   @author Gus Grubba <gus@auterion.com>
 */

#include <QtQml>
#include <QQmlEngine>
#include <QDateTime>
#include "QGCSettings.h"
#include "MAVLinkLogManager.h"
#include "DataBalancerPlugin.h"

#include "MultiVehicleManager.h"
#include "QGCApplication.h"
#include "SettingsManager.h"
#include "AppMessages.h"
#include "QmlComponentInfo.h"
#include "QGCPalette.h"

// QGC_LOGGING_CATEGORY(CustomLog, "CustomLog")



DataBalancerPlugin::DataBalancerPlugin(QGCApplication *app, QGCToolbox* toolbox)
    : QGCCorePlugin(app, toolbox)
{
    // _showAdvancedUI = false;
}

DataBalancerPlugin::~DataBalancerPlugin()
{

}

bool DataBalancerPlugin::mavlinkMessage(Vehicle* vehicle, LinkInterface* link, mavlink_message_t message)
{

    qDebug() << "DataBalancerPlugin::mavlinkMessage";
    FactGroup* metFactGroup = vehicle->getFactGroup("temperature");

    if (!metFactGroup) {
        return true;
    }
    // make sure we're not logging the same data again
    Fact* timeUAVMilliseconds = metFactGroup->getFact("timeUAVMilliseconds");
    Fact* timeUnixMilliseconds = metFactGroup->getFact("timeUnixMilliseconds");
    Fact* timeUAVBootMilliseconds = metFactGroup->getFact("timeUAVBootMilliseconds");
    Fact* altitudeMillimetersMSL = metFactGroup->getFact("altitudeMillimetersMSL");
    Fact* absolutePressureMillibars = metFactGroup->getFact("absolutePressureMillibars");
    Fact* temperature0Celsius = metFactGroup->getFact("temperature0Celsius");
    Fact* temperature1Celsius = metFactGroup->getFact("temperature1Celsius");
    Fact* temperature2Celsius = metFactGroup->getFact("temperature2Celsius");
    Fact* relativeHumidity = metFactGroup->getFact("relativeHumidity");
    Fact* relativeHumidity0 = metFactGroup->getFact("relativeHumidity0");
    Fact* relativeHumidity1 = metFactGroup->getFact("relativeHumidity1");
    Fact* relativeHumidity2 = metFactGroup->getFact("relativeHumidity2");
    Fact* windSpeedMetersPerSecond = metFactGroup->getFact("windSpeedMetersPerSecond");
    Fact* windBearingDegrees = metFactGroup->getFact("windBearingDegrees");
    Fact* latitudeDegreesE7 = metFactGroup->getFact("latitudeDegreesE7");
    Fact* longitudeDegreesE7 = metFactGroup->getFact("longitudeDegreesE7");
    Fact* rollRadians = metFactGroup->getFact("rollRadians");
    Fact* pitchRadians = metFactGroup->getFact("pitchRadians");
    Fact* yawRadians = metFactGroup->getFact("yawRadians");
    Fact* rollRateRadiansPerSecond = metFactGroup->getFact("rollRateRadiansPerSecond");
    Fact* pitchRateRadiansPerSecond = metFactGroup->getFact("pitchRateRadiansPerSecond");
    Fact* yawRateRadiansPerSecond = metFactGroup->getFact("yawRateRadiansPerSecond");
    Fact* zVelocityMetersPerSecondInverted = metFactGroup->getFact("zVelocityMetersPerSecondInverted");
    Fact* xVelocityMetersPerSecond = metFactGroup->getFact("xVelocityMetersPerSecond");
    Fact* yVelocityMetersPerSecond = metFactGroup->getFact("yVelocityMetersPerSecond");
    Fact* groundSpeedMetersPerSecond = metFactGroup->getFact("groundSpeedMetersPerSecond");
    Fact* heartBeatCustomMode = metFactGroup->getFact("heartBeatCustomMode");
    Fact* ascending = metFactGroup->getFact("ascending");
    Fact* timeUAVSeconds = metFactGroup->getFact("timeUAVSeconds");
    Fact* timeUnixSeconds = metFactGroup->getFact("timeUnixSeconds");
    Fact* timeUAVBootSeconds = metFactGroup->getFact("timeUAVBootSeconds");
    Fact* altitudeMetersMSL = metFactGroup->getFact("altitudeMetersMSL");
    Fact* temperatureCelsius = metFactGroup->getFact("temperatureCelsius");
    Fact* latitudeDegrees = metFactGroup->getFact("latitudeDegrees");
    Fact* longitudeDegrees = metFactGroup->getFact("longitudeDegrees");
    Fact* rollDegrees = metFactGroup->getFact("rollDegrees");
    Fact* pitchDegrees = metFactGroup->getFact("pitchDegrees");
    Fact* yawDegrees = metFactGroup->getFact("yawDegrees");
    Fact* rollRateDegreesPerSecond = metFactGroup->getFact("rollRateDegreesPerSecond");
    Fact* pitchRateDegreesPerSecond = metFactGroup->getFact("pitchRateDegreesPerSecond");
    Fact* yawRateDegreesPerSecond = metFactGroup->getFact("yawRateDegreesPerSecond");
    Fact* zVelocityMetersPerSecond = metFactGroup->getFact("zVelocityMetersPerSecond");
    Fact* lastState = metFactGroup->getFact("lastState");
    Fact* ascents = metFactGroup->getFact("ascents");

    Fact* asl = metFactGroup->getFact("asl");
    Fact* time = metFactGroup->getFact("time");
    Fact* pressure = metFactGroup->getFact("pressure");
    Fact* airTemp = metFactGroup->getFact("airTemp");
    Fact* relHum = metFactGroup->getFact("relHum");
    Fact* windSpeed = metFactGroup->getFact("windSpeed");
    Fact* windDirection = metFactGroup->getFact("windDirection");
    Fact* latitude = metFactGroup->getFact("latitude");
    Fact* longitude = metFactGroup->getFact("longitude");
    Fact* roll = metFactGroup->getFact("roll");
    Fact* rollRate = metFactGroup->getFact("rollRate");
    Fact* pitch = metFactGroup->getFact("pitch");
    Fact* pitchRate = metFactGroup->getFact("pitchRate");
    Fact* yaw = metFactGroup->getFact("yaw");
    Fact* yawRate = metFactGroup->getFact("yawRate");
    Fact* ascentRate = metFactGroup->getFact("ascentRate");
    Fact* speedOverGround = metFactGroup->getFact("speedOverGround");
    Fact* update = metFactGroup->getFact("update");

    qDebug() << "DataBalancerPlugin::mavlinkMessage";

    balancer.update(&message, timeUAVMilliseconds, timeUnixMilliseconds, timeUAVBootMilliseconds, altitudeMillimetersMSL, absolutePressureMillibars,
                    temperature0Celsius, temperature1Celsius, temperature2Celsius, relativeHumidity, relativeHumidity0, relativeHumidity1, relativeHumidity2,
                    windSpeedMetersPerSecond, windBearingDegrees, latitudeDegreesE7, longitudeDegreesE7, rollRadians, pitchRadians, yawRadians,
                    rollRateRadiansPerSecond, pitchRateRadiansPerSecond, yawRateRadiansPerSecond, zVelocityMetersPerSecondInverted, xVelocityMetersPerSecond,
                    yVelocityMetersPerSecond, groundSpeedMetersPerSecond, heartBeatCustomMode, ascending, timeUAVSeconds, timeUnixSeconds,
                    timeUAVBootSeconds, altitudeMetersMSL, temperatureCelsius, latitudeDegrees, longitudeDegrees, rollDegrees, pitchDegrees,
                    yawDegrees, rollRateDegreesPerSecond, pitchRateDegreesPerSecond, yawRateDegreesPerSecond, zVelocityMetersPerSecond, lastState,
                    ascents);

    switch(balancer.updateALM()){
    case DataBalancer::DATA_NOT_INITIALIZED:
        break;
    case DataBalancer::NOT_ASCENDING:
        break;
    case DataBalancer::ALTITUDE_CHANGE_TOO_SMALL:
        break;
    case DataBalancer::SUCCESS:
        balancer.onALMUpdate(asl, time, pressure, airTemp, relHum, windSpeed, windDirection, latitude, longitude,
                             roll, rollRate, pitch, pitchRate, yaw, yawRate, ascentRate, speedOverGround, update);
        break;
    }

    return true;
}

