#include "DataFactGroup.h"

const char* DataFactGroup::_timeUnixMicrosecondsName                = "timeUnixMicroseconds";
const char* DataFactGroup::_timeUnixSecondsName                     = "timeUnixSeconds";
const char* DataFactGroup::_altitudeMillimetersMSLName              = "altitudeMillimetersMSL";
const char* DataFactGroup::_altitudeMetersMSLName                   = "altitudeMetersMSL";
const char* DataFactGroup::_absolutePressureMillibarsName           = "absolutePressureMillibars";
const char* DataFactGroup::_temperature0KelvinName                  = "temperature0Kelvin";
const char* DataFactGroup::_temperature1KelvinName                  = "temperature1Kelvin";
const char* DataFactGroup::_temperature2KelvinName                  = "temperature2Kelvin";
const char* DataFactGroup::_temperature0CelsiusName                 = "temperature0Celsius";
const char* DataFactGroup::_temperature1CelsiusName                 = "temperature1Celsius";
const char* DataFactGroup::_temperature2CelsiusName                 = "temperature2Celsius";
const char* DataFactGroup::_temperatureCelsiusName                  = "temperatureCelsius";
const char* DataFactGroup::_relativeHumidity0Name                   = "relativeHumidity0";
const char* DataFactGroup::_relativeHumidity1Name                   = "relativeHumidity1";
const char* DataFactGroup::_relativeHumidity2Name                   = "relativeHumidity2";
const char* DataFactGroup::_relativeHumidityName                    = "relativeHumidity";
const char* DataFactGroup::_latitudeDegreesE7Name                   = "latitudeDegreesE7";
const char* DataFactGroup::_longitudeDegreesE7Name                  = "longitudeDegreesE7";
const char* DataFactGroup::_latitudeDegreesName                     = "latitudeDegrees";
const char* DataFactGroup::_longitudeDegreesName                    = "longitudeDegrees";
const char* DataFactGroup::_rollRadiansName                         = "rollRadians";
const char* DataFactGroup::_pitchRadiansName                        = "pitchRadians";
const char* DataFactGroup::_yawRadiansName                          = "yawRadians";
const char* DataFactGroup::_rollDegreesName                         = "rollDegrees";
const char* DataFactGroup::_pitchDegreesName                        = "pitchDegrees";
const char* DataFactGroup::_yawDegreesName                          = "yawDegrees";
const char* DataFactGroup::_rollRateRadiansPerSecondName            = "rollRateRadiansPerSecond";
const char* DataFactGroup::_pitchRateRadiansPerSecondName           = "pitchRateRadiansPerSecond";
const char* DataFactGroup::_yawRateRadiansPerSecondName             = "yawRateRadiansPerSecond";
const char* DataFactGroup::_rollRateDegreesPerSecondName            = "rollRateDegreesPerSecond";
const char* DataFactGroup::_pitchRateDegreesPerSecondName           = "pitchRateDegreesPerSecond";
const char* DataFactGroup::_yawRateDegreesPerSecondName             = "yawRateDegreesPerSecond";
const char* DataFactGroup::_xVelocityMetersPerSecondName            = "xVelocityMetersPerSecond";
const char* DataFactGroup::_yVelocityMetersPerSecondName            = "yVelocityMetersPerSecond";
const char* DataFactGroup::_zVelocityMetersPerSecondName            = "zVelocityMetersPerSecond";
const char* DataFactGroup::_zVelocityMetersPerSecondInvertedName    = "zVelocityMetersPerSecondInverted";
const char* DataFactGroup::_customModeHeartbeatName                 = "customModeHeartbeat";
const char* DataFactGroup::_dataQualityName                         = "dataQuality";
const char* DataFactGroup::_homePositionLatitudeDegreesName         = "homePositionLatitudeDegrees";
const char* DataFactGroup::_homePositionLongitudeDegreesName        = "homePositionLatitudeDegrees";
const char* DataFactGroup::_homePositionAltitudeMetersName          = "homePositionAltitudeMeters";
const char* DataFactGroup::_droneSerialNumberName                   = "droneSerialNumber";
const char* DataFactGroup::_groundWindSpeedMetersPerSecondName      = "groundWindSpeedMetersPerSecond";
const char* DataFactGroup::_groundWindDirectionDegreesName          = "groundWindDirectionDegrees";
const char* DataFactGroup::_groundAirTemperatureCelsiusName         = "groundAirTemperatureCelsius";
const char* DataFactGroup::_groundHumidityName                      = "groundHumidity";
const char* DataFactGroup::_groundPressureMillibarsName             = "groundPressureMillibars";
const char* DataFactGroup::_poweredAgeSecondsName                   = "poweredAgeSeconds";
const char* DataFactGroup::_armedAgeSecondsName                     = "armedAgeSeconds";
const char* DataFactGroup::_satellitesName                          = "satellites";
const char* DataFactGroup::_horizontalDilutionOfPositionName        = "horizontalDilutionOfPosition";
const char* DataFactGroup::_horizontalDilutionOfPositionFloatName   = "horizontalDilutionOfPositionFloat";

