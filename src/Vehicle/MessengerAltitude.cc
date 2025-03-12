#include "MessengerAltitude.h"
#include "IMetMath.h"
#include <ctime>
#include <cstdint>
#include <cmath>
#include "QDebug"


#define _CRT_SECURE_NO_WARNINGS

const MessengerAltitude::WindProps MessengerAltitude::calcWindProps() const {
    WindProps props;

    assert(source && "AltitudeMessenger.source was null during calcWindProps");
    if (!source) {
        /* if not source, QGC or hardware has shit the bed, perhaps this would be a good time to except or log the error to a file and flush? */
        qDebug() << "Fatal error";
        return props;
    }

    /* Magic numbers from Tony Segales' paper */
    constexpr double a = 39.4;
    constexpr double b = 5.71;

    const double rolldegrees = source->rollDegrees()->rawValue().toDouble();
    const double pitchdegrees = source->pitchDegrees()->rawValue().toDouble();
    const double yawdegrees = source->yawDegrees()->rawValue().toDouble();

    IMetMath::SResult croll_r = IMetMath::DegreesToRadians(rolldegrees);
    assert(croll_r.result == IMetMath::Result::_SUCCESS);
    const double croll = cos(croll_r.value);

    IMetMath::SResult sroll_r = IMetMath::DegreesToRadians(rolldegrees);
    assert(sroll_r.result == IMetMath::Result::_SUCCESS);
    const double sroll = sin(sroll_r.value);

    IMetMath::SResult cpitch_r = IMetMath::DegreesToRadians(pitchdegrees);
    assert(cpitch_r.result == IMetMath::Result::_SUCCESS);
    const double cpitch = cos(cpitch_r.value);

    IMetMath::SResult spitch_r = IMetMath::DegreesToRadians(pitchdegrees);
    assert(spitch_r.result == IMetMath::Result::_SUCCESS);
    const double spitch = sin(spitch_r.value);

    IMetMath::SResult cyaw_r = IMetMath::DegreesToRadians(yawdegrees);
    assert(cyaw_r.result == IMetMath::Result::_SUCCESS);
    const double cyaw = cos(cyaw_r.value);

    IMetMath::SResult syaw_r = IMetMath::DegreesToRadians(yawdegrees);
    assert(syaw_r.result == IMetMath::Result::_SUCCESS);
    const double syaw = sin(syaw_r.value);

    const double dirRads = atan2(-croll * spitch * syaw + sroll * cyaw, -sroll * syaw - croll * spitch * cyaw);

    IMetMath::SResult dirDegrees_r = IMetMath::RadiansToDegrees(dirRads);
    assert(dirDegrees_r.result == IMetMath::Result::_SUCCESS);

    props.dir = static_cast<uint32_t>(fmod(dirDegrees_r.value + 360., 360.));

    /* Can still yield 0.0 and +inf, however these are appropriate given the algorithm. */
    props.speed = fmax(0., a * sqrt(tan(acos(std::clamp(croll * cpitch, -1., +1.)))) - b);

    return props;
}

void MessengerAltitude::buildUTCDateStr(){
    std::string YY = std::to_string(static_cast<int>((pt->tm_year + 1900) % 100));
    std::string MM = std::to_string(static_cast<int>(pt->tm_mon + 1));
    std::string DD = std::to_string(static_cast<int>(pt->tm_mday));
    std::string s = std::string("/");
    std::string str = YY + s + MM + s + DD;
    data->uTCDate()->setRawValue(QVariant(str.c_str()));
}

void MessengerAltitude::buildUTCTimeStr(){
    std::string hh = std::to_string(static_cast<int>(pt->tm_hour));
    std::string mm = std::to_string(static_cast<int>(pt->tm_min));
    std::string ss = std::to_string(static_cast<int>(pt->tm_sec));
    std::string c = std::string(":");
    std::string str = hh + c + mm + c + ss;
    data->uTCTime()->setRawValue(QVariant(str.c_str()));
}

void MessengerAltitude::buildFilename(){
    std::string alm = std::string("ALM");
    std::string srn = std::to_string(data->droneSerial()->rawValue().toInt());
    std::string YYYY = std::to_string(data->year()->rawValue().toUInt());
    std::string MM = std::to_string(data->month()->rawValue().toUInt());
    std::string DD = std::to_string(data->day()->rawValue().toUInt());
    std::string HH = std::to_string(data->hour()->rawValue().toUInt());
    std::string Mm = std::to_string(data->minute()->rawValue().toUInt());
    std::string ss = std::to_string(data->second()->rawValue().toUInt());
    std::string str = data->string()->rawValueString().toStdString();
    std::string csv = std::string(".csv");
    std::string _ = std::string("_");
    std::string filename = alm + _ + srn + _ + YYYY + MM + DD + _ + HH + Mm + ss + _ + str + csv;
    data->rawDataFilename()->setRawValue(QVariant(filename.c_str()));
}

void MessengerAltitude::getStringFromUser(){
    const char* s = ""; /* TODO: read a file or GUI, don't know what file to read yet tho. */
    data->string()->setRawValue(QVariant(s));
}

