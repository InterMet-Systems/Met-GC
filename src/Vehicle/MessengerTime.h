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
    QStringList logFactNames = {
        "UTC date",
        "UTC time",
        "time since start",
        "altitude ASL",
        "pressure",
        "air temp",
        "rel hum",
        "wind speed",
        "wind direction",
        "latitude",
        "longitude",
        "roll",
        "roll rate",
        "pitch",
        "pitch rate",
        "yaw",
        "yaw rate",
        "ascent rate",
        "speed over ground",
        "satellites",
        "hdop",
        "data quality",
    };
};

#endif // MESSENGERTIME_H
