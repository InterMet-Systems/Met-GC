#include "MessageRawFactGroup.h"

const char* MessageRawFactGroup::_timeUnixSecondsName                   = "timeUnixSeconds";
const char* MessageRawFactGroup::_altitudeMetersASLName                 = "altitudeMetersASL";
const char* MessageRawFactGroup::_absolutePressureMillibarsName         = "absolutePressureMillibars";
const char* MessageRawFactGroup::_temperature0CelsiusName               = "temperature0Celsius";
const char* MessageRawFactGroup::_temperature1CelsiusName               = "temperature1Celsius";
const char* MessageRawFactGroup::_temperature2CelsiusName               = "temperature2Celsius";
const char* MessageRawFactGroup::_relativeHumidity0Name                 = "relativeHumidity0";
const char* MessageRawFactGroup::_relativeHumidity1Name                 = "relativeHumidity1";
const char* MessageRawFactGroup::_relativeHumidity2Name                 = "relativeHumidity2";
const char* MessageRawFactGroup::_latitudeDegreesName                   = "latitudeDegrees";
const char* MessageRawFactGroup::_longitudeDegreesName                  = "longitudeDegrees";
const char* MessageRawFactGroup::_rollDegreesName                       = "rollDegrees";
const char* MessageRawFactGroup::_pitchDegreesName                      = "pitchDegrees";
const char* MessageRawFactGroup::_yawDegreesName                        = "yawDegrees";
const char* MessageRawFactGroup::_rollRateDegreesPerSecondName          = "rollRateDegreesPerSecond";
const char* MessageRawFactGroup::_pitchRateDegreesPerSecondName         = "pitchRateDegreesPerSecond";
const char* MessageRawFactGroup::_yawRateDegreesPerSecondName           = "yawRateDegreesPerSecond";
const char* MessageRawFactGroup::_xVelocityMetersPerSecondName          = "xVelocityMetersPerSecond";
const char* MessageRawFactGroup::_yVelocityMetersPerSecondName          = "yVelocityMetersPerSecond";
const char* MessageRawFactGroup::_zVelocityMetersPerSecondName          = "zVelocityMetersPerSecond";
const char* MessageRawFactGroup::_customModeHeartbeatName               = "customModeHeartbeat";
const char* MessageRawFactGroup::_dataQualityName                       = "dataQuality";
const char* MessageRawFactGroup::_homePositionLatitudeDegreesName       = "homePositionLatitudeDegrees";
const char* MessageRawFactGroup::_homePositionLongitudeDegreesName      = "homePositionLongitudeDegrees";
const char* MessageRawFactGroup::_homePositionAltitudeMetersName        = "homePositionAltitudeMeters";
const char* MessageRawFactGroup::_droneSerialNumberName                 = "droneSerialNumber";
const char* MessageRawFactGroup::_groundWindSpeedMetersPerSecondName    = "groundWindSpeedMetersPerSecond";
const char* MessageRawFactGroup::_groundWindDirectionDegreesName        = "groundWindDirectionDegrees";
const char* MessageRawFactGroup::_groundAirTemperatureCelsiusName       = "groundAirTemperatureCelsius";
const char* MessageRawFactGroup::_groundHumidityName                    = "groundHumidity";
const char* MessageRawFactGroup::_groundPressureMillibarsName           = "groundPressureMillibars";
const char* MessageRawFactGroup::_poweredAgeSecondsName                 = "poweredAgeSeconds";
const char* MessageRawFactGroup::_armedAgeSecondsName                   = "armedAgeSeconds";
const char* MessageRawFactGroup::_satellitesName                        = "satellites";
const char* MessageRawFactGroup::_horizontalDilutionOfPositionFloatName = "horizontalDilutionOfPositionFloat";
const char* MessageRawFactGroup::_filenameName                          = "filename";

