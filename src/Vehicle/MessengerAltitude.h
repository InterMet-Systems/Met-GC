#ifndef MESSENGERALTITUDE_H
#define MESSENGERALTITUDE_H

#include "MessengerBase.h"
#include "MessageRawFactGroup.h"
#include "MessageAltitudeFactGroup.h"

class MessengerAltitude final : public MessengerBase<MessageRawFactGroup, MessageAltitudeFactGroup> {
public:
    MessengerAltitude(MessageRawFactGroup* src, MessageAltitudeFactGroup* data)
        : MessengerBase<MessageRawFactGroup, MessageAltitudeFactGroup>(src, data) {}
    bool criteriaMet() override;
    void publish() override;
private:

    struct WindProps {
        double speed = 0.;
        uint32_t dir = 0;
    };

    void updateTime();
    std::tm* pt;
    void updateConstantData();
    void getStringFromUser();
    double* windSpeedDir(const double roll, const double pitch, const double yaw);
    double groundSpeed(const double vx, const double vy);
    const WindProps calcWindProps() const;
    void buildFilename();
    void buildUTCDateStr();
    void buildUTCTimeStr();
    void updateData();
    bool passedThreshold();
};

#endif // MESSENGERALTITUDE_H
