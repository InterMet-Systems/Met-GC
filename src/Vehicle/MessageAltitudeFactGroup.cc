#include "MessageAltitudeFactGroup.h"

const char* MessageAltitudeFactGroup::_droneSerialFactName =              "droneSerial";
const char* MessageAltitudeFactGroup::_yearFactName =                     "year";
const char* MessageAltitudeFactGroup::_monthFactName =                    "month";
const char* MessageAltitudeFactGroup::_dayFactName =                      "day";
const char* MessageAltitudeFactGroup::_hourFactName =                     "hour";
const char* MessageAltitudeFactGroup::_minuteFactName =                   "minute";
const char* MessageAltitudeFactGroup::_secondFactName =                   "second";
const char* MessageAltitudeFactGroup::_stringFactName =                   "string";
const char* MessageAltitudeFactGroup::_messageVersionFactName =           "messageVersion";
const char* MessageAltitudeFactGroup::_dronePoweredAgeFactName =          "dronePoweredAge";
const char* MessageAltitudeFactGroup::_droneArmedAgeFactName =            "droneArmedAge";
const char* MessageAltitudeFactGroup::_rawDataFilenameFactName =          "rawDataFilename";
const char* MessageAltitudeFactGroup::_unixStartTimeFactName =            "unixStartTime";
const char* MessageAltitudeFactGroup::_groundWindSpeedFactName =          "groundWindSpeed";
const char* MessageAltitudeFactGroup::_groundWindDirectionFactName =      "groundWindDirection";
const char* MessageAltitudeFactGroup::_groundAirTemperatureFactName =     "groundAirTemperature";
const char* MessageAltitudeFactGroup::_groundHumidityFactName =           "groundHumidity";
const char* MessageAltitudeFactGroup::_groundPressureFactName =           "groundPressure";
const char* MessageAltitudeFactGroup::_homePositionLatitudeFactName =     "homePositionLatitude";
const char* MessageAltitudeFactGroup::_homePositionLongitudeFactName =    "homePositionLongitude";
const char* MessageAltitudeFactGroup::_homePositionAltitudeFactName =     "homePositionAltitude";
const char* MessageAltitudeFactGroup::_altitudeASLFactName =              "altitudeASL";
const char* MessageAltitudeFactGroup::_uTCDateFactName =                  "uTCDate";
const char* MessageAltitudeFactGroup::_uTCTimeFactName =                  "uTCTime";
const char* MessageAltitudeFactGroup::_timeSinceStartFactName =           "timeSinceStart";
const char* MessageAltitudeFactGroup::_pressureFactName =                 "pressure";
const char* MessageAltitudeFactGroup::_airTempFactName =                  "airTemp";
const char* MessageAltitudeFactGroup::_relHumFactName =                   "relHum";
const char* MessageAltitudeFactGroup::_windSpeedFactName =                "windSpeed";
const char* MessageAltitudeFactGroup::_windDirectionFactName =            "windDirection";
const char* MessageAltitudeFactGroup::_latitudeFactName =                 "latitude";
const char* MessageAltitudeFactGroup::_longitudeFactName =                "longitude";
const char* MessageAltitudeFactGroup::_rollFactName =                     "roll";
const char* MessageAltitudeFactGroup::_rollRateFactName =                 "rollRate";
const char* MessageAltitudeFactGroup::_pitchFactName =                    "pitch";
const char* MessageAltitudeFactGroup::_pitchRateFactName =                "pitchRate";
const char* MessageAltitudeFactGroup::_yawFactName =                      "yaw";
const char* MessageAltitudeFactGroup::_yawRateFactName =                  "yawRate";
const char* MessageAltitudeFactGroup::_ascentRateFactName =               "ascentRate";
const char* MessageAltitudeFactGroup::_speedOverGroundFactName =          "speedOverGround";
const char* MessageAltitudeFactGroup::_satellitesFactName =               "satellites";
const char* MessageAltitudeFactGroup::_hDOPFactName =                     "hDOP";
const char* MessageAltitudeFactGroup::_dataQualityFactName =              "dataQuality";

