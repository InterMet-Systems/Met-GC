/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#pragma once

#include <QObject>

#include "QmlObjectListModel.h"
#include "QGCApplication.h"


class MetFlightDataRecorderController : public QObject
{
    Q_OBJECT

public:
    MetFlightDataRecorderController(QQuickItem *parent = nullptr);

    Q_PROPERTY(QString flightFileName MEMBER flightFileName WRITE setFlightFileName NOTIFY flightFileNameChanged)

    QString flightFileName;

public slots:
    void setFlightFileName(QString flightFileName);

signals:
    void flightFileNameChanged();

private:
    Q_DISABLE_COPY(MetFlightDataRecorderController)
};

QML_DECLARE_TYPE(MetFlightDataRecorderController)
