#include "IMetDataBalancer.h"

void DataBalancer::update(const mavlink_message_t& m){
    switch(m.msgid){
        /* Replace literals with macros */
    case 227:
        /* create struct from the message, yet to be implemented, very simple if I could include the damn file, simple enough even if not tho */
        mavlink_cass_sensor_raw_t_local s;
        cassArr[cassHead] = s;
        cassHead = 1 + cassHead % cassArrSize;

        /* if first cass message, calculate the cass boot time. Do the same thing for altTime in the other cases, provided they have a timestamp at all */
        if (time == 0){
            using namespace std::chrono;
            milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
            uint64_t uTime = ms.count();
            time = uTime - s.time_boot_ms;
        }

        if (cassCount <= cassArrSize) cassCount++;
        break;
    case 32:
        break;
    case 33:
        break;
    case 137:
        break;
    case 30:
        break;
    }

    /* If we have at least one of everything, average, timestamp, and create and store a data record for use by subsequent stages */
}
