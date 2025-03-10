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

    const double rolldegrees = source->getFactPointerRollDegrees()->rawValue().toDouble();
    const double pitchdegrees = source->getFactPointerPitchDegrees()->rawValue().toDouble();
    const double yawdegrees = source->getFactPointerYawDegrees()->rawValue().toDouble();

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
    data->getFactPointerUTC_Date()->setRawValue(QVariant(str.c_str()));
}

void MessengerAltitude::buildUTCTimeStr(){
    std::string hh = std::to_string(static_cast<int>(pt->tm_hour));
    std::string mm = std::to_string(static_cast<int>(pt->tm_min));
    std::string ss = std::to_string(static_cast<int>(pt->tm_sec));
    std::string c = std::string(":");
    std::string str = hh + c + mm + c + ss;
    data->getFactPointerUTC_Time()->setRawValue(QVariant(str.c_str()));
}

void MessengerAltitude::buildFilename(){
    std::string alm = std::string("ALM");
    std::string srn = std::to_string(data->getFactPointerSRN()->rawValue().toInt());
    std::string YYYY = std::to_string(data->getFactPointerYYYY()->rawValue().toUInt());
    std::string MM = std::to_string(data->getFactPointerMM()->rawValue().toUInt());
    std::string DD = std::to_string(data->getFactPointerDD()->rawValue().toUInt());
    std::string HH = std::to_string(data->getFactPointerHH()->rawValue().toUInt());
    std::string Mm = std::to_string(data->getFactPointerMm()->rawValue().toUInt());
    std::string ss = std::to_string(data->getFactPointerss()->rawValue().toUInt());
    std::string str = data->getFactPointerString()->rawValueString().toStdString();
    std::string csv = std::string(".csv");
    std::string _ = std::string("_");
    std::string filename = alm + _ + srn + _ + YYYY + MM + DD + _ + HH + Mm + ss + _ + str + csv;
    data->getFactPointerRaw_Data_Filename()->setRawValue(QVariant(filename.c_str()));
}

void MessengerAltitude::getStringFromUser(){
    const char* s = ""; /* TODO: read a file or GUI, don't know what file to read yet tho. */
    data->getFactPointerString()->setRawValue(QVariant(s));
}

void MessengerAltitude::updateTime(){
    std::time_t t = static_cast<std::time_t>(source->getFactPointerTimeUnixSeconds()->rawValue().toDouble());
    pt = std::gmtime(&t);

    if (!pt){
        /* Technically gmtime may be able to fail, so we should probably handle that somehow, but I don't think it can in practise. And if it's null, we just don't
            update the time facts, which have defaults anyway, so no crash, just 00 for the time facts. */
    }
}

