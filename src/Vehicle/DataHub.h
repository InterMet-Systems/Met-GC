#ifndef DATAHUB_H
#define DATAHUB_H

#include "DataFactGroup.h"
#include <type_traits>

class DataHub{
    DataFactGroup* pData = nullptr;

    size_t timeUnixMicrosecondsC = 0;
    //uint64_t timeUnixMicrosecondsA = 0;

    size_t altitudeMillimetersMSLC = 0;
    int32_t altitudeMillimetersMSLA = 0;

    size_t absolutePressureMillibarsC = 0;
    double absolutePressureMillibarsA = .0;

    size_t temperature0KelvinC = 0;
    double temperature0KelvinA = .0;

    size_t temperature1KelvinC = 0;
    double temperature1KelvinA = .0;

    size_t temperature2KelvinC = 0;
    double temperature2KelvinA = .0;

    size_t relativeHumidity0C = 0;
    double relativeHumidity0A = .0;

    size_t relativeHumidity1C = 0;
    double relativeHumidity1A = .0;

    size_t relativeHumidity2C = 0;
    double relativeHumidity2A = .0;

    size_t latitudeDegreesE7C = 0;
    int32_t latitudeDegreesE7A = 0;

    size_t longitudeDegreesE7C = 0;
    int32_t longitudeDegreesE7A = 0;

    size_t rollRadiansC = 0;
    double rollRadiansA = .0;

    size_t pitchRadiansC = 0;
    double pitchRadiansA = .0;

    size_t yawRadiansC = 0;
    double yawRadiansA = .0;

    size_t rollRateRadiansPerSecondC = 0;
    double rollRateRadiansPerSecondA = .0;

    size_t pitchRateRadiansPerSecondC = 0;
    double pitchRateRadiansPerSecondA = .0;

    size_t yawRateRadiansPerSecondC = 0;
    double yawRateRadiansPerSecondA = .0;

    size_t xVelocityMetersPerSecondC = 0;
    double xVelocityMetersPerSecondA = .0;

    size_t yVelocityMetersPerSecondC = 0;
    double yVelocityMetersPerSecondA = .0;

    size_t zVelocityMetersPerSecondC = 0;
    double zVelocityMetersPerSecondA = .0;

    size_t satellitesC = 0;
    uint8_t satellitesA = 0;

    size_t horizontalDilutionOfPositionC = 0;
    uint16_t horizontalDilutionOfPositionA = 0;

public:
    /* parses all relevant messages, keeps the most recent several data points, and updates a rolling average for each data point. */
    int parseMessage(const mavlink_message_t& m);
    void resetAverages();
    DataHub(DataFactGroup* pData, size_t slotWidthMS, size_t slotCount);

private:
    template <typename T, bool bSigned = std::is_signed_v<T>>
    struct LargerType {};

    // template <typename T>
    // struct LargerType<T, false> {
    //     using type = std::conditional_t<sizeof(T) <= 4, uint64_t, __uint128_t>;
    // };

    // template <typename T>
    // struct LargerType<T, true> {
    //     using type = std::conditional_t<sizeof(T) <= 4, int64_t, __int128_t>;
    // };

    /* MSVC apparently doesn't support triple longs
        TODO: figure this out
     */

    template <typename T>
    struct LargerType<T, false> {
        using type = uint64_t;
    };

    template <typename T>
    struct LargerType<T, true> {
        using type = int64_t;
    };

    template <typename T, typename V>
    void updateRollingAverage(T& average, size_t& count, const V& newValue) {
        if constexpr (std::is_integral_v<T>) {
            using LargerT = typename LargerType<T>::type;
            average = static_cast<T>((static_cast<LargerT>(average) * count + static_cast<LargerT>(newValue)) / (count + 1));
        } else {
            /* Within MetGC, all floats are doubles, and we assume doubles have enough precision */
            average = (average * count + static_cast<T>(newValue)) / (count + 1);
        }
        count++;
    }


public:
    typedef enum {
        HUMIDITY /* just one for now, there will be many more */
    } DataType;

    typedef struct {
        uint64_t unixTime;
        DataType type;
        char data[48];
        struct Slot* child;
    } Slot;

    size_t slotWidthMS;
    size_t slotCount;
    Slot* ring;
    uint64_t headUnixTimeUS; /* this + index * slotWidthMS * 1000 is unix time in microseconds */
    size_t headIndex;
    uint64_t unixBootTimeUS;
    bool ringInit;

    inline void msgSysTime(const mavlink_message_t&);
    inline void msgGlobalPosition(const mavlink_message_t& m);
    inline void msgScaledPressure2(const mavlink_message_t& m);
    inline void msgCassSensorRaw(const mavlink_message_t& m);
    inline void msgAttitude(const mavlink_message_t& m);
    inline void msgLocalPositionNED(const mavlink_message_t& m);
    inline void msgHeartbeat(const mavlink_message_t& m);
    inline void msgGPSRawInt(const mavlink_message_t& m);

    inline size_t indexFromUnixTimeUS(uint64_t unixTimeUS);


};

#endif // DATAHUB_H
