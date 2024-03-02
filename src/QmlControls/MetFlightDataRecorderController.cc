/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "MetFlightDataRecorderController.h"
#include "QGCCorePlugin.h"

#include <QSettings>

MetFlightDataRecorderController::MetFlightDataRecorderController(QQuickItem* parent)
{

}

void MetFlightDataRecorderController::setFlightFileName(QString _flightFileName)
{
    this->flightFileName = _flightFileName;
    bool isValid = this->flightFileName.length() > 0;
    if(isValid) {
        for (const QChar ch : _flightFileName) {
            if (!this->flightNameValidChars.contains(ch)) {
                isValid = false;
            }
        }
    }
    if(isValid != this->flightNameValid) {
        this->flightNameValid = isValid;
        emit flightNameValidChanged();
    }
}
