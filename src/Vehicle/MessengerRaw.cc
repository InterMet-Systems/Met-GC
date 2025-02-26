#include "MessengerRaw.h"
#include "QDebug"
#include "QGCApplication.h"
#include "MetDataLogManager.h"

#define K_TO_C(k) ((k) - 273.15)
#define RAD_TO_DEG(r) ((r) * (180.0 / M_PI))

void MessengerRaw::updateData(){
    uint64_t time = source->getFactPointerTimeUnixMicroseconds()->rawValue().toULongLong();
    data->getFactPointerTimeUnixSeconds()->setRawValue(QVariant(static_cast<double>(time) / 1e6));

    int32_t alt = source->getFactPointerAltitudeMillimetersMSL()->rawValue().toInt();
    data->getFactPointerAltitudeMetersASL()->setRawValue(QVariant(static_cast<double>(alt) / 1e3));

    double pres = source->getFactPointerAbsolutePressureMillibars()->rawValue().toDouble();
    data->getFactPointerAbsolutePressureMillibars()->setRawValue(QVariant(pres));

    double t0 = source->getFactPointerTemperature0Kelvin()->rawValue().toDouble();
    data->getFactPointerTemperature0Celsius()->setRawValue(QVariant(K_TO_C(t0)));

    double t1 = source->getFactPointerTemperature1Kelvin()->rawValue().toDouble();
    data->getFactPointerTemperature1Celsius()->setRawValue(QVariant(K_TO_C(t1)));

    double t2 = source->getFactPointerTemperature2Kelvin()->rawValue().toDouble();
    data->getFactPointerTemperature2Celsius()->setRawValue(QVariant(K_TO_C(t2)));

    double h0 = source->getFactPointerRelativeHumidity0()->rawValue().toDouble();
    data->getFactPointerRelativeHumidity0()->setRawValue(QVariant(h0));

    double h1 = source->getFactPointerRelativeHumidity1()->rawValue().toDouble();
    data->getFactPointerRelativeHumidity1()->setRawValue(QVariant(h1));

    double h2 = source->getFactPointerRelativeHumidity2()->rawValue().toDouble();
    data->getFactPointerRelativeHumidity2()->setRawValue(QVariant(h2));

    int32_t lat = source->getFactPointerLatitudeDegreesE7()->rawValue().toInt();
    data->getFactPointerLatitudeDegrees()->setRawValue(QVariant(static_cast<double>(lat) / 1e7));

    int32_t lon = source->getFactPointerLongitudeDegreesE7()->rawValue().toInt();
    data->getFactPointerLongitudeDegrees()->setRawValue(QVariant(static_cast<double>(lon) / 1e7));

    double roll = source->getFactPointerRollRadians()->rawValue().toDouble();
    data->getFactPointerRollDegrees()->setRawValue(QVariant(RAD_TO_DEG(roll)));

    double pitch = source->getFactPointerPitchRadians()->rawValue().toDouble();
    data->getFactPointerPitchDegrees()->setRawValue(QVariant(RAD_TO_DEG(pitch)));

    double yaw = source->getFactPointerYawRadians()->rawValue().toDouble();
    data->getFactPointerYawDegrees()->setRawValue(QVariant(RAD_TO_DEG(yaw)));

    double rollrate = source->getFactPointerRollRateRadiansPerSecond()->rawValue().toDouble();
    data->getFactPointerRollRateDegreesPerSecond()->setRawValue(QVariant(RAD_TO_DEG(rollrate)));

    double pitchrate = source->getFactPointerPitchRateRadiansPerSecond()->rawValue().toDouble();
    data->getFactPointerPitchRateDegreesPerSecond()->setRawValue(QVariant(RAD_TO_DEG(pitchrate)));

    double yawrate = source->getFactPointerYawRateRadiansPerSecond()->rawValue().toDouble();
    data->getFactPointerYawRateDegreesPerSecond()->setRawValue(QVariant(RAD_TO_DEG(yawrate)));

    double vx = source->getFactPointerXVelocityMetersPerSecond()->rawValue().toDouble();
    data->getFactPointerXVelocityMetersPerSecond()->setRawValue(QVariant(vx));

    double vy = source->getFactPointerYVelocityMetersPerSecond()->rawValue().toDouble();
    data->getFactPointerYVelocityMetersPerSecond()->setRawValue(QVariant(vy));

    double vz = source->getFactPointerZVelocityMetersPerSecond()->rawValue().toDouble();
    data->getFactPointerZVelocityMetersPerSecond()->setRawValue(QVariant(vz));

    uint32_t heartbeat = source->getFactPointerCustomModeHeartbeat()->rawValue().toUInt();
    data->getFactPointerCustomModeHeartbeat()->setRawValue(QVariant(heartbeat));

    int32_t quality = source->getFactPointerDataQuality()->rawValue().toInt();
    data->getFactPointerDataQuality()->setRawValue(QVariant(quality));

    uint8_t sats = source->getFactPointerSatellites()->rawValue().toUInt();
    data->getFactPointerSatellites()->setRawValue(QVariant(sats));

    uint16_t hdop = source->getFactPointerHorizontalDilutionOfPosition()->rawValue().toUInt();
    data->getFactPointerHorizontalDilutionOfPositionFloat()->setRawValue(QVariant(static_cast<double>(hdop) / 100));
}

