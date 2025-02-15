/****************************************************************************
 *
 * (c) 2009-2019 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 *   @brief Custom QGCCorePlugin Declaration
 *   @author Gus Grubba <gus@auterion.com>
 */

#pragma once

#include "QGCCorePlugin.h"
#include "QGCLoggingCategory.h"
#include "SettingsManager.h"
#include "DataBalancer.h"

#include <QTranslator>

class DataBalancerPlugin;

// Q_DECLARE_LOGGING_CATEGORY(CustomLog)

class DataBalancerPlugin : public QGCCorePlugin
{
    Q_OBJECT
public:
    DataBalancerPlugin(QGCApplication* app, QGCToolbox *toolbox);
    ~DataBalancerPlugin();

    bool mavlinkMessage(Vehicle* vehicle, LinkInterface* link, mavlink_message_t message);


private slots:

private:
    DataBalancer balancer;
};
