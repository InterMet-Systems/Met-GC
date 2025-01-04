/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "FactGroup.h"
#include "QGCMAVLink.h"

class VehicleTemperatureFactGroup : public FactGroup
{
    Q_OBJECT

public:
    VehicleTemperatureFactGroup(QObject* parent = nullptr);

    Q_PROPERTY(Fact* temperature1                       READ temperature1                       CONSTANT)
    Q_PROPERTY(Fact* temperature2                       READ temperature2                       CONSTANT)
    Q_PROPERTY(Fact* temperature3                       READ temperature3                       CONSTANT)
    /* IMetData */
    Q_PROPERTY(Fact* temperature4                       READ temperature4                       CONSTANT)
    Q_PROPERTY(Fact* timeUAVMilliseconds                READ timeUAVMilliseconds                CONSTANT)
    Q_PROPERTY(Fact* timeUnixMilliseconds               READ timeUnixMilliseconds               CONSTANT)
    Q_PROPERTY(Fact* timeUAVBootMilliseconds            READ timeUAVBootMilliseconds            CONSTANT)
    Q_PROPERTY(Fact* altitudeMillimetersMSL             READ altitudeMillimetersMSL             CONSTANT)
    Q_PROPERTY(Fact* absolutePressureMillibars          READ absolutePressureMillibars          CONSTANT)
    Q_PROPERTY(Fact* temperature0Celsius                 READ temperature0Celsius                 CONSTANT)
    Q_PROPERTY(Fact* temperature1Celsius                 READ temperature1Celsius                 CONSTANT)
    Q_PROPERTY(Fact* temperature2Celsius                 READ temperature2Celsius                 CONSTANT)
    Q_PROPERTY(Fact* relativeHumidity                   READ relativeHumidity                   CONSTANT)
    Q_PROPERTY(Fact* relativeHumidity0                  READ relativeHumidity0                  CONSTANT)
    Q_PROPERTY(Fact* relativeHumidity1                  READ relativeHumidity1                  CONSTANT)
    Q_PROPERTY(Fact* relativeHumidity2                  READ relativeHumidity2                  CONSTANT)
    Q_PROPERTY(Fact* windSpeedMetersPerSecond           READ windSpeedMetersPerSecond           CONSTANT)
    Q_PROPERTY(Fact* windBearingDegrees                 READ windBearingDegrees                 CONSTANT)
    Q_PROPERTY(Fact* latitudeDegreesE7                  READ latitudeDegreesE7                  CONSTANT)
    Q_PROPERTY(Fact* longitudeDegreesE7                 READ longitudeDegreesE7                 CONSTANT)
    Q_PROPERTY(Fact* rollRadians                        READ rollRadians                        CONSTANT)
    Q_PROPERTY(Fact* pitchRadians                       READ pitchRadians                       CONSTANT)
    Q_PROPERTY(Fact* yawRadians                         READ yawRadians                         CONSTANT)
    Q_PROPERTY(Fact* rollRateRadiansPerSecond           READ rollRateRadiansPerSecond           CONSTANT)
    Q_PROPERTY(Fact* pitchRateRadiansPerSecond          READ pitchRateRadiansPerSecond          CONSTANT)
    Q_PROPERTY(Fact* yawRateRadiansPerSecond            READ yawRateRadiansPerSecond            CONSTANT)
    Q_PROPERTY(Fact* zVelocityMetersPerSecondInverted   READ zVelocityMetersPerSecondInverted   CONSTANT)
    Q_PROPERTY(Fact* xVelocityMetersPerSecond           READ xVelocityMetersPerSecond           CONSTANT)
    Q_PROPERTY(Fact* yVelocityMetersPerSecond           READ yVelocityMetersPerSecond           CONSTANT)
    Q_PROPERTY(Fact* groundSpeedMetersPerSecond         READ groundSpeedMetersPerSecond         CONSTANT)
    Q_PROPERTY(Fact* heartBeatCustomMode                READ heartBeatCustomMode                CONSTANT)
    Q_PROPERTY(Fact* ascending                          READ ascending                          CONSTANT)
    Q_PROPERTY(Fact* timeUAVSeconds                     READ timeUAVSeconds                     CONSTANT)
    Q_PROPERTY(Fact* timeUnixSeconds                    READ timeUnixSeconds                    CONSTANT)
    Q_PROPERTY(Fact* timeUAVBootSeconds                 READ timeUAVBootSeconds                 CONSTANT)
    Q_PROPERTY(Fact* altitudeMetersMSL                  READ altitudeMetersMSL                  CONSTANT)
    Q_PROPERTY(Fact* temperatureCelsius                 READ temperatureCelsius                 CONSTANT)
    Q_PROPERTY(Fact* latitudeDegrees                    READ latitudeDegrees                    CONSTANT)
    Q_PROPERTY(Fact* longitudeDegrees                   READ longitudeDegrees                   CONSTANT)
    Q_PROPERTY(Fact* rollDegrees                        READ rollDegrees                        CONSTANT)
    Q_PROPERTY(Fact* pitchDegrees                       READ pitchDegrees                       CONSTANT)
    Q_PROPERTY(Fact* yawDegrees                         READ yawDegrees                         CONSTANT)
    Q_PROPERTY(Fact* rollRateDegreesPerSecond           READ rollRateDegreesPerSecond           CONSTANT)
    Q_PROPERTY(Fact* pitchRateDegreesPerSecond          READ pitchRateDegreesPerSecond          CONSTANT)
    Q_PROPERTY(Fact* yawRateDegreesPerSecond            READ yawRateDegreesPerSecond            CONSTANT)
    Q_PROPERTY(Fact* zVelocityMetersPerSecond           READ zVelocityMetersPerSecond           CONSTANT)
    Q_PROPERTY(Fact* lastState                          READ lastState                          CONSTANT)
    Q_PROPERTY(Fact* ascents                            READ ascents                            CONSTANT)
    /* Altitude Level Message */
    Q_PROPERTY(Fact* asl                READ asl                CONSTANT)
    Q_PROPERTY(Fact* time               READ time               CONSTANT)
    Q_PROPERTY(Fact* pressure           READ pressure           CONSTANT)
    Q_PROPERTY(Fact* airTemp            READ airTemp            CONSTANT)
    Q_PROPERTY(Fact* relHum             READ relHum             CONSTANT)
    Q_PROPERTY(Fact* windSpeed          READ windSpeed          CONSTANT)
    Q_PROPERTY(Fact* windDirection      READ windDirection      CONSTANT)
    Q_PROPERTY(Fact* latitude           READ latitude           CONSTANT)
    Q_PROPERTY(Fact* longitude          READ longitude          CONSTANT)
    Q_PROPERTY(Fact* roll               READ roll               CONSTANT)
    Q_PROPERTY(Fact* rollRate           READ rollRate           CONSTANT)
    Q_PROPERTY(Fact* pitch              READ pitch              CONSTANT)
    Q_PROPERTY(Fact* pitchRate          READ pitchRate          CONSTANT)
    Q_PROPERTY(Fact* yaw                READ yaw                CONSTANT)
    Q_PROPERTY(Fact* yawRate            READ yawRate            CONSTANT)
    Q_PROPERTY(Fact* ascentRate         READ ascentRate         CONSTANT)
    Q_PROPERTY(Fact* speedOverGround    READ speedOverGround    CONSTANT)
    /* Used by MetFlightDataRecorderController and DataBalancer::onALMUpdate to determine if a given ALM has been sent to the GUI or not */
    Q_PROPERTY(Fact* ALMIsProcessed     READ ALMIsProcessed     CONSTANT)
    Q_PROPERTY(Fact* update     READ update     CONSTANT)

