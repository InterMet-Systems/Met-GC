#ifndef MESSENGERRAW_H
#define MESSENGERRAW_H

#include "MessengerBase.h"
#include "DataFactGroup.h"
#include "MessageRawFactGroup.h"
#include "DataHub.h"

class MessengerRaw final : public MessengerBase<DataFactGroup, MessageRawFactGroup> {
public:
    MessengerRaw(DataFactGroup* src, MessageRawFactGroup* data)
        : MessengerBase<DataFactGroup, MessageRawFactGroup>(src, data)
        , frequency(50.) {}
    bool criteriaMet() override;
    void publish() override;
    double frequency;
    DataHub* dataHub;
private:
    /* These four are called in succession in criteriaMet */

    bool srcInit();

    /* Populates MessageRawFactGroup given DataFactGroup, performing unit/type conversions as necessary. */
    void updateData();
    /* Read some file and populate the nine facts that come from the file, assuming that they only need to be set once on startup.
       This also sets poweredAgeSeconds and armedAgeSeconds. */
    void initFileFacts();
    /* True if each fact has a valid value */
    bool validValues();
    /* True if it's been at least 1 / 'frequency' seconds since the last time it returned true */
    bool timer();
    double lastMessage = 0.;

    bool ascending();

    std::vector<MessengerBase> subscribers;

    const std::string createFilename() const;
};

#endif // MESSENGERRAW_H
