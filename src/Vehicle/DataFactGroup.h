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

    Fact* getFactPointerTime()                       { return &_timeFact; }

    // Overrides from FactGroup
    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    static const char* _timeName;

private:
    DataHub hub;

    Fact            _timeFact;
};

#endif // DATAFACTGROUP_H
