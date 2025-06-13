#ifndef MESSENGERALTITUDE_H
#define MESSENGERALTITUDE_H

#include "MessengerBase.h"
#include "MessageRawFactGroup.h"
#include "MessageAltitudeFactGroup.h"

class MessengerAltitude final : public MessengerBase<MessageRawFactGroup, MessageAltitudeFactGroup> {
public:
    MessengerAltitude(MessageRawFactGroup* src, MessageAltitudeFactGroup* data)
        : MessengerBase<MessageRawFactGroup, MessageAltitudeFactGroup>(src, data) {}
    bool criteriaMet() override;
    void publish() override;
    void log() override;
private:

    struct WindProps {
        double speed = 0.;
        int32_t dir = 0;
    };

    void updateTime();
    std::tm* pt;
    void updateConstantData();
    void getStringFromUser();
    double* windSpeedDir(const double roll, const double pitch, const double yaw);
    double groundSpeed(const double vx, const double vy);
    const WindProps calcWindProps() const;
    void buildFilename();
    void buildUTCDateStr();
    void buildUTCTimeStr();
    void updateData();

    bool passedThreshold();
    bool handleFirstAltitude(const double alt);
    static constexpr double altitudeBin = 5.;
    static constexpr double maxHomeAlt = 8848.86;   /* Everest */
    static constexpr double minHomeAlt = -414.;     /* Dead sea */
    static constexpr double homeAltRange = 512.;    /* If home altitude is provided, ignore initial altitude reports more than this distance from home altitude */
    double lastAltBin = qQNaN();

    /* new way of collating data */
    static constexpr int bufferCapacity = 32;
    typedef struct {
        double pressure;
    } ALMData;
    int head, tail, count;
    ALMData buffer[bufferCapacity];
    void initBuffer();
    void resetBuffer();
    ALMData collateData();

    /* logging */
    static constexpr bool logOnConnect = false; /* if true, begins writing to log file without waiting for the vehicle to become active */
    void initLogFile();
    QFile logFile;
    QString latestTimestamp = "0";
    QStringList logHeaders = {
        "Altitude ASL",
        "UTC Date",
        "UTC Time",
        "Time Since Start",
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
        "m",
        "MM/DD/YY",
        "HH:MM:SS",
        "s",
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
        "altitudeASL",
        "uTCDate",
        "uTCTime",
        "timeSinceStart",
        "pressure",
        "airTemp",
        "relHum",
        "windSpeed",
        "windDirection",
        "latitude",
        "longitude",
        "roll",
        "rollRate",
        "pitch",
        "pitchRate",
        "yaw",
        "yawRate",
        "ascentRate",
        "speedOverGround",
        "satellites",
        "hDOP",
        "dataQuality"
    };
    QStringList logConstantNames = {
        "Message Version",
        "Drone Serial Number",
        "Drone Powered Age",
        "Drone Armed Age",
        "Raw Data Filename",
        "Unix Start Time",
        "Ground Wind Speed",
        "Ground Wind Direction",
        "Ground Air Temperature",
        "Ground Humidity",
        "Ground Pressure",
        "Home Position Latitude",
        "Home Position Longitude",
        "Home Position Altitude"
    };
    QStringList logConstantUnits = {
        "N/A",
        "N/A",
        "s",
        "s",
        "N/A",
        "s",
        "m/s",
        "deg",
        "C",
        "%",
        "mB",
        "deg",
        "deg",
        "m"
    };
    QStringList logConstantFactNames = {
        "messageVersion",
        "droneSerial",
        "dronePoweredAge",
        "droneArmedAge",
        "rawDataFilename",
        "unixStartTime",
        "groundWindSpeed",
        "groundWindDirection",
        "groundAirTemperature",
        "groundHumidity",
        "groundPressure",
        "homePositionLatitude",
        "homePositionLongitude",
        "homePositionAltitude"
    };
};

#endif // MESSENGERALTITUDE_H
