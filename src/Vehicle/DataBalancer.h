#ifndef DATABALANCER_H
#define DATABALANCER_H

#include "mavlink_types.h"

typedef struct { /* Had trouble including the headers for whatever reason... */
    uint32_t time_boot_ms; /*<  Timestamp (milliseconds since system boot)*/
    float values[5]; /*<  Raw data*/
    uint8_t app_datatype; /*<  Data type indicating what data is being sent. 0 = iMet temp, 1 = RH, 2 = temps from RH, 3 = wind data*/
    uint8_t app_datalength; /*<  Length of raw data array*/
} mavlink_cass_sensor_raw_t_local;

typedef struct {
    uint64_t time; /* drone's frame of reference */
    /* cass sensor type 0 (iMet temp) */
    float iMetTemp;
    /* rest of variables... */
} BalancedDataRecord;

class DataBalancer{
    BalancedDataRecord data;

    uint64_t timeOffset = 0; /* difference between this PC and drone time in milliseconds */
    uint64_t timeOffsetAlt = 0; /* same thing for non-cass messages */
    uint64_t lastUpdate = UINT64_MAX; /* time since last BalancedDataRecord creation */
    uint64_t balancedDataFrequency = 1000; /* min milliseconds between BalancedDataRecord creation */

    /* ring buffers, one for each type of message. Should just store the relevent contents of the message, but this is bloated enough it doesn't matter */
    size_t static constexpr bufSize = 8;

    size_t cass0Head = 0;
    size_t cass1Head = 0;
    size_t cass2Head = 0;
    size_t cass3Head = 0;
    size_t head0 = 0;
    size_t head1 = 0;
    size_t head2 = 0;
    size_t head3 = 0;
    size_t head4 = 0;

    size_t cass0Count = 0;
    size_t cass1Count = 0;
    size_t cass2Count = 0;
    size_t cass3Count = 0;
    size_t count0 = 0;
    size_t count1 = 0;
    size_t count2 = 0;
    size_t count3 = 0;
    size_t count4 = 0;

    mavlink_cass_sensor_raw_t_local cass0Buf[bufSize];
    float cass0Avg = .0f;
    mavlink_cass_sensor_raw_t_local cass1Buf[bufSize];
    /* each variable should have an average */
    mavlink_cass_sensor_raw_t_local cass2Buf[bufSize];
    mavlink_cass_sensor_raw_t_local cass3Buf[bufSize];
    /* more buffers here, of various types, with averages */
public:
    void update(const mavlink_message_t* m);
    void mavlinkTo227(const mavlink_message_t* m, mavlink_cass_sensor_raw_t_local* s);
};

#endif // DATABALANCER_H
