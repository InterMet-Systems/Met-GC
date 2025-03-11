#ifndef MESSAGERAWFACTGROUP_H
#define MESSAGERAWFACTGROUP_H

#include "FactGroup.h"

class MessageRawFactGroup : public FactGroup{
    Q_OBJECT

public:
    MessageRawFactGroup(QObject* parent = nullptr);
    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    Q_PROPERTY(Fact* timeUnixSeconds                    READ timeUnixSeconds                    CONSTANT) /* f64        derived from timeUnixMicroseconds      */
    Q_PROPERTY(Fact* altitudeMetersASL                  READ altitudeMetersASL                  CONSTANT) /* f64        derived from altitudeMillimetersMSL    */
    Q_PROPERTY(Fact* absolutePressureMillibars          READ absolutePressureMillibars          CONSTANT) /* f32        MAVLINK_MSG_ID_SCALED_PRESSURE2        */
    Q_PROPERTY(Fact* temperature0Celsius                READ temperature0Celsius                CONSTANT) /* f32        derived from temperature0Kelvin        */
    Q_PROPERTY(Fact* temperature1Celsius                READ temperature1Celsius                CONSTANT) /* f32        derived from temperature1Kelvin        */
    Q_PROPERTY(Fact* temperature2Celsius                READ temperature2Celsius                CONSTANT) /* f32        derived from temperature2Kelvin        */
    Q_PROPERTY(Fact* relativeHumidity0                  READ relativeHumidity0                  CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* relativeHumidity1                  READ relativeHumidity1                  CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* relativeHumidity2                  READ relativeHumidity2                  CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* latitudeDegrees                    READ latitudeDegrees                    CONSTANT) /* f64        derived from latitudeDegreesE7         */
    Q_PROPERTY(Fact* longitudeDegrees                   READ longitudeDegrees                   CONSTANT) /* f64        derived from longitudeDegreesE7        */
    Q_PROPERTY(Fact* rollDegrees                        READ rollDegrees                        CONSTANT) /* f32        derived from rollRadians               */
    Q_PROPERTY(Fact* pitchDegrees                       READ pitchDegrees                       CONSTANT) /* f32        derived from pitchRadians              */
    Q_PROPERTY(Fact* yawDegrees                         READ yawDegrees                         CONSTANT) /* f32        derived from yawRadians                */
    Q_PROPERTY(Fact* rollRateDegreesPerSecond           READ rollRateDegreesPerSecond           CONSTANT) /* f32        derived from rollRateRadiansPerSecond  */
    Q_PROPERTY(Fact* pitchRateDegreesPerSecond          READ pitchRateDegreesPerSecond          CONSTANT) /* f32        derived from pitchRateRadiansPerSecond */
    Q_PROPERTY(Fact* yawRateDegreesPerSecond            READ yawRateDegreesPerSecond            CONSTANT) /* f32        derived from yawRateRadiansPerSecond   */
    Q_PROPERTY(Fact* xVelocityMetersPerSecond           READ xVelocityMetersPerSecond           CONSTANT) /* f32        MAVLINK_MSG_ID_LOCAL_POSITION_NED      */
    Q_PROPERTY(Fact* yVelocityMetersPerSecond           READ yVelocityMetersPerSecond           CONSTANT) /* f32        MAVLINK_MSG_ID_LOCAL_POSITION_NED      */
    Q_PROPERTY(Fact* zVelocityMetersPerSecond           READ zVelocityMetersPerSecond           CONSTANT) /* f32        MAVLINK_MSG_ID_LOCAL_POSITION_NED      */
    Q_PROPERTY(Fact* customModeHeartbeat                READ customModeHeartbeat                CONSTANT) /* uint32_t   MAVLINK_MSG_ID_HEARTBEAT               */
    Q_PROPERTY(Fact* dataQuality                        READ dataQuality                        CONSTANT) /* int32_t    Unknown                                */
    Q_PROPERTY(Fact* homePositionLatitudeDegrees        READ homePositionLatitudeDegrees        CONSTANT) /* f64        file                                   */
    Q_PROPERTY(Fact* homePositionLongitudeDegrees       READ homePositionLongitudeDegrees       CONSTANT) /* f64        file                                   */
    Q_PROPERTY(Fact* homePositionAltitudeMeters         READ homePositionAltitudeMeters         CONSTANT) /* f32        file                                   */
    Q_PROPERTY(Fact* droneSerialNumber                  READ droneSerialNumber                  CONSTANT) /* int32_t    file                                   */
    Q_PROPERTY(Fact* groundWindSpeedMetersPerSecond     READ groundWindSpeedMetersPerSecond     CONSTANT) /* f32        file                                   */
    Q_PROPERTY(Fact* groundWindDirectionDegrees         READ groundWindDirectionDegrees         CONSTANT) /* int32_t    file                                   */
    Q_PROPERTY(Fact* groundAirTemperatureCelsius        READ groundAirTemperatureCelsius        CONSTANT) /* f32        file                                   */
    Q_PROPERTY(Fact* groundHumidity                     READ groundHumidity                     CONSTANT) /* f32        file                                   */
    Q_PROPERTY(Fact* groundPressureMillibars            READ groundPressureMillibars            CONSTANT) /* f32        file                                   */
    Q_PROPERTY(Fact* poweredAgeSeconds                  READ poweredAgeSeconds                  CONSTANT) /* int32_t    Unknown                                */
    Q_PROPERTY(Fact* armedAgeSeconds                    READ armedAgeSeconds                    CONSTANT) /* int32_t    Unknown                                */
    Q_PROPERTY(Fact* satellites                         READ satellites                         CONSTANT) /* uint8_t    MAVLINK_MSG_ID_GPS_RAW_INT             */
    Q_PROPERTY(Fact* horizontalDilutionOfPositionFloat  READ horizontalDilutionOfPositionFloat  CONSTANT) /* f32        derived from horizontalDilutionOfPosition */
    Q_PROPERTY(Fact* filename                           READ filename                           CONSTANT) /* string     MessengerRaw::createFilename           */

