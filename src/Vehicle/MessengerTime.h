#ifndef MESSENGERTIME_H
#define MESSENGERTIME_H

#include "MessengerBase.h"
#include "MessageRawFactGroup.h"
#include "MessageTimeFactGroup.h"

class MessengerTime final : public MessengerBase<MessageRawFactGroup, MessageTimeFactGroup> {
public:
    MessengerTime(MessageRawFactGroup* src, MessageTimeFactGroup* data)
        : MessengerBase<MessageRawFactGroup, MessageTimeFactGroup>(src, data)
        , frequency(1.) {}
    bool criteriaMet() override;
    void publish() override;
private:
    struct WindProps {
        double speed = 0.;
        int32_t dir = 0;
    };

    void updateConstantData();
    void buildFilename();
    void updateTime();
    std::tm* pt;
    void updateData();
    void buildUTCDateStr();
    void buildUTCTimeStr();
    bool timer();
    double lastMessage = 0.;
    double frequency;
    const WindProps calcWindProps() const; /* copy pasted from MessengerAltitude */
};

#endif // MESSENGERTIME_H
