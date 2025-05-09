#ifndef MESSENGERBASE_H
#define MESSENGERBASE_H

#include "MessengerBaseCommon.h"

template<typename TSource, typename TData>
class MessengerBase : public MessengerBaseCommon {
public:
    MessengerBase(TSource* src, TData* data) : source(src), data(data) {}
    virtual bool criteriaMet() = 0;
    virtual void publish() = 0;
    virtual void log() = 0;
protected:
    TSource* source;
    TData* data;
};

#endif // MESSENGERBASE_H
