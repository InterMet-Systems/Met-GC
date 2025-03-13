#ifndef DATAHUBPLUGIN_H
#define DATAHUBPLUGIN_H

#include "QGCCorePlugin.h"
#include "DataHub.h"
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
    void logDataToFile(); // New method for logging

private:
    DataFactGroup dataFactGroup;
    DataHub hub;
    QTimer* logTimer; // Timer to trigger logging
};

#endif // DATAHUBPLUGIN_H
