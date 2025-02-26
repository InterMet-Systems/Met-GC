#include "MessageAltitudeFactGroup.h"

const char* MessageAltitudeFactGroup::_SRNName =                        "SRN";
const char* MessageAltitudeFactGroup::_YYYYName =                       "YYYY";
const char* MessageAltitudeFactGroup::_MMName =                         "MM";
const char* MessageAltitudeFactGroup::_DDName =                         "DD";
const char* MessageAltitudeFactGroup::_HHName =                         "HH";
const char* MessageAltitudeFactGroup::_MmName =                         "Mm";
const char* MessageAltitudeFactGroup::_ssName =                         "ss";
const char* MessageAltitudeFactGroup::_StringName =                     "String";
const char* MessageAltitudeFactGroup::_Message_VersionName =            "Message_Version";
const char* MessageAltitudeFactGroup::_Drone_Powered_AgeName =          "Drone_Powered_Age";
const char* MessageAltitudeFactGroup::_Drone_Armed_AgeName =            "Drone_Armed_Age";
const char* MessageAltitudeFactGroup::_Raw_Data_FilenameName =          "Raw_Data_Filename";
const char* MessageAltitudeFactGroup::_Unix_Start_TimeName =            "Unix_Start_Time";
const char* MessageAltitudeFactGroup::_Ground_Wind_SpeedName =          "Ground_Wind_Speed";
const char* MessageAltitudeFactGroup::_Ground_Wind_DirectionName =      "Ground_Wind_Direction";
const char* MessageAltitudeFactGroup::_Ground_Air_TemperatureName =     "Ground_Air_Temperature";
const char* MessageAltitudeFactGroup::_Ground_HumidityName =            "Ground_Humidity";
const char* MessageAltitudeFactGroup::_Ground_PressureName =            "Ground_Pressure";
const char* MessageAltitudeFactGroup::_Home_Position_LatitudeName =     "Home_Position_Latitude";
const char* MessageAltitudeFactGroup::_Home_Position_LongitudeName =    "Home_Position_Longitude";
const char* MessageAltitudeFactGroup::_Home_Position_AltitudeName =     "Home_Position_Altitude";
const char* MessageAltitudeFactGroup::_Altitude_ASLName =               "Altitude_ASL";
const char* MessageAltitudeFactGroup::_UTC_DateName =                   "UTC_Date";
const char* MessageAltitudeFactGroup::_UTC_TimeName =                   "UTC_Time";
const char* MessageAltitudeFactGroup::_Time_Since_StartName =           "Time_Since_Start";
const char* MessageAltitudeFactGroup::_PressureName =                   "Pressure";
const char* MessageAltitudeFactGroup::_Air_TempName =                   "Air_Temp";
const char* MessageAltitudeFactGroup::_Rel_HumName =                    "Rel_Hum";
const char* MessageAltitudeFactGroup::_Wind_SpeedName =                 "Wind_Speed";
const char* MessageAltitudeFactGroup::_Wind_DirectionName =             "Wind_Direction";
const char* MessageAltitudeFactGroup::_LatitudeName =                   "Latitude";
const char* MessageAltitudeFactGroup::_LongitudeName =                  "Longitude";
const char* MessageAltitudeFactGroup::_RollName =                       "Roll";
const char* MessageAltitudeFactGroup::_Roll_RateName =                  "Roll_Rate";
const char* MessageAltitudeFactGroup::_PitchName =                      "Pitch";
const char* MessageAltitudeFactGroup::_Pitch_RateName =                 "Pitch_Rate";
const char* MessageAltitudeFactGroup::_YawName =                        "Yaw";
const char* MessageAltitudeFactGroup::_Yaw_RateName =                   "Yaw_Rate";
const char* MessageAltitudeFactGroup::_Ascent_RateName =                "Ascent_Rate";
const char* MessageAltitudeFactGroup::_Speed_Over_GroundName =          "Speed_Over_Ground";
const char* MessageAltitudeFactGroup::_SatellitesName =                 "Satellites";
const char* MessageAltitudeFactGroup::_HDOPName =                       "HDOP";
const char* MessageAltitudeFactGroup::_Data_QualityName =               "Data_Quality";

