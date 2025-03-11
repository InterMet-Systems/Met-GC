#ifndef MESSAGEALTITUDEFACTGROUP_H
#define MESSAGEALTITUDEFACTGROUP_H

#include "FactGroup.h"

class MessageAltitudeFactGroup : public FactGroup{
    Q_OBJECT

public:
    MessageAltitudeFactGroup(QObject* parent = nullptr);
    void handleMessage(Vehicle* vehicle, mavlink_message_t& message) override;
    Q_PROPERTY(Fact* droneSerial              READ droneSerial              CONSTANT) /* int32_t    filename, constant          raw         */
    Q_PROPERTY(Fact* year                     READ year                     CONSTANT) /* uint16_t   filename                    raw         */
    Q_PROPERTY(Fact* month                    READ month                    CONSTANT) /* uint8_t    filename                    raw         */
    Q_PROPERTY(Fact* day                      READ day                      CONSTANT) /* uint8_t    filename                    raw         */
    Q_PROPERTY(Fact* hour                     READ hour                     CONSTANT) /* uint8_t    filename                    raw         */
    Q_PROPERTY(Fact* minute                   READ minute                   CONSTANT) /* uint8_t    filename                    raw         */
    Q_PROPERTY(Fact* second                   READ second                   CONSTANT) /* uint8_t    filename                    raw         */
    Q_PROPERTY(Fact* string                   READ string                   CONSTANT) /* string     filename                    file/gui    */
    Q_PROPERTY(Fact* messageVersion           READ messageVersion           CONSTANT) /* string     constant                    hard coded  */
    Q_PROPERTY(Fact* dronePoweredAge          READ dronePoweredAge          CONSTANT) /* int32_t    constant                    raw         */
    Q_PROPERTY(Fact* droneArmedAge            READ droneArmedAge            CONSTANT) /* int32_t    constant                    raw         */
    Q_PROPERTY(Fact* rawDataFilename          READ rawDataFilename          CONSTANT) /* string     constant                    raw         */
    Q_PROPERTY(Fact* unixStartTime            READ unixStartTime            CONSTANT) /* uint64_t   constant                    raw         */
    Q_PROPERTY(Fact* groundWindSpeed          READ groundWindSpeed          CONSTANT) /* f64        constant                    raw         */
    Q_PROPERTY(Fact* groundWindDirection      READ groundWindDirection      CONSTANT) /* int32_t    constant                    raw         */
    Q_PROPERTY(Fact* groundAirTemperature     READ groundAirTemperature     CONSTANT) /* f64        constant                    raw         */
    Q_PROPERTY(Fact* groundHumidity           READ groundHumidity           CONSTANT) /* f64        constant                    raw         */
    Q_PROPERTY(Fact* groundPressure           READ groundPressure           CONSTANT) /* f64        constant                    raw         */
    Q_PROPERTY(Fact* homePositionLatitude     READ homePositionLatitude     CONSTANT) /* f64        constant                    raw         */
    Q_PROPERTY(Fact* homePositionLongitude    READ homePositionLongitude    CONSTANT) /* f64        constant                    raw         */
    Q_PROPERTY(Fact* homePositionAltitude     READ homePositionAltitude     CONSTANT) /* f64        constant                    raw         */
    Q_PROPERTY(Fact* altitudeASL              READ altitudeASL              CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* uTCDate                  READ uTCDate                  CONSTANT) /* string     time-varying                raw         */
    Q_PROPERTY(Fact* uTCTime                  READ uTCTime                  CONSTANT) /* string     time-varying                raw         */
    Q_PROPERTY(Fact* timeSinceStart           READ timeSinceStart           CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* pressure                 READ pressure                 CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* airTemp                  READ airTemp                  CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* relHum                   READ relHum                   CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* windSpeed                READ windSpeed                CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* windDirection            READ windDirection            CONSTANT) /* int32_t    time-varying                raw         */
    Q_PROPERTY(Fact* latitude                 READ latitude                 CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* longitude                READ longitude                CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* roll                     READ roll                     CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* rollRate                 READ rollRate                 CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* pitch                    READ pitch                    CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* pitchRate                READ pitchRate                CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* yaw                      READ yaw                      CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* yawRate                  READ yawRate                  CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* ascentRate               READ ascentRate               CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* speedOverGround          READ speedOverGround          CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* satellites               READ satellites               CONSTANT) /* uint8_t    time-varying                raw         */
    Q_PROPERTY(Fact* hDOP                     READ hDOP                     CONSTANT) /* f64        time-varying                raw         */
    Q_PROPERTY(Fact* dataQuality              READ dataQuality              CONSTANT) /* int32_t    time-varying                raw         */

