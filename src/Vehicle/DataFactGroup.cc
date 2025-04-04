#include "DataFactGroup.h"

const char* DataFactGroup::_timeUnixMicrosecondsFactName                = "timeUnixMicroseconds";
const char* DataFactGroup::_altitudeMillimetersMSLFactName              = "altitudeMillimetersMSL";
const char* DataFactGroup::_absolutePressureMillibarsFactName           = "absolutePressureMillibars";
const char* DataFactGroup::_temperature0KelvinFactName                  = "temperature0Kelvin";
const char* DataFactGroup::_temperature1KelvinFactName                  = "temperature1Kelvin";
const char* DataFactGroup::_temperature2KelvinFactName                  = "temperature2Kelvin";
const char* DataFactGroup::_relativeHumidity0FactName                   = "relativeHumidity0";
const char* DataFactGroup::_relativeHumidity1FactName                   = "relativeHumidity1";
const char* DataFactGroup::_relativeHumidity2FactName                   = "relativeHumidity2";
const char* DataFactGroup::_latitudeDegreesE7FactName                   = "latitudeDegreesE7";
const char* DataFactGroup::_longitudeDegreesE7FactName                  = "longitudeDegreesE7";
const char* DataFactGroup::_rollRadiansFactName                         = "rollRadians";
const char* DataFactGroup::_pitchRadiansFactName                        = "pitchRadians";
const char* DataFactGroup::_yawRadiansFactName                          = "yawRadians";
const char* DataFactGroup::_rollRateRadiansPerSecondFactName            = "rollRateRadiansPerSecond";
const char* DataFactGroup::_pitchRateRadiansPerSecondFactName           = "pitchRateRadiansPerSecond";
const char* DataFactGroup::_yawRateRadiansPerSecondFactName             = "yawRateRadiansPerSecond";
const char* DataFactGroup::_xVelocityMetersPerSecondFactName            = "xVelocityMetersPerSecond";
const char* DataFactGroup::_yVelocityMetersPerSecondFactName            = "yVelocityMetersPerSecond";
const char* DataFactGroup::_zVelocityMetersPerSecondFactName            = "zVelocityMetersPerSecond";
const char* DataFactGroup::_customModeHeartbeatFactName                 = "customModeHeartbeat";
const char* DataFactGroup::_dataQualityFactName                         = "dataQuality";
const char* DataFactGroup::_satellitesFactName                          = "satellites";
const char* DataFactGroup::_horizontalDilutionOfPositionFactName        = "horizontalDilutionOfPosition";
const char* DataFactGroup::_zVelocityForAscentDetectionFactName         = "zVelocityForAscentDetection";

