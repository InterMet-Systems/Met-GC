#include "MessengerRaw.h"
#include "QDebug"
#include "QGCApplication.h"
#include "MetDataLogManager.h"
#include "IMetMath.h"

void MessengerRaw::updateData(){
    uint64_t time = source->timeUnixMicroseconds()->rawValue().toULongLong();
    data->timeUnixSeconds()->setRawValue(QVariant(static_cast<double>(time) / 1e6));

    int32_t alt = source->altitudeMillimetersMSL()->rawValue().toInt();
    data->altitudeMetersASL()->setRawValue(QVariant(static_cast<double>(alt) / 1e3));

    double pres = source->absolutePressureMillibars()->rawValue().toDouble();
    data->absolutePressureMillibars()->setRawValue(QVariant(pres));

    double t0 = source->temperature0Kelvin()->rawValue().toDouble();
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

    double t1 = source->temperature1Kelvin()->rawValue().toDouble();
    IMetMath::SResult t1_r = IMetMath::KelvinToCelsius(t1);
    assert(t1_r.result == IMetMath::Result::_SUCCESS);
    data->temperature1Celsius()->setRawValue(QVariant(t1_r.value));

    double t2 = source->temperature2Kelvin()->rawValue().toDouble();
    IMetMath::SResult t2_r = IMetMath::KelvinToCelsius(t2);
    assert(t2_r.result == IMetMath::Result::_SUCCESS);
    data->temperature2Celsius()->setRawValue(QVariant(t2_r.value));

    double h0 = source->relativeHumidity0()->rawValue().toDouble();
    data->relativeHumidity0()->setRawValue(QVariant(h0));

    double h1 = source->relativeHumidity1()->rawValue().toDouble();
    data->relativeHumidity1()->setRawValue(QVariant(h1));

    double h2 = source->relativeHumidity2()->rawValue().toDouble();
    data->relativeHumidity2()->setRawValue(QVariant(h2));

    int32_t lat = source->latitudeDegreesE7()->rawValue().toInt();
    data->latitudeDegrees()->setRawValue(QVariant(static_cast<double>(lat) / 1e7));

    int32_t lon = source->longitudeDegreesE7()->rawValue().toInt();
    data->longitudeDegrees()->setRawValue(QVariant(static_cast<double>(lon) / 1e7));

    double roll = source->rollRadians()->rawValue().toDouble();
    IMetMath::SResult roll_r = IMetMath::RadiansToDegrees(roll);
    assert(roll_r.result == IMetMath::Result::_SUCCESS || roll_r.result == IMetMath::Result::_INPUT_EXCEEDS_RANGE
           || roll_r.result == IMetMath::Result::_OUTPUT_EXCEEDS_RANGE);
    data->rollDegrees()->setRawValue(QVariant(roll_r.value));

    double pitch = source->pitchRadians()->rawValue().toDouble();
    IMetMath::SResult pitch_r = IMetMath::RadiansToDegrees(pitch);
    assert(pitch_r.result == IMetMath::Result::_SUCCESS || pitch_r.result == IMetMath::Result::_INPUT_EXCEEDS_RANGE
           || pitch_r.result == IMetMath::Result::_OUTPUT_EXCEEDS_RANGE);
    data->pitchDegrees()->setRawValue(QVariant(pitch_r.value));

    double yaw = source->yawRadians()->rawValue().toDouble();
    IMetMath::SResult yaw_r = IMetMath::RadiansToDegrees(yaw);
    assert(yaw_r.result == IMetMath::Result::_SUCCESS || yaw_r.result == IMetMath::Result::_INPUT_EXCEEDS_RANGE
           || yaw_r.result == IMetMath::Result::_OUTPUT_EXCEEDS_RANGE);
    data->yawDegrees()->setRawValue(QVariant(yaw_r.value));

    double rollrate = source->rollRateRadiansPerSecond()->rawValue().toDouble();
    IMetMath::SResult rollrate_r = IMetMath::RadiansToDegrees(rollrate);
    assert(rollrate_r.result == IMetMath::Result::_SUCCESS || rollrate_r.result == IMetMath::Result::_INPUT_EXCEEDS_RANGE
           || rollrate_r.result == IMetMath::Result::_OUTPUT_EXCEEDS_RANGE);
    data->rollRateDegreesPerSecond()->setRawValue(QVariant(rollrate_r.value));

    double pitchrate = source->pitchRateRadiansPerSecond()->rawValue().toDouble();
    IMetMath::SResult pitchrate_r = IMetMath::RadiansToDegrees(pitchrate);
    assert(pitchrate_r.result == IMetMath::Result::_SUCCESS || pitchrate_r.result == IMetMath::Result::_INPUT_EXCEEDS_RANGE
           || pitchrate_r.result == IMetMath::Result::_OUTPUT_EXCEEDS_RANGE);
    data->pitchRateDegreesPerSecond()->setRawValue(QVariant(pitchrate_r.value));

    double yawrate = source->yawRateRadiansPerSecond()->rawValue().toDouble();
    IMetMath::SResult yawrate_r = IMetMath::RadiansToDegrees(yawrate);
    assert(yawrate_r.result == IMetMath::Result::_SUCCESS || yawrate_r.result == IMetMath::Result::_INPUT_EXCEEDS_RANGE
           || yawrate_r.result == IMetMath::Result::_OUTPUT_EXCEEDS_RANGE);
    data->yawRateDegreesPerSecond()->setRawValue(QVariant(yawrate_r.value));

    double vx = source->xVelocityMetersPerSecond()->rawValue().toDouble();
    data->xVelocityMetersPerSecond()->setRawValue(QVariant(vx));

    double vy = source->yVelocityMetersPerSecond()->rawValue().toDouble();
    data->yVelocityMetersPerSecond()->setRawValue(QVariant(vy));

    double vz = source->zVelocityMetersPerSecond()->rawValue().toDouble();
    data->zVelocityMetersPerSecond()->setRawValue(QVariant(vz));

    uint32_t heartbeat = source->customModeHeartbeat()->rawValue().toUInt();
    data->customModeHeartbeat()->setRawValue(QVariant(heartbeat));

    int32_t quality = source->dataQuality()->rawValue().toInt();
    data->dataQuality()->setRawValue(QVariant(quality));

    uint8_t sats = source->satellites()->rawValue().toUInt();
    data->satellites()->setRawValue(QVariant(sats));

    uint16_t hdop = source->horizontalDilutionOfPosition()->rawValue().toUInt();
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
    auto testVal = data->customModeHeartbeat()->rawValue().toUInt();
    if (testVal ==               std::numeric_limits<uint32_t>::max())   return false;
    qDebug() << "passed heartbeat";
    auto testVal1 = data->satellites()->rawValue().toUInt();
    if (testVal1 ==                        std::numeric_limits<uint8_t>::max())    return false;
    qDebug() << "passed satellites";
    auto testval2 = data->horizontalDilutionOfPositionFloat()->rawValue().toUInt();
    if (testval2 == qQNaN())                                return false;
    qDebug() << "passed hdop";
    return init = true;
}