MessageAltitudeFactGroup::MessageAltitudeFactGroup(QObject* parent)
    : FactGroup(1000, ":/path.json", parent, true)
    ,_SRNFact                       (0, _SRNName,                       FactMetaData::valueTypeInt32)
    ,_YYYYFact                      (0, _YYYYName,                      FactMetaData::valueTypeUint16)
    ,_MMFact                        (0, _MMName,                        FactMetaData::valueTypeUint8)
    ,_DDFact                        (0, _DDName,                        FactMetaData::valueTypeUint8)
    ,_HHFact                        (0, _HHName,                        FactMetaData::valueTypeUint8)
    ,_MmFact                        (0, _MmName,                        FactMetaData::valueTypeUint8)
    ,_ssFact                        (0, _ssName,                        FactMetaData::valueTypeUint8)
    ,_StringFact                    (0, _StringName,                    FactMetaData::valueTypeString)
    ,_Message_VersionFact           (0, _Message_VersionName,           FactMetaData::valueTypeString)
    ,_Drone_Powered_AgeFact         (0, _Drone_Powered_AgeName,         FactMetaData::valueTypeInt32)
    ,_Drone_Armed_AgeFact           (0, _Drone_Armed_AgeName,           FactMetaData::valueTypeInt32)
    ,_Raw_Data_FilenameFact         (0, _Raw_Data_FilenameName,         FactMetaData::valueTypeString)
    ,_Unix_Start_TimeFact           (0, _Unix_Start_TimeName,           FactMetaData::valueTypeUint64)
    ,_Ground_Wind_SpeedFact         (0, _Ground_Wind_SpeedName,         FactMetaData::valueTypeDouble)
    ,_Ground_Wind_DirectionFact     (0, _Ground_Wind_DirectionName,     FactMetaData::valueTypeInt32)
    ,_Ground_Air_TemperatureFact    (0, _Ground_Air_TemperatureName,    FactMetaData::valueTypeDouble)
    ,_Ground_HumidityFact           (0, _Ground_HumidityName,           FactMetaData::valueTypeDouble)
    ,_Ground_PressureFact           (0, _Ground_PressureName,           FactMetaData::valueTypeDouble)
    ,_Home_Position_LatitudeFact    (0, _Home_Position_LatitudeName,    FactMetaData::valueTypeDouble)
    ,_Home_Position_LongitudeFact   (0, _Home_Position_LongitudeName,   FactMetaData::valueTypeDouble)
    ,_Home_Position_AltitudeFact    (0, _Home_Position_AltitudeName,    FactMetaData::valueTypeDouble)
    ,_Altitude_ASLFact              (0, _Altitude_ASLName,              FactMetaData::valueTypeDouble)
    ,_UTC_DateFact                  (0, _UTC_DateName,                  FactMetaData::valueTypeString)
    ,_UTC_TimeFact                  (0, _UTC_TimeName,                  FactMetaData::valueTypeString)
    ,_Time_Since_StartFact          (0, _Time_Since_StartName,          FactMetaData::valueTypeDouble)
    ,_PressureFact                  (0, _PressureName,                  FactMetaData::valueTypeDouble)
    ,_Air_TempFact                  (0, _Air_TempName,                  FactMetaData::valueTypeDouble)
    ,_Rel_HumFact                   (0, _Rel_HumName,                   FactMetaData::valueTypeDouble)
    ,_Wind_SpeedFact                (0, _Wind_SpeedName,                FactMetaData::valueTypeDouble)
    ,_Wind_DirectionFact            (0, _Wind_DirectionName,            FactMetaData::valueTypeInt32)
    ,_LatitudeFact                  (0, _LatitudeName,                  FactMetaData::valueTypeDouble)
    ,_LongitudeFact                 (0, _LongitudeName,                 FactMetaData::valueTypeDouble)
    ,_RollFact                      (0, _RollName,                      FactMetaData::valueTypeDouble)
    ,_Roll_RateFact                 (0, _Roll_RateName,                 FactMetaData::valueTypeDouble)
    ,_PitchFact                     (0, _PitchName,                     FactMetaData::valueTypeDouble)
    ,_Pitch_RateFact                (0, _Pitch_RateName,                FactMetaData::valueTypeDouble)
    ,_YawFact                       (0, _YawName,                       FactMetaData::valueTypeDouble)
    ,_Yaw_RateFact                  (0, _Yaw_RateName,                  FactMetaData::valueTypeDouble)
    ,_Ascent_RateFact               (0, _Ascent_RateName,               FactMetaData::valueTypeDouble)
    ,_Speed_Over_GroundFact         (0, _Speed_Over_GroundName,         FactMetaData::valueTypeDouble)
    ,_SatellitesFact                (0, _SatellitesName,                FactMetaData::valueTypeUint8)
    ,_HDOPFact                      (0, _HDOPName,                      FactMetaData::valueTypeDouble)
    ,_Data_QualityFact              (0, _Data_QualityName,              FactMetaData::valueTypeInt32)
{
    _addFact(&_SRNFact                       , _SRNName                       );
    _addFact(&_YYYYFact                      , _YYYYName                      );
    _addFact(&_MMFact                        , _MMName                        );
    _addFact(&_DDFact                        , _DDName                        );
    _addFact(&_HHFact                        , _HHName                        );
    _addFact(&_MmFact                        , _MmName                        );
    _addFact(&_ssFact                        , _ssName                        );
    _addFact(&_StringFact                    , _StringName                    );
    _addFact(&_Message_VersionFact           , _Message_VersionName           );
    _addFact(&_Drone_Powered_AgeFact         , _Drone_Powered_AgeName         );
    _addFact(&_Drone_Armed_AgeFact           , _Drone_Armed_AgeName           );
    _addFact(&_Raw_Data_FilenameFact         , _Raw_Data_FilenameName         );
    _addFact(&_Unix_Start_TimeFact           , _Unix_Start_TimeName           );
    _addFact(&_Ground_Wind_SpeedFact         , _Ground_Wind_SpeedName         );
    _addFact(&_Ground_Wind_DirectionFact     , _Ground_Wind_DirectionName     );
    _addFact(&_Ground_Air_TemperatureFact    , _Ground_Air_TemperatureName    );
    _addFact(&_Ground_HumidityFact           , _Ground_HumidityName           );
    _addFact(&_Ground_PressureFact           , _Ground_PressureName           );
    _addFact(&_Home_Position_LatitudeFact    , _Home_Position_LatitudeName    );
    _addFact(&_Home_Position_LongitudeFact   , _Home_Position_LongitudeName   );
    _addFact(&_Home_Position_AltitudeFact    , _Home_Position_AltitudeName    );
    _addFact(&_Altitude_ASLFact              , _Altitude_ASLName              );
    _addFact(&_UTC_DateFact                  , _UTC_DateName                  );
    _addFact(&_UTC_TimeFact                  , _UTC_TimeName                  );
    _addFact(&_Time_Since_StartFact          , _Time_Since_StartName          );
    _addFact(&_PressureFact                  , _PressureName                  );
    _addFact(&_Air_TempFact                  , _Air_TempName                  );
    _addFact(&_Rel_HumFact                   , _Rel_HumName                   );
    _addFact(&_Wind_SpeedFact                , _Wind_SpeedName                );
    _addFact(&_Wind_DirectionFact            , _Wind_DirectionName            );
    _addFact(&_LatitudeFact                  , _LatitudeName                  );
    _addFact(&_LongitudeFact                 , _LongitudeName                 );
    _addFact(&_RollFact                      , _RollName                      );
    _addFact(&_Roll_RateFact                 , _Roll_RateName                 );
    _addFact(&_PitchFact                     , _PitchName                     );
    _addFact(&_Pitch_RateFact                , _Pitch_RateName                );
    _addFact(&_YawFact                       , _YawName                       );
    _addFact(&_Yaw_RateFact                  , _Yaw_RateName                  );
    _addFact(&_Ascent_RateFact               , _Ascent_RateName               );
    _addFact(&_Speed_Over_GroundFact         , _Speed_Over_GroundName         );
    _addFact(&_SatellitesFact                , _SatellitesName                );
    _addFact(&_HDOPFact                      , _HDOPName                      );
    _addFact(&_Data_QualityFact              , _Data_QualityName              );

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