void MessengerRaw::initFileFacts(){
    static bool init = false;
    if (init) return;
    /*
        The SoW says that the source of these facts is a file, but what file?
        Whatever it is, presumably the file only needs to be read once, so do so and upate these facts here.

        homePositionLatitudeDegrees
        homePositionLongitudeDegrees
        homePositionAltitudeMeters
        droneSerialNumber
        groundWindSpeedMetersPerSecond
        groundWindDirectionDegrees
        groundAirTemperatureCelsius
        groundHumidity
        groundPressureMillibars

        SoW doesn't list a source at all for these two, but if they are updated once on startup, and not continuously, then this is a good place to set them.

        poweredAgeSeconds
        armedAgeSeconds
    */
    init = true;
}

bool MessengerRaw::validValues(){
    static bool init = false;
    if (init) return true;
    /* for each fact marked 'required' in SoW, check that it's not NaN, if one is, then return false. */
    if (data->getFactPointerTimeUnixSeconds()->rawValue().toDouble() == qQNaN()){
        /* Maybe log something like "We don't have timeUnixSeconds yet" */
        return false;
    }
    if (data->getFactPointerAltitudeMetersASL()->rawValue().toDouble() ==               qQNaN())                                return false;
    if (data->getFactPointerAbsolutePressureMillibars()->rawValue().toDouble() ==       qQNaN())                                return false;
    if (data->getFactPointerTemperature0Celsius()->rawValue().toDouble() ==             qQNaN())                                return false;
    if (data->getFactPointerTemperature1Celsius()->rawValue().toDouble() ==             qQNaN())                                return false;
    if (data->getFactPointerTemperature2Celsius()->rawValue().toDouble() ==             qQNaN())                                return false;
    if (data->getFactPointerRelativeHumidity0()->rawValue().toDouble() ==               qQNaN())                                return false;
    if (data->getFactPointerRelativeHumidity1()->rawValue().toDouble() ==               qQNaN())                                return false;
    if (data->getFactPointerRelativeHumidity2()->rawValue().toDouble() ==               qQNaN())                                return false;
    if (data->getFactPointerLatitudeDegrees()->rawValue().toDouble() ==                 qQNaN())                                return false;
    if (data->getFactPointerLongitudeDegrees()->rawValue().toDouble() ==                qQNaN())                                return false;
    if (data->getFactPointerRollDegrees()->rawValue().toDouble() ==                     qQNaN())                                return false;
    if (data->getFactPointerPitchDegrees()->rawValue().toDouble() ==                    qQNaN())                                return false;
    if (data->getFactPointerYawDegrees()->rawValue().toDouble() ==                      qQNaN())                                return false;
    if (data->getFactPointerRollRateDegreesPerSecond()->rawValue().toDouble() ==        qQNaN())                                return false;
    if (data->getFactPointerPitchRateDegreesPerSecond()->rawValue().toDouble() ==       qQNaN())                                return false;
    if (data->getFactPointerYawRateDegreesPerSecond()->rawValue().toDouble() ==         qQNaN())                                return false;
    if (data->getFactPointerXVelocityMetersPerSecond()->rawValue().toDouble() ==        qQNaN())                                return false;
    if (data->getFactPointerYVelocityMetersPerSecond()->rawValue().toDouble() ==        qQNaN())                                return false;
    if (data->getFactPointerZVelocityMetersPerSecond()->rawValue().toDouble() ==        qQNaN())                                return false;
    if (data->getFactPointerCustomModeHeartbeat()->rawValue().toUInt() ==               std::numeric_limits<uint32_t>::max())   return false;
    if (data->getFactPointerSatellites()->rawValue().toUInt() ==                        std::numeric_limits<uint8_t>::max())    return false;
    if (data->getFactPointerHorizontalDilutionOfPositionFloat()->rawValue().toUInt() == qQNaN())                                return false;
    return init = true;
}

bool MessengerRaw::timer() {
    double t = std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count();
    if (t - lastMessage >= (1 / frequency)) {
        lastMessage = t;
        return true;
    }
    return false;
}

const std::string MessengerRaw::createFilename() const{
    /* TODO: go find out from a previous SOW how the raw message file name was created since current SoW says "unchanged".
        Also, we need to call this some place. Obviously it only needs to be called once, and right on startup. But, this can't be done until I figure out what
        information is needed to create the filename in the first place.
    */
    return std::string("");
}

/* return true if drone is ascending, and if this is the first message of an ascent, update metDataLogManager */
bool MessengerRaw::ascending() {
    static bool bAscending = false;
    static bool bLastState = false;
    static size_t ascents = 0;

    uint32_t hearbeat = data->getFactPointerCustomModeHeartbeat()->rawValue().toUInt();
    double vz = -data->getFactPointerZVelocityMetersPerSecond()->rawValue().toDouble();
    if ((bAscending = (hearbeat == 3 && vz > 2.5)) && !bLastState)
        qgcApp()->toolbox()->metDataLogManager()->setAscentNumber(++ascents);
    bLastState = bAscending;
    return bAscending;
}

bool MessengerRaw::criteriaMet() {
    updateData();
    initFileFacts();
    if (!ascending()) return false;
    if (!validValues()) return false;
    if (!timer()) return false;
    return true;
}

void MessengerRaw::publish() {
    /* this is where you would do things like write to the raw log file or update GUI */

    for (size_t i = 0; i < subscribers.size(); i++)
        if (subscribers[i].criteriaMet())
            subscribers[i].publish();

    if (dataHub) dataHub->resetAverages();
    else qDebug() << "no datahub linked";
}

#undef K_TO_C
#undef RAD_TO_DEG
