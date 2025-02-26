#include "DataHub.h"

template <typename T>
void DataHub::addDataPoint(std::deque<T>& deque, const T& val){
    if (deque.size() >= maxDataPoints) deque.pop_front();
    deque.push_back(val);
}

DataHub::DataHub(DataFactGroup* pData){
    this->pData = pData;
}

int DataHub::parseMessage(const mavlink_message_t* m){
    switch(m->msgid){
    case MAVLINK_MSG_ID_SYSTEM_TIME:{
        mavlink_system_time_t s;
        mavlink_msg_system_time_decode(m, &s);
        uint64_t val = s.time_unix_usec;

        updateRollingAverage(timeUnixMicrosecondsA, timeUnixMicrosecondsC, val);
        addDataPoint(timeUnixMicrosecondsArr, val);
        pData->getFactPointerTimeUnixMicroseconds()->setRawValue(QVariant(timeUnixMicrosecondsA));
        break;
    }
    case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:{
        mavlink_global_position_int_t s;
        mavlink_msg_global_position_int_decode(m, &s);
        int32_t val0 = s.alt;
        int32_t val1 = s.lat;
        int32_t val2 = s.lon;

        updateRollingAverage(altitudeMillimetersMSLA, altitudeMillimetersMSLC, val0);
        addDataPoint(altitudeMillimetersMSLArr, val0);
        pData->getFactPointerAltitudeMillimetersMSL()->setRawValue(QVariant(altitudeMillimetersMSLA));

        updateRollingAverage(latitudeDegreesE7A, latitudeDegreesE7C, val1);
        addDataPoint(latitudeDegreesE7Arr, val1);
        pData->getFactPointerLatitudeDegreesE7()->setRawValue(QVariant(latitudeDegreesE7A));

        updateRollingAverage(longitudeDegreesE7A, longitudeDegreesE7C, val2);
        addDataPoint(longitudeDegreesE7Arr, val2);
        pData->getFactPointerLongitudeDegreesE7()->setRawValue(QVariant(longitudeDegreesE7A));
        break;
    }
    case MAVLINK_MSG_ID_SCALED_PRESSURE2:{
        mavlink_scaled_pressure2_t s;
        mavlink_msg_scaled_pressure2_decode(m, &s);
        double val = static_cast<double>(s.press_abs);

        updateRollingAverage(absolutePressureMillibarsA, absolutePressureMillibarsC, val);
        addDataPoint(absolutePressureMillibarsArr, val);
        pData->getFactPointerAbsolutePressureMillibars()->setRawValue(QVariant(absolutePressureMillibarsA));
        break;
    }
    case MAVLINK_MSG_ID_CASS_SENSOR_RAW:{
        mavlink_cass_sensor_raw_t s;
        mavlink_msg_cass_sensor_raw_decode(m, &s);
        switch(s.app_datatype){
        case 0:{
            double val0 = static_cast<double>(s.values[0]), val1 = static_cast<double>(s.values[1]), val2 = static_cast<double>(s.values[2]);

            updateRollingAverage(temperature0KelvinA, temperature0KelvinC, val0);
            addDataPoint(temperature0KelvinArr, val0);
            pData->getFactPointerTemperature0Kelvin()->setRawValue(QVariant(temperature0KelvinA));

            updateRollingAverage(temperature1KelvinA, temperature1KelvinC, val1);
            addDataPoint(temperature1KelvinArr, val1);
            pData->getFactPointerTemperature1Kelvin()->setRawValue(QVariant(temperature1KelvinA));

            updateRollingAverage(temperature2KelvinA, temperature2KelvinC, val2);
            addDataPoint(temperature2KelvinArr, val2);
            pData->getFactPointerTemperature2Kelvin()->setRawValue(QVariant(temperature2KelvinA));
            break;
        }
        case 1:{
            double val0 = static_cast<double>(s.values[0]), val1 = static_cast<double>(s.values[1]), val2 = static_cast<double>(s.values[2]);

            updateRollingAverage(relativeHumidity0A, relativeHumidity0C, val0);
            addDataPoint(relativeHumidity0Arr, val0);
            pData->getFactPointerRelativeHumidity0()->setRawValue(QVariant(relativeHumidity0A));

            updateRollingAverage(relativeHumidity1A, relativeHumidity1C, val1);
            addDataPoint(relativeHumidity1Arr, val1);
            pData->getFactPointerRelativeHumidity1()->setRawValue(QVariant(relativeHumidity1A));

            updateRollingAverage(relativeHumidity2A, relativeHumidity2C, val2);
            addDataPoint(relativeHumidity2Arr, val2);
            pData->getFactPointerRelativeHumidity2()->setRawValue(QVariant(relativeHumidity2A));
            break;
        }
        }
        break;
    }
    case MAVLINK_MSG_ID_ATTITUDE:{
        mavlink_attitude_t s;
        mavlink_msg_attitude_decode(m, &s);
        double val0 = static_cast<double>(s.roll);
        double val1 = static_cast<double>(s.pitch);
        double val2 = static_cast<double>(s.yaw);
        double val3 = static_cast<double>(s.rollspeed);
        double val4 = static_cast<double>(s.pitchspeed);
        double val5 = static_cast<double>(s.yawspeed);

        updateRollingAverage(rollRadiansA, rollRadiansC, val0);
        addDataPoint(rollRadiansArr, val0);
        pData->getFactPointerRollRadians()->setRawValue(QVariant(rollRadiansA));

        updateRollingAverage(pitchRadiansA, pitchRadiansC, val1);
        addDataPoint(pitchRadiansArr, val1);
        pData->getFactPointerPitchRadians()->setRawValue(QVariant(pitchRadiansA));

        updateRollingAverage(yawRadiansA, yawRadiansC, val2);
        addDataPoint(yawRadiansArr, val2);
        pData->getFactPointerYawRadians()->setRawValue(QVariant(yawRadiansA));

        updateRollingAverage(rollRateRadiansPerSecondA, rollRateRadiansPerSecondC, val3);
        addDataPoint(rollRateRadiansPerSecondArr, val3);
        pData->getFactPointerRollRateRadiansPerSecond()->setRawValue(QVariant(rollRateRadiansPerSecondA));

        updateRollingAverage(pitchRateRadiansPerSecondA, pitchRateRadiansPerSecondC, val4);
        addDataPoint(pitchRateRadiansPerSecondArr, val4);
        pData->getFactPointerPitchRateRadiansPerSecond()->setRawValue(QVariant(pitchRateRadiansPerSecondA));

        updateRollingAverage(yawRateRadiansPerSecondA, yawRateRadiansPerSecondC, val5);
        addDataPoint(yawRateRadiansPerSecondArr, val5);
        pData->getFactPointerYawRateRadiansPerSecond()->setRawValue(QVariant(yawRateRadiansPerSecondA));
        break;
    }
    case MAVLINK_MSG_ID_LOCAL_POSITION_NED:{
        mavlink_local_position_ned_t s;
        mavlink_msg_local_position_ned_decode(m, &s);
        double val0 = static_cast<double>(s.vx);
        double val1 = static_cast<double>(s.vy);
        double val2 = static_cast<double>(s.vz);

        updateRollingAverage(xVelocityMetersPerSecondA, xVelocityMetersPerSecondC, val0);
        addDataPoint(xVelocityMetersPerSecondArr, val0);
        pData->getFactPointerXVelocityMetersPerSecond()->setRawValue(QVariant(xVelocityMetersPerSecondA));

        updateRollingAverage(yVelocityMetersPerSecondA, yVelocityMetersPerSecondC, val1);
        addDataPoint(yVelocityMetersPerSecondArr, val1);
        pData->getFactPointerYVelocityMetersPerSecond()->setRawValue(QVariant(yVelocityMetersPerSecondA));

        updateRollingAverage(zVelocityMetersPerSecondA, zVelocityMetersPerSecondC, val2);
        addDataPoint(zVelocityMetersPerSecondArr, val2);
        pData->getFactPointerZVelocityMetersPerSecond()->setRawValue(QVariant(zVelocityMetersPerSecondA));
        break;
    }
    case MAVLINK_MSG_ID_HEARTBEAT:{
        mavlink_heartbeat_t s;
        mavlink_msg_heartbeat_decode(m, &s);
        /* This one doesn't get averaged */
        pData->getFactPointerCustomModeHeartbeat()->setRawValue(QVariant(s.custom_mode));
        break;
    }
    case MAVLINK_MSG_ID_GPS_RAW_INT:{
        mavlink_gps_raw_int_t s;
        mavlink_msg_gps_raw_int_decode(m, &s);
        uint8_t val0 = s.satellites_visible;
        uint16_t val1 = s.eph;

        updateRollingAverage(satellitesA, satellitesC, val0);
        addDataPoint(satellitesArr, val0);
        pData->getFactPointerSatellites()->setRawValue(QVariant(satellitesA));

        updateRollingAverage(horizontalDilutionOfPositionA, horizontalDilutionOfPositionC, val1);
        addDataPoint(horizontalDilutionOfPositionArr, val1);
        pData->getFactPointerHorizontalDilutionOfPosition()->setRawValue(QVariant(horizontalDilutionOfPositionA));
        break;
    }
    }
    return 0;
}

void DataHub::resetAverages(){
    timeUnixMicrosecondsC = 0;
    altitudeMillimetersMSLC = 0;
    absolutePressureMillibarsC = 0;
    temperature0KelvinC = 0;
    temperature1KelvinC = 0;
    temperature2KelvinC = 0;
    relativeHumidity0C = 0;
    relativeHumidity1C = 0;
    relativeHumidity2C = 0;
    latitudeDegreesE7C = 0;
    longitudeDegreesE7C = 0;
    rollRadiansC = 0;
    pitchRadiansC = 0;
    yawRadiansC = 0;
    rollRateRadiansPerSecondC = 0;
    pitchRateRadiansPerSecondC = 0;
    yawRateRadiansPerSecondC = 0;
    xVelocityMetersPerSecondC = 0;
    yVelocityMetersPerSecondC = 0;
    zVelocityMetersPerSecondC = 0;
    satellitesC = 0;
    horizontalDilutionOfPositionC = 0;
}
