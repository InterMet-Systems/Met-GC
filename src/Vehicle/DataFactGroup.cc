#include "DataFactGroup.h"

const char* DataFactGroup::_timeUnixMicrosecondsName                = "timeUnixMicroseconds";
const char* DataFactGroup::_altitudeMillimetersMSLName              = "altitudeMillimetersMSL";
const char* DataFactGroup::_absolutePressureMillibarsName           = "absolutePressureMillibars";
const char* DataFactGroup::_temperature0KelvinName                  = "temperature0Kelvin";
const char* DataFactGroup::_temperature1KelvinName                  = "temperature1Kelvin";
const char* DataFactGroup::_temperature2KelvinName                  = "temperature2Kelvin";
const char* DataFactGroup::_relativeHumidity0Name                   = "relativeHumidity0";
const char* DataFactGroup::_relativeHumidity1Name                   = "relativeHumidity1";
const char* DataFactGroup::_relativeHumidity2Name                   = "relativeHumidity2";
const char* DataFactGroup::_latitudeDegreesE7Name                   = "latitudeDegreesE7";
const char* DataFactGroup::_longitudeDegreesE7Name                  = "longitudeDegreesE7";
const char* DataFactGroup::_rollRadiansName                         = "rollRadians";
const char* DataFactGroup::_pitchRadiansName                        = "pitchRadians";
const char* DataFactGroup::_yawRadiansName                          = "yawRadians";
const char* DataFactGroup::_rollRateRadiansPerSecondName            = "rollRateRadiansPerSecond";
const char* DataFactGroup::_pitchRateRadiansPerSecondName           = "pitchRateRadiansPerSecond";
const char* DataFactGroup::_yawRateRadiansPerSecondName             = "yawRateRadiansPerSecond";
const char* DataFactGroup::_xVelocityMetersPerSecondName            = "xVelocityMetersPerSecond";
const char* DataFactGroup::_yVelocityMetersPerSecondName            = "yVelocityMetersPerSecond";
const char* DataFactGroup::_zVelocityMetersPerSecondName            = "zVelocityMetersPerSecond";
const char* DataFactGroup::_customModeHeartbeatName                 = "customModeHeartbeat";
const char* DataFactGroup::_dataQualityName                         = "dataQuality";
const char* DataFactGroup::_satellitesName                          = "satellites";
const char* DataFactGroup::_horizontalDilutionOfPositionName        = "horizontalDilutionOfPosition";