void MessengerAltitude::updateConstantData(){
    static bool init = false;
    if (init) return;

    int32_t srn = source->getFactPointerDroneSerialNumber()->rawValue().toInt();
    data->getFactPointerSRN()->setRawValue(QVariant(srn));

    uint16_t YYYY = static_cast<uint16_t>(pt->tm_year + 1900);
    data->getFactPointerYYYY()->setRawValue(QVariant(YYYY));

    uint8_t MM = static_cast<uint8_t>(pt->tm_mon + 1);
    data->getFactPointerMM()->setRawValue(QVariant(MM));

    uint8_t DD = static_cast<uint8_t>(pt->tm_mday);
    data->getFactPointerDD()->setRawValue(QVariant(DD));

    uint8_t HH = static_cast<uint8_t>(pt->tm_hour);
    data->getFactPointerHH()->setRawValue(QVariant(HH));

    uint8_t Mm = static_cast<uint8_t>(pt->tm_min);
    data->getFactPointerMm()->setRawValue(QVariant(Mm));

    uint8_t ss = static_cast<uint8_t>(pt->tm_sec);
    data->getFactPointerss()->setRawValue(QVariant(ss));

    getStringFromUser(); /* Not yet implemented, need to know what file to read. */

    /* Message_Version doesn't need to be updated here because the default value set in MessageAltitudeFactGroup.cc is all sufficient. */

    int32_t poweredAge = source->getFactPointerPoweredAgeSeconds()->rawValue().toInt();
    data->getFactPointerDrone_Powered_Age()->setRawValue(QVariant(poweredAge));

    int32_t armedAge = source->getFactPointerArmedAgeSeconds()->rawValue().toInt();
    data->getFactPointerDrone_Armed_Age()->setRawValue(QVariant(armedAge));

    buildFilename();

    double time = source->getFactPointerTimeUnixSeconds()->rawValue().toDouble();
    data->getFactPointerUnix_Start_Time()->setRawValue(QVariant(static_cast<uint64_t>(time)));

    double groundWindSpd = source->getFactPointerGroundWindSpeedMetersPerSecond()->rawValue().toDouble();
    data->getFactPointerGround_Wind_Speed()->setRawValue(QVariant(groundWindSpd));

    int32_t groundWindDir = source->getFactPointerGroundWindDirectionDegrees()->rawValue().toInt();
    data->getFactPointerGround_Wind_Direction()->setRawValue(QVariant(groundWindDir));

    double groundAirTemp = source->getFactPointerGroundAirTemperatureCelsius()->rawValue().toDouble();
    data->getFactPointerGround_Air_Temperature()->setRawValue(QVariant(groundAirTemp));

    double groundHum = source->getFactPointerGroundHumidity()->rawValue().toDouble();
    data->getFactPointerGround_Humidity()->setRawValue(QVariant(groundHum));

    double groundPressure = source->getFactPointerGroundPressureMillibars()->rawValue().toDouble();
    data->getFactPointerGround_Pressure()->setRawValue(QVariant(groundPressure));

    double homeLat = source->getFactPointerHomePositionLatitudeDegrees()->rawValue().toDouble();
    data->getFactPointerHome_Position_Latitude()->setRawValue(QVariant(homeLat));

    double homeLon = source->getFactPointerHomePositionLongitudeDegrees()->rawValue().toDouble();
    data->getFactPointerHome_Position_Longitude()->setRawValue(QVariant(homeLon));

    double homeAlt = source->getFactPointerHomePositionAltitudeMeters()->rawValue().toDouble();
    data->getFactPointerHome_Position_Altitude()->setRawValue(QVariant(homeAlt));

    init = true;
}

void MessengerAltitude::updateData(){
    double alt = source->getFactPointerAltitudeMetersASL()->rawValue().toDouble();
    data->getFactPointerAltitude_ASL()->setRawValue(QVariant(alt));

    updateTime();
    buildUTCDateStr();
    buildUTCTimeStr();

    double now = source->getFactPointerTimeUnixSeconds()->rawValue().toDouble();
    double start = static_cast<double>(data->getFactPointerUnix_Start_Time()->rawValue().toInt());
    data->getFactPointerTime_Since_Start()->setRawValue(QVariant(now - start));

    double pres = source->getFactPointerAbsolutePressureMillibars()->rawValue().toDouble();
    data->getFactPointerPressure()->setRawValue(QVariant(pres));

    double t0 = source->getFactPointerTemperature0Celsius()->rawValue().toDouble();
    double t1 = source->getFactPointerTemperature1Celsius()->rawValue().toDouble();
    double t2 = source->getFactPointerTemperature2Celsius()->rawValue().toDouble();
    data->getFactPointerAir_Temp()->setRawValue(QVariant((t0 + t1 + t2) / 3.));

    double h0 = source->getFactPointerRelativeHumidity0()->rawValue().toDouble();
    double h1 = source->getFactPointerRelativeHumidity1()->rawValue().toDouble();
    double h2 = source->getFactPointerRelativeHumidity2()->rawValue().toDouble();
    data->getFactPointerAir_Temp()->setRawValue(QVariant((h0 + h1 + h2) / 3.));
}

bool MessengerAltitude::criteriaMet(){
    updateTime();
    updateConstantData();
    updateData();
    if (!passedThreshold()) return false;
    return true;
}

#undef _CRT_SECURE_NO_WARNINGS
