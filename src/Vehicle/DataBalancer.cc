#include "DataBalancer.h"
#include <chrono>

void DataBalancer::update(const mavlink_message_t* m){
    uint64_t currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    switch(m->msgid){
        /* TODO (at least)
         * Replace literals with macros
         * Replace message converters with the function from the mavlink files
         * error handling
         * All the other messages
         */
    case 227:{
        mavlink_cass_sensor_raw_t_local s;
        mavlinkTo227(m, &s);

        /* if first cass message, calculate the cass boot time. Do the same thing for altTime in the other cases, provided they have a timestamp at all */
        if (timeOffset == 0){
            timeOffset = currentTime - s.time_boot_ms;
        }

        switch(s.app_datatype){
        case 0:{ /* iMet temp */
            cass0Buf[cass0Head] = s;
            cass0Head = 1 + cass0Head % bufSize;
            cass0Avg = ((cass0Avg * cass0Count) + s.values[0]) / (cass0Count + 1);
            if (cass0Count <= bufSize) cass0Count++;
            break;
        }
        case 1:{ /* RH */
            break;
        }
        case 2:{ /* temp from RH */
            break;
        }
        case 3:{ /* wind */
            break;
        }
        }
        break;
    }
    case 32:        
        break;
    case 33:
        break;
    case 137:
        break;
    case 30:
        break;
    }

    /* Some fields not yet ready... */
    if (!(cass0Count > 0 && cass1Count > 0 && cass2Count > 0 && cass3Count > 0 && count0 > 0 && count1 > 0 && count2 > 0 && count3 > 0 && count4 > 0)) return;
    /* Too soon... */
    if (currentTime - lastUpdate < balancedDataFrequency) return;
    data.time = currentTime - timeOffset;
    data.iMetTemp = cass0Avg;
    /* set the rest of the members... */
    lastUpdate = currentTime;
}

/* Better to use the functions in the mavlink files, but I can't include them for some reason. This implementation doesn't account for platform differences yet. */
/* On the other hand, re-implementing it might be a good idea if we want to build in some error handling */
void DataBalancer::mavlinkTo227(const mavlink_message_t* m, mavlink_cass_sensor_raw_t_local* s){
    memcpy(&s->time_boot_ms, m, sizeof(uint32_t));
    memcpy(s->values, (char*)m + 4, 5 * sizeof(float));
    memcpy(&s->app_datatype, (char*)m + 24, sizeof(char));
    memcpy(&s->app_datalength, (char*)m + 25, sizeof(char));
}
