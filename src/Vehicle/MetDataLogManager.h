#pragma once
#include "QGCToolbox.h"
#include <QObject>
#include <QTime>
#include "Vehicle.h"

class MetDataLogManager : public QGCTool
{
    Q_OBJECT

    public:
        MetDataLogManager(QGCApplication* app, QGCToolbox* toolbox);
        ~MetDataLogManager();
    
    public slots:
        void setFlightFileName(QString flightName);

    private:

        void _initializeMetRawCsv           ();
        void _writeMetRawCsvLine            ();
        void _writeMetAlmCsvLine            ();
        void _initializeMetAlmCsv           ();

        Vehicle*            _activeVehicle;
        QTimer              _metRawCsvTimer;
        QFile               _metRawCsvFile;
        QFile               _metAlmCsvFile;

        QString             _flightName = "unnamed flight";
        int                 ascentNumber = 1;


        QStringList metAlmFactHeaders = {
            "Time",
            "ASL",
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
            "Speed Over Ground"
        };

        QStringList metAlmFactUnits = {
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
            "m/s"
        };

        QStringList metAlmFactNames = {
            "timeUnixSeconds",
            "altitudeMetersMSL",
            "absolutePressureMillibars",
            "temperatureCelsius",
            "relativeHumidity",
            "windSpeedMetersPerSecond",
            "windBearingDegrees",
            "latitudeDegrees",
            "longitudeDegrees",
            "rollDegrees",
            "rollRateDegreesPerSecond",
            "pitchDegrees",
            "pitchRateDegreesPerSecond",
            "yawDegrees",
            "yawRateDegreesPerSecond",
            "zVelocityMetersPerSecond",
            "groundSpeedMetersPerSecond"
        };

        QStringList metRawFactHeaders = {
            "Time",
            "ASL",
            "Pressure",
            "Air Temp",
            "Rel Hum",
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
            "Custom Mode"
        };

        QStringList metRawFactUnits = {
            "s",
            "m",
            "mB",
            "C",
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
            ""
        };

        QStringList metRawFactNames = {
            "timeUnixSeconds",
            "altitudeMetersMSL",
            "absolutePressureMillibars",
            "temperatureCelsius",
            "relativeHumidity",
            "latitudeDegrees",
            "longitudeDegrees",
            "rollDegrees",
            "rollRateDegreesPerSecond",
            "pitchDegrees",
            "pitchRateDegreesPerSecond",
            "yawDegrees",
            "yawRateDegreesPerSecond",
            "xVelocityMetersPerSecond",
            "yVelocityMetersPerSecond",
            "zVelocityMetersPerSecondInverted",
            "heartBeatCustomMode"
        };

};
