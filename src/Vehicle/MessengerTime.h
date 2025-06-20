#ifndef MESSENGERTIME_H
#define MESSENGERTIME_H

#include "MessengerBase.h"
#include "MessageRawFactGroup.h"
#include "MessageTimeFactGroup.h"

class MessengerTime final : public MessengerBase<MessageRawFactGroup, MessageTimeFactGroup> {
public:
    MessengerTime(MessageRawFactGroup* src, MessageTimeFactGroup* data)
        : MessengerBase<MessageRawFactGroup, MessageTimeFactGroup>(src, data)
        , frequency(1.) {}
    bool criteriaMet() override;
    void publish() override;
    void log() override;
private:
    struct WindProps {
        double speed = 0.;
        int32_t dir = 0;
    };

    void updateConstantData();
    void buildFilename();
    void updateTime();
    std::tm* pt;
    void updateData();
    void buildUTCDateStr();
    void buildUTCTimeStr();
    bool timer();
    double lastMessage = 0.;
    double frequency;
    const WindProps calcWindProps() const; /* copy pasted from MessengerAltitude */

    static constexpr bool logOnConnect = false; /* if true, begins writing to log file without waiting for the vehicle to become active */
    void initLogFile();
    void logConstantData();
    QFile logFile;
    QString latestTimestamp = "0";
    QStringList logHeaders = {
        "UTC Date",
        "UTC Time",
        "Time Since Start",
        "Altitude ASL",
        "Pressure",
        "Air Temp",
        "Rel Hum",
        "Wind Speed",
        "Wind Direction",
        "Latitude",
        "Longitude",
        "Roll",
        "Roll Rate",
        "Pitch",
        "Pitch Rate",
        "Yaw",
        "Yaw Rate",
        "Ascent Rate",
        "Speed Over Ground",
        "Satellites",
        "HDOP",
        "Data Quality"
    };
    QStringList logUnits = {
        "MM/DD/YY",
        "HH:MM:SS",
        "s",
        "m",
        "mB",
        "C",
        "%",
        "m/s",
        "deg",
        "deg",
        "deg",
        "deg",
        "deg/s",
        "deg",
        "deg/s",
        "deg",
        "deg/s",
        "m/s",
        "m/s",
        "N/A",
        "N/A",
        "N/A"
    };
    typedef struct {
        QString str;
        char format;
        int precision;
    } LogItem;
    typedef struct {
        QString str, labelStr;
        char format;
        int precision;
        QString unitStr;
    } ConstantDataItem;
    QList<LogItem> logItems = {
        { "uTCDate",              0, 0 },
        { "uTCTime",              0, 0 },
        { "timeSinceStart",     'i', 0 },
        { "altitudeASL",        'f', 1 },
        { "pressure",           'f', 2 },
        { "airTemp",            'f', 2 },
        { "relHum",             'f', 1 },
        { "windSpeed",          'f', 1 },
        { "windDirection",      'i', 0 },
        { "latitude",           'f', 6 },
        { "longitude",          'f', 6 },
        { "roll",               'f', 1 },
        { "rollRate",           'f', 1 },
        { "pitch",              'f', 1 },
        { "pitchRate",          'f', 1 },
        { "yaw",                'f', 1 },
        { "yawRate",            'f', 1 },
        { "ascentRate",         'f', 1 },
        { "speedOverGround",    'f', 1 },
        { "satellites",         'i', 0 },
        { "hDOP",               'f', 1 },
        { "dataQuality",        'i', 0 },
    };
    QList<ConstantDataItem> constantDatalogItems = {
        { "messageVersion",         "Message Version",            0,    0,    "" },
        { "droneSerial",            "Drone Serial Number",      'i',    0,    "" },
        { "dronePoweredAge",        "Drone Powered Age",        'i',    0,   "s" },
        { "droneArmedAge",          "Drone Armed Age",          'i',    0,   "s" },
        { "rawDataFilename",        "Raw Data Filename",          0,    0,    "" },
        { "unixStartTime",          "Unix Start Time",          'i',    0,   "s" },
        { "groundWindSpeed",        "Ground Wind Speed",        'f',    1, "m/s" },
        { "groundWindDirection",    "Ground Wind Direction",    'i',    0, "deg" },
        { "groundAirTemperature",   "Ground Air Temperature",   'f',    2,   "C" },
        { "groundHumidity",         "Ground Humidity",          'f',    1,   "%" },
        { "groundPressure",         "Ground Pressure",          'f',    2,  "mB" },
        { "homePositionLatitude",   "Home Position Latitude",   'f',    6, "deg" },
        { "homePositionLongitude",  "Home Position Longitude",  'f',    6, "deg" },
        { "homePositionAltitude",   "Home Position Altitude",   'f',    1,   "m" },
    };
};

#endif // MESSENGERTIME_H
