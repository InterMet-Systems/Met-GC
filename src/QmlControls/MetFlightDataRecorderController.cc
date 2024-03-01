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

void MetFlightDataRecorderController::setFlightFileName(QString flightFileName)
{
     qDebug() << "Changing Flight file name to: " << flightFileName;
}
