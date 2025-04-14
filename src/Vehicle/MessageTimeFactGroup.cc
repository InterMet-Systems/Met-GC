#include "MessageTimeFactGroup.h"

const char* MessageTimeFactGroup::_droneSerialFactName =                "droneSerial";
const char* MessageTimeFactGroup::_filenameFactName =                   "filename";
const char* MessageTimeFactGroup::_messageVersionFactName =             "message version";
const char* MessageTimeFactGroup::_dronePoweredAgeFactName =            "drone power age";
const char* MessageTimeFactGroup::_droneArmedAgeFactName =              "drone armed age";
const char* MessageTimeFactGroup::_rawDataFilenameFactName =            "raw data filename";
const char* MessageTimeFactGroup::_unixStartTimeFactName =              "unix start time";
const char* MessageTimeFactGroup::_groundWindSpeedFactName =            "ground wind speed";
const char* MessageTimeFactGroup::_groundWindDirectionFactName =        "ground wind direction";
const char* MessageTimeFactGroup::_groundAirTemperatureFactName =       "ground air temperature";
const char* MessageTimeFactGroup::_groundHumidityFactName =             "ground humidity";
const char* MessageTimeFactGroup::_groundPressureFactName =             "ground pressure";
const char* MessageTimeFactGroup::_homePositionLatitudeFactName =       "home position latitude";
const char* MessageTimeFactGroup::_homePositionLongitudeFactName =      "home position longitude";
const char* MessageTimeFactGroup::_homePositionAltitudeFactName =       "home position altitude";
const char* MessageTimeFactGroup::_uTCDateFactName =                    "UTC date";
const char* MessageTimeFactGroup::_uTCTimeFactName =                    "UTC time";
const char* MessageTimeFactGroup::_timeSinceStartFactName =             "time since start";
const char* MessageTimeFactGroup::_altitudeASLFactName =                "altitude ASL";
const char* MessageTimeFactGroup::_pressureFactName =                   "pressure";
const char* MessageTimeFactGroup::_airTempFactName =                    "air temp";
const char* MessageTimeFactGroup::_relHumFactName =                     "rel hum";
const char* MessageTimeFactGroup::_windSpeedFactName =                  "wind speed";
const char* MessageTimeFactGroup::_windDirectionFactName =              "wind direction";
const char* MessageTimeFactGroup::_latitudeFactName =                   "latitude";
const char* MessageTimeFactGroup::_longitudeFactName =                  "longitude";
const char* MessageTimeFactGroup::_rollFactName =                       "roll";
const char* MessageTimeFactGroup::_rollRateFactName =                   "roll rate";
const char* MessageTimeFactGroup::_pitchFactName =                      "pitch";
const char* MessageTimeFactGroup::_pitchRateFactName =                  "pitch rate";
const char* MessageTimeFactGroup::_yawFactName =                        "yaw";
const char* MessageTimeFactGroup::_yawRateFactName =                    "yaw rate";
const char* MessageTimeFactGroup::_ascentRateFactName =                 "ascent rate";
const char* MessageTimeFactGroup::_speedOverGroundFactName =            "speed over ground";
const char* MessageTimeFactGroup::_satellitesFactName =                 "satellites";
const char* MessageTimeFactGroup::_hDOPFactName =                       "hdop";
const char* MessageTimeFactGroup::_dataQualityFactName =                "data quality";

