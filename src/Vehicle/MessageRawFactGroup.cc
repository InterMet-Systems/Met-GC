#include "MessageRawFactGroup.h"

const char* MessageRawFactGroup::_timeUnixSecondsFactName                   = "timeUnixSeconds";
const char* MessageRawFactGroup::_altitudeMetersASLFactName                 = "altitudeMetersASL";
const char* MessageRawFactGroup::_absolutePressureMillibarsFactName         = "absolutePressureMillibars";
const char* MessageRawFactGroup::_temperature0CelsiusFactName               = "temperature0Celsius";
const char* MessageRawFactGroup::_temperature1CelsiusFactName               = "temperature1Celsius";
const char* MessageRawFactGroup::_temperature2CelsiusFactName               = "temperature2Celsius";
const char* MessageRawFactGroup::_relativeHumidity0FactName                 = "relativeHumidity0";
const char* MessageRawFactGroup::_relativeHumidity1FactName                 = "relativeHumidity1";
const char* MessageRawFactGroup::_relativeHumidity2FactName                 = "relativeHumidity2";
const char* MessageRawFactGroup::_latitudeDegreesFactName                   = "latitudeDegrees";
const char* MessageRawFactGroup::_longitudeDegreesFactName                  = "longitudeDegrees";
const char* MessageRawFactGroup::_rollDegreesFactName                       = "rollDegrees";
const char* MessageRawFactGroup::_pitchDegreesFactName                      = "pitchDegrees";
const char* MessageRawFactGroup::_yawDegreesFactName                        = "yawDegrees";
const char* MessageRawFactGroup::_rollRateDegreesPerSecondFactName          = "rollRateDegreesPerSecond";
const char* MessageRawFactGroup::_pitchRateDegreesPerSecondFactName         = "pitchRateDegreesPerSecond";
const char* MessageRawFactGroup::_yawRateDegreesPerSecondFactName           = "yawRateDegreesPerSecond";
const char* MessageRawFactGroup::_xVelocityMetersPerSecondFactName          = "xVelocityMetersPerSecond";
const char* MessageRawFactGroup::_yVelocityMetersPerSecondFactName          = "yVelocityMetersPerSecond";
const char* MessageRawFactGroup::_zVelocityMetersPerSecondFactName          = "zVelocityMetersPerSecond";
const char* MessageRawFactGroup::_customModeHeartbeatFactName               = "customModeHeartbeat";
const char* MessageRawFactGroup::_dataQualityFactName                       = "dataQuality";
const char* MessageRawFactGroup::_homePositionLatitudeDegreesFactName       = "homePositionLatitudeDegrees";
const char* MessageRawFactGroup::_homePositionLongitudeDegreesFactName      = "homePositionLongitudeDegrees";
const char* MessageRawFactGroup::_homePositionAltitudeMetersFactName        = "homePositionAltitudeMeters";
const char* MessageRawFactGroup::_droneSerialNumberFactName                 = "droneSerialNumber";
const char* MessageRawFactGroup::_groundWindSpeedMetersPerSecondFactName    = "groundWindSpeedMetersPerSecond";
const char* MessageRawFactGroup::_groundWindDirectionDegreesFactName        = "groundWindDirectionDegrees";
const char* MessageRawFactGroup::_groundAirTemperatureCelsiusFactName       = "groundAirTemperatureCelsius";
const char* MessageRawFactGroup::_groundHumidityFactName                    = "groundHumidity";
const char* MessageRawFactGroup::_groundPressureMillibarsFactName           = "groundPressureMillibars";
const char* MessageRawFactGroup::_poweredAgeSecondsFactName                 = "poweredAgeSeconds";
const char* MessageRawFactGroup::_armedAgeSecondsFactName                   = "armedAgeSeconds";
const char* MessageRawFactGroup::_satellitesFactName                        = "satellites";
const char* MessageRawFactGroup::_horizontalDilutionOfPositionFloatFactName = "horizontalDilutionOfPositionFloat";
const char* MessageRawFactGroup::_filenameFactName                          = "filename";

