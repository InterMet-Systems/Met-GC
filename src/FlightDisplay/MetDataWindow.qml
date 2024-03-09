/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

import QtQuick          2.3
import QtQuick.Controls 2.15
import QtQuick.Layouts  1.15
import QtQuick.Dialogs  1.3

import QGroundControl               1.0
import QGroundControl.Controls      1.0
import QGroundControl.Palette       1.0
import QGroundControl.Controllers   1.0
import QGroundControl.FactSystem    1.0
import QGroundControl.FactControls  1.0
import QGroundControl.ScreenTools   1.0

Rectangle {
    id:                 metDataWindow
    height:             700
    width:              900
    color:              qgcPal.window
    radius:             ScreenTools.defaultFontPixelWidth / 2

    property real   _toolsMargin:           ScreenTools.defaultFontPixelWidth * 0.75

    MetFlightDataRecorder {
        id:             metFlightData
        width:          parent.width
        height:         250
        anchors.top:    parent.top
    }

    Rectangle {
        color: qgcPal.window
        width: parent.width
        height: 250
        anchors.bottom: parent.bottom
        MetFactValueGrid {
            id:                     valueArea
            defaultSettingsGroup:   metDataDefaultSettingsGroup
            anchors.fill: parent
        }
    }
}