DataFactGroup::DataFactGroup(QObject* parent)
    : FactGroup(1000, ":/json/Vehicle/DataFact.json", parent, true)
    ,_timeUnixMicrosecondsFact                  (0, _timeUnixMicrosecondsName             , FactMetaData::valueTypeUint64)
    ,_timeUnixSecondsFact                       (0, _timeUnixSecondsName                  , FactMetaData::valueTypeDouble)
    ,_altitudeMillimetersMSLFact                (0, _altitudeMillimetersMSLName           , FactMetaData::valueTypeInt32)
    ,_altitudeMetersMSLFact                     (0, _altitudeMetersMSLName                , FactMetaData::valueTypeDouble)
    ,_absolutePressureMillibarsFact             (0, _absolutePressureMillibarsName        , FactMetaData::valueTypeDouble)
    ,_temperature0KelvinFact                    (0, _temperature0KelvinName               , FactMetaData::valueTypeDouble)
    ,_temperature1KelvinFact                    (0, _temperature1KelvinName               , FactMetaData::valueTypeDouble)
    ,_temperature2KelvinFact                    (0, _temperature2KelvinName               , FactMetaData::valueTypeDouble)
    ,_temperature0CelsiusFact                   (0, _temperature0CelsiusName              , FactMetaData::valueTypeDouble)
    ,_temperature1CelsiusFact                   (0, _temperature1CelsiusName              , FactMetaData::valueTypeDouble)
    ,_temperature2CelsiusFact                   (0, _temperature2CelsiusName              , FactMetaData::valueTypeDouble)
    ,_temperatureCelsiusFact                    (0, _temperatureCelsiusName               , FactMetaData::valueTypeDouble)
    ,_relativeHumidity0Fact                     (0, _relativeHumidity0Name                , FactMetaData::valueTypeDouble)
    ,_relativeHumidity1Fact                     (0, _relativeHumidity1Name                , FactMetaData::valueTypeDouble)
    ,_relativeHumidity2Fact                     (0, _relativeHumidity2Name                , FactMetaData::valueTypeDouble)
    ,_relativeHumidityFact                      (0, _relativeHumidityName                 , FactMetaData::valueTypeDouble)
    ,_latitudeDegreesE7Fact                     (0, _latitudeDegreesE7Name                , FactMetaData::valueTypeInt32)
    ,_longitudeDegreesE7Fact                    (0, _longitudeDegreesE7Name               , FactMetaData::valueTypeInt32)
    ,_latitudeDegreesFact                       (0, _latitudeDegreesName                  , FactMetaData::valueTypeDouble)
    ,_longitudeDegreesFact                      (0, _longitudeDegreesName                 , FactMetaData::valueTypeDouble)
    ,_rollRadiansFact                           (0, _rollRadiansName                      , FactMetaData::valueTypeDouble)
    ,_pitchRadiansFact                          (0, _pitchRadiansName                     , FactMetaData::valueTypeDouble)
    ,_yawRadiansFact                            (0, _yawRadiansName                       , FactMetaData::valueTypeDouble)
    ,_rollDegreesFact                           (0, _rollDegreesName                      , FactMetaData::valueTypeDouble)
    ,_pitchDegreesFact                          (0, _pitchDegreesName                     , FactMetaData::valueTypeDouble)
    ,_yawDegreesFact                            (0, _yawDegreesName                       , FactMetaData::valueTypeDouble)
    ,_rollRateRadiansPerSecondFact              (0, _rollRateRadiansPerSecondName         , FactMetaData::valueTypeDouble)
    ,_pitchRateRadiansPerSecondFact             (0, _pitchRateRadiansPerSecondName        , FactMetaData::valueTypeDouble)
    ,_yawRateRadiansPerSecondFact               (0, _yawRateRadiansPerSecondName          , FactMetaData::valueTypeDouble)
    ,_rollRateDegreesPerSecondFact              (0, _rollRateDegreesPerSecondName         , FactMetaData::valueTypeDouble)
    ,_pitchRateDegreesPerSecondFact             (0, _pitchRateDegreesPerSecondName        , FactMetaData::valueTypeDouble)
    ,_yawRateDegreesPerSecondFact               (0, _yawRateDegreesPerSecondName          , FactMetaData::valueTypeDouble)
    ,_xVelocityMetersPerSecondFact              (0, _xVelocityMetersPerSecondName         , FactMetaData::valueTypeDouble)
    ,_yVelocityMetersPerSecondFact              (0, _yVelocityMetersPerSecondName         , FactMetaData::valueTypeDouble)
    ,_zVelocityMetersPerSecondFact              (0, _zVelocityMetersPerSecondName         , FactMetaData::valueTypeDouble)
    ,_zVelocityMetersPerSecondInvertedFact      (0, _zVelocityMetersPerSecondInvertedName , FactMetaData::valueTypeDouble)
    ,_customModeHeartbeatFact                   (0, _customModeHeartbeatName              , FactMetaData::valueTypeUint32)
    ,_dataQualityFact                           (0, _dataQualityName                      , FactMetaData::valueTypeInt32)
    ,_homePositionLatitudeDegreesFact           (0, _homePositionLatitudeDegreesName      , FactMetaData::valueTypeDouble)
    ,_homePositionLongitudeDegreesFact          (0, _homePositionLongitudeDegreesName     , FactMetaData::valueTypeDouble)
    ,_homePositionAltitudeMetersFact            (0, _homePositionAltitudeMetersName       , FactMetaData::valueTypeDouble)
    ,_droneSerialNumberFact                     (0, _droneSerialNumberName                , FactMetaData::valueTypeUint32)
    ,_groundWindSpeedMetersPerSecondFact        (0, _groundWindSpeedMetersPerSecondName   , FactMetaData::valueTypeDouble)
    ,_groundWindDirectionDegreesFact            (0, _groundWindDirectionDegreesName       , FactMetaData::valueTypeInt32)
    ,_groundAirTemperatureCelsiusFact           (0, _groundAirTemperatureCelsiusName      , FactMetaData::valueTypeDouble)
    ,_groundHumidityFact                        (0, _groundHumidityName                   , FactMetaData::valueTypeDouble)
    ,_groundPressureMillibarsFact               (0, _groundPressureMillibarsName          , FactMetaData::valueTypeDouble)
    ,_poweredAgeSecondsFact                     (0, _poweredAgeSecondsName                , FactMetaData::valueTypeInt32)
    ,_armedAgeSecondsFact                       (0, _armedAgeSecondsName                  , FactMetaData::valueTypeInt32)
    ,_satellitesFact                            (0, _satellitesName                       , FactMetaData::valueTypeUint8)
    ,_horizontalDilutionOfPositionFact          (0, _horizontalDilutionOfPositionName     , FactMetaData::valueTypeUint16)
    ,_horizontalDilutionOfPositionFloatFact     (0, _horizontalDilutionOfPositionFloatName, FactMetaData::valueTypeDouble)
{
    _addFact(&_timeUnixMicrosecondsFact,                _timeUnixMicrosecondsName);
    _addFact(&_timeUnixSecondsFact,                     _timeUnixSecondsName);
    _addFact(&_altitudeMillimetersMSLFact,              _altitudeMillimetersMSLName);
    _addFact(&_altitudeMetersMSLFact,                   _altitudeMetersMSLName);
    _addFact(&_absolutePressureMillibarsFact,           _absolutePressureMillibarsName);
    _addFact(&_temperature0KelvinFact,                  _temperature0KelvinName);
    _addFact(&_temperature1KelvinFact,                  _temperature1KelvinName);
    _addFact(&_temperature2KelvinFact,                  _temperature2KelvinName);
    _addFact(&_temperature0CelsiusFact,                 _temperature0CelsiusName);
    _addFact(&_temperature1CelsiusFact,                 _temperature1CelsiusName);
    _addFact(&_temperature2CelsiusFact,                 _temperature2CelsiusName);
    _addFact(&_temperatureCelsiusFact,                  _temperatureCelsiusName);
    _addFact(&_relativeHumidity0Fact,                   _relativeHumidity0Name);
    _addFact(&_relativeHumidity1Fact,                   _relativeHumidity1Name);
    _addFact(&_relativeHumidity2Fact,                   _relativeHumidity2Name);
    _addFact(&_relativeHumidityFact,                    _relativeHumidityName);
    _addFact(&_latitudeDegreesE7Fact,                   _latitudeDegreesE7Name);
    _addFact(&_longitudeDegreesE7Fact,                  _longitudeDegreesE7Name);
    _addFact(&_latitudeDegreesFact,                     _latitudeDegreesName);
    _addFact(&_longitudeDegreesFact,                    _longitudeDegreesName);
    _addFact(&_rollRadiansFact,                         _rollRadiansName);
    _addFact(&_pitchRadiansFact,                        _pitchRadiansName);
    _addFact(&_yawRadiansFact,                          _yawRadiansName);
    _addFact(&_rollDegreesFact,                         _rollDegreesName);
    _addFact(&_pitchDegreesFact,                        _pitchDegreesName);
    _addFact(&_yawDegreesFact,                          _yawDegreesName);
    _addFact(&_rollRateRadiansPerSecondFact,            _rollRateRadiansPerSecondName);
    _addFact(&_pitchRateRadiansPerSecondFact,           _pitchRateRadiansPerSecondName);
    _addFact(&_yawRateRadiansPerSecondFact,             _yawRateRadiansPerSecondName);
    _addFact(&_rollRateDegreesPerSecondFact,            _rollRateDegreesPerSecondName);
    _addFact(&_pitchRateDegreesPerSecondFact,           _pitchRateDegreesPerSecondName);
    _addFact(&_yawRateDegreesPerSecondFact,             _yawRateDegreesPerSecondName);
    _addFact(&_xVelocityMetersPerSecondFact,            _xVelocityMetersPerSecondName);
    _addFact(&_yVelocityMetersPerSecondFact,            _yVelocityMetersPerSecondName);
    _addFact(&_zVelocityMetersPerSecondFact,            _zVelocityMetersPerSecondName);
    _addFact(&_zVelocityMetersPerSecondInvertedFact,    _zVelocityMetersPerSecondInvertedName);
    _addFact(&_customModeHeartbeatFact,                 _customModeHeartbeatName);
    _addFact(&_dataQualityFact,                         _dataQualityName);
    _addFact(&_homePositionLatitudeDegreesFact,         _homePositionLatitudeDegreesName);
    _addFact(&_homePositionLongitudeDegreesFact,        _homePositionLongitudeDegreesName);
    _addFact(&_homePositionAltitudeMetersFact,          _homePositionAltitudeMetersName);
    _addFact(&_droneSerialNumberFact,                   _droneSerialNumberName);
    _addFact(&_groundWindSpeedMetersPerSecondFact,      _groundWindSpeedMetersPerSecondName);
    _addFact(&_groundWindDirectionDegreesFact,          _groundWindDirectionDegreesName);
    _addFact(&_groundAirTemperatureCelsiusFact,         _groundAirTemperatureCelsiusName);
    _addFact(&_groundHumidityFact,                      _groundHumidityName);
    _addFact(&_groundPressureMillibarsFact,             _groundPressureMillibarsName);
    _addFact(&_poweredAgeSecondsFact,                   _poweredAgeSecondsName);
    _addFact(&_armedAgeSecondsFact,                     _armedAgeSecondsName);
    _addFact(&_satellitesFact,                          _satellitesName);
    _addFact(&_horizontalDilutionOfPositionFact,        _horizontalDilutionOfPositionName);
    _addFact(&_horizontalDilutionOfPositionFloatFact,   _horizontalDilutionOfPositionFloatName);

    _timeUnixMicrosecondsFact.              setRawValue(std::numeric_limits<unsigned int>::quiet_NaN());
    _timeUnixSecondsFact.                   setRawValue(qQNaN());
    _altitudeMillimetersMSLFact.            setRawValue(std::numeric_limits<signed int>::quiet_NaN());
    _altitudeMetersMSLFact.                 setRawValue(qQNaN());
    _absolutePressureMillibarsFact.         setRawValue(qQNaN());
    _temperature0KelvinFact.                setRawValue(qQNaN());
    _temperature1KelvinFact.                setRawValue(qQNaN());
    _temperature2KelvinFact.                setRawValue(qQNaN());
    _temperature0CelsiusFact.               setRawValue(qQNaN());
    _temperature1CelsiusFact.               setRawValue(qQNaN());
    _temperature2CelsiusFact.               setRawValue(qQNaN());
    _temperatureCelsiusFact.                setRawValue(qQNaN());
    _relativeHumidity0Fact.                 setRawValue(qQNaN());
    _relativeHumidity1Fact.                 setRawValue(qQNaN());
    _relativeHumidity2Fact.                 setRawValue(qQNaN());
    _relativeHumidityFact.                  setRawValue(qQNaN());
    _latitudeDegreesE7Fact.                 setRawValue(std::numeric_limits<signed int>::quiet_NaN());
    _longitudeDegreesE7Fact.                setRawValue(std::numeric_limits<signed int>::quiet_NaN());
    _latitudeDegreesFact.                   setRawValue(qQNaN());
    _longitudeDegreesFact.                  setRawValue(qQNaN());
    _rollRadiansFact.                       setRawValue(qQNaN());
    _pitchRadiansFact.                      setRawValue(qQNaN());
    _yawRadiansFact.                        setRawValue(qQNaN());
    _rollDegreesFact.                       setRawValue(qQNaN());
    _pitchDegreesFact.                      setRawValue(qQNaN());
    _yawDegreesFact.                        setRawValue(qQNaN());
    _rollRateRadiansPerSecondFact.          setRawValue(qQNaN());
    _pitchRateRadiansPerSecondFact.         setRawValue(qQNaN());
    _yawRateRadiansPerSecondFact.           setRawValue(qQNaN());
    _rollRateDegreesPerSecondFact.          setRawValue(qQNaN());
    _pitchRateDegreesPerSecondFact.         setRawValue(qQNaN());
    _yawRateDegreesPerSecondFact.           setRawValue(qQNaN());
    _xVelocityMetersPerSecondFact.          setRawValue(qQNaN());
    _yVelocityMetersPerSecondFact.          setRawValue(qQNaN());
    _zVelocityMetersPerSecondFact.          setRawValue(qQNaN());
    _zVelocityMetersPerSecondInvertedFact.  setRawValue(qQNaN());
    _customModeHeartbeatFact.               setRawValue(std::numeric_limits<unsigned int>::quiet_NaN());
    _dataQualityFact.                       setRawValue(std::numeric_limits<unsigned int>::quiet_NaN());
    _homePositionLatitudeDegreesFact.       setRawValue(qQNaN());
    _homePositionLongitudeDegreesFact.      setRawValue(qQNaN());
    _homePositionAltitudeMetersFact.        setRawValue(qQNaN());
    _droneSerialNumberFact.                 setRawValue(std::numeric_limits<unsigned int>::quiet_NaN());
    _groundWindSpeedMetersPerSecondFact.    setRawValue(qQNaN());
    _groundWindDirectionDegreesFact.        setRawValue(std::numeric_limits<signed int>::quiet_NaN());
    _groundAirTemperatureCelsiusFact.       setRawValue(qQNaN());
    _groundHumidityFact.                    setRawValue(qQNaN());
    _groundPressureMillibarsFact.           setRawValue(qQNaN());
    _poweredAgeSecondsFact.                 setRawValue(std::numeric_limits<signed int>::quiet_NaN());
    _armedAgeSecondsFact.                   setRawValue(std::numeric_limits<signed int>::quiet_NaN());
    _satellitesFact.                        setRawValue(std::numeric_limits<unsigned int>::quiet_NaN());
    _horizontalDilutionOfPositionFact.      setRawValue(std::numeric_limits<unsigned int>::quiet_NaN());
    _horizontalDilutionOfPositionFloatFact. setRawValue(qQNaN());
}

void DataFactGroup::handleMessage(Vehicle* /* vehicle */, mavlink_message_t& message)
{
    switch (message.msgid) {
    case
        break;
    default:
        break;
    }
}
