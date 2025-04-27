#ifndef MESSAGETIMEFACTGROUP_H
#define MESSAGETIMEFACTGROUP_H

#include "FactGroup.h"

class MessageTimeFactGroup : public FactGroup{
    Q_OBJECT

public:
    MessageTimeFactGroup(QObject* parent = nullptr);
    Q_PROPERTY(Fact* droneSerial              READ droneSerial              CONSTANT)
    Q_PROPERTY(Fact* filename                 READ filename                 CONSTANT)
    Q_PROPERTY(Fact* messageVersion           READ messageVersion           CONSTANT)
    Q_PROPERTY(Fact* dronePoweredAge          READ dronePoweredAge          CONSTANT)
    Q_PROPERTY(Fact* droneArmedAge            READ droneArmedAge            CONSTANT)
    Q_PROPERTY(Fact* rawDataFilename          READ rawDataFilename          CONSTANT)
    Q_PROPERTY(Fact* unixStartTime            READ unixStartTime            CONSTANT)
    Q_PROPERTY(Fact* groundWindSpeed          READ groundWindSpeed          CONSTANT)
    Q_PROPERTY(Fact* groundWindDirection      READ groundWindDirection      CONSTANT)
    Q_PROPERTY(Fact* groundAirTemperature     READ groundAirTemperature     CONSTANT)
    Q_PROPERTY(Fact* groundHumidity           READ groundHumidity           CONSTANT)
    Q_PROPERTY(Fact* groundPressure           READ groundPressure           CONSTANT)
    Q_PROPERTY(Fact* homePositionLatitude     READ homePositionLatitude     CONSTANT)
    Q_PROPERTY(Fact* homePositionLongitude    READ homePositionLongitude    CONSTANT)
    Q_PROPERTY(Fact* homePositionAltitude     READ homePositionAltitude     CONSTANT)
    Q_PROPERTY(Fact* uTCDate                  READ uTCDate                  CONSTANT)
    Q_PROPERTY(Fact* uTCTime                  READ uTCTime                  CONSTANT)
    Q_PROPERTY(Fact* timeSinceStart           READ timeSinceStart           CONSTANT)
    Q_PROPERTY(Fact* altitudeASL              READ altitudeASL              CONSTANT)
    Q_PROPERTY(Fact* pressure                 READ pressure                 CONSTANT)
    Q_PROPERTY(Fact* airTemp                  READ airTemp                  CONSTANT)
    Q_PROPERTY(Fact* relHum                   READ relHum                   CONSTANT)
    Q_PROPERTY(Fact* windSpeed                READ windSpeed                CONSTANT)
    Q_PROPERTY(Fact* windDirection            READ windDirection            CONSTANT)
    Q_PROPERTY(Fact* latitude                 READ latitude                 CONSTANT)
    Q_PROPERTY(Fact* longitude                READ longitude                CONSTANT)
    Q_PROPERTY(Fact* roll                     READ roll                     CONSTANT)
    Q_PROPERTY(Fact* rollRate                 READ rollRate                 CONSTANT)
    Q_PROPERTY(Fact* pitch                    READ pitch                    CONSTANT)
    Q_PROPERTY(Fact* pitchRate                READ pitchRate                CONSTANT)
    Q_PROPERTY(Fact* yaw                      READ yaw                      CONSTANT)
    Q_PROPERTY(Fact* yawRate                  READ yawRate                  CONSTANT)
    Q_PROPERTY(Fact* ascentRate               READ ascentRate               CONSTANT)
    Q_PROPERTY(Fact* speedOverGround          READ speedOverGround          CONSTANT)
    Q_PROPERTY(Fact* satellites               READ satellites               CONSTANT)
    Q_PROPERTY(Fact* hDOP                     READ hDOP                     CONSTANT)
    Q_PROPERTY(Fact* dataQuality              READ dataQuality              CONSTANT)

