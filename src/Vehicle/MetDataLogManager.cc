#include "QGCApplication.h"
#include "MetDataLogManager.h"
#include "SettingsManager.h"
#include "MetFlightDataRecorderController.h"

MetDataLogManager::MetDataLogManager(QGCApplication* app, QGCToolbox* toolbox) : QGCTool(app, toolbox)
{
    connect(&_metRawCsvTimer, &QTimer::timeout, this, &MetDataLogManager::_writeMetRawCsvLine);
    connect(&_metRawCsvTimer, &QTimer::timeout, this, &MetDataLogManager::_writeMetAlmCsvLine);
    _metRawCsvTimer.start(1000);
}

MetDataLogManager::~MetDataLogManager()
{
    _metRawCsvFile.close();
    _metAlmCsvFile.close();
}

void MetDataLogManager::_initializeMetRawCsv()
{
    QString now = QDateTime::currentDateTime().toString("MM-dd-yyyy_hh-mm-ss");
    QString metRawFileName = QString("RAW_%1.csv").arg(now);
    QDir saveDir(qgcApp()->toolbox()->settingsManager()->appSettings()->messagesRawSavePath());
    _metRawCsvFile.setFileName(saveDir.absoluteFilePath(metRawFileName));

    if (!_metRawCsvFile.open(QIODevice::Append)) {
        qCWarning(VehicleLog) << "unable to open raw message file for csv logging, Stopping csv logging!";
        return;
    }

    QTextStream stream(&_metRawCsvFile);

    qCDebug(VehicleLog) << "Facts logged to csv:" << metRawFactHeaders;
    stream << metRawFactHeaders.join(",") << "\r\n";
    stream << metRawFactUnits.join(",") << "\r\n";
}

void MetDataLogManager::_writeMetRawCsvLine()
{
    // Only save the logs after the the vehicle gets armed, unless "Save logs even if vehicle was not armed" is checked
    Vehicle* _activeVehicle = qgcApp()->toolbox()->multiVehicleManager()->activeVehicle();
    if(!_metRawCsvFile.isOpen() && _activeVehicle && _activeVehicle->armed()) {
        _initializeMetRawCsv();
    }

    if(!_metRawCsvFile.isOpen() || !_activeVehicle || !_activeVehicle->armed()) {
        return;
    }

    QStringList metFactValues;
    QTextStream stream(&_metRawCsvFile);

    FactGroup* factGroup = nullptr;
    factGroup = _activeVehicle->getFactGroup("temperature");

    if (!factGroup) {
        return;
    }

    // Write timestamp to csv file
    for (const auto &factName : metRawFactNames) {
        if(!factGroup->factExists(factName)) {
            qCWarning(VehicleLog) << "Fact does not exist: " << factName;
            continue;
        }
        metFactValues << factGroup->getFact(factName)->rawValueString();
    }

    stream << metFactValues.join(",") << "\r\n";
}

void MetDataLogManager::setFlightFileName(QString flightName)
{
    _flightName = flightName;
}

void MetDataLogManager::_initializeMetAlmCsv()
{
    qDebug() << "Initializing ALM csv file";
    // TODO: get flight name, and ascent number from the GUI, copy number by testing files in the directory
    int copyNumber = 1;

    QString metAlmFileName = QString("%1_%2_%3.csv").arg(_flightName).arg(copyNumber).arg(ascentNumber);
    QDir saveDir(qgcApp()->toolbox()->settingsManager()->appSettings()->messagesAltLevelSavePath());
    _metAlmCsvFile.setFileName(saveDir.absoluteFilePath(metAlmFileName));

    if (!_metAlmCsvFile.open(QIODevice::Append)) {
        qCWarning(VehicleLog) << "unable to open ALM message file for csv logging, Stopping csv logging!";
        return;
    }

    QTextStream stream(&_metAlmCsvFile);

    qCDebug(VehicleLog) << "Facts logged to csv:" << metAlmFactHeaders;
    stream << metAlmFactHeaders.join(",") << "\r\n";
    stream << metAlmFactUnits.join(",") << "\r\n";
}

void MetDataLogManager::_writeMetAlmCsvLine()
{
    Vehicle* _activeVehicle = qgcApp()->toolbox()->multiVehicleManager()->activeVehicle();
    if(!_metAlmCsvFile.isOpen() && _activeVehicle && _activeVehicle->armed()) {
        _initializeMetAlmCsv();
    }

    if(!_metAlmCsvFile.isOpen() || !_activeVehicle || !_activeVehicle->armed()) {
        return;
    }

    QStringList metFactValues;
    QTextStream stream(&_metAlmCsvFile);

    FactGroup* factGroup = nullptr;
    factGroup = _activeVehicle->getFactGroup("temperature");

    if (!factGroup) {
        return;
    }

    for (const auto &factName : metAlmFactNames) {
        if(!factGroup->factExists(factName)) {
            qCWarning(VehicleLog) << "Fact does not exist: " << factName;
            continue;
        }
        metFactValues << factGroup->getFact(factName)->rawValueString();
    }

    stream << metFactValues.join(",") << "\r\n";
}