MessageRawFactGroup::MessageRawFactGroup(QObject* parent)
    : FactGroup(1000, ":/path.json", parent, true)
    ,_timeUnixSecondsFact                   (0, _timeUnixSecondsName                    , FactMetaData::valueTypeDouble)
    ,_altitudeMetersASLFact                 (0, _altitudeMetersASLName                  , FactMetaData::valueTypeDouble)
    ,_absolutePressureMillibarsFact         (0, _absolutePressureMillibarsName          , FactMetaData::valueTypeDouble)
    ,_temperature0CelsiusFact               (0, _temperature0CelsiusName                , FactMetaData::valueTypeDouble)
    ,_temperature1CelsiusFact               (0, _temperature1CelsiusName                , FactMetaData::valueTypeDouble)
    ,_temperature2CelsiusFact               (0, _temperature2CelsiusName                , FactMetaData::valueTypeDouble)
    ,_relativeHumidity0Fact                 (0, _relativeHumidity0Name                  , FactMetaData::valueTypeDouble)
    ,_relativeHumidity1Fact                 (0, _relativeHumidity1Name                  , FactMetaData::valueTypeDouble)
    ,_relativeHumidity2Fact                 (0, _relativeHumidity2Name                  , FactMetaData::valueTypeDouble)
    ,_latitudeDegreesFact                   (0, _latitudeDegreesName                    , FactMetaData::valueTypeDouble)
    ,_longitudeDegreesFact                  (0, _longitudeDegreesName                   , FactMetaData::valueTypeDouble)
    ,_rollDegreesFact                       (0, _rollDegreesName                        , FactMetaData::valueTypeDouble)
    ,_pitchDegreesFact                      (0, _pitchDegreesName                       , FactMetaData::valueTypeDouble)
    ,_yawDegreesFact                        (0, _yawDegreesName                         , FactMetaData::valueTypeDouble)
    ,_rollRateDegreesPerSecondFact          (0, _rollRateDegreesPerSecondName           , FactMetaData::valueTypeDouble)
    ,_pitchRateDegreesPerSecondFact         (0, _pitchRateDegreesPerSecondName          , FactMetaData::valueTypeDouble)
    ,_yawRateDegreesPerSecondFact           (0, _yawRateDegreesPerSecondName            , FactMetaData::valueTypeDouble)
    ,_xVelocityMetersPerSecondFact          (0, _xVelocityMetersPerSecondName           , FactMetaData::valueTypeDouble)
    ,_yVelocityMetersPerSecondFact          (0, _yVelocityMetersPerSecondName           , FactMetaData::valueTypeDouble)
    ,_zVelocityMetersPerSecondFact          (0, _zVelocityMetersPerSecondName           , FactMetaData::valueTypeDouble)
    ,_customModeHeartbeatFact               (0, _customModeHeartbeatName                , FactMetaData::valueTypeUint32)
    ,_dataQualityFact                       (0, _dataQualityName                        , FactMetaData::valueTypeInt32)
    ,_homePositionLatitudeDegreesFact       (0, _homePositionLatitudeDegreesName        , FactMetaData::valueTypeDouble)
    ,_homePositionLongitudeDegreesFact      (0, _homePositionLongitudeDegreesName       , FactMetaData::valueTypeDouble)
    ,_homePositionAltitudeMetersFact        (0, _homePositionAltitudeMetersName         , FactMetaData::valueTypeDouble)
    ,_droneSerialNumberFact                 (0, _droneSerialNumberName                  , FactMetaData::valueTypeInt32)
    ,_groundWindSpeedMetersPerSecondFact    (0, _groundWindSpeedMetersPerSecondName     , FactMetaData::valueTypeDouble)
    ,_groundWindDirectionDegreesFact        (0, _groundWindDirectionDegreesName         , FactMetaData::valueTypeInt32)
    ,_groundAirTemperatureCelsiusFact       (0, _groundAirTemperatureCelsiusName        , FactMetaData::valueTypeDouble)
    ,_groundHumidityFact                    (0, _groundHumidityName                     , FactMetaData::valueTypeDouble)
    ,_groundPressureMillibarsFact           (0, _groundPressureMillibarsName            , FactMetaData::valueTypeDouble)
    ,_poweredAgeSecondsFact                 (0, _poweredAgeSecondsName                  , FactMetaData::valueTypeInt32)
    ,_armedAgeSecondsFact                   (0, _armedAgeSecondsName                    , FactMetaData::valueTypeInt32)
    ,_satellitesFact                        (0, _satellitesName                         , FactMetaData::valueTypeUint8)
    ,_horizontalDilutionOfPositionFloatFact (0, _horizontalDilutionOfPositionFloatName  , FactMetaData::valueTypeDouble)
    ,_filenameFact                          (0, _filenameName                           , FactMetaData::valueTypeString)
{
    _addFact(&_timeUnixSecondsFact                  , _timeUnixSecondsName                  );
    _addFact(&_altitudeMetersASLFact                , _altitudeMetersASLName                );
    _addFact(&_absolutePressureMillibarsFact        , _absolutePressureMillibarsName        );
    _addFact(&_temperature0CelsiusFact              , _temperature0CelsiusName              );
    _addFact(&_temperature1CelsiusFact              , _temperature1CelsiusName              );
    _addFact(&_temperature2CelsiusFact              , _temperature2CelsiusName              );
    _addFact(&_relativeHumidity0Fact                , _relativeHumidity0Name                );
    _addFact(&_relativeHumidity1Fact                , _relativeHumidity1Name                );
    _addFact(&_relativeHumidity2Fact                , _relativeHumidity2Name                );
    _addFact(&_latitudeDegreesFact                  , _latitudeDegreesName                  );
    _addFact(&_longitudeDegreesFact                 , _longitudeDegreesName                 );
    _addFact(&_rollDegreesFact                      , _rollDegreesName                      );
    _addFact(&_pitchDegreesFact                     , _pitchDegreesName                     );
    _addFact(&_yawDegreesFact                       , _yawDegreesName                       );
    _addFact(&_rollRateDegreesPerSecondFact         , _rollRateDegreesPerSecondName         );
    _addFact(&_pitchRateDegreesPerSecondFact        , _pitchRateDegreesPerSecondName        );
    _addFact(&_yawRateDegreesPerSecondFact          , _yawRateDegreesPerSecondName          );
    _addFact(&_xVelocityMetersPerSecondFact         , _xVelocityMetersPerSecondName         );
    _addFact(&_yVelocityMetersPerSecondFact         , _yVelocityMetersPerSecondName         );
    _addFact(&_zVelocityMetersPerSecondFact         , _zVelocityMetersPerSecondName         );
    _addFact(&_customModeHeartbeatFact              , _customModeHeartbeatName              );
    _addFact(&_dataQualityFact                      , _dataQualityName                      );
    _addFact(&_homePositionLatitudeDegreesFact      , _homePositionLatitudeDegreesName      );
    _addFact(&_homePositionLongitudeDegreesFact     , _homePositionLongitudeDegreesName     );
    _addFact(&_homePositionAltitudeMetersFact       , _homePositionAltitudeMetersName       );
    _addFact(&_droneSerialNumberFact                , _droneSerialNumberName                );
    _addFact(&_groundWindSpeedMetersPerSecondFact   , _groundWindSpeedMetersPerSecondName   );
    _addFact(&_groundWindDirectionDegreesFact       , _groundWindDirectionDegreesName       );
    _addFact(&_groundAirTemperatureCelsiusFact      , _groundAirTemperatureCelsiusName      );
    _addFact(&_groundHumidityFact                   , _groundHumidityName                   );
    _addFact(&_groundPressureMillibarsFact          , _groundPressureMillibarsName          );
    _addFact(&_poweredAgeSecondsFact                , _poweredAgeSecondsName                );
    _addFact(&_armedAgeSecondsFact                  , _armedAgeSecondsName                  );
    _addFact(&_satellitesFact                       , _satellitesName                       );
    _addFact(&_horizontalDilutionOfPositionFloatFact, _horizontalDilutionOfPositionFloatName);
    _addFact(&_filenameFact                         , _filenameName                         );

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
