#ifndef DATAFACTGROUP_H
#define DATAFACTGROUP_H

#include "FactGroup.h"

class DataFactGroup : public FactGroup{
    Q_OBJECT

public:
    DataFactGroup(QObject* parent = nullptr);
    // void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    Q_PROPERTY(Fact* timeUnixMicroseconds               READ timeUnixMicroseconds               CONSTANT) /* uint64_t   MAVLINK_MSG_ID_SYSTEM_TIME             */
    Q_PROPERTY(Fact* altitudeMillimetersMSL             READ altitudeMillimetersMSL             CONSTANT) /* int32_t    MAVLINK_MSG_ID_GLOBAL_POSITION_INT     */
    Q_PROPERTY(Fact* absolutePressureMillibars          READ absolutePressureMillibars          CONSTANT) /* f32        MAVLINK_MSG_ID_SCALED_PRESSURE2        */
    Q_PROPERTY(Fact* temperature0Kelvin                 READ temperature0Kelvin                 CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* temperature1Kelvin                 READ temperature1Kelvin                 CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* temperature2Kelvin                 READ temperature2Kelvin                 CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* relativeHumidity0                  READ relativeHumidity0                  CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* relativeHumidity1                  READ relativeHumidity1                  CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* relativeHumidity2                  READ relativeHumidity2                  CONSTANT) /* f32        MAVLINK_MSG_ID_CASS_SENSOR_RAW         */
    Q_PROPERTY(Fact* latitudeDegreesE7                  READ latitudeDegreesE7                  CONSTANT) /* int32_t    MAVLINK_MSG_ID_GLOBAL_POSITION_INT     */
    Q_PROPERTY(Fact* longitudeDegreesE7                 READ longitudeDegreesE7                 CONSTANT) /* int32_t    MAVLINK_MSG_ID_GLOBAL_POSITION_INT     */
    Q_PROPERTY(Fact* rollRadians                        READ rollRadians                        CONSTANT) /* f32        MAVLINK_MSG_ID_ATTITUDE                */
    Q_PROPERTY(Fact* pitchRadians                       READ pitchRadians                       CONSTANT) /* f32        MAVLINK_MSG_ID_ATTITUDE                */
    Q_PROPERTY(Fact* yawRadians                         READ yawRadians                         CONSTANT) /* f32        MAVLINK_MSG_ID_ATTITUDE                */
    Q_PROPERTY(Fact* rollRateRadiansPerSecond           READ rollRateRadiansPerSecond           CONSTANT) /* f32        MAVLINK_MSG_ID_ATTITUDE                */
    Q_PROPERTY(Fact* pitchRateRadiansPerSecond          READ pitchRateRadiansPerSecond          CONSTANT) /* f32        MAVLINK_MSG_ID_ATTITUDE                */
    Q_PROPERTY(Fact* yawRateRadiansPerSecond            READ yawRateRadiansPerSecond            CONSTANT) /* f32        MAVLINK_MSG_ID_ATTITUDE                */
    Q_PROPERTY(Fact* xVelocityMetersPerSecond           READ xVelocityMetersPerSecond           CONSTANT) /* f32        MAVLINK_MSG_ID_LOCAL_POSITION_NED      */
    Q_PROPERTY(Fact* yVelocityMetersPerSecond           READ yVelocityMetersPerSecond           CONSTANT) /* f32        MAVLINK_MSG_ID_LOCAL_POSITION_NED      */
    Q_PROPERTY(Fact* zVelocityMetersPerSecond           READ zVelocityMetersPerSecond           CONSTANT) /* f32        MAVLINK_MSG_ID_LOCAL_POSITION_NED      */
    Q_PROPERTY(Fact* customModeHeartbeat                READ customModeHeartbeat                CONSTANT) /* uint32_t   MAVLINK_MSG_ID_HEARTBEAT               */
    Q_PROPERTY(Fact* dataQuality                        READ dataQuality                        CONSTANT) /* int32_t    Unknown                                */
    Q_PROPERTY(Fact* satellites                         READ satellites                         CONSTANT) /* uint8_t    MAVLINK_MSG_ID_GPS_RAW_INT             */
    Q_PROPERTY(Fact* horizontalDilutionOfPosition       READ horizontalDilutionOfPosition       CONSTANT) /* uint16_t   MAVLINK_MSG_ID_GPS_RAW_INT             */

