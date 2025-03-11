#include "MessengerRaw.h"
#include "QDebug"
#include "QGCApplication.h"
#include "MetDataLogManager.h"
#include "IMetMath.h"

void MessengerRaw::updateData(){
    uint64_t time = source->getFactPointerTimeUnixMicroseconds()->rawValue().toULongLong();
    data->timeUnixSeconds()->setRawValue(QVariant(static_cast<double>(time) / 1e6));

    int32_t alt = source->getFactPointerAltitudeMillimetersMSL()->rawValue().toInt();
    data->altitudeMetersASL()->setRawValue(QVariant(static_cast<double>(alt) / 1e3));

    double pres = source->getFactPointerAbsolutePressureMillibars()->rawValue().toDouble();
    data->absolutePressureMillibars()->setRawValue(QVariant(pres));

    double t0 = source->getFactPointerTemperature0Kelvin()->rawValue().toDouble();
    IMetMath::SResult t0_r = IMetMath::KelvinToCelsius(t0);
    assert(t0_r.result == IMetMath::Result::_SUCCESS);
    if (t0_r.result == IMetMath::Result::_SUCCESS)
        data->temperature0Celsius()->setRawValue(QVariant(t0_r.value));
    else {
        /* TODO: Find out if we need any form of runtime error handling here, and which conditions are permissble to pass along silently. For instance,
            we may wish to simply log the error and continue given that the function only returns either 0.0 or a mathmatically valid value, which may
            still be nonsense, for instance < absolute zero. */
        data->temperature0Celsius()->setRawValue(QVariant(t0_r.value));
    }

    double t1 = source->getFactPointerTemperature1Kelvin()->rawValue().toDouble();
    IMetMath::SResult t1_r = IMetMath::KelvinToCelsius(t1);
    assert(t1_r.result == IMetMath::Result::_SUCCESS);
    data->temperature1Celsius()->setRawValue(QVariant(t1_r.value));

    double t2 = source->getFactPointerTemperature2Kelvin()->rawValue().toDouble();
    IMetMath::SResult t2_r = IMetMath::KelvinToCelsius(t2);
    assert(t2_r.result == IMetMath::Result::_SUCCESS);
    data->temperature2Celsius()->setRawValue(QVariant(t2_r.value));

    double h0 = source->getFactPointerRelativeHumidity0()->rawValue().toDouble();
    data->relativeHumidity0()->setRawValue(QVariant(h0));

    double h1 = source->getFactPointerRelativeHumidity1()->rawValue().toDouble();
    data->relativeHumidity1()->setRawValue(QVariant(h1));

    double h2 = source->getFactPointerRelativeHumidity2()->rawValue().toDouble();
    data->relativeHumidity2()->setRawValue(QVariant(h2));

    int32_t lat = source->getFactPointerLatitudeDegreesE7()->rawValue().toInt();
    data->latitudeDegrees()->setRawValue(QVariant(static_cast<double>(lat) / 1e7));

    int32_t lon = source->getFactPointerLongitudeDegreesE7()->rawValue().toInt();
    data->longitudeDegrees()->setRawValue(QVariant(static_cast<double>(lon) / 1e7));

    double roll = source->getFactPointerRollRadians()->rawValue().toDouble();
    IMetMath::SResult roll_r = IMetMath::RadiansToDegrees(roll);
    assert(roll_r.result == IMetMath::Result::_SUCCESS);
    data->rollDegrees()->setRawValue(QVariant(roll_r.value));

    double pitch = source->getFactPointerPitchRadians()->rawValue().toDouble();
    IMetMath::SResult pitch_r = IMetMath::RadiansToDegrees(pitch);
    assert(pitch_r.result == IMetMath::Result::_SUCCESS);
    data->pitchDegrees()->setRawValue(QVariant(pitch_r.value));

    double yaw = source->getFactPointerYawRadians()->rawValue().toDouble();
    IMetMath::SResult yaw_r = IMetMath::RadiansToDegrees(yaw);
    assert(yaw_r.result == IMetMath::Result::_SUCCESS);
    data->yawDegrees()->setRawValue(QVariant(yaw_r.value));

    double rollrate = source->getFactPointerRollRateRadiansPerSecond()->rawValue().toDouble();
    IMetMath::SResult rollrate_r = IMetMath::RadiansToDegrees(rollrate);
    assert(rollrate_r.result == IMetMath::Result::_SUCCESS);
    data->rollRateDegreesPerSecond()->setRawValue(QVariant(rollrate_r.value));

    double pitchrate = source->getFactPointerPitchRateRadiansPerSecond()->rawValue().toDouble();
    IMetMath::SResult pitchrate_r = IMetMath::RadiansToDegrees(pitchrate);
    assert(pitchrate_r.result == IMetMath::Result::_SUCCESS);
    data->pitchRateDegreesPerSecond()->setRawValue(QVariant(pitchrate_r.value));

    double yawrate = source->getFactPointerYawRateRadiansPerSecond()->rawValue().toDouble();
    IMetMath::SResult yawrate_r = IMetMath::RadiansToDegrees(yawrate);
    assert(yawrate_r.result == IMetMath::Result::_SUCCESS);
    data->yawRateDegreesPerSecond()->setRawValue(QVariant(yawrate_r.value));

    double vx = source->getFactPointerXVelocityMetersPerSecond()->rawValue().toDouble();
    data->xVelocityMetersPerSecond()->setRawValue(QVariant(vx));

    double vy = source->getFactPointerYVelocityMetersPerSecond()->rawValue().toDouble();
    data->yVelocityMetersPerSecond()->setRawValue(QVariant(vy));

    double vz = source->getFactPointerZVelocityMetersPerSecond()->rawValue().toDouble();
    data->zVelocityMetersPerSecond()->setRawValue(QVariant(vz));

    uint32_t heartbeat = source->getFactPointerCustomModeHeartbeat()->rawValue().toUInt();
    data->customModeHeartbeat()->setRawValue(QVariant(heartbeat));

    int32_t quality = source->getFactPointerDataQuality()->rawValue().toInt();
    data->dataQuality()->setRawValue(QVariant(quality));

    uint8_t sats = source->getFactPointerSatellites()->rawValue().toUInt();
    data->satellites()->setRawValue(QVariant(sats));

    uint16_t hdop = source->getFactPointerHorizontalDilutionOfPosition()->rawValue().toUInt();
    data->horizontalDilutionOfPositionFloat()->setRawValue(QVariant(static_cast<double>(hdop) / 100));
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
    if (data->timeUnixSeconds()->rawValue().toDouble() == qQNaN()){
        /* Maybe log something like "We don't have timeUnixSeconds yet" */
        return false;
    }
    if (data->altitudeMetersASL()->rawValue().toDouble() ==               qQNaN())                                return false;
    if (data->absolutePressureMillibars()->rawValue().toDouble() ==       qQNaN())                                return false;
    if (data->temperature0Celsius()->rawValue().toDouble() ==             qQNaN())                                return false;
    if (data->temperature1Celsius()->rawValue().toDouble() ==             qQNaN())                                return false;
    if (data->temperature2Celsius()->rawValue().toDouble() ==             qQNaN())                                return false;
    if (data->relativeHumidity0()->rawValue().toDouble() ==               qQNaN())                                return false;
    if (data->relativeHumidity1()->rawValue().toDouble() ==               qQNaN())                                return false;
    if (data->relativeHumidity2()->rawValue().toDouble() ==               qQNaN())                                return false;
    if (data->latitudeDegrees()->rawValue().toDouble() ==                 qQNaN())                                return false;
    if (data->longitudeDegrees()->rawValue().toDouble() ==                qQNaN())                                return false;
    if (data->rollDegrees()->rawValue().toDouble() ==                     qQNaN())                                return false;
    if (data->pitchDegrees()->rawValue().toDouble() ==                    qQNaN())                                return false;
    if (data->yawDegrees()->rawValue().toDouble() ==                      qQNaN())                                return false;
    if (data->rollRateDegreesPerSecond()->rawValue().toDouble() ==        qQNaN())                                return false;
    if (data->pitchRateDegreesPerSecond()->rawValue().toDouble() ==       qQNaN())                                return false;
    if (data->yawRateDegreesPerSecond()->rawValue().toDouble() ==         qQNaN())                                return false;
    if (data->xVelocityMetersPerSecond()->rawValue().toDouble() ==        qQNaN())                                return false;
    if (data->yVelocityMetersPerSecond()->rawValue().toDouble() ==        qQNaN())                                return false;
    if (data->zVelocityMetersPerSecond()->rawValue().toDouble() ==        qQNaN())                                return false;
    if (data->customModeHeartbeat()->rawValue().toUInt() ==               std::numeric_limits<uint32_t>::max())   return false;
    if (data->satellites()->rawValue().toUInt() ==                        std::numeric_limits<uint8_t>::max())    return false;
    if (data->horizontalDilutionOfPositionFloat()->rawValue().toUInt() == qQNaN())                                return false;
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

    uint32_t hearbeat = data->customModeHeartbeat()->rawValue().toUInt();
    double vz = -data->zVelocityMetersPerSecond()->rawValue().toDouble();
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