    Fact* getFactPointerSRN                     ()  { return &_SRNFact; }
    Fact* getFactPointerDrone_Serial_Number     ()  { return &_SRNFact; }
    Fact* getFactPointerYYYY                    ()  { return &_YYYYFact; }
    Fact* getFactPointerMM                      ()  { return &_MMFact; }
    Fact* getFactPointerDD                      ()  { return &_DDFact; }
    Fact* getFactPointerHH                      ()  { return &_HHFact; }
    Fact* getFactPointerMm                      ()  { return &_MmFact; }
    Fact* getFactPointerss                      ()  { return &_ssFact; }
    Fact* getFactPointerString                  ()  { return &_StringFact; }
    Fact* getFactPointerMessage_Version         ()  { return &_Message_VersionFact; }
    Fact* getFactPointerDrone_Powered_Age       ()  { return &_Drone_Powered_AgeFact; }
    Fact* getFactPointerDrone_Armed_Age         ()  { return &_Drone_Armed_AgeFact; }
    Fact* getFactPointerRaw_Data_Filename       ()  { return &_Raw_Data_FilenameFact; }
    Fact* getFactPointerUnix_Start_Time         ()  { return &_Unix_Start_TimeFact; }
    Fact* getFactPointerGround_Wind_Speed       ()  { return &_Ground_Wind_SpeedFact; }
    Fact* getFactPointerGround_Wind_Direction   ()  { return &_Ground_Wind_DirectionFact; }
    Fact* getFactPointerGround_Air_Temperature  ()  { return &_Ground_Air_TemperatureFact; }
    Fact* getFactPointerGround_Humidity         ()  { return &_Ground_HumidityFact; }
    Fact* getFactPointerGround_Pressure         ()  { return &_Ground_PressureFact; }
    Fact* getFactPointerHome_Position_Latitude  ()  { return &_Home_Position_LatitudeFact; }
    Fact* getFactPointerHome_Position_Longitude ()  { return &_Home_Position_LongitudeFact; }
    Fact* getFactPointerHome_Position_Altitude  ()  { return &_Home_Position_AltitudeFact; }
    Fact* getFactPointerAltitude_ASL            ()  { return &_Altitude_ASLFact; }
    Fact* getFactPointerUTC_Date                ()  { return &_UTC_DateFact; }
    Fact* getFactPointerUTC_Time                ()  { return &_UTC_TimeFact; }
    Fact* getFactPointerTime_Since_Start        ()  { return &_Time_Since_StartFact; }
    Fact* getFactPointerPressure                ()  { return &_PressureFact; }
    Fact* getFactPointerAir_Temp                ()  { return &_Air_TempFact; }
    Fact* getFactPointerRel_Hum                 ()  { return &_Rel_HumFact; }
    Fact* getFactPointerWind_Speed              ()  { return &_Wind_SpeedFact; }
    Fact* getFactPointerWind_Direction          ()  { return &_Wind_DirectionFact; }
    Fact* getFactPointerLatitude                ()  { return &_LatitudeFact; }
    Fact* getFactPointerLongitude               ()  { return &_LongitudeFact; }
    Fact* getFactPointerRoll                    ()  { return &_RollFact; }
    Fact* getFactPointerRoll_Rate               ()  { return &_Roll_RateFact; }
    Fact* getFactPointerPitch                   ()  { return &_PitchFact; }
    Fact* getFactPointerPitch_Rate              ()  { return &_Pitch_RateFact; }
    Fact* getFactPointerYaw                     ()  { return &_YawFact; }
    Fact* getFactPointerYaw_Rate                ()  { return &_Yaw_RateFact; }
    Fact* getFactPointerAscent_Rate             ()  { return &_Ascent_RateFact; }
    Fact* getFactPointerSpeed_Over_Ground       ()  { return &_Speed_Over_GroundFact; }
    Fact* getFactPointerSatellites              ()  { return &_SatellitesFact; }
    Fact* getFactPointerHDOP                    ()  { return &_HDOPFact; }
    Fact* getFactPointerData_Quality            ()  { return &_Data_QualityFact; }