    Fact* timeUnixMicroseconds()              { return &_timeUnixMicrosecondsFact; }
    Fact* altitudeMillimetersMSL()            { return &_altitudeMillimetersMSLFact; }
    Fact* absolutePressureMillibars()         { return &_absolutePressureMillibarsFact; }
    Fact* temperature0Kelvin()                { return &_temperature0KelvinFact; }
    Fact* temperature1Kelvin()                { return &_temperature1KelvinFact; }
    Fact* temperature2Kelvin()                { return &_temperature2KelvinFact; }
    Fact* relativeHumidity0()                 { return &_relativeHumidity0Fact; }
    Fact* relativeHumidity1()                 { return &_relativeHumidity1Fact; }
    Fact* relativeHumidity2()                 { return &_relativeHumidity2Fact; }
    Fact* latitudeDegreesE7()                 { return &_latitudeDegreesE7Fact; }
    Fact* longitudeDegreesE7()                { return &_longitudeDegreesE7Fact; }
    Fact* rollRadians()                       { return &_rollRadiansFact; }
    Fact* pitchRadians()                      { return &_pitchRadiansFact; }
    Fact* yawRadians()                        { return &_yawRadiansFact; }
    Fact* rollRateRadiansPerSecond()          { return &_rollRateRadiansPerSecondFact; }
    Fact* pitchRateRadiansPerSecond()         { return &_pitchRateRadiansPerSecondFact; }
    Fact* yawRateRadiansPerSecond()           { return &_yawRateRadiansPerSecondFact; }
    Fact* xVelocityMetersPerSecond()          { return &_xVelocityMetersPerSecondFact; }
    Fact* yVelocityMetersPerSecond()          { return &_yVelocityMetersPerSecondFact; }
    Fact* zVelocityMetersPerSecond()          { return &_zVelocityMetersPerSecondFact; }
    Fact* customModeHeartbeat()               { return &_customModeHeartbeatFact; }
    Fact* dataQuality()                       { return &_dataQualityFact; }
    Fact* satellites()                        { return &_satellitesFact; }
    Fact* horizontalDilutionOfPosition()      { return &_horizontalDilutionOfPositionFact; }

    static const char* _timeUnixMicrosecondsFactName;
    static const char* _altitudeMillimetersMSLFactName;
    static const char* _absolutePressureMillibarsFactName;
    static const char* _temperature0KelvinFactName;
    static const char* _temperature1KelvinFactName;
    static const char* _temperature2KelvinFactName;
    static const char* _relativeHumidity0FactName;
    static const char* _relativeHumidity1FactName;
    static const char* _relativeHumidity2FactName;
    static const char* _latitudeDegreesE7FactName;
    static const char* _longitudeDegreesE7FactName;
    static const char* _rollRadiansFactName;
    static const char* _pitchRadiansFactName;
    static const char* _yawRadiansFactName;
    static const char* _rollRateRadiansPerSecondFactName;
    static const char* _pitchRateRadiansPerSecondFactName;
    static const char* _yawRateRadiansPerSecondFactName;
    static const char* _xVelocityMetersPerSecondFactName;
    static const char* _yVelocityMetersPerSecondFactName;
    static const char* _zVelocityMetersPerSecondFactName;
    static const char* _customModeHeartbeatFactName;
    static const char* _dataQualityFactName;
    static const char* _satellitesFactName;
    static const char* _horizontalDilutionOfPositionFactName;

private:
    Fact            _timeUnixMicrosecondsFact;
    Fact            _altitudeMillimetersMSLFact;
    Fact            _absolutePressureMillibarsFact;
    Fact            _temperature0KelvinFact;
    Fact            _temperature1KelvinFact;
    Fact            _temperature2KelvinFact;
    Fact            _relativeHumidity0Fact;
    Fact            _relativeHumidity1Fact;
    Fact            _relativeHumidity2Fact;
    Fact            _latitudeDegreesE7Fact;
    Fact            _longitudeDegreesE7Fact;
    Fact            _rollRadiansFact;
    Fact            _pitchRadiansFact;
    Fact            _yawRadiansFact;
    Fact            _rollRateRadiansPerSecondFact;
    Fact            _pitchRateRadiansPerSecondFact;
    Fact            _yawRateRadiansPerSecondFact;
    Fact            _xVelocityMetersPerSecondFact;
    Fact            _yVelocityMetersPerSecondFact;
    Fact            _zVelocityMetersPerSecondFact;
    Fact            _customModeHeartbeatFact;
    Fact            _dataQualityFact;
    Fact            _satellitesFact;
    Fact            _horizontalDilutionOfPositionFact;
};

#endif // DATAFACTGROUP_H
