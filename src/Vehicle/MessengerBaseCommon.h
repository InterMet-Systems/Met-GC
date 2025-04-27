#ifndef MESSENGERBASECOMMON_H
#define MESSENGERBASECOMMON_H

class MessengerBaseCommon {
public:
    virtual ~MessengerBaseCommon() = default;
    virtual bool criteriaMet() = 0;
    virtual void publish() = 0;
};

#endif // MESSENGERBASECOMMON_H
