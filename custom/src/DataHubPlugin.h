#ifndef DATAHUBPLUGIN_H
#define DATAHUBPLUGIN_H

#include "HerelinkOptions.h" // herelink adaptations
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

    // herelink plugin adaptations
    Q_PROPERTY(bool isHerelink READ isHerelink CONSTANT)
    bool isHerelink (void) const { return true; }
    // overrides from QGCCorePlugin
    QGCOptions* options(void) override { return qobject_cast<QGCOptions*>(_herelinkOptions); }
    bool overrideSettingsGroupVisibility(QString name) override;
    bool adjustSettingMetaData(const QString& settingsGroup, FactMetaData& metaData) override;
    void factValueGridCreateDefaultSettings(const QString& defaultSettingsGroup) override;
    // Overrides from QGCTool
    void setToolbox(QGCToolbox* toolbox) override;

private slots:
    /* very much WIP - puts the .txt log file in users/documents/QGroundControl */
    void logDataToFile();
    void logRawMessagesToFile();

    // herelink plugin adaptations
    void _activeVehicleChanged(Vehicle* activeVehicle);

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

    // herelink plugin adaptations
    HerelinkOptions* _herelinkOptions = nullptr;

};

#endif // DATAHUBPLUGIN_H