bool MessengerRaw::srcInit(){
    if (source->timeUnixMicroseconds()->rawValue().toULongLong() == std::numeric_limits<uint64_t>::max())                return false;
    if (source->altitudeMillimetersMSL()->rawValue().toInt() == std::numeric_limits<signed int>::quiet_NaN())               return false;
    if (std::isnan(source->absolutePressureMillibars()->rawValue().toDouble()))                                              return false;
    if (std::isnan(source->temperature0Kelvin()->rawValue().toDouble())) return false;
    if (std::isnan(source->temperature1Kelvin()->rawValue().toDouble())) return false;
    if (std::isnan(source->temperature2Kelvin()->rawValue().toDouble())) return false;
    if (std::isnan(source->relativeHumidity0()->rawValue().toDouble())) return false;
    if (std::isnan(source->relativeHumidity1()->rawValue().toDouble())) return false;
    if (std::isnan(source->relativeHumidity2()->rawValue().toDouble())) return false;
    if (source->latitudeDegreesE7()->rawValue().toInt() == std::numeric_limits<signed int>::quiet_NaN()) return false;
    if (source->longitudeDegreesE7()->rawValue().toInt() == std::numeric_limits<signed int>::quiet_NaN()) return false;
    if (std::isnan(source->rollRadians()->rawValue().toDouble())) return false;
    if (std::isnan(source->pitchRadians()->rawValue().toDouble())) return false;
    if (std::isnan(source->yawRadians()->rawValue().toDouble())) return false;
    if (std::isnan(source->rollRateRadiansPerSecond()->rawValue().toDouble())) return false;
    if (std::isnan(source->pitchRateRadiansPerSecond()->rawValue().toDouble())) return false;
    if (std::isnan(source->yawRateRadiansPerSecond()->rawValue().toDouble())) return false;
    if (std::isnan(source->xVelocityMetersPerSecond()->rawValue().toDouble())) return false;
    if (std::isnan(source->yVelocityMetersPerSecond()->rawValue().toDouble())) return false;
    if (std::isnan(source->zVelocityMetersPerSecond()->rawValue().toDouble())) return false;
    if (source->customModeHeartbeat()->rawValue().toDouble() == std::numeric_limits<unsigned int>::quiet_NaN()) return false;
    // if (source->dataQuality()->rawValue().toInt() == QVariant(0)) return false;
    if (source->satellites()->rawValue().toInt() == std::numeric_limits<unsigned int>::quiet_NaN()) return false;
    if (source->horizontalDilutionOfPosition()->rawValue().toInt() == std::numeric_limits<unsigned int>::quiet_NaN()) return false;
    return true;
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
    if (!srcInit()) return false;
    updateData();
    qDebug() << "data updated";
    if (!validValues()) return false;
    qDebug() << "values validated";
    initFileFacts();
    qDebug() << "file facts init";
    if (!ascending()) return false;
    qDebug() << "ascending";
    if (!timer()) return false;
    qDebug() << "timer passed";
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
