/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include "FactSystem.h"
#include "QmlObjectListModel.h"
#include "QGCApplication.h"
#include "FactValueGrid.h"

class InstrumentValueData;

class MetFlightDataRecorder : public FactValueGrid
{
    Q_OBJECT

public:
    MetFlightDataRecorder(QQuickItem *parent = nullptr);
    MetFlightDataRecorder(const QString& flightFileName);

    Q_PROPERTY(QString flightFileName MEMBER flightFileName CONSTANT)

    static const QString flightFileName;

private:
    Q_DISABLE_COPY(MetFlightDataRecorder)
};

QML_DECLARE_TYPE(MetFlightDataRecorder)
