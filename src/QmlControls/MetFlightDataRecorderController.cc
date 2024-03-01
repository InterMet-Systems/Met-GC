/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "MetFlightDataRecorder.h"
#include "InstrumentValueData.h"
#include "QGCApplication.h"
#include "QGCCorePlugin.h"

#include <QSettings>

const QString MetFlightDataRecorder::flightFileName ("Flight1");

MetFlightDataRecorder::MetFlightDataRecorder(QQuickItem* parent)
{

}

MetFlightDataRecorder::MetFlightDataRecorder(const QString& flightFileName)
{

}
