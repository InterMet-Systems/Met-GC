#ifndef IMETDATABALANCER_H
#define IMETDATABALANCER_H

#include "mavlink_types.h"
#include <chrono>

typedef struct { /* Had trouble including the headers for whatever reason... */
    uint32_t time_boot_ms; /*<  Timestamp (milliseconds since system boot)*/
    float values[5]; /*<  Raw data*/
    uint8_t app_datatype; /*<  Data type indicating what data is being sent. 0 = iMet temp, 1 = RH, 2 = temps from RH, 3 = wind data*/
    uint8_t app_datalength; /*<  Length of raw data array*/
} mavlink_cass_sensor_raw_t_local;

class DataBalancer{
    uint64_t time = 0; /* reference boot time relative to Unix time */
    int64_t altTime = 0; /* same thing for non-cass messages */

    size_t static constexpr cassArrSize = 8;
    size_t static constexpr ARR1SIZE = 8;
    size_t static constexpr ARR2SIZE = 8;
    size_t static constexpr ARR3SIZE = 8;
    size_t static constexpr ARR4SIZE = 8;
    size_t static constexpr ARR5SIZE = 8;
    size_t cassHead = 0;
    size_t head1 = 0;
    size_t head2 = 0;
    size_t head3 = 0;
    size_t head4 = 0;
    size_t head5 = 0;

    size_t cassCount = 0;
    size_t head1Count = 0;
    size_t head2Count = 0;
    size_t head3Count = 0;
    size_t head4Count = 0;
    size_t head5Count = 0;

    mavlink_cass_sensor_raw_t_local cassArr[cassArrSize];
public:
    void update(const mavlink_message_t& m);
};

#endif // IMETDATABALANCER_H