    static const char* _SRNName;
    static const char* _YYYYName;
    static const char* _MMName;
    static const char* _DDName;
    static const char* _HHName;
    static const char* _MmName;
    static const char* _ssName;
    static const char* _StringName;
    static const char* _Message_VersionName;
    static const char* _Drone_Powered_AgeName;
    static const char* _Drone_Armed_AgeName;
    static const char* _Raw_Data_FilenameName;
    static const char* _Unix_Start_TimeName;
    static const char* _Ground_Wind_SpeedName;
    static const char* _Ground_Wind_DirectionName;
    static const char* _Ground_Air_TemperatureName;
    static const char* _Ground_HumidityName;
    static const char* _Ground_PressureName;
    static const char* _Home_Position_LatitudeName;
    static const char* _Home_Position_LongitudeName;
    static const char* _Home_Position_AltitudeName;
    static const char* _Altitude_ASLName;
    static const char* _UTC_DateName;
    static const char* _UTC_TimeName;
    static const char* _Time_Since_StartName;
    static const char* _PressureName;
    static const char* _Air_TempName;
    static const char* _Rel_HumName;
    static const char* _Wind_SpeedName;
    static const char* _Wind_DirectionName;
    static const char* _LatitudeName;
    static const char* _LongitudeName;
    static const char* _RollName;
    static const char* _Roll_RateName;
    static const char* _PitchName;
    static const char* _Pitch_RateName;
    static const char* _YawName;
    static const char* _Yaw_RateName;
    static const char* _Ascent_RateName;
    static const char* _Speed_Over_GroundName;
    static const char* _SatellitesName;
    static const char* _HDOPName;
    static const char* _Data_QualityName;

private:
    Fact _SRNFact;
    Fact _YYYYFact;
    Fact _MMFact;
    Fact _DDFact;
    Fact _HHFact;
    Fact _MmFact;
    Fact _ssFact;
    Fact _StringFact;
    Fact _Message_VersionFact;
    Fact _Drone_Powered_AgeFact;
    Fact _Drone_Armed_AgeFact;
    Fact _Raw_Data_FilenameFact;
    Fact _Unix_Start_TimeFact;
    Fact _Ground_Wind_SpeedFact;
    Fact _Ground_Wind_DirectionFact;
    Fact _Ground_Air_TemperatureFact;
    Fact _Ground_HumidityFact;
    Fact _Ground_PressureFact;
    Fact _Home_Position_LatitudeFact;
    Fact _Home_Position_LongitudeFact;
    Fact _Home_Position_AltitudeFact;
    Fact _Altitude_ASLFact;
    Fact _UTC_DateFact;
    Fact _UTC_TimeFact;
    Fact _Time_Since_StartFact;
    Fact _PressureFact;
    Fact _Air_TempFact;
    Fact _Rel_HumFact;
    Fact _Wind_SpeedFact;
    Fact _Wind_DirectionFact;
    Fact _LatitudeFact;
    Fact _LongitudeFact;
    Fact _RollFact;
    Fact _Roll_RateFact;
    Fact _PitchFact;
    Fact _Pitch_RateFact;
    Fact _YawFact;
    Fact _Yaw_RateFact;
    Fact _Ascent_RateFact;
    Fact _Speed_Over_GroundFact;
    Fact _SatellitesFact;
    Fact _HDOPFact;
    Fact _Data_QualityFact;
};

#endif // MESSAGEALTITUDEFACTGROUP_H