    Fact* temperature1 ()                       { return &_temperature1Fact; }
    Fact* temperature2 ()                       { return &_temperature2Fact; }
    Fact* temperature3 ()                       { return &_temperature3Fact; }
    /* TD test */
    Fact* temperature4 ()                       { return &_temperature4Fact; }
    Fact* timeUAVMilliseconds ()                { return &_timeUAVMillisecondsFact; }
    Fact* timeUnixMilliseconds ()               { return &_timeUnixMillisecondsFact; }
    Fact* timeUAVBootMilliseconds ()            { return &_timeUAVBootMillisecondsFact; }
    Fact* altitudeMillimetersMSL ()             { return &_altitudeMillimetersMSLFact; }
    Fact* absolutePressureMillibars ()          { return &_absolutePressureMillibarsFact; }
    Fact* temperature0Celsius ()                 { return &_temperature0CelsiusFact; }
    Fact* temperature1Celsius ()                 { return &_temperature1CelsiusFact; }
    Fact* temperature2Celsius ()                 { return &_temperature2CelsiusFact; }
    Fact* relativeHumidity ()                   { return &_relativeHumidityFact; }
    Fact* relativeHumidity0 ()                  { return &_relativeHumidity0Fact; }
    Fact* relativeHumidity1 ()                  { return &_relativeHumidity1Fact; }
    Fact* relativeHumidity2 ()                  { return &_relativeHumidity2Fact; }
    Fact* windSpeedMetersPerSecond ()           { return &_windSpeedMetersPerSecondFact; }
    Fact* windBearingDegrees ()                 { return &_windBearingDegreesFact; }
    Fact* latitudeDegreesE7 ()                  { return &_latitudeDegreesE7Fact; }
    Fact* longitudeDegreesE7 ()                 { return &_longitudeDegreesE7Fact; }
    Fact* rollRadians ()                        { return &_rollRadiansFact; }
    Fact* pitchRadians ()                       { return &_pitchRadiansFact; }
    Fact* yawRadians ()                         { return &_yawRadiansFact; }
    Fact* rollRateRadiansPerSecond ()           { return &_rollRateRadiansPerSecondFact; }
    Fact* pitchRateRadiansPerSecond ()          { return &_pitchRateRadiansPerSecondFact; }
    Fact* yawRateRadiansPerSecond ()            { return &_yawRateRadiansPerSecondFact; }
    Fact* zVelocityMetersPerSecondInverted ()   { return &_zVelocityMetersPerSecondInvertedFact; }
    Fact* xVelocityMetersPerSecond ()           { return &_xVelocityMetersPerSecondFact; }
    Fact* yVelocityMetersPerSecond ()           { return &_yVelocityMetersPerSecondFact; }
    Fact* groundSpeedMetersPerSecond ()         { return &_groundSpeedMetersPerSecondFact; }
    Fact* heartBeatCustomMode ()                { return &_heartBeatCustomModeFact; }
    Fact* ascending ()                          { return &_ascendingFact; }
    Fact* timeUAVSeconds ()                     { return &_timeUAVSecondsFact; }
    Fact* timeUnixSeconds ()                    { return &_timeUnixSecondsFact; }
    Fact* timeUAVBootSeconds ()                 { return &_timeUAVBootSecondsFact; }
    Fact* altitudeMetersMSL ()                  { return &_altitudeMetersMSLFact; }
    Fact* temperatureCelsius ()                 { return &_temperatureCelsiusFact; }
    Fact* latitudeDegrees ()                    { return &_latitudeDegreesFact; }
    Fact* longitudeDegrees ()                   { return &_longitudeDegreesFact; }
    Fact* rollDegrees ()                        { return &_rollDegreesFact; }
    Fact* pitchDegrees ()                       { return &_pitchDegreesFact; }
    Fact* yawDegrees ()                         { return &_yawDegreesFact; }
    Fact* rollRateDegreesPerSecond ()           { return &_rollRateDegreesPerSecondFact; }
    Fact* pitchRateDegreesPerSecond ()          { return &_pitchRateDegreesPerSecondFact; }
    Fact* yawRateDegreesPerSecond ()            { return &_yawRateDegreesPerSecondFact; }
    Fact* zVelocityMetersPerSecond ()           { return &_zVelocityMetersPerSecondFact; }
    Fact* lastState ()                          { return &_lastStateFact; }
    Fact* ascents ()                            { return &_ascentsFact; }
    /* Altitude Level message */
    Fact* asl ()                                { return &_aslFact; }
    Fact* time ()                               { return &_timeFact; }
    Fact* pressure ()                           { return &_pressureFact; }
    Fact* airTemp ()                            { return &_airTempFact; }
    Fact* relHum ()                             { return &_relHumFact; }
    Fact* windSpeed ()                          { return &_windSpeedFact; }
    Fact* windDirection ()                      { return &_windDirectionFact; }
    Fact* latitude ()                           { return &_latitudeFact; }
    Fact* longitude ()                          { return &_longitudeFact; }
    Fact* roll ()                               { return &_rollFact; }
    Fact* rollRate ()                           { return &_rollRateFact; }
    Fact* pitch ()                              { return &_pitchFact; }
    Fact* pitchRate ()                          { return &_pitchRateFact; }
    Fact* yaw ()                                { return &_yawFact; }
    Fact* yawRate ()                            { return &_yawRateFact; }
    Fact* ascentRate ()                         { return &_ascentRateFact; }
    Fact* speedOverGround ()                    { return &_speedOverGroundFact; }
    Fact* ALMIsProcessed ()                     { return &_ALMIsProcessedFact; }
    Fact* update ()                         { return &_updateFact; }