MessageTimeFactGroup::MessageTimeFactGroup(QObject* parent)
    : FactGroup(1000, ":/json/Vehicle/TimeFact.json", parent, true)
    ,_droneSerialFact                (0, _droneSerialFactName,             FactMetaData::valueTypeInt32)
    ,_filenameFact                      (0, _filenameFactName,              FactMetaData::valueTypeString)
    ,_messageVersionFact                (0, _messageVersionFactName,        FactMetaData::valueTypeString)
    ,_dronePoweredAgeFact               (0, _dronePoweredAgeFactName,       FactMetaData::valueTypeInt32)
    ,_droneArmedAgeFact                 (0, _droneArmedAgeFactName,         FactMetaData::valueTypeInt32)
    ,_rawDataFilenameFact               (0, _rawDataFilenameFactName,       FactMetaData::valueTypeString)
    ,_unixStartTimeFact                 (0, _unixStartTimeFactName,         FactMetaData::valueTypeUint64)
    ,_groundWindSpeedFact               (0, _groundWindSpeedFactName,       FactMetaData::valueTypeDouble)
    ,_groundWindDirectionFact           (0, _groundWindDirectionFactName,   FactMetaData::valueTypeInt32)
    ,_groundAirTemperatureFact          (0, _groundAirTemperatureFactName,  FactMetaData::valueTypeDouble)
    ,_groundHumidityFact                (0, _groundHumidityFactName,        FactMetaData::valueTypeDouble)
    ,_groundPressureFact                (0, _groundPressureFactName,        FactMetaData::valueTypeDouble)
    ,_homePositionLatitudeFact          (0, _homePositionLatitudeFactName,  FactMetaData::valueTypeDouble)
    ,_homePositionLongitudeFact         (0, _homePositionLongitudeFactName, FactMetaData::valueTypeDouble)
    ,_homePositionAltitudeFact          (0, _homePositionAltitudeFactName,  FactMetaData::valueTypeDouble)
    ,_uTCDateFact                       (0, _uTCDateFactName,               FactMetaData::valueTypeString)
    ,_uTCTimeFact                       (0, _uTCTimeFactName,               FactMetaData::valueTypeString)
    ,_timeSinceStartFact                (0, _timeSinceStartFactName,        FactMetaData::valueTypeInt32)
    ,_altitudeASLFact                   (0, _altitudeASLFactName,           FactMetaData::valueTypeDouble)
    ,_pressureFact                      (0, _pressureFactName,              FactMetaData::valueTypeDouble)
    ,_airTempFact                       (0, _airTempFactName,               FactMetaData::valueTypeDouble)
    ,_relHumFact                        (0, _relHumFactName,                FactMetaData::valueTypeDouble)
    ,_windSpeedFact                     (0, _windSpeedFactName,             FactMetaData::valueTypeDouble)
    ,_windDirectionFact                 (0, _windDirectionFactName,         FactMetaData::valueTypeInt32)
    ,_latitudeFact                      (0, _latitudeFactName,              FactMetaData::valueTypeDouble)
    ,_longitudeFact                     (0, _longitudeFactName,             FactMetaData::valueTypeDouble)
    ,_rollFact                          (0, _rollFactName,                  FactMetaData::valueTypeDouble)
    ,_rollRateFact                      (0, _rollRateFactName,              FactMetaData::valueTypeDouble)
    ,_pitchFact                         (0, _pitchFactName,                 FactMetaData::valueTypeDouble)
    ,_pitchRateFact                     (0, _pitchRateFactName,             FactMetaData::valueTypeDouble)
    ,_yawFact                           (0, _yawFactName,                   FactMetaData::valueTypeDouble)
    ,_yawRateFact                       (0, _yawRateFactName,               FactMetaData::valueTypeDouble)
    ,_ascentRateFact                    (0, _ascentRateFactName,            FactMetaData::valueTypeDouble)
    ,_speedOverGroundFact               (0, _speedOverGroundFactName,       FactMetaData::valueTypeDouble)
    ,_satellitesFact                    (0, _satellitesFactName,            FactMetaData::valueTypeUint16)
    ,_hDOPFact                          (0, _hDOPFactName,                  FactMetaData::valueTypeDouble)
    ,_dataQualityFact                   (0, _dataQualityFactName,           FactMetaData::valueTypeInt32)
{
    _addFact(&_droneSerialFact             , _droneSerialFactName             );
    _addFact(&_filenameFact                , _filenameFactName                );
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
    _addFact(&_uTCDateFact                 , _uTCDateFactName                 );
    _addFact(&_uTCTimeFact                 , _uTCTimeFactName                 );
    _addFact(&_timeSinceStartFact          , _timeSinceStartFactName          );
    _addFact(&_altitudeASLFact             , _altitudeASLFactName             );
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

    _droneSerialFact              .setRawValue(std::numeric_limits<int32_t>::max());
    _filenameFact                 .setRawValue(QVariant(""));
    _messageVersionFact           .setRawValue(QVariant("1.0.0"));
    _dronePoweredAgeFact          .setRawValue(std::numeric_limits<int32_t>::max());
    _droneArmedAgeFact            .setRawValue(std::numeric_limits<int32_t>::max());
    _rawDataFilenameFact          .setRawValue(QVariant(""));
    _unixStartTimeFact            .setRawValue(std::numeric_limits<uint64_t>::max());
    _groundWindSpeedFact          .setRawValue(qQNaN());
    _groundWindDirectionFact      .setRawValue(std::numeric_limits<int32_t>::max());
    _groundAirTemperatureFact     .setRawValue(qQNaN());
    _groundHumidityFact           .setRawValue(qQNaN());
    _groundPressureFact           .setRawValue(qQNaN());
    _homePositionLatitudeFact     .setRawValue(qQNaN());
    _homePositionLongitudeFact    .setRawValue(qQNaN());
    _homePositionAltitudeFact     .setRawValue(qQNaN());
    _uTCDateFact                  .setRawValue(QVariant(""));
    _uTCTimeFact                  .setRawValue(QVariant(""));
    _timeSinceStartFact           .setRawValue(std::numeric_limits<int32_t>::max());
    _altitudeASLFact              .setRawValue(qQNaN());
    _pressureFact                 .setRawValue(qQNaN());
    _airTempFact                  .setRawValue(qQNaN());
    _relHumFact                   .setRawValue(qQNaN());
    _windSpeedFact                .setRawValue(qQNaN());
    _windDirectionFact            .setRawValue(std::numeric_limits<int32_t>::max());
    _latitudeFact                 .setRawValue(qQNaN());
    _longitudeFact                .setRawValue(qQNaN());
    _rollFact                     .setRawValue(qQNaN());
    _rollRateFact                 .setRawValue(qQNaN());
    _pitchFact                    .setRawValue(qQNaN());
    _pitchRateFact                .setRawValue(qQNaN());
    _yawFact                      .setRawValue(qQNaN());
    _yawRateFact                  .setRawValue(qQNaN());
    _ascentRateFact               .setRawValue(qQNaN());
    _speedOverGroundFact          .setRawValue(qQNaN());
    _satellitesFact               .setRawValue(std::numeric_limits<uint16_t>::max());
    _hDOPFact                     .setRawValue(qQNaN());
    _dataQualityFact              .setRawValue(std::numeric_limits<int32_t>::max());
}
