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

    Q_PROPERTY(QString flightFileName MEMBER flightFileName WRITE setFlightFileName)
    Q_PROPERTY(bool flightNameValid MEMBER flightNameValid NOTIFY flightNameValidChanged)
    Q_PROPERTY(int ascentNumber MEMBER ascentNumber NOTIFY ascentNumberChanged)

    QString flightFileName;
    bool flightNameValid = false;
    int ascentNumber = 1;

public slots:
    void setFlightFileName(QString flightFileName);

signals:
    void flightNameValidChanged();
    void ascentNumberChanged();

private:
    Q_DISABLE_COPY(MetFlightDataRecorderController)
    const QString flightNameValidChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_,+=(`~!@#$%^&(){}[];\"'. ";
};

QML_DECLARE_TYPE(MetFlightDataRecorderController)