    // Overrides from FactGroup
    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;

    static const char* _temperature1FactName;
    static const char* _temperature2FactName;
    static const char* _temperature3FactName;
    /* TD test */
    static const char* _temperature4FactName;
    static const char* _timeUAVMillisecondsFactName;
    static const char* _timeUnixMillisecondsFactName;
    static const char* _timeUAVBootMillisecondsFactName;
    static const char* _altitudeMillimetersMSLFactName;
    static const char* _absolutePressureMillibarsFactName;
    static const char* _temperature0CelsiusFactName;
    static const char* _temperature1CelsiusFactName;
    static const char* _temperature2CelsiusFactName;
    static const char* _relativeHumidityFactName;
    static const char* _relativeHumidity0FactName;
    static const char* _relativeHumidity1FactName;
    static const char* _relativeHumidity2FactName;
    static const char* _windSpeedMetersPerSecondFactName;
    static const char* _windBearingDegreesFactName;
    static const char* _latitudeDegreesE7FactName;
    static const char* _longitudeDegreesE7FactName;
    static const char* _rollRadiansFactName;
    static const char* _pitchRadiansFactName;
    static const char* _yawRadiansFactName;
    static const char* _rollRateRadiansPerSecondFactName;
    static const char* _pitchRateRadiansPerSecondFactName;
    static const char* _yawRateRadiansPerSecondFactName;
    static const char* _zVelocityMetersPerSecondInvertedFactName;
    static const char* _xVelocityMetersPerSecondFactName;
    static const char* _yVelocityMetersPerSecondFactName;
    static const char* _groundSpeedMetersPerSecondFactName;
    static const char* _heartBeatCustomModeFactName;
    static const char* _ascendingFactName;
    static const char* _timeUAVSecondsFactName;
    static const char* _timeUnixSecondsFactName;
    static const char* _timeUAVBootSecondsFactName;
    static const char* _altitudeMetersMSLFactName;
    static const char* _temperatureCelsiusFactName;
    static const char* _latitudeDegreesFactName;
    static const char* _longitudeDegreesFactName;
    static const char* _rollDegreesFactName;
    static const char* _pitchDegreesFactName;
    static const char* _yawDegreesFactName;
    static const char* _rollRateDegreesPerSecondFactName;
    static const char* _pitchRateDegreesPerSecondFactName;
    static const char* _yawRateDegreesPerSecondFactName;
    static const char* _zVelocityMetersPerSecondFactName;
    static const char* _lastStateFactName;
    static const char* _ascentsFactName;
    /* Altitude Level message */
    static const char* _aslFactName;
    static const char* _timeFactName;
    static const char* _pressureFactName;
    static const char* _airTempFactName;
    static const char* _relHumFactName;
    static const char* _windSpeedFactName;
    static const char* _windDirectionFactName;
    static const char* _latitudeFactName;
    static const char* _longitudeFactName;
    static const char* _rollFactName;
    static const char* _rollRateFactName;
    static const char* _pitchFactName;
    static const char* _pitchRateFactName;
    static const char* _yawFactName;
    static const char* _yawRateFactName;
    static const char* _ascentRateFactName;
    static const char* _speedOverGroundFactName;
    static const char* _ALMIsProcessedFactName;
    static const char* _updateFactName;