DataFactGroup::DataFactGroup(QObject* parent)
    : FactGroup(1000, ":/json/Vehicle/DataFact.json", parent, true)
        // : FactGroup(1000, ":/path.json", parent, true)
    ,_timeUnixMicrosecondsFact                  (0, _timeUnixMicrosecondsFactName             , FactMetaData::valueTypeUint64)
    ,_altitudeMillimetersMSLFact                (0, _altitudeMillimetersMSLFactName           , FactMetaData::valueTypeInt32)
    ,_absolutePressureMillibarsFact             (0, _absolutePressureMillibarsFactName        , FactMetaData::valueTypeDouble)
    ,_temperature0KelvinFact                    (0, _temperature0KelvinFactName               , FactMetaData::valueTypeDouble)
    ,_temperature1KelvinFact                    (0, _temperature1KelvinFactName               , FactMetaData::valueTypeDouble)
    ,_temperature2KelvinFact                    (0, _temperature2KelvinFactName               , FactMetaData::valueTypeDouble)
    ,_relativeHumidity0Fact                     (0, _relativeHumidity0FactName                , FactMetaData::valueTypeDouble)
    ,_relativeHumidity1Fact                     (0, _relativeHumidity1FactName                , FactMetaData::valueTypeDouble)
    ,_relativeHumidity2Fact                     (0, _relativeHumidity2FactName                , FactMetaData::valueTypeDouble)
    ,_latitudeDegreesE7Fact                     (0, _latitudeDegreesE7FactName                , FactMetaData::valueTypeInt32)
    ,_longitudeDegreesE7Fact                    (0, _longitudeDegreesE7FactName               , FactMetaData::valueTypeInt32)
    ,_rollRadiansFact                           (0, _rollRadiansFactName                      , FactMetaData::valueTypeDouble)
    ,_pitchRadiansFact                          (0, _pitchRadiansFactName                     , FactMetaData::valueTypeDouble)
    ,_yawRadiansFact                            (0, _yawRadiansFactName                       , FactMetaData::valueTypeDouble)
    ,_rollRateRadiansPerSecondFact              (0, _rollRateRadiansPerSecondFactName         , FactMetaData::valueTypeDouble)
    ,_pitchRateRadiansPerSecondFact             (0, _pitchRateRadiansPerSecondFactName        , FactMetaData::valueTypeDouble)
    ,_yawRateRadiansPerSecondFact               (0, _yawRateRadiansPerSecondFactName          , FactMetaData::valueTypeDouble)
    ,_xVelocityMetersPerSecondFact              (0, _xVelocityMetersPerSecondFactName         , FactMetaData::valueTypeDouble)
    ,_yVelocityMetersPerSecondFact              (0, _yVelocityMetersPerSecondFactName         , FactMetaData::valueTypeDouble)
    ,_zVelocityMetersPerSecondFact              (0, _zVelocityMetersPerSecondFactName         , FactMetaData::valueTypeDouble)
    ,_customModeHeartbeatFact                   (0, _customModeHeartbeatFactName              , FactMetaData::valueTypeUint32)
    ,_dataQualityFact                           (0, _dataQualityFactName                      , FactMetaData::valueTypeInt32)
    ,_satellitesFact                            (0, _satellitesFactName                       , FactMetaData::valueTypeUint16)
    ,_horizontalDilutionOfPositionFact          (0, _horizontalDilutionOfPositionFactName     , FactMetaData::valueTypeUint16)
    ,_zVelocityForAscentDetectionFact           (0, _zVelocityForAscentDetectionFactName      , FactMetaData::valueTypeDouble)
{
    _addFact(&_timeUnixMicrosecondsFact,                _timeUnixMicrosecondsFactName);
    _addFact(&_altitudeMillimetersMSLFact,              _altitudeMillimetersMSLFactName);
    _addFact(&_absolutePressureMillibarsFact,           _absolutePressureMillibarsFactName);
    _addFact(&_temperature0KelvinFact,                  _temperature0KelvinFactName);
    _addFact(&_temperature1KelvinFact,                  _temperature1KelvinFactName);
    _addFact(&_temperature2KelvinFact,                  _temperature2KelvinFactName);
    _addFact(&_relativeHumidity0Fact,                   _relativeHumidity0FactName);
    _addFact(&_relativeHumidity1Fact,                   _relativeHumidity1FactName);
    _addFact(&_relativeHumidity2Fact,                   _relativeHumidity2FactName);
    _addFact(&_latitudeDegreesE7Fact,                   _latitudeDegreesE7FactName);
    _addFact(&_longitudeDegreesE7Fact,                  _longitudeDegreesE7FactName);
    _addFact(&_rollRadiansFact,                         _rollRadiansFactName);
    _addFact(&_pitchRadiansFact,                        _pitchRadiansFactName);
    _addFact(&_yawRadiansFact,                          _yawRadiansFactName);
    _addFact(&_rollRateRadiansPerSecondFact,            _rollRateRadiansPerSecondFactName);
    _addFact(&_pitchRateRadiansPerSecondFact,           _pitchRateRadiansPerSecondFactName);
    _addFact(&_yawRateRadiansPerSecondFact,             _yawRateRadiansPerSecondFactName);
    _addFact(&_xVelocityMetersPerSecondFact,            _xVelocityMetersPerSecondFactName);
    _addFact(&_yVelocityMetersPerSecondFact,            _yVelocityMetersPerSecondFactName);
    _addFact(&_zVelocityMetersPerSecondFact,            _zVelocityMetersPerSecondFactName);
    _addFact(&_customModeHeartbeatFact,                 _customModeHeartbeatFactName);
    _addFact(&_dataQualityFact,                         _dataQualityFactName);
    _addFact(&_satellitesFact,                          _satellitesFactName);
    _addFact(&_horizontalDilutionOfPositionFact,        _horizontalDilutionOfPositionFactName);
    _addFact(&_zVelocityForAscentDetectionFact,         _zVelocityForAscentDetectionFactName);

    _timeUnixMicrosecondsFact.              setRawValue(std::numeric_limits<uint64_t>::max());
    _altitudeMillimetersMSLFact.            setRawValue(std::numeric_limits<int32_t>::max());
    _absolutePressureMillibarsFact.         setRawValue(qQNaN());
    _temperature0KelvinFact.                setRawValue(qQNaN());
    _temperature1KelvinFact.                setRawValue(qQNaN());
    _temperature2KelvinFact.                setRawValue(qQNaN());
    _relativeHumidity0Fact.                 setRawValue(qQNaN());
    _relativeHumidity1Fact.                 setRawValue(qQNaN());
    _relativeHumidity2Fact.                 setRawValue(qQNaN());
    _latitudeDegreesE7Fact.                 setRawValue(std::numeric_limits<signed int>::quiet_NaN());
    _longitudeDegreesE7Fact.                setRawValue(std::numeric_limits<signed int>::quiet_NaN());
    _rollRadiansFact.                       setRawValue(qQNaN());
    _pitchRadiansFact.                      setRawValue(qQNaN());
    _yawRadiansFact.                        setRawValue(qQNaN());
    _rollRateRadiansPerSecondFact.          setRawValue(qQNaN());
    _pitchRateRadiansPerSecondFact.         setRawValue(qQNaN());
    _yawRateRadiansPerSecondFact.           setRawValue(qQNaN());
    _xVelocityMetersPerSecondFact.          setRawValue(qQNaN());
    _yVelocityMetersPerSecondFact.          setRawValue(qQNaN());
    _zVelocityMetersPerSecondFact.          setRawValue(qQNaN());
    _customModeHeartbeatFact.               setRawValue(std::numeric_limits<unsigned int>::quiet_NaN());
    /* TODO: find source fact for this */
    _dataQualityFact.                       setRawValue(QVariant(0));
    _satellitesFact.                        setRawValue(std::numeric_limits<uint16_t>::max());
    _horizontalDilutionOfPositionFact.      setRawValue(std::numeric_limits<unsigned int>::quiet_NaN());
    _zVelocityForAscentDetectionFact.       setRawValue(qQNaN());
}
