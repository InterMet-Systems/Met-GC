#ifndef DATAFACTGROUP_H
#define DATAFACTGROUP_H

#include "FactGroup.h"
#include "QGCMAVLink.h"
#include "DataHub.h"

class DataFactGroup : public FactGroup
{
    Q_OBJECT

public:
    DataFactGroup(QObject* parent = nullptr);

    /* There will be many of these */
    Q_PROPERTY(Fact* timeUnixMicroseconds                       READ timeUnixMicroseconds                       CONSTANT)
    Q_PROPERTY(Fact* timeUnixSeconds                            READ timeUnixSeconds                            CONSTANT)
    Q_PROPERTY(Fact* poweredAgeSeconds                          READ poweredAgeSeconds                          CONSTANT)
    Q_PROPERTY(Fact* armedAgeSeconds                            READ armedAgeSeconds                            CONSTANT)

    Q_PROPERTY(Fact* altitudeMillimetersMSL                       READ altitudeMillimetersMSL CONSTANT)
    Q_PROPERTY(Fact* absolutePressureMillibars                       READ absolutePressureMillibars                       CONSTANT)
    Q_PROPERTY(Fact* temperature0Celsius                       READ temperature0Celsius                       CONSTANT)
    Q_PROPERTY(Fact* temperature1Celsius                       READ temperature1Celsius                       CONSTANT)
    Q_PROPERTY(Fact* temperature2Celsius                       READ temperature2Celsius                       CONSTANT)
    Q_PROPERTY(Fact* relativeHumidity                       READ relativeHumidity                       CONSTANT)
    Q_PROPERTY(Fact* relativeHumidity0                       READ relativeHumidity0                       CONSTANT)
    Q_PROPERTY(Fact* relativeHumidity1                       READ relativeHumidity1                       CONSTANT)
    Q_PROPERTY(Fact* relativeHumidity2                       READ relativeHumidity2                       CONSTANT)
    Q_PROPERTY(Fact* windSpeedMetersPerSecond                       READ windSpeedMetersPerSecond                       CONSTANT)
    Q_PROPERTY(Fact* windBearingDegrees                       READ windBearingDegrees                       CONSTANT)
    Q_PROPERTY(Fact* latitudeDegreesE7                       READ latitudeDegreesE7                       CONSTANT)
    Q_PROPERTY(Fact* longitudeDegreesE7                       READ longitudeDegreesE7                       CONSTANT)
    Q_PROPERTY(Fact* rollRadians                       READ rollRadians                       CONSTANT)
    Q_PROPERTY(Fact* pitchRadians                       READ pitchRadians                       CONSTANT)
    Q_PROPERTY(Fact* yawRadians                       READ yawRadians                       CONSTANT)
    Q_PROPERTY(Fact* rollRateRadiansPerSecond                       READ rollRateRadiansPerSecond                       CONSTANT)
    Q_PROPERTY(Fact* pitchRateRadiansPerSecond                       READ pitchRateRadiansPerSecond                       CONSTANT)
    Q_PROPERTY(Fact* yawRateRadiansPerSecond                       READ yawRateRadiansPerSecond                       CONSTANT)
    Q_PROPERTY(Fact* zVelocityMetersPerSecondInverted                       READ zVelocityMetersPerSecondInverted                       CONSTANT)
    Q_PROPERTY(Fact* xVelocityMetersPerSecond                       READ xVelocityMetersPerSecond                       CONSTANT)
    Q_PROPERTY(Fact* yVelocityMetersPerSecond                       READ yVelocityMetersPerSecond                       CONSTANT)
    Q_PROPERTY(Fact* GroundSpeedMetersPerSecond                       READ GroundSpeedMetersPerSecond                       CONSTANT)
    Q_PROPERTY(Fact* heartBeatCustomMode                       READ heartBeatCustomMode                       CONSTANT)
    Q_PROPERTY(Fact* ascending                       READ ascending                       CONSTANT)

    Q_PROPERTY(Fact* altitudeMetersMSL                       READ altitudeMetersMSL                       CONSTANT)
    Q_PROPERTY(Fact* temperatureCelsius                       READ temperatureCelsius                       CONSTANT)
    Q_PROPERTY(Fact* latitudeDegrees                       READ latitudeDegrees                       CONSTANT)
    Q_PROPERTY(Fact* longitudeDegrees                       READ longitudeDegrees                       CONSTANT)
    Q_PROPERTY(Fact* rollDegrees                       READ rollDegrees                       CONSTANT)
    Q_PROPERTY(Fact* pitchDegrees                       READ pitchDegrees                       CONSTANT)
    Q_PROPERTY(Fact* yawDegrees                       READ yawDegrees                       CONSTANT)
    Q_PROPERTY(Fact* rollRateDegreesPerSecond                       READ rollRateDegreesPerSecond                       CONSTANT)
    Q_PROPERTY(Fact* pitchRateDegreesPerSecond                       READ pitchRateDegreesPerSecond                       CONSTANT)
    Q_PROPERTY(Fact* yawRateDegreesPerSecond                       READ yawRateDegreesPerSecond                       CONSTANT)
    Q_PROPERTY(Fact* zVelocityMetersPerSecond                       READ zVelocityMetersPerSecond                       CONSTANT)
    Q_PROPERTY(Fact* lastState                       READ lastState                       CONSTANT)
    Q_PROPERTY(Fact* ascents                       READ ascents                       CONSTANT)

    Fact* getFactPointerTime ()                       { return &_timeFact; }

    // Overrides from FactGroup
    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    static const char* _timeName;

private:
    DataHub hub;

    Fact            _timeFact;
};

#endif // DATAFACTGROUP_H
