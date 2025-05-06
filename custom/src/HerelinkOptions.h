#pragma once

#include "QGCOptions.h"

class DataHubPlugin;

class HerelinkOptions : public QGCOptions
{
public:
    HerelinkOptions(DataHubPlugin* plugin, QObject* parent = NULL);

    // QGCOptions overrides
    bool wifiReliableForCalibration () const override { return true; }
    bool showFirmwareUpgrade        () const override { return false; }
    bool multiVehicleEnabled        () const override { return false; }
    bool allowJoystickSelection     () const override { return false; }
};