    static const char* _settingsGroup;

    static const double _temperatureUnavailable;

private:
    void _handleScaledPressure  (mavlink_message_t& message);
    void _handleScaledPressure2 (mavlink_message_t& message);
    void _handleScaledPressure3 (mavlink_message_t& message);
    void _handleHighLatency     (mavlink_message_t& message);
    void _handleHighLatency2    (mavlink_message_t& message);

    Fact            _temperature1Fact;
    Fact            _temperature2Fact;
    Fact            _temperature3Fact;
    /* TD test */
    Fact            _temperature4Fact;
    Fact            _timeUAVMillisecondsFact;
    Fact            _timeUnixMillisecondsFact;
    Fact            _timeUAVBootMillisecondsFact;
    Fact            _altitudeMillimetersMSLFact;
    Fact            _absolutePressureMillibarsFact;
    Fact            _temperature0CelsiusFact;
    Fact            _temperature1CelsiusFact;
    Fact            _temperature2CelsiusFact;
    Fact            _relativeHumidityFact;
    Fact            _relativeHumidity0Fact;
    Fact            _relativeHumidity1Fact;
    Fact            _relativeHumidity2Fact;
    Fact            _windSpeedMetersPerSecondFact;
    Fact            _windBearingDegreesFact;
    Fact            _latitudeDegreesE7Fact;
    Fact            _longitudeDegreesE7Fact;
    Fact            _rollRadiansFact;
    Fact            _pitchRadiansFact;
    Fact            _yawRadiansFact;
    Fact            _rollRateRadiansPerSecondFact;
    Fact            _pitchRateRadiansPerSecondFact;
    Fact            _yawRateRadiansPerSecondFact;
    Fact            _zVelocityMetersPerSecondInvertedFact;
    Fact            _xVelocityMetersPerSecondFact;
    Fact            _yVelocityMetersPerSecondFact;
    Fact            _groundSpeedMetersPerSecondFact;
    Fact            _heartBeatCustomModeFact;
    Fact            _ascendingFact;
    Fact            _timeUAVSecondsFact;
    Fact            _timeUnixSecondsFact;
    Fact            _timeUAVBootSecondsFact;
    Fact            _altitudeMetersMSLFact;
    Fact            _temperatureCelsiusFact;
    Fact            _latitudeDegreesFact;
    Fact            _longitudeDegreesFact;
    Fact            _rollDegreesFact;
    Fact            _pitchDegreesFact;
    Fact            _yawDegreesFact;
    Fact            _rollRateDegreesPerSecondFact;
    Fact            _pitchRateDegreesPerSecondFact;
    Fact            _yawRateDegreesPerSecondFact;
    Fact            _zVelocityMetersPerSecondFact;
    Fact            _lastStateFact;
    Fact            _ascentsFact;
    /* Altitude Level message */
    Fact            _aslFact;
    Fact            _timeFact;
    Fact            _pressureFact;
    Fact            _airTempFact;
    Fact            _relHumFact;
    Fact            _windSpeedFact;
    Fact            _windDirectionFact;
    Fact            _latitudeFact;
    Fact            _longitudeFact;
    Fact            _rollFact;
    Fact            _rollRateFact;
    Fact            _pitchFact;
    Fact            _pitchRateFact;
    Fact            _yawFact;
    Fact            _yawRateFact;
    Fact            _ascentRateFact;
    Fact            _speedOverGroundFact;
    Fact            _ALMIsProcessedFact;
    Fact            _updateFact;
};