    Fact* timeUnixSeconds()                   { return &_timeUnixSecondsFact; }
    Fact* altitudeMetersASL()                 { return &_altitudeMetersASLFact; }
    Fact* absolutePressureMillibars()         { return &_absolutePressureMillibarsFact; }
    Fact* temperature0Celsius()               { return &_temperature0CelsiusFact; }
    Fact* temperature1Celsius()               { return &_temperature1CelsiusFact; }
    Fact* temperature2Celsius()               { return &_temperature2CelsiusFact; }
    Fact* relativeHumidity0()                 { return &_relativeHumidity0Fact; }
    Fact* relativeHumidity1()                 { return &_relativeHumidity1Fact; }
    Fact* relativeHumidity2()                 { return &_relativeHumidity2Fact; }
    Fact* latitudeDegrees()                   { return &_latitudeDegreesFact; }
    Fact* longitudeDegrees()                  { return &_longitudeDegreesFact; }
    Fact* rollDegrees()                       { return &_rollDegreesFact; }
    Fact* pitchDegrees()                      { return &_pitchDegreesFact; }
    Fact* yawDegrees()                        { return &_yawDegreesFact; }
    Fact* rollRateDegreesPerSecond()          { return &_rollRateDegreesPerSecondFact; }
    Fact* pitchRateDegreesPerSecond()         { return &_pitchRateDegreesPerSecondFact; }
    Fact* yawRateDegreesPerSecond()           { return &_yawRateDegreesPerSecondFact; }
    Fact* xVelocityMetersPerSecond()          { return &_xVelocityMetersPerSecondFact; }
    Fact* yVelocityMetersPerSecond()          { return &_yVelocityMetersPerSecondFact; }
    Fact* zVelocityMetersPerSecond()          { return &_zVelocityMetersPerSecondFact; }
    Fact* customModeHeartbeat()               { return &_customModeHeartbeatFact; }
    Fact* dataQuality()                       { return &_dataQualityFact; }
    Fact* homePositionLatitudeDegrees()       { return &_homePositionLatitudeDegreesFact; }
    Fact* homePositionLongitudeDegrees()      { return &_homePositionLongitudeDegreesFact; }
    Fact* homePositionAltitudeMeters()        { return &_homePositionAltitudeMetersFact; }
    Fact* droneSerialNumber()                 { return &_droneSerialNumberFact; }
    Fact* groundWindSpeedMetersPerSecond()    { return &_groundWindSpeedMetersPerSecondFact; }
    Fact* groundWindDirectionDegrees()        { return &_groundWindDirectionDegreesFact; }
    Fact* groundAirTemperatureCelsius()       { return &_groundAirTemperatureCelsiusFact; }
    Fact* groundHumidity()                    { return &_groundHumidityFact; }
    Fact* groundPressureMillibars()           { return &_groundPressureMillibarsFact; }
    Fact* poweredAgeSeconds()                 { return &_poweredAgeSecondsFact; }
    Fact* armedAgeSeconds()                   { return &_armedAgeSecondsFact; }
    Fact* satellites()                        { return &_satellitesFact; }
    Fact* horizontalDilutionOfPositionFloat() { return &_horizontalDilutionOfPositionFloatFact; }
    Fact* filename()                          { return &_filenameFact; }

