#include "DataHub.h"

DataHub::DataHub(DataFactGroup* pData){
    this->pData = pData;
}

int DataHub::parseMessage(const mavlink_message_t& m){
    switch(m.msgid){
    case MAVLINK_MSG_ID_SYSTEM_TIME:{
        mavlink_system_time_t s;
        mavlink_msg_system_time_decode(&m, &s);
        uint64_t val = s.time_unix_usec;        

        updateRollingAverage(timeUnixMicrosecondsA, timeUnixMicrosecondsC, val);
        pData->timeUnixMicroseconds()->setRawValue(QVariant(timeUnixMicrosecondsA));
        break;
    }
    case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:{
        mavlink_global_position_int_t s;
        mavlink_msg_global_position_int_decode(&m, &s);
        int32_t val0 = s.alt;
        int32_t val1 = s.lat;
        int32_t val2 = s.lon;

        updateRollingAverage(altitudeMillimetersMSLA, altitudeMillimetersMSLC, val0);
        pData->altitudeMillimetersMSL()->setRawValue(QVariant(altitudeMillimetersMSLA));

        updateRollingAverage(latitudeDegreesE7A, latitudeDegreesE7C, val1);
        pData->latitudeDegreesE7()->setRawValue(QVariant(latitudeDegreesE7A));

        updateRollingAverage(longitudeDegreesE7A, longitudeDegreesE7C, val2);
        pData->longitudeDegreesE7()->setRawValue(QVariant(longitudeDegreesE7A));

        /* temp debug */
        // char str[256];
        // (void)sprintf(str, "%i", val2);
        // qDebug() << str;

        break;
    }
    case MAVLINK_MSG_ID_SCALED_PRESSURE2:{
        mavlink_scaled_pressure2_t s;
        mavlink_msg_scaled_pressure2_decode(&m, &s);
        double val = static_cast<double>(s.press_abs);

        updateRollingAverage(absolutePressureMillibarsA, absolutePressureMillibarsC, val);
        pData->absolutePressureMillibars()->setRawValue(QVariant(absolutePressureMillibarsA));
        break;
    }
    case MAVLINK_MSG_ID_CASS_SENSOR_RAW:{
        mavlink_cass_sensor_raw_t s;
        mavlink_msg_cass_sensor_raw_decode(&m, &s);
        switch(s.app_datatype){
        case 0:{
            double val0 = static_cast<double>(s.values[0]), val1 = static_cast<double>(s.values[1]), val2 = static_cast<double>(s.values[2]);

            updateRollingAverage(temperature0KelvinA, temperature0KelvinC, val0);
            pData->temperature0Kelvin()->setRawValue(QVariant(temperature0KelvinA));

            updateRollingAverage(temperature1KelvinA, temperature1KelvinC, val1);
            pData->temperature1Kelvin()->setRawValue(QVariant(temperature1KelvinA));

            updateRollingAverage(temperature2KelvinA, temperature2KelvinC, val2);
            pData->temperature2Kelvin()->setRawValue(QVariant(temperature2KelvinA));
            break;
        }
        case 1:{
            double val0 = static_cast<double>(s.values[0]), val1 = static_cast<double>(s.values[1]), val2 = static_cast<double>(s.values[2]);

            updateRollingAverage(relativeHumidity0A, relativeHumidity0C, val0);
            pData->relativeHumidity0()->setRawValue(QVariant(relativeHumidity0A));

            updateRollingAverage(relativeHumidity1A, relativeHumidity1C, val1);
            pData->relativeHumidity1()->setRawValue(QVariant(relativeHumidity1A));

            updateRollingAverage(relativeHumidity2A, relativeHumidity2C, val2);
            pData->relativeHumidity2()->setRawValue(QVariant(relativeHumidity2A));
            break;
        }
        default:{
            /* we're ignoring MAVLINK_MSG_ID_CASS_SENSOR_RAW if app_datatype is anything other than 0 or 1. */
        }
        }
        break;
    }
    case MAVLINK_MSG_ID_ATTITUDE:{
        mavlink_attitude_t s;
        mavlink_msg_attitude_decode(&m, &s);
        double val0 = static_cast<double>(s.roll);
        double val1 = static_cast<double>(s.pitch);
        double val2 = static_cast<double>(s.yaw);
        double val3 = static_cast<double>(s.rollspeed);
        double val4 = static_cast<double>(s.pitchspeed);
        double val5 = static_cast<double>(s.yawspeed);

        updateRollingAverage(rollRadiansA, rollRadiansC, val0);
        pData->rollRadians()->setRawValue(QVariant(rollRadiansA));

        updateRollingAverage(pitchRadiansA, pitchRadiansC, val1);
        pData->pitchRadians()->setRawValue(QVariant(pitchRadiansA));

        updateRollingAverage(yawRadiansA, yawRadiansC, val2);
        pData->yawRadians()->setRawValue(QVariant(yawRadiansA));

        updateRollingAverage(rollRateRadiansPerSecondA, rollRateRadiansPerSecondC, val3);
        pData->rollRateRadiansPerSecond()->setRawValue(QVariant(rollRateRadiansPerSecondA));

        updateRollingAverage(pitchRateRadiansPerSecondA, pitchRateRadiansPerSecondC, val4);
        pData->pitchRateRadiansPerSecond()->setRawValue(QVariant(pitchRateRadiansPerSecondA));

        updateRollingAverage(yawRateRadiansPerSecondA, yawRateRadiansPerSecondC, val5);
        pData->yawRateRadiansPerSecond()->setRawValue(QVariant(yawRateRadiansPerSecondA));
        break;
    }
    case MAVLINK_MSG_ID_LOCAL_POSITION_NED:{
        mavlink_local_position_ned_t s;
        mavlink_msg_local_position_ned_decode(&m, &s);
        double val0 = static_cast<double>(s.vx);
        double val1 = static_cast<double>(s.vy);
        double val2 = static_cast<double>(s.vz);

        updateRollingAverage(xVelocityMetersPerSecondA, xVelocityMetersPerSecondC, val0);
        pData->xVelocityMetersPerSecond()->setRawValue(QVariant(xVelocityMetersPerSecondA));

        updateRollingAverage(yVelocityMetersPerSecondA, yVelocityMetersPerSecondC, val1);
        pData->yVelocityMetersPerSecond()->setRawValue(QVariant(yVelocityMetersPerSecondA));

        updateRollingAverage(zVelocityMetersPerSecondA, zVelocityMetersPerSecondC, val2);
        pData->zVelocityMetersPerSecond()->setRawValue(QVariant(zVelocityMetersPerSecondA));
        break;
    }
    case MAVLINK_MSG_ID_HEARTBEAT:{
        mavlink_heartbeat_t s;
        mavlink_msg_heartbeat_decode(&m, &s);
        /* This one doesn't get averaged */
        pData->customModeHeartbeat()->setRawValue(QVariant(s.custom_mode));
        break;
    }
    case MAVLINK_MSG_ID_GPS_RAW_INT:{
        mavlink_gps_raw_int_t s;
        mavlink_msg_gps_raw_int_decode(&m, &s);
        uint8_t val0 = s.satellites_visible;
        uint16_t val1 = s.eph;

        updateRollingAverage(satellitesA, satellitesC, val0);
        pData->satellites()->setRawValue(QVariant(satellitesA));

        updateRollingAverage(horizontalDilutionOfPositionA, horizontalDilutionOfPositionC, val1);
        pData->horizontalDilutionOfPosition()->setRawValue(QVariant(horizontalDilutionOfPositionA));
        break;
    }
    default:{
        /* we're ignoring all other mavlink messages */
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
