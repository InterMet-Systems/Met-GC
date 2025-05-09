#ifndef MESSENGERRAW_H
#define MESSENGERRAW_H

#include "MessengerBase.h"
#include "DataFactGroup.h"
#include "MessageRawFactGroup.h"
#include "DataHub.h"

class MessengerRaw final : public MessengerBase<DataFactGroup, MessageRawFactGroup> {
public:
    MessengerRaw(DataFactGroup* src, MessageRawFactGroup* data)
        : MessengerBase<DataFactGroup, MessageRawFactGroup>(src, data)
        , frequency(50.) {}
    bool criteriaMet() override;
    void publish() override;
    void log() override;
    double frequency;
    DataHub* dataHub;
private:
    /* These four are called in succession in criteriaMet */

    bool srcInit();

    /* Populates MessageRawFactGroup given DataFactGroup, performing unit/type conversions as necessary. */
    void updateData();
    /* Read some file and populate the nine facts that come from the file, assuming that they only need to be set once on startup.
       This also sets poweredAgeSeconds and armedAgeSeconds. */
    void initFileFacts();
    /* True if each fact has a valid value */
    bool validValues();
    /* True if it's been at least 1 / 'frequency' seconds since the last time it returned true */
    bool timer();
    double lastMessage = 0.;

    bool ascending();
public:
    std::vector<MessengerBaseCommon*> subscribers;
private:
    const std::string createFilename() const;
    /* logging */
    static constexpr bool logOnConnect = false; /* if true, begins writing to log file without waiting for the vehicle to become active */
    void initLogFile();
    QFile logFile;
    QString latestTimestamp = "0";
    QStringList logHeaders = {
        "Time",
        "Altitude ASL",
        "Pressure",
        "Air Temp A",
        "Air Temp B",
        "Air Temp C",
        "Rel Hum A",
        "Rel Hum B",
        "Rel Hum C",
        "Latitude",
        "Longitude",
        "Roll",
        "Roll Rate",
        "Pitch",
        "Pitch Rate",
        "Yaw",
        "Yaw Rate",
        "Velocity North",
        "Velocity East",
        "Velocity Down",
        "Custom Mode",
        "Data Quality",
        "Home Position Latitude",
        "Home Position Longitude",
        "Home Position Altitude",
        "Drone Serial Number",
        "Ground Wind Speed",
        "Ground Wind Direction",
        "Ground Air Temperature",
        "Ground Humidity",
        "Ground Pressure",
        "Powered Age",
        "Armed Age",
        "Satellites",
        "HDOP"
    };
    QStringList logUnits = {
        "s",
        "m",
        "mB",
        "C",
        "C",
        "C",
        "%",
        "%",
        "%",
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
        "m/s",
        "N/A",
        "N/A",
        "deg",
        "deg",
        "m",
        "N/A",
        "m/s",
        "deg",
        "C",
        "%",
        "mB",
        "s",
        "s",
        "N/A",
        "N/A"
    };
    QStringList logFactNames = {
        "timeUnixSeconds",
        "altitudeMetersASL",
        "absolutePressureMillibars",
        "temperature0Celsius",
        "temperature1Celsius",
        "temperature2Celsius",
        "relativeHumidity0",
        "relativeHumidity1",
        "relativeHumidity2",
        "latitudeDegrees",
        "longitudeDegrees",
        "rollDegrees",
        "pitchDegrees",
        "yawDegrees",
        "rollRateDegreesPerSecond",
        "pitchRateDegreesPerSecond",
        "yawRateDegreesPerSecond",
        "xVelocityMetersPerSecond",
        "yVelocityMetersPerSecond",
        "zVelocityMetersPerSecond",
        "customModeHeartbeat",
        "dataQuality",
        "homePositionLatitudeDegrees",
        "homePositionLongitudeDegrees",
        "homePositionAltitudeMeters",
        "droneSerialNumber",
        "groundWindSpeedMetersPerSecond",
        "groundWindDirectionDegrees",
        "groundAirTemperatureCelsius",
        "groundHumidity",
        "groundPressureMillibars",
        "poweredAgeSeconds",
        "armedAgeSeconds",
        "satellites",
        "horizontalDilutionOfPositionFloat"
    };
};

#endif // MESSENGERRAW_H