void MessengerAltitude::updateTime(){
    std::time_t t = static_cast<std::time_t>(source->timeUnixSeconds()->rawValue().toDouble());
    pt = std::gmtime(&t);

    if (!pt){
        /* Technically gmtime may be able to fail, so we should probably handle that somehow, but I don't think it can in practise. And if it's null, we just don't
            update the time facts, which have defaults anyway, so no crash, just 00 for the time facts. */
    }
}

void MessengerAltitude::updateConstantData(){
    static bool init = false;
    if (init) return;

    int32_t srn = source->droneSerialNumber()->rawValue().toInt();
    data->droneSerial()->setRawValue(QVariant(srn));

    uint16_t YYYY = static_cast<uint16_t>(pt->tm_year + 1900);
    data->year()->setRawValue(QVariant(YYYY));

    uint8_t MM = static_cast<uint8_t>(pt->tm_mon + 1);
    data->month()->setRawValue(QVariant(MM));

    uint8_t DD = static_cast<uint8_t>(pt->tm_mday);
    data->day()->setRawValue(QVariant(DD));

    uint8_t HH = static_cast<uint8_t>(pt->tm_hour);
    data->hour()->setRawValue(QVariant(HH));

    uint8_t Mm = static_cast<uint8_t>(pt->tm_min);
    data->minute()->setRawValue(QVariant(Mm));

    uint8_t ss = static_cast<uint8_t>(pt->tm_sec);
    data->second()->setRawValue(QVariant(ss));

    getStringFromUser(); /* Not yet implemented, need to know what file to read. */

    /* Message_Version doesn't need to be updated here because the default value set in MessageAltitudeFactGroup.cc is all sufficient. */

    int32_t poweredAge = source->poweredAgeSeconds()->rawValue().toInt();
    data->dronePoweredAge()->setRawValue(QVariant(poweredAge));

    int32_t armedAge = source->armedAgeSeconds()->rawValue().toInt();
    data->droneArmedAge()->setRawValue(QVariant(armedAge));

    buildFilename();

    double time = source->timeUnixSeconds()->rawValue().toDouble();
    data->unixStartTime()->setRawValue(QVariant(static_cast<uint64_t>(time)));

    double groundWindSpd = source->groundWindSpeedMetersPerSecond()->rawValue().toDouble();
    data->groundWindSpeed()->setRawValue(QVariant(groundWindSpd));

    int32_t groundWindDir = source->groundWindDirectionDegrees()->rawValue().toInt();
    data->groundWindDirection()->setRawValue(QVariant(groundWindDir));

    double groundAirTemp = source->groundAirTemperatureCelsius()->rawValue().toDouble();
    data->groundAirTemperature()->setRawValue(QVariant(groundAirTemp));

    double groundHum = source->groundHumidity()->rawValue().toDouble();
    data->groundHumidity()->setRawValue(QVariant(groundHum));

    double groundPressure = source->groundPressureMillibars()->rawValue().toDouble();
    data->groundPressure()->setRawValue(QVariant(groundPressure));

    double homeLat = source->homePositionLatitudeDegrees()->rawValue().toDouble();
    data->homePositionLatitude()->setRawValue(QVariant(homeLat));

    double homeLon = source->homePositionLongitudeDegrees()->rawValue().toDouble();
    data->homePositionLongitude()->setRawValue(QVariant(homeLon));

    double homeAlt = source->homePositionAltitudeMeters()->rawValue().toDouble();
    data->homePositionAltitude()->setRawValue(QVariant(homeAlt));

    init = true;
}

void MessengerAltitude::updateData(){
    double alt = source->altitudeMetersASL()->rawValue().toDouble();
    data->altitudeASL()->setRawValue(QVariant(alt));

    updateTime();
    buildUTCDateStr();
    buildUTCTimeStr();

    double now = source->timeUnixSeconds()->rawValue().toDouble();
    double start = static_cast<double>(data->unixStartTime()->rawValue().toInt());
    data->timeSinceStart()->setRawValue(QVariant(now - start));

    double pres = source->absolutePressureMillibars()->rawValue().toDouble();
    data->pressure()->setRawValue(QVariant(pres));

    double t0 = source->temperature0Celsius()->rawValue().toDouble();
    double t1 = source->temperature1Celsius()->rawValue().toDouble();
    double t2 = source->temperature2Celsius()->rawValue().toDouble();
    data->airTemp()->setRawValue(QVariant((t0 + t1 + t2) / 3.));

    double h0 = source->relativeHumidity0()->rawValue().toDouble();
    double h1 = source->relativeHumidity1()->rawValue().toDouble();
    double h2 = source->relativeHumidity2()->rawValue().toDouble();
    data->airTemp()->setRawValue(QVariant((h0 + h1 + h2) / 3.));
}

bool MessengerAltitude::criteriaMet(){
    updateTime();
    updateConstantData();
    updateData();
    if (!passedThreshold()) return false;
    return true;
}

bool MessengerAltitude::passedThreshold(){
    return true;
}

#undef _CRT_SECURE_NO_WARNINGS
