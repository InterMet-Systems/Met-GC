#ifndef DATAHUBPLUGIN_H
#define DATAHUBPLUGIN_H

#include "QGCCorePlugin.h"
#include "DataHub.h"
#include "MessengerRaw.h"
#include "MessengerAltitude.h"
#include "MessengerTime.h"
#include <QTranslator>
#include <QTimer>

class DataHubPlugin : public QGCCorePlugin
{
    Q_OBJECT
public:
    DataHubPlugin(QGCApplication* app, QGCToolbox *toolbox);
    ~DataHubPlugin();

    bool mavlinkMessage(Vehicle* vehicle, LinkInterface* link, mavlink_message_t message) override;

private slots:
    /* very much WIP - puts the .txt log file in users/documents/QGroundControl */
    void logDataToFile();
    void logRawMessagesToFile();

private:
    DataFactGroup dataFactGroup;
    DataHub hub;

    MessageRawFactGroup messageRawFactGroup;
    MessengerRaw messengerRaw;

    MessageAltitudeFactGroup messageAltitudeFactGroup;
    MessengerAltitude messengerAltitude;

    MessageTimeFactGroup messageTimeFactGroup;
    MessengerTime messengerTime;

    /* this is only for the temp logging method */
    QTimer* logTimer;
};

#endif // DATAHUBPLUGIN_H
