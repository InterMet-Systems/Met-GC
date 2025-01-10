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

    Q_PROPERTY(Fact* timeUnixMicroseconds               READ timeUnixMicroseconds               CONSTANT) /* uint64_t   MAVLINK_MSG_ID_SYSTEM_TIME             */
    Q_PROPERTY(Fact* timeUnixSeconds                    READ timeUnixSeconds                    CONSTANT) /* f64        derived from timeUnixMicroseconds      */
    Q_PROPERTY(Fact* altitudeMillimetersMSL             READ altitudeMillimetersMSL             CONSTANT) /* int32_t    MAVLINK_MSG_ID_GLOBAL_POSITION_INT     */
    Q_PROPERTY(Fact* altitudeMetersMSL                  READ altitudeMetersMSL                  CONSTANT) /* f64        derived from altitudeMillimetersMSL    */
    /* Source unit in mavlink says hectopascals, but that's the same as a millibar */
    Q_PROPERTY(Fact* absolutePressureMillibars          READ absolutePressureMillibars          CONSTANT) /* f32        MAVLINK_MSG_ID_SCALED_PRESSURE2        */
    Q_PROPERTY(Fact* temperature0Kelvin                 READ temperature0Kelvin                 CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* temperature1Kelvin                 READ temperature1Kelvin                 CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* temperature2Kelvin                 READ temperature2Kelvin                 CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* temperature0Celsius                READ temperature0Celsius                CONSTANT) /* f32        derived from temperature0Kelvin        */
    Q_PROPERTY(Fact* temperature1Celsius                READ temperature1Celsius                CONSTANT) /* f32        derived from temperature1Kelvin        */
    Q_PROPERTY(Fact* temperature2Celsius                READ temperature2Celsius                CONSTANT) /* f32        derived from temperature2Kelvin        */
    Q_PROPERTY(Fact* temperatureCelsius                 READ temperatureCelsius                 CONSTANT) /* f32        averaged                               */
    Q_PROPERTY(Fact* relativeHumidity0                  READ relativeHumidity0                  CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* relativeHumidity1                  READ relativeHumidity1                  CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* relativeHumidity2                  READ relativeHumidity2                  CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* relativeHumidity                   READ relativeHumidity                   CONSTANT) /* f32        averaged                               */
    Q_PROPERTY(Fact* latitudeDegreesE7                  READ latitudeDegreesE7                  CONSTANT) /* int32_t    MAVLINK_MSG_ID_GLOBAL_POSITION_INT     */
    Q_PROPERTY(Fact* longitudeDegreesE7                 READ longitudeDegreesE7                 CONSTANT) /* int32_t    MAVLINK_MSG_ID_GLOBAL_POSITION_INT     */
    Q_PROPERTY(Fact* latitudeDegrees                    READ latitudeDegrees                    CONSTANT) /* f64        derived from latitudeDegreesE7         */
    Q_PROPERTY(Fact* longitudeDegrees                   READ longitudeDegrees                   CONSTANT) /* f64        derived from longitudeDegreesE7        */
    Q_PROPERTY(Fact* rollRadians                        READ rollRadians                        CONSTANT) /* f32        MAVLINK_MSG_ID_ATTITUDE                */
    Q_PROPERTY(Fact* pitchRadians                       READ pitchRadians                       CONSTANT) /* f32        MAVLINK_MSG_ID_ATTITUDE                */
    Q_PROPERTY(Fact* yawRadians                         READ yawRadians                         CONSTANT) /* f32        MAVLINK_MSG_ID_ATTITUDE                */
    Q_PROPERTY(Fact* rollDegrees                        READ rollDegrees                        CONSTANT) /* f32        derived from rollRadians               */
    Q_PROPERTY(Fact* pitchDegrees                       READ pitchDegrees                       CONSTANT) /* f32        derived from pitchRadians              */
    Q_PROPERTY(Fact* yawDegrees                         READ yawDegrees                         CONSTANT) /* f32        derived from yawRadians                */
    Q_PROPERTY(Fact* rollRateRadiansPerSecond           READ rollRateRadiansPerSecond           CONSTANT) /* f32        MAVLINK_MSG_ID_ATTITUDE                */
    Q_PROPERTY(Fact* pitchRateRadiansPerSecond          READ pitchRateRadiansPerSecond          CONSTANT) /* f32        MAVLINK_MSG_ID_ATTITUDE                */
    Q_PROPERTY(Fact* yawRateRadiansPerSecond            READ yawRateRadiansPerSecond            CONSTANT) /* f32        MAVLINK_MSG_ID_ATTITUDE                */
    Q_PROPERTY(Fact* rollRateDegreesPerSecond           READ rollRateDegreesPerSecond           CONSTANT) /* f32        derived from rollRateRadiansPerSecond  */
    Q_PROPERTY(Fact* pitchRateDegreesPerSecond          READ pitchRateDegreesPerSecond          CONSTANT) /* f32        derived from pitchRateRadiansPerSecond */
    Q_PROPERTY(Fact* yawRateDegreesPerSecond            READ yawRateDegreesPerSecond            CONSTANT) /* f32        derived from yawRateRadiansPerSecond   */
    Q_PROPERTY(Fact* xVelocityMetersPerSecond           READ xVelocityMetersPerSecond           CONSTANT) /* f32        MAVLINK_MSG_ID_LOCAL_POSITION_NED      */
    Q_PROPERTY(Fact* yVelocityMetersPerSecond           READ yVelocityMetersPerSecond           CONSTANT) /* f32        MAVLINK_MSG_ID_LOCAL_POSITION_NED      */
    Q_PROPERTY(Fact* zVelocityMetersPerSecond           READ zVelocityMetersPerSecond           CONSTANT) /* f32        MAVLINK_MSG_ID_LOCAL_POSITION_NED      */
    Q_PROPERTY(Fact* zVelocityMetersPerSecondInverted   READ zVelocityMetersPerSecondInverted   CONSTANT) /* f32        derived from zVelocityMetersPerSecond  */
    Q_PROPERTY(Fact* homePositionLatitudeDegrees        READ homePositionLatitudeDegrees        CONSTANT) /* f64        file                                   */
    Q_PROPERTY(Fact* homePositionLongitudeDegrees       READ homePositionLongitudeDegrees       CONSTANT) /* f64        file                                   */
    Q_PROPERTY(Fact* homePositionAltitudeMeters         READ homePositionAltitudeMeters         CONSTANT) /* f32        file                                   */
    Q_PROPERTY(Fact* droneSerialNumber                  READ droneSerialNumber                  CONSTANT) /* uint32_t   file                                   */
    Q_PROPERTY(Fact* groundWindSpeedMetersPerSecond     READ groundWindSpeedMetersPerSecond     CONSTANT) /* f32        file                                   */
    Q_PROPERTY(Fact* groundWindDirectionDegrees         READ groundWindDirectionDegrees         CONSTANT) /* int32_t    file                                   */
    Q_PROPERTY(Fact* groundAirTemperatureCelsius        READ groundAirTemperatureCelsius        CONSTANT) /* f32        file                                   */
    Q_PROPERTY(Fact* groundHumidity                     READ groundHumidity                     CONSTANT) /* f32        file                                   */
    Q_PROPERTY(Fact* groundPressureMillibars            READ groundPressureMillibars            CONSTANT) /* f32        file                                   */
    Q_PROPERTY(Fact* satellites                         READ satellites                         CONSTANT) /* uint8_t    MAVLINK_MSG_ID_GPS_RAW_INT             */
    Q_PROPERTY(Fact* horizontalDilutionOfPosition       READ horizontalDilutionOfPosition       CONSTANT) /* uint16_t   MAVLINK_MSG_ID_GPS_RAW_INT             */
    Q_PROPERTY(Fact* horizontalDilutionOfPositionFloat  READ horizontalDilutionOfPositionFloat  CONSTANT) /* f32        MAVLINK_MSG_ID_GPS_RAW_INT             */

    /*
        Everything below this is WIP
        A few items in the SoW 205192-10 table 2-1 (Raw Data) do not yet have associated facts, these are:

            column 21 - Custom mode
            column 22 - Data quality
            column 32 - Powered age
            column 33 - Armed age
    */

    Fact* getFactPointertimeUnixMicroseconds()              { return &_timeUnixMicrosecondsFact; }
    Fact* getFactPointertimeUnixSeconds()                   { return &_timeUnixSecondsFact; }
    Fact* getFactPointeraltitudeMillimetersMSL()            { return &_altitudeMillimetersMSLFact; }
    Fact* getFactPointeraltitudeMetersMSL()                 { return &_altitudeMetersMSLFact; }
    Fact* getFactPointerabsolutePressureMillibars()         { return &_absolutePressureMillibarsFact; }
    Fact* getFactPointertemperature0Kelvin()                { return &_temperature0KelvinFact; }
    Fact* getFactPointertemperature1Kelvin()                { return &_temperature1KelvinFact; }
    Fact* getFactPointertemperature2Kelvin()                { return &_temperature2KelvinFact; }
    Fact* getFactPointertemperature0Celsius()               { return &_temperature0CelsiusFact; }
    Fact* getFactPointertemperature1Celsius()               { return &_temperature1CelsiusFact; }
    Fact* getFactPointertemperature2Celsius()               { return &_temperature2CelsiusFact; }
    Fact* getFactPointertemperatureCelsius()                { return &_temperatureCelsiusFact; }
    Fact* getFactPointerrelativeHumidity0()                 { return &_relativeHumidity0Fact; }
    Fact* getFactPointerrelativeHumidity1()                 { return &_relativeHumidity1Fact; }
    Fact* getFactPointerrelativeHumidity2()                 { return &_relativeHumidity2Fact; }
    Fact* getFactPointerrelativeHumidity()                  { return &_relativeHumidityFact; }
    Fact* getFactPointerlatitudeDegreesE7()                 { return &_latitudeDegreesE7Fact; }
    Fact* getFactPointerlongitudeDegreesE7()                { return &_longitudeDegreesE7Fact; }
    Fact* getFactPointerlatitudeDegrees()                   { return &_latitudeDegreesFact; }
    Fact* getFactPointerlongitudeDegrees()                  { return &_longitudeDegreesFact; }
    Fact* getFactPointerrollRadians()                       { return &_rollRadiansFact; }
    Fact* getFactPointerpitchRadians()                      { return &_pitchRadiansFact; }
    Fact* getFactPointeryawRadians()                        { return &_yawRadiansFact; }
    Fact* getFactPointerrollDegrees()                       { return &_rollDegreesFact; }
    Fact* getFactPointerpitchDegrees()                      { return &_pitchDegreesFact; }
    Fact* getFactPointeryawDegrees()                        { return &_yawDegreesFact; }
    Fact* getFactPointerrollRateRadiansPerSecond()          { return &_rollRateRadiansPerSecondFact; }
    Fact* getFactPointerpitchRateRadiansPerSecond()         { return &_pitchRateDegreesPerSecondFact; }
    Fact* getFactPointeryawRateRadiansPerSecond()           { return &_yawRateRadiansPerSecondFact; }
    Fact* getFactPointerrollRateDegreesPerSecond()          { return &_rollRateDegreesPerSecondFact; }
    Fact* getFactPointerpitchRateDegreesPerSecond()         { return &_pitchRateDegreesPerSecondFact; }
    Fact* getFactPointeryawRateDegreesPerSecond()           { return &_yawRateDegreesPerSecondFact; }
    Fact* getFactPointerxVelocityMetersPerSecond()          { return &_xVelocityMetersPerSecondFact; }
    Fact* getFactPointeryVelocityMetersPerSecond()          { return &_yVelocityMetersPerSecondFact; }
    Fact* getFactPointerzVelocityMetersPerSecond()          { return &_zVelocityMetersPerSecondFact; }
    Fact* getFactPointerzVelocityMetersPerSecondInverted()  { return &_zVelocityMetersPerSecondInvertedFact; }
    Fact* getFactPointerhomePositionLatitudeDegrees()       { return &_homePositionLatitudeDegreesFact; }
    Fact* getFactPointerhomePositionLongitudeDegrees()      { return &_homePositionLongitudeDegreesFact; }
    Fact* getFactPointerhomePositionAltitudeMeters()        { return &_homePositionAltitudeMetersFact; }
    Fact* getFactPointerdroneSerialNumber()                 { return &_droneSerialNumberFact; }
    Fact* getFactPointergroundWindSpeedMetersPerSecond()    { return &_groundWindSpeedMetersPerSecondFact; }
    Fact* getFactPointergroundWindDirectionDegrees()        { return &_groundWindDirectionDegreesFact; }
    Fact* getFactPointergroundAirTemperatureCelsius()       { return &_groundAirTemperatureCelsiusFact; }
    Fact* getFactPointergroundHumidity()                    { return &_groundHumidityFact; }
    Fact* getFactPointergroundPressureMillibars()           { return &_groundPressureMillibarsFact; }
    Fact* getFactPointersatellites()                        { return &_satellitesFact; }
    Fact* getFactPointerhorizontalDilutionOfPosition()      { return &_horizontalDilutionOfPositionFact; }
    Fact* getFactPointerhorizontalDilutionOfPositionFloat() { return &_horizontalDilutionOfPositionFloatFact; }

    // Overrides from FactGroup
    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    static const char* _timeName;