    Fact* droneSerial           ()  { return &_droneSerialFact; }
    Fact* filename              ()  { return &_filenameFact; }
    Fact* messageVersion        ()  { return &_messageVersionFact; }
    Fact* dronePoweredAge       ()  { return &_dronePoweredAgeFact; }
    Fact* droneArmedAge         ()  { return &_droneArmedAgeFact; }
    Fact* rawDataFilename       ()  { return &_rawDataFilenameFact; }
    Fact* unixStartTime         ()  { return &_unixStartTimeFact; }
    Fact* groundWindSpeed       ()  { return &_groundWindSpeedFact; }
    Fact* groundWindDirection   ()  { return &_groundWindDirectionFact; }
    Fact* groundAirTemperature  ()  { return &_groundAirTemperatureFact; }
    Fact* groundHumidity        ()  { return &_groundHumidityFact; }
    Fact* groundPressure        ()  { return &_groundPressureFact; }
    Fact* homePositionLatitude  ()  { return &_homePositionLatitudeFact; }
    Fact* homePositionLongitude ()  { return &_homePositionLongitudeFact; }
    Fact* homePositionAltitude  ()  { return &_homePositionAltitudeFact; }
    Fact* uTCDate               ()  { return &_uTCDateFact; }
    Fact* uTCTime               ()  { return &_uTCTimeFact; }
    Fact* timeSinceStart        ()  { return &_timeSinceStartFact; }
    Fact* altitudeASL           ()  { return &_altitudeASLFact; }
    Fact* pressure              ()  { return &_pressureFact; }
    Fact* airTemp               ()  { return &_airTempFact; }
    Fact* relHum                ()  { return &_relHumFact; }
    Fact* windSpeed             ()  { return &_windSpeedFact; }
    Fact* windDirection         ()  { return &_windDirectionFact; }
    Fact* latitude              ()  { return &_latitudeFact; }
    Fact* longitude             ()  { return &_longitudeFact; }
    Fact* roll                  ()  { return &_rollFact; }
    Fact* rollRate              ()  { return &_rollRateFact; }
    Fact* pitch                 ()  { return &_pitchFact; }
    Fact* pitchRate             ()  { return &_pitchRateFact; }
    Fact* yaw                   ()  { return &_yawFact; }
    Fact* yawRate               ()  { return &_yawRateFact; }
    Fact* ascentRate            ()  { return &_ascentRateFact; }
    Fact* speedOverGround       ()  { return &_speedOverGroundFact; }
    Fact* satellites            ()  { return &_satellitesFact; }
    Fact* hDOP                  ()  { return &_hDOPFact; }
    Fact* dataQuality           ()  { return &_dataQualityFact; }

    static const char* _droneSerialFactName;
    static const char* _filenameFactName;
    static const char* _messageVersionFactName;
    static const char* _dronePoweredAgeFactName;
    static const char* _droneArmedAgeFactName;
    static const char* _rawDataFilenameFactName;
    static const char* _unixStartTimeFactName;
    static const char* _groundWindSpeedFactName;
    static const char* _groundWindDirectionFactName;
    static const char* _groundAirTemperatureFactName;
    static const char* _groundHumidityFactName;
    static const char* _groundPressureFactName;
    static const char* _homePositionLatitudeFactName;
    static const char* _homePositionLongitudeFactName;
    static const char* _homePositionAltitudeFactName;
    static const char* _uTCDateFactName;
    static const char* _uTCTimeFactName;
    static const char* _timeSinceStartFactName;
    static const char* _altitudeASLFactName;
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
    static const char* _satellitesFactName;
    static const char* _hDOPFactName;
    static const char* _dataQualityFactName;

private:
    Fact _droneSerialFact;
    Fact _filenameFact;
    Fact _messageVersionFact;
    Fact _dronePoweredAgeFact;
    Fact _droneArmedAgeFact;
    Fact _rawDataFilenameFact;
    Fact _unixStartTimeFact;
    Fact _groundWindSpeedFact;
    Fact _groundWindDirectionFact;
    Fact _groundAirTemperatureFact;
    Fact _groundHumidityFact;
    Fact _groundPressureFact;
    Fact _homePositionLatitudeFact;
    Fact _homePositionLongitudeFact;
    Fact _homePositionAltitudeFact;
    Fact _uTCDateFact;
    Fact _uTCTimeFact;
    Fact _timeSinceStartFact;
    Fact _altitudeASLFact;
    Fact _pressureFact;
    Fact _airTempFact;
    Fact _relHumFact;
    Fact _windSpeedFact;
    Fact _windDirectionFact;
    Fact _latitudeFact;
    Fact _longitudeFact;
    Fact _rollFact;
    Fact _rollRateFact;
    Fact _pitchFact;
    Fact _pitchRateFact;
    Fact _yawFact;
    Fact _yawRateFact;
    Fact _ascentRateFact;
    Fact _speedOverGroundFact;
    Fact _satellitesFact;
    Fact _hDOPFact;
    Fact _dataQualityFact;
};

#endif // MESSAGETIMEFACTGROUP_H
