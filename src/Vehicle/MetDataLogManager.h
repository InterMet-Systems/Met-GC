#pragma once
#include "QGCToolbox.h"
#include <QObject>
#include <QTime>
#include "Vehicle.h"
#include <libs/netcdf-cxx4/cxx4/netcdf>

using namespace std;
using namespace netCDF;
using namespace netCDF::exceptions;

class MetDataLogManager : public QGCTool
{
    Q_OBJECT

    public:
        MetDataLogManager(QGCApplication* app, QGCToolbox* toolbox);
        ~MetDataLogManager();
    
    public slots:
        void setFlightFileName(QString flightName);
        void setOperatorId(QString operatorId);
        void setAirframeId(QString airframeId);
        void setAscentNumber(int ascentNumber);

    private:

        void _initializeMetRawCsv           ();
        void _writeMetRawCsvLine            ();
        void _writeMetAlmCsvLine            ();
        void _initializeMetAlmCsv           ();
        void _initializeMetNetCdf           ();
        void _writeMetNetCdfLine            ();

        Vehicle*            _activeVehicle;
        QTimer              _metRawCsvTimer;
        QTimer              _metAlmCsvTimer;
        QTimer              _metNetCdfTimer;
        QFile               _metRawCsvFile;
        QFile               _metAlmCsvFile;
        NcFile              _metNetCdfFile = NcFile();

        QString             _openNetCdfFile = "";

        QString             DEFAULT_OPERATOR_ID = "operatorid";
        QString             DEFAULT_AIRFRAME_ID = "airframeid";

        QString             _flightName = "unnamed flight";
        QString             _operatorId = DEFAULT_OPERATOR_ID;
        QString             _airframeId = DEFAULT_AIRFRAME_ID;

        int                 _ascentNumber = 0;

        QString             _latestRawTimestamp = "0";
        QString             _latestAlmTimestamp = "0";
        QString            _latestNetCdfTimestamp = "0";

        bool                netCdfFileInitialized = false;

        QStringList metAlmFactHeaders = {
            "ASL",
            "Time",
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
            "m",
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
            "m/s"
        };

        QStringList metAlmFactNames = {
            "asl",
            "time",
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
            "speedOverGround"
        };

        QStringList metRawFactHeaders = {
            "Time",
            "ASL",
            "Pressure",
            "Air Temp 1",
            "Air Temp 2",
            "Air Temp 3",
            "Rel Hum 1",
            "Rel Hum 2",
            "Rel Hum 3",
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
            ""
        };

        QStringList metRawFactNames = {
            "timeUnixSeconds",
            "altitudeMetersMSL",
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


        vector<size_t> startp;

        // NetCdf Variables
        NcVar altitude;
        NcVar time;
        NcVar pressure;
        NcVar airTemp;
        NcVar relHum;
        NcVar windSpeed;
        NcVar windDirection;
        NcVar latitude;
        NcVar longitude;
        NcVar roll;
        NcVar rollRate;
        NcVar pitch;
        NcVar pitchRate;
        NcVar yaw;
        NcVar yawRate;
        NcVar speedOverGround;
        NcVar speedOverGroundUp;
        NcVar mixRatio;

};
