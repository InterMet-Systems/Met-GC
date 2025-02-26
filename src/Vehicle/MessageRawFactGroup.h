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
    Q_PROPERTY(Fact* R          READ absolutePressureMillibars          CONSTANT) /* f32        MAVLINK_MSG_ID_SCALED_PRESSURE2        */
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

    Fact* getFactPointerTimeUnixSeconds()                   { return &_timeUnixSecondsFact; }
    Fact* getFactPointerAltitudeMetersASL()                 { return &_altitudeMetersASLFact; }
    Fact* getFactPointerAbsolutePressureMillibars()         { return &_absolutePressureMillibarsFact; }
    Fact* getFactPointerTemperature0Celsius()               { return &_temperature0CelsiusFact; }
    Fact* getFactPointerTemperature1Celsius()               { return &_temperature1CelsiusFact; }
    Fact* getFactPointerTemperature2Celsius()               { return &_temperature2CelsiusFact; }
    Fact* getFactPointerRelativeHumidity0()                 { return &_relativeHumidity0Fact; }
    Fact* getFactPointerRelativeHumidity1()                 { return &_relativeHumidity1Fact; }
    Fact* getFactPointerRelativeHumidity2()                 { return &_relativeHumidity2Fact; }
    Fact* getFactPointerLatitudeDegrees()                   { return &_latitudeDegreesFact; }
    Fact* getFactPointerLongitudeDegrees()                  { return &_longitudeDegreesFact; }
    Fact* getFactPointerRollDegrees()                       { return &_rollDegreesFact; }
    Fact* getFactPointerPitchDegrees()                      { return &_pitchDegreesFact; }
    Fact* getFactPointerYawDegrees()                        { return &_yawDegreesFact; }
    Fact* getFactPointerRollRateDegreesPerSecond()          { return &_rollRateDegreesPerSecondFact; }
    Fact* getFactPointerPitchRateDegreesPerSecond()         { return &_pitchRateDegreesPerSecondFact; }
    Fact* getFactPointerYawRateDegreesPerSecond()           { return &_yawRateDegreesPerSecondFact; }
    Fact* getFactPointerXVelocityMetersPerSecond()          { return &_xVelocityMetersPerSecondFact; }
    Fact* getFactPointerYVelocityMetersPerSecond()          { return &_yVelocityMetersPerSecondFact; }
    Fact* getFactPointerZVelocityMetersPerSecond()          { return &_zVelocityMetersPerSecondFact; }
    Fact* getFactPointerCustomModeHeartbeat()               { return &_customModeHeartbeatFact; }
    Fact* getFactPointerDataQuality()                       { return &_dataQualityFact; }
    Fact* getFactPointerHomePositionLatitudeDegrees()       { return &_homePositionLatitudeDegreesFact; }
    Fact* getFactPointerHomePositionLongitudeDegrees()      { return &_homePositionLongitudeDegreesFact; }
    Fact* getFactPointerHomePositionAltitudeMeters()        { return &_homePositionAltitudeMetersFact; }
    Fact* getFactPointerDroneSerialNumber()                 { return &_droneSerialNumberFact; }
    Fact* getFactPointerGroundWindSpeedMetersPerSecond()    { return &_groundWindSpeedMetersPerSecondFact; }
    Fact* getFactPointerGroundWindDirectionDegrees()        { return &_groundWindDirectionDegreesFact; }
    Fact* getFactPointerGroundAirTemperatureCelsius()       { return &_groundAirTemperatureCelsiusFact; }
    Fact* getFactPointerGroundHumidity()                    { return &_groundHumidityFact; }
    Fact* getFactPointerGroundPressureMillibars()           { return &_groundPressureMillibarsFact; }
    Fact* getFactPointerPoweredAgeSeconds()                 { return &_poweredAgeSecondsFact; }
    Fact* getFactPointerArmedAgeSeconds()                   { return &_armedAgeSecondsFact; }
    Fact* getFactPointerSatellites()                        { return &_satellitesFact; }
    Fact* getFactPointerHorizontalDilutionOfPositionFloat() { return &_horizontalDilutionOfPositionFloatFact; }
    Fact* getFactPointerFilename()                          { return &_filenameFact; }

    static const char* _timeUnixSecondsName;
    static const char* _altitudeMetersASLName;
    static const char* _absolutePressureMillibarsName;
    static const char* _temperature0CelsiusName;
    static const char* _temperature1CelsiusName;
    static const char* _temperature2CelsiusName;
    static const char* _relativeHumidity0Name;
    static const char* _relativeHumidity1Name;
    static const char* _relativeHumidity2Name;
    static const char* _latitudeDegreesName;
    static const char* _longitudeDegreesName;
    static const char* _rollDegreesName;
    static const char* _pitchDegreesName;
    static const char* _yawDegreesName;
    static const char* _rollRateDegreesPerSecondName;
    static const char* _pitchRateDegreesPerSecondName;
    static const char* _yawRateDegreesPerSecondName;
    static const char* _xVelocityMetersPerSecondName;
    static const char* _yVelocityMetersPerSecondName;
    static const char* _zVelocityMetersPerSecondName;
    static const char* _customModeHeartbeatName;
    static const char* _dataQualityName;
    static const char* _homePositionLatitudeDegreesName;
    static const char* _homePositionLongitudeDegreesName;
    static const char* _homePositionAltitudeMetersName;
    static const char* _droneSerialNumberName;
    static const char* _groundWindSpeedMetersPerSecondName;
    static const char* _groundWindDirectionDegreesName;
    static const char* _groundAirTemperatureCelsiusName;
    static const char* _groundHumidityName;
    static const char* _groundPressureMillibarsName;
    static const char* _poweredAgeSecondsName;
    static const char* _armedAgeSecondsName;
    static const char* _satellitesName;
    static const char* _horizontalDilutionOfPositionFloatName;
    static const char* _filenameName;

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