    static const char* _timeUnixSecondsFactName;
    static const char* _altitudeMetersASLFactName;
    static const char* _absolutePressureMillibarsFactName;
    static const char* _temperature0CelsiusFactName;
    static const char* _temperature1CelsiusFactName;
    static const char* _temperature2CelsiusFactName;
    static const char* _relativeHumidity0FactName;
    static const char* _relativeHumidity1FactName;
    static const char* _relativeHumidity2FactName;
    static const char* _latitudeDegreesFactName;
    static const char* _longitudeDegreesFactName;
    static const char* _rollDegreesFactName;
    static const char* _pitchDegreesFactName;
    static const char* _yawDegreesFactName;
    static const char* _rollRateDegreesPerSecondFactName;
    static const char* _pitchRateDegreesPerSecondFactName;
    static const char* _yawRateDegreesPerSecondFactName;
    static const char* _xVelocityMetersPerSecondFactName;
    static const char* _yVelocityMetersPerSecondFactName;
    static const char* _zVelocityMetersPerSecondFactName;
    static const char* _customModeHeartbeatFactName;
    static const char* _dataQualityFactName;
    static const char* _homePositionLatitudeDegreesFactName;
    static const char* _homePositionLongitudeDegreesFactName;
    static const char* _homePositionAltitudeMetersFactName;
    static const char* _droneSerialNumberFactName;
    static const char* _groundWindSpeedMetersPerSecondFactName;
    static const char* _groundWindDirectionDegreesFactName;
    static const char* _groundAirTemperatureCelsiusFactName;
    static const char* _groundHumidityFactName;
    static const char* _groundPressureMillibarsFactName;
    static const char* _poweredAgeSecondsFactName;
    static const char* _armedAgeSecondsFactName;
    static const char* _satellitesFactName;
    static const char* _horizontalDilutionOfPositionFloatFactName;
    static const char* _filenameFactName;

private:
    Fact    _timeUnixSecondsFact;
    Fact    _altitudeMetersASLFact;
    Fact    _absolutePressureMillibarsFact;
    Fact    _temperature0CelsiusFact;
    Fact    _temperature1CelsiusFact;
    Fact    _temperature2CelsiusFact;
    Fact    _relativeHumidity0Fact;
    Fact    _relativeHumidity1Fact;
    Fact    _relativeHumidity2Fact;
    Fact    _latitudeDegreesFact;
    Fact    _longitudeDegreesFact;
    Fact    _rollDegreesFact;
    Fact    _pitchDegreesFact;
    Fact    _yawDegreesFact;
    Fact    _rollRateDegreesPerSecondFact;
    Fact    _pitchRateDegreesPerSecondFact;
    Fact    _yawRateDegreesPerSecondFact;
    Fact    _xVelocityMetersPerSecondFact;
    Fact    _yVelocityMetersPerSecondFact;
    Fact    _zVelocityMetersPerSecondFact;
    Fact    _customModeHeartbeatFact;
    Fact    _dataQualityFact;
    Fact    _homePositionLatitudeDegreesFact;
    Fact    _homePositionLongitudeDegreesFact;
    Fact    _homePositionAltitudeMetersFact;
    Fact    _droneSerialNumberFact;
    Fact    _groundWindSpeedMetersPerSecondFact;
    Fact    _groundWindDirectionDegreesFact;
    Fact    _groundAirTemperatureCelsiusFact;
    Fact    _groundHumidityFact;
    Fact    _groundPressureMillibarsFact;
    Fact    _poweredAgeSecondsFact;
    Fact    _armedAgeSecondsFact;
    Fact    _satellitesFact;
    Fact    _horizontalDilutionOfPositionFloatFact;
    Fact    _filenameFact;
};

#endif // MESSAGERAWFACTGROUP_H