MessageRawFactGroup::MessageRawFactGroup(QObject* parent)
    : FactGroup(1000, ":/path.json", parent, true)
    ,_timeUnixSecondsFact                   (0, _timeUnixSecondsFactName                    , FactMetaData::valueTypeDouble)
    ,_altitudeMetersASLFact                 (0, _altitudeMetersASLFactName                  , FactMetaData::valueTypeDouble)
    ,_absolutePressureMillibarsFact         (0, _absolutePressureMillibarsFactName          , FactMetaData::valueTypeDouble)
    ,_temperature0CelsiusFact               (0, _temperature0CelsiusFactName                , FactMetaData::valueTypeDouble)
    ,_temperature1CelsiusFact               (0, _temperature1CelsiusFactName                , FactMetaData::valueTypeDouble)
    ,_temperature2CelsiusFact               (0, _temperature2CelsiusFactName                , FactMetaData::valueTypeDouble)
    ,_relativeHumidity0Fact                 (0, _relativeHumidity0FactName                  , FactMetaData::valueTypeDouble)
    ,_relativeHumidity1Fact                 (0, _relativeHumidity1FactName                  , FactMetaData::valueTypeDouble)
    ,_relativeHumidity2Fact                 (0, _relativeHumidity2FactName                  , FactMetaData::valueTypeDouble)
    ,_latitudeDegreesFact                   (0, _latitudeDegreesFactName                    , FactMetaData::valueTypeDouble)
    ,_longitudeDegreesFact                  (0, _longitudeDegreesFactName                   , FactMetaData::valueTypeDouble)
    ,_rollDegreesFact                       (0, _rollDegreesFactName                        , FactMetaData::valueTypeDouble)
    ,_pitchDegreesFact                      (0, _pitchDegreesFactName                       , FactMetaData::valueTypeDouble)
    ,_yawDegreesFact                        (0, _yawDegreesFactName                         , FactMetaData::valueTypeDouble)
    ,_rollRateDegreesPerSecondFact          (0, _rollRateDegreesPerSecondFactName           , FactMetaData::valueTypeDouble)
    ,_pitchRateDegreesPerSecondFact         (0, _pitchRateDegreesPerSecondFactName          , FactMetaData::valueTypeDouble)
    ,_yawRateDegreesPerSecondFact           (0, _yawRateDegreesPerSecondFactName            , FactMetaData::valueTypeDouble)
    ,_xVelocityMetersPerSecondFact          (0, _xVelocityMetersPerSecondFactName           , FactMetaData::valueTypeDouble)
    ,_yVelocityMetersPerSecondFact          (0, _yVelocityMetersPerSecondFactName           , FactMetaData::valueTypeDouble)
    ,_zVelocityMetersPerSecondFact          (0, _zVelocityMetersPerSecondFactName           , FactMetaData::valueTypeDouble)
    ,_customModeHeartbeatFact               (0, _customModeHeartbeatFactName                , FactMetaData::valueTypeUint32)
    ,_dataQualityFact                       (0, _dataQualityFactName                        , FactMetaData::valueTypeInt32)
    ,_homePositionLatitudeDegreesFact       (0, _homePositionLatitudeDegreesFactName        , FactMetaData::valueTypeDouble)
    ,_homePositionLongitudeDegreesFact      (0, _homePositionLongitudeDegreesFactName       , FactMetaData::valueTypeDouble)
    ,_homePositionAltitudeMetersFact        (0, _homePositionAltitudeMetersFactName         , FactMetaData::valueTypeDouble)
    ,_droneSerialNumberFact                 (0, _droneSerialNumberFactName                  , FactMetaData::valueTypeInt32)
    ,_groundWindSpeedMetersPerSecondFact    (0, _groundWindSpeedMetersPerSecondFactName     , FactMetaData::valueTypeDouble)
    ,_groundWindDirectionDegreesFact        (0, _groundWindDirectionDegreesFactName         , FactMetaData::valueTypeInt32)
    ,_groundAirTemperatureCelsiusFact       (0, _groundAirTemperatureCelsiusFactName        , FactMetaData::valueTypeDouble)
    ,_groundHumidityFact                    (0, _groundHumidityFactName                     , FactMetaData::valueTypeDouble)
    ,_groundPressureMillibarsFact           (0, _groundPressureMillibarsFactName            , FactMetaData::valueTypeDouble)
    ,_poweredAgeSecondsFact                 (0, _poweredAgeSecondsFactName                  , FactMetaData::valueTypeInt32)
    ,_armedAgeSecondsFact                   (0, _armedAgeSecondsFactName                    , FactMetaData::valueTypeInt32)
    ,_satellitesFact                        (0, _satellitesFactName                         , FactMetaData::valueTypeUint8)
    ,_horizontalDilutionOfPositionFloatFact (0, _horizontalDilutionOfPositionFloatFactName  , FactMetaData::valueTypeDouble)
    ,_filenameFact                          (0, _filenameFactName                           , FactMetaData::valueTypeString)
{
    _addFact(&_timeUnixSecondsFact                  , _timeUnixSecondsFactName                  );
    _addFact(&_altitudeMetersASLFact                , _altitudeMetersASLFactName                );
    _addFact(&_absolutePressureMillibarsFact        , _absolutePressureMillibarsFactName        );
    _addFact(&_temperature0CelsiusFact              , _temperature0CelsiusFactName              );
    _addFact(&_temperature1CelsiusFact              , _temperature1CelsiusFactName              );
    _addFact(&_temperature2CelsiusFact              , _temperature2CelsiusFactName              );
    _addFact(&_relativeHumidity0Fact                , _relativeHumidity0FactName                );
    _addFact(&_relativeHumidity1Fact                , _relativeHumidity1FactName                );
    _addFact(&_relativeHumidity2Fact                , _relativeHumidity2FactName                );
    _addFact(&_latitudeDegreesFact                  , _latitudeDegreesFactName                  );
    _addFact(&_longitudeDegreesFact                 , _longitudeDegreesFactName                 );
    _addFact(&_rollDegreesFact                      , _rollDegreesFactName                      );
    _addFact(&_pitchDegreesFact                     , _pitchDegreesFactName                     );
    _addFact(&_yawDegreesFact                       , _yawDegreesFactName                       );
    _addFact(&_rollRateDegreesPerSecondFact         , _rollRateDegreesPerSecondFactName         );
    _addFact(&_pitchRateDegreesPerSecondFact        , _pitchRateDegreesPerSecondFactName        );
    _addFact(&_yawRateDegreesPerSecondFact          , _yawRateDegreesPerSecondFactName          );
    _addFact(&_xVelocityMetersPerSecondFact         , _xVelocityMetersPerSecondFactName         );
    _addFact(&_yVelocityMetersPerSecondFact         , _yVelocityMetersPerSecondFactName         );
    _addFact(&_zVelocityMetersPerSecondFact         , _zVelocityMetersPerSecondFactName         );
    _addFact(&_customModeHeartbeatFact              , _customModeHeartbeatFactName              );
    _addFact(&_dataQualityFact                      , _dataQualityFactName                      );
    _addFact(&_homePositionLatitudeDegreesFact      , _homePositionLatitudeDegreesFactName      );
    _addFact(&_homePositionLongitudeDegreesFact     , _homePositionLongitudeDegreesFactName     );
    _addFact(&_homePositionAltitudeMetersFact       , _homePositionAltitudeMetersFactName       );
    _addFact(&_droneSerialNumberFact                , _droneSerialNumberFactName                );
    _addFact(&_groundWindSpeedMetersPerSecondFact   , _groundWindSpeedMetersPerSecondFactName   );
    _addFact(&_groundWindDirectionDegreesFact       , _groundWindDirectionDegreesFactName       );
    _addFact(&_groundAirTemperatureCelsiusFact      , _groundAirTemperatureCelsiusFactName      );
    _addFact(&_groundHumidityFact                   , _groundHumidityFactName                   );
    _addFact(&_groundPressureMillibarsFact          , _groundPressureMillibarsFactName          );
    _addFact(&_poweredAgeSecondsFact                , _poweredAgeSecondsFactName                );
    _addFact(&_armedAgeSecondsFact                  , _armedAgeSecondsFactName                  );
    _addFact(&_satellitesFact                       , _satellitesFactName                       );
    _addFact(&_horizontalDilutionOfPositionFloatFact, _horizontalDilutionOfPositionFloatFactName);
    _addFact(&_filenameFact                         , _filenameFactName                         );

    _timeUnixSecondsFact                            .setRawValue(qQNaN());
    _altitudeMetersASLFact                          .setRawValue(qQNaN());
    _absolutePressureMillibarsFact                  .setRawValue(qQNaN());
    _temperature0CelsiusFact                        .setRawValue(qQNaN());
    _temperature1CelsiusFact                        .setRawValue(qQNaN());
    _temperature2CelsiusFact                        .setRawValue(qQNaN());
    _relativeHumidity0Fact                          .setRawValue(qQNaN());
    _relativeHumidity1Fact                          .setRawValue(qQNaN());
    _relativeHumidity2Fact                          .setRawValue(qQNaN());
    _latitudeDegreesFact                            .setRawValue(qQNaN());
    _longitudeDegreesFact                           .setRawValue(qQNaN());
    _rollDegreesFact                                .setRawValue(qQNaN());
    _pitchDegreesFact                               .setRawValue(qQNaN());
    _yawDegreesFact                                 .setRawValue(qQNaN());
    _rollRateDegreesPerSecondFact                   .setRawValue(qQNaN());
    _pitchRateDegreesPerSecondFact                  .setRawValue(qQNaN());
    _yawRateDegreesPerSecondFact                    .setRawValue(qQNaN());
    _xVelocityMetersPerSecondFact                   .setRawValue(qQNaN());
    _yVelocityMetersPerSecondFact                   .setRawValue(qQNaN());
    _zVelocityMetersPerSecondFact                   .setRawValue(qQNaN());
    _customModeHeartbeatFact                        .setRawValue(std::numeric_limits<uint32_t>::max());
    _dataQualityFact                                .setRawValue(QVariant(0));
    _homePositionLatitudeDegreesFact                .setRawValue(QVariant(0.));
    _homePositionLongitudeDegreesFact               .setRawValue(QVariant(0.));
    _homePositionAltitudeMetersFact                 .setRawValue(QVariant(0.));
    _droneSerialNumberFact                          .setRawValue(QVariant(0));
    _groundWindSpeedMetersPerSecondFact             .setRawValue(QVariant(0.));
    _groundWindDirectionDegreesFact                 .setRawValue(QVariant(0));
    _groundAirTemperatureCelsiusFact                .setRawValue(QVariant(0.));
    _groundHumidityFact                             .setRawValue(QVariant(0.));
    _groundPressureMillibarsFact                    .setRawValue(QVariant(0.));
    _poweredAgeSecondsFact                          .setRawValue(QVariant(0));
    _armedAgeSecondsFact                            .setRawValue(QVariant(0));
    _satellitesFact                                 .setRawValue(std::numeric_limits<uint8_t>::max());
    _horizontalDilutionOfPositionFloatFact          .setRawValue(qQNaN());
    _filenameFact                                   .setRawValue(QVariant(""));
}