private:
    DataHub hub;

    Fact            _timeUnixMicrosecondsFact;
    Fact            _timeUnixSecondsFact;
    Fact            _altitudeMillimetersMSLFact;
    Fact            _altitudeMetersMSLFact;
    Fact            _absolutePressureMillibarsFact;
    Fact            _temperature0KelvinFact;
    Fact            _temperature1KelvinFact;
    Fact            _temperature2KelvinFact;
    Fact            _temperature0CelsiusFact;
    Fact            _temperature1CelsiusFact;
    Fact            _temperature2CelsiusFact;
    Fact            _temperatureCelsiusFact;
    Fact            _relativeHumidity0Fact;
    Fact            _relativeHumidity1Fact;
    Fact            _relativeHumidity2Fact;
    Fact            _relativeHumidityFact;
    Fact            _latitudeDegreesE7Fact;
    Fact            _longitudeDegreesE7Fact;
    Fact            _latitudeDegreesFact;
    Fact            _longitudeDegreesFact;
    Fact            _rollRadiansFact;
    Fact            _pitchRadiansFact;
    Fact            _yawRadiansFact;
    Fact            _rollDegreesFact;
    Fact            _pitchDegreesFact;
    Fact            _yawDegreesFact;
    Fact            _rollRateRadiansPerSecondFact;
    Fact            _pitchRateRadiansPerSecondFact;
    Fact            _yawRateRadiansPerSecondFact;
    Fact            _rollRateDegreesPerSecondFact;
    Fact            _pitchRateDegreesPerSecondFact;
    Fact            _yawRateDegreesPerSecondFact;
    Fact            _xVelocityMetersPerSecondFact;
    Fact            _yVelocityMetersPerSecondFact;
    Fact            _zVelocityMetersPerSecondFact;
    Fact            _zVelocityMetersPerSecondInvertedFact;
    Fact            _homePositionLatitudeDegreesFact;
    Fact            _homePositionLongitudeDegreesFact;
    Fact            _homePositionAltitudeMetersFact;
    Fact            _droneSerialNumberFact;
    Fact            _groundWindSpeedMetersPerSecondFact;
    Fact            _groundWindDirectionDegreesFact;
    Fact            _groundAirTemperatureCelsiusFact;
    Fact            _groundHumidityFact;
    Fact            _groundPressureMillibarsFact;
    Fact            _satellitesFact;
    Fact            _horizontalDilutionOfPositionFact;
    Fact            _horizontalDilutionOfPositionFloatFact;
};

#endif // DATAFACTGROUP_H