DataFactGroup::DataFactGroup(QObject* parent)
    : FactGroup(1000, ":/json/Vehicle/DataFact.json", parent, true)
    ,_timeUnixMicrosecondsFact                  (0, _timeUnixMicrosecondsName             , FactMetaData::valueTypeUint64)
    ,_altitudeMillimetersMSLFact                (0, _altitudeMillimetersMSLName           , FactMetaData::valueTypeInt32)
    ,_absolutePressureMillibarsFact             (0, _absolutePressureMillibarsName        , FactMetaData::valueTypeDouble)
    ,_temperature0KelvinFact                    (0, _temperature0KelvinName               , FactMetaData::valueTypeDouble)
    ,_temperature1KelvinFact                    (0, _temperature1KelvinName               , FactMetaData::valueTypeDouble)
    ,_temperature2KelvinFact                    (0, _temperature2KelvinName               , FactMetaData::valueTypeDouble)
    ,_relativeHumidity0Fact                     (0, _relativeHumidity0Name                , FactMetaData::valueTypeDouble)
    ,_relativeHumidity1Fact                     (0, _relativeHumidity1Name                , FactMetaData::valueTypeDouble)
    ,_relativeHumidity2Fact                     (0, _relativeHumidity2Name                , FactMetaData::valueTypeDouble)
    ,_latitudeDegreesE7Fact                     (0, _latitudeDegreesE7Name                , FactMetaData::valueTypeInt32)
    ,_longitudeDegreesE7Fact                    (0, _longitudeDegreesE7Name               , FactMetaData::valueTypeInt32)
    ,_rollRadiansFact                           (0, _rollRadiansName                      , FactMetaData::valueTypeDouble)
    ,_pitchRadiansFact                          (0, _pitchRadiansName                     , FactMetaData::valueTypeDouble)
    ,_yawRadiansFact                            (0, _yawRadiansName                       , FactMetaData::valueTypeDouble)
    ,_rollRateRadiansPerSecondFact              (0, _rollRateRadiansPerSecondName         , FactMetaData::valueTypeDouble)
    ,_pitchRateRadiansPerSecondFact             (0, _pitchRateRadiansPerSecondName        , FactMetaData::valueTypeDouble)
    ,_yawRateRadiansPerSecondFact               (0, _yawRateRadiansPerSecondName          , FactMetaData::valueTypeDouble)
    ,_xVelocityMetersPerSecondFact              (0, _xVelocityMetersPerSecondName         , FactMetaData::valueTypeDouble)
    ,_yVelocityMetersPerSecondFact              (0, _yVelocityMetersPerSecondName         , FactMetaData::valueTypeDouble)
    ,_zVelocityMetersPerSecondFact              (0, _zVelocityMetersPerSecondName         , FactMetaData::valueTypeDouble)
    ,_customModeHeartbeatFact                   (0, _customModeHeartbeatName              , FactMetaData::valueTypeUint32)
    ,_dataQualityFact                           (0, _dataQualityName                      , FactMetaData::valueTypeInt32)
    ,_satellitesFact                            (0, _satellitesName                       , FactMetaData::valueTypeUint8)
    ,_horizontalDilutionOfPositionFact          (0, _horizontalDilutionOfPositionName     , FactMetaData::valueTypeUint16)
{
    _addFact(&_timeUnixMicrosecondsFact,                _timeUnixMicrosecondsName);
    _addFact(&_altitudeMillimetersMSLFact,              _altitudeMillimetersMSLName);
    _addFact(&_absolutePressureMillibarsFact,           _absolutePressureMillibarsName);
    _addFact(&_temperature0KelvinFact,                  _temperature0KelvinName);
    _addFact(&_temperature1KelvinFact,                  _temperature1KelvinName);
    _addFact(&_temperature2KelvinFact,                  _temperature2KelvinName);
    _addFact(&_relativeHumidity0Fact,                   _relativeHumidity0Name);
    _addFact(&_relativeHumidity1Fact,                   _relativeHumidity1Name);
    _addFact(&_relativeHumidity2Fact,                   _relativeHumidity2Name);
    _addFact(&_latitudeDegreesE7Fact,                   _latitudeDegreesE7Name);
    _addFact(&_longitudeDegreesE7Fact,                  _longitudeDegreesE7Name);
    _addFact(&_rollRadiansFact,                         _rollRadiansName);
    _addFact(&_pitchRadiansFact,                        _pitchRadiansName);
    _addFact(&_yawRadiansFact,                          _yawRadiansName);
    _addFact(&_rollRateRadiansPerSecondFact,            _rollRateRadiansPerSecondName);
    _addFact(&_pitchRateRadiansPerSecondFact,           _pitchRateRadiansPerSecondName);
    _addFact(&_yawRateRadiansPerSecondFact,             _yawRateRadiansPerSecondName);
    _addFact(&_xVelocityMetersPerSecondFact,            _xVelocityMetersPerSecondName);
    _addFact(&_yVelocityMetersPerSecondFact,            _yVelocityMetersPerSecondName);
    _addFact(&_zVelocityMetersPerSecondFact,            _zVelocityMetersPerSecondName);
    _addFact(&_customModeHeartbeatFact,                 _customModeHeartbeatName);
    _addFact(&_dataQualityFact,                         _dataQualityName);
    _addFact(&_satellitesFact,                          _satellitesName);
    _addFact(&_horizontalDilutionOfPositionFact,        _horizontalDilutionOfPositionName);

    _timeUnixMicrosecondsFact.              setRawValue(std::numeric_limits<uint64_t>::max());
    _altitudeMillimetersMSLFact.            setRawValue(std::numeric_limits<signed int>::quiet_NaN());
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
    _satellitesFact.                        setRawValue(std::numeric_limits<unsigned int>::quiet_NaN());
    _horizontalDilutionOfPositionFact.      setRawValue(std::numeric_limits<unsigned int>::quiet_NaN());
}