MessageAltitudeFactGroup::MessageAltitudeFactGroup(QObject* parent)
    : FactGroup(1000, ":/path.json", parent, true)
    ,_droneSerialFact             (0, _droneSerialFactName,             FactMetaData::valueTypeInt32)
    ,_yearFact                    (0, _yearFactName,                    FactMetaData::valueTypeUint16)
    ,_monthFact                   (0, _monthFactName,                   FactMetaData::valueTypeUint8)
    ,_dayFact                     (0, _dayFactName,                     FactMetaData::valueTypeUint8)
    ,_hourFact                    (0, _hourFactName,                    FactMetaData::valueTypeUint8)
    ,_minuteFact                  (0, _minuteFactName,                  FactMetaData::valueTypeUint8)
    ,_secondFact                  (0, _secondFactName,                  FactMetaData::valueTypeUint8)
    ,_stringFact                  (0, _stringFactName,                  FactMetaData::valueTypeString)
    ,_messageVersionFact          (0, _messageVersionFactName,          FactMetaData::valueTypeString)
    ,_dronePoweredAgeFact         (0, _dronePoweredAgeFactName,         FactMetaData::valueTypeInt32)
    ,_droneArmedAgeFact           (0, _droneArmedAgeFactName,           FactMetaData::valueTypeInt32)
    ,_rawDataFilenameFact         (0, _rawDataFilenameFactName,         FactMetaData::valueTypeString)
    ,_unixStartTimeFact           (0, _unixStartTimeFactName,           FactMetaData::valueTypeUint64)
    ,_groundWindSpeedFact         (0, _groundWindSpeedFactName,         FactMetaData::valueTypeDouble)
    ,_groundWindDirectionFact     (0, _groundWindDirectionFactName,     FactMetaData::valueTypeInt32)
    ,_groundAirTemperatureFact    (0, _groundAirTemperatureFactName,    FactMetaData::valueTypeDouble)
    ,_groundHumidityFact          (0, _groundHumidityFactName,          FactMetaData::valueTypeDouble)
    ,_groundPressureFact          (0, _groundPressureFactName,          FactMetaData::valueTypeDouble)
    ,_homePositionLatitudeFact    (0, _homePositionLatitudeFactName,    FactMetaData::valueTypeDouble)
    ,_homePositionLongitudeFact   (0, _homePositionLongitudeFactName,   FactMetaData::valueTypeDouble)
    ,_homePositionAltitudeFact    (0, _homePositionAltitudeFactName,    FactMetaData::valueTypeDouble)
    ,_altitudeASLFact             (0, _altitudeASLFactName,             FactMetaData::valueTypeDouble)
    ,_uTCDateFact                 (0, _uTCDateFactName,                 FactMetaData::valueTypeString)
    ,_uTCTimeFact                 (0, _uTCTimeFactName,                 FactMetaData::valueTypeString)
    ,_timeSinceStartFact          (0, _timeSinceStartFactName,          FactMetaData::valueTypeDouble)
    ,_pressureFact                (0, _pressureFactName,                FactMetaData::valueTypeDouble)
    ,_airTempFact                 (0, _airTempFactName,                 FactMetaData::valueTypeDouble)
    ,_relHumFact                  (0, _relHumFactName,                  FactMetaData::valueTypeDouble)
    ,_windSpeedFact               (0, _windSpeedFactName,               FactMetaData::valueTypeDouble)
    ,_windDirectionFact           (0, _windDirectionFactName,           FactMetaData::valueTypeInt32)
    ,_latitudeFact                (0, _latitudeFactName,                FactMetaData::valueTypeDouble)
    ,_longitudeFact               (0, _longitudeFactName,               FactMetaData::valueTypeDouble)
    ,_rollFact                    (0, _rollFactName,                    FactMetaData::valueTypeDouble)
    ,_rollRateFact                (0, _rollRateFactName,                FactMetaData::valueTypeDouble)
    ,_pitchFact                   (0, _pitchFactName,                   FactMetaData::valueTypeDouble)
    ,_pitchRateFact               (0, _pitchRateFactName,               FactMetaData::valueTypeDouble)
    ,_yawFact                     (0, _yawFactName,                     FactMetaData::valueTypeDouble)
    ,_yawRateFact                 (0, _yawRateFactName,                 FactMetaData::valueTypeDouble)
    ,_ascentRateFact              (0, _ascentRateFactName,              FactMetaData::valueTypeDouble)
    ,_speedOverGroundFact         (0, _speedOverGroundFactName,         FactMetaData::valueTypeDouble)
    ,_satellitesFact              (0, _satellitesFactName,              FactMetaData::valueTypeUint8)
    ,_hDOPFact                    (0, _hDOPFactName,                    FactMetaData::valueTypeDouble)
    ,_dataQualityFact             (0, _dataQualityFactName,             FactMetaData::valueTypeInt32)
{
    _addFact(&_droneSerialFact             , _droneSerialFactName             );
    _addFact(&_yearFact                    , _yearFactName                    );
    _addFact(&_monthFact                   , _monthFactName                   );
    _addFact(&_dayFact                     , _dayFactName                     );
    _addFact(&_hourFact                    , _hourFactName                    );
    _addFact(&_minuteFact                  , _minuteFactName                  );
    _addFact(&_secondFact                  , _secondFactName                  );
    _addFact(&_stringFact                  , _stringFactName                  );
    _addFact(&_messageVersionFact          , _messageVersionFactName          );
    _addFact(&_dronePoweredAgeFact         , _dronePoweredAgeFactName         );
    _addFact(&_droneArmedAgeFact           , _droneArmedAgeFactName           );
    _addFact(&_rawDataFilenameFact         , _rawDataFilenameFactName         );
    _addFact(&_unixStartTimeFact           , _unixStartTimeFactName           );
    _addFact(&_groundWindSpeedFact         , _groundWindSpeedFactName         );
    _addFact(&_groundWindDirectionFact     , _groundWindDirectionFactName     );
    _addFact(&_groundAirTemperatureFact    , _groundAirTemperatureFactName    );
    _addFact(&_groundHumidityFact          , _groundHumidityFactName          );
    _addFact(&_groundPressureFact          , _groundPressureFactName          );
    _addFact(&_homePositionLatitudeFact    , _homePositionLatitudeFactName    );
    _addFact(&_homePositionLongitudeFact   , _homePositionLongitudeFactName   );
    _addFact(&_homePositionAltitudeFact    , _homePositionAltitudeFactName    );
    _addFact(&_altitudeASLFact             , _altitudeASLFactName             );
    _addFact(&_uTCDateFact                 , _uTCDateFactName                 );
    _addFact(&_uTCTimeFact                 , _uTCTimeFactName                 );
    _addFact(&_timeSinceStartFact          , _timeSinceStartFactName          );
    _addFact(&_pressureFact                , _pressureFactName                );
    _addFact(&_airTempFact                 , _airTempFactName                 );
    _addFact(&_relHumFact                  , _relHumFactName                  );
    _addFact(&_windSpeedFact               , _windSpeedFactName               );
    _addFact(&_windDirectionFact           , _windDirectionFactName           );
    _addFact(&_latitudeFact                , _latitudeFactName                );
    _addFact(&_longitudeFact               , _longitudeFactName               );
    _addFact(&_rollFact                    , _rollFactName                    );
    _addFact(&_rollRateFact                , _rollRateFactName                );
    _addFact(&_pitchFact                   , _pitchFactName                   );
    _addFact(&_pitchRateFact               , _pitchRateFactName               );
    _addFact(&_yawFact                     , _yawFactName                     );
    _addFact(&_yawRateFact                 , _yawRateFactName                 );
    _addFact(&_ascentRateFact              , _ascentRateFactName              );
    _addFact(&_speedOverGroundFact         , _speedOverGroundFactName         );
    _addFact(&_satellitesFact              , _satellitesFactName              );
    _addFact(&_hDOPFact                    , _hDOPFactName                    );
    _addFact(&_dataQualityFact             , _dataQualityFactName             );

    _SRNFact                        .setRawValue(std::numeric_limits<int32_t>::max());
    _YYYYFact                       .setRawValue(std::numeric_limits<uint16_t>::max());
    _MMFact                         .setRawValue(std::numeric_limits<uint8_t>::max());
    _DDFact                         .setRawValue(std::numeric_limits<uint8_t>::max());
    _HHFact                         .setRawValue(std::numeric_limits<uint8_t>::max());
    _MmFact                         .setRawValue(std::numeric_limits<uint8_t>::max());
    _ssFact                         .setRawValue(std::numeric_limits<uint8_t>::max());
    _StringFact                     .setRawValue(QVariant(""));
    _Message_VersionFact            .setRawValue(QVariant("1.0.0"));
    _Drone_Powered_AgeFact          .setRawValue(std::numeric_limits<int32_t>::max());
    _Drone_Armed_AgeFact            .setRawValue(std::numeric_limits<int32_t>::max());
    _Raw_Data_FilenameFact          .setRawValue(QVariant(""));
    _Unix_Start_TimeFact            .setRawValue(std::numeric_limits<uint64_t>::max());
    _Ground_Wind_SpeedFact          .setRawValue(qQNaN());
    _Ground_Wind_DirectionFact      .setRawValue(std::numeric_limits<int32_t>::max());
    _Ground_Air_TemperatureFact     .setRawValue(qQNaN());
    _Ground_HumidityFact            .setRawValue(qQNaN());
    _Ground_PressureFact            .setRawValue(qQNaN());
    _Home_Position_LatitudeFact     .setRawValue(qQNaN());
    _Home_Position_LongitudeFact    .setRawValue(qQNaN());
    _Home_Position_AltitudeFact     .setRawValue(qQNaN());
    _Altitude_ASLFact               .setRawValue(qQNaN());
    _UTC_DateFact                   .setRawValue(QVariant(""));
    _UTC_TimeFact                   .setRawValue(QVariant(""));
    _Time_Since_StartFact           .setRawValue(qQNaN());
    _PressureFact                   .setRawValue(qQNaN());
    _Air_TempFact                   .setRawValue(qQNaN());
    _Rel_HumFact                    .setRawValue(qQNaN());
    _Wind_SpeedFact                 .setRawValue(qQNaN());
    _Wind_DirectionFact             .setRawValue(std::numeric_limits<int32_t>::max());
    _LatitudeFact                   .setRawValue(qQNaN());
    _LongitudeFact                  .setRawValue(qQNaN());
    _RollFact                       .setRawValue(qQNaN());
    _Roll_RateFact                  .setRawValue(qQNaN());
    _PitchFact                      .setRawValue(qQNaN());
    _Pitch_RateFact                 .setRawValue(qQNaN());
    _YawFact                        .setRawValue(qQNaN());
    _Yaw_RateFact                   .setRawValue(qQNaN());
    _Ascent_RateFact                .setRawValue(qQNaN());
    _Speed_Over_GroundFact          .setRawValue(qQNaN());
    _SatellitesFact                 .setRawValue(std::numeric_limits<uint8_t>::max());
    _HDOPFact                       .setRawValue(qQNaN());
    _Data_QualityFact               .setRawValue(std::numeric_limits<int32_t>::max());
}
