#ifndef DATAFACTGROUP_H
#define DATAFACTGROUP_H

#include "FactGroup.h"

class DataFactGroup : public FactGroup{
    Q_OBJECT

public:
    DataFactGroup(QObject* parent = nullptr);
    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

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

    Fact* getFactPointerTimeUnixMicroseconds()              { return &_timeUnixMicrosecondsFact; }
    Fact* getFactPointerAltitudeMillimetersMSL()            { return &_altitudeMillimetersMSLFact; }
    Fact* getFactPointerAbsolutePressureMillibars()         { return &_absolutePressureMillibarsFact; }
    Fact* getFactPointerTemperature0Kelvin()                { return &_temperature0KelvinFact; }
    Fact* getFactPointerTemperature1Kelvin()                { return &_temperature1KelvinFact; }
    Fact* getFactPointerTemperature2Kelvin()                { return &_temperature2KelvinFact; }
    Fact* getFactPointerRelativeHumidity0()                 { return &_relativeHumidity0Fact; }
    Fact* getFactPointerRelativeHumidity1()                 { return &_relativeHumidity1Fact; }
    Fact* getFactPointerRelativeHumidity2()                 { return &_relativeHumidity2Fact; }
    Fact* getFactPointerLatitudeDegreesE7()                 { return &_latitudeDegreesE7Fact; }
    Fact* getFactPointerLongitudeDegreesE7()                { return &_longitudeDegreesE7Fact; }
    Fact* getFactPointerRollRadians()                       { return &_rollRadiansFact; }
    Fact* getFactPointerPitchRadians()                      { return &_pitchRadiansFact; }
    Fact* getFactPointerYawRadians()                        { return &_yawRadiansFact; }
    Fact* getFactPointerRollRateRadiansPerSecond()          { return &_rollRateRadiansPerSecondFact; }
    Fact* getFactPointerPitchRateRadiansPerSecond()         { return &_pitchRateRadiansPerSecondFact; }
    Fact* getFactPointerYawRateRadiansPerSecond()           { return &_yawRateRadiansPerSecondFact; }
    Fact* getFactPointerXVelocityMetersPerSecond()          { return &_xVelocityMetersPerSecondFact; }
    Fact* getFactPointerYVelocityMetersPerSecond()          { return &_yVelocityMetersPerSecondFact; }
    Fact* getFactPointerZVelocityMetersPerSecond()          { return &_zVelocityMetersPerSecondFact; }
    Fact* getFactPointerCustomModeHeartbeat()               { return &_customModeHeartbeatFact; }
    Fact* getFactPointerDataQuality()                       { return &_dataQualityFact; }
    Fact* getFactPointerSatellites()                        { return &_satellitesFact; }
    Fact* getFactPointerHorizontalDilutionOfPosition()      { return &_horizontalDilutionOfPositionFact; }

    static const char* _timeUnixMicrosecondsName;
    static const char* _altitudeMillimetersMSLName;
    static const char* _absolutePressureMillibarsName;
    static const char* _temperature0KelvinName;
    static const char* _temperature1KelvinName;
    static const char* _temperature2KelvinName;
    static const char* _relativeHumidity0Name;
    static const char* _relativeHumidity1Name;
    static const char* _relativeHumidity2Name;
    static const char* _latitudeDegreesE7Name;
    static const char* _longitudeDegreesE7Name;
    static const char* _rollRadiansName;
    static const char* _pitchRadiansName;
    static const char* _yawRadiansName;
    static const char* _rollRateRadiansPerSecondName;
    static const char* _pitchRateRadiansPerSecondName;
    static const char* _yawRateRadiansPerSecondName;
    static const char* _xVelocityMetersPerSecondName;
    static const char* _yVelocityMetersPerSecondName;
    static const char* _zVelocityMetersPerSecondName;
    static const char* _customModeHeartbeatName;
    static const char* _dataQualityName;
    static const char* _satellitesName;
    static const char* _horizontalDilutionOfPositionName;

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
