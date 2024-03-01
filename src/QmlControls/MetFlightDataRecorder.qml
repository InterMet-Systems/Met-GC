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
    id:                 metFlightData
    color:              qgcPal.window
    radius:             ScreenTools.defaultFontPixelWidth / 2

    property real   _toolsMargin:           ScreenTools.defaultFontPixelWidth * 0.75

    MetFlightDataRecorderController {
        id: controller
    }

    Text {
        id: flightLabel
        text: "Flight:"
        font.pixelSize: 20
        width: 65
        color: qgcPal.text
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.leftMargin: _toolsMargin
        anchors.topMargin: _toolsMargin
    }

    QGCTextField {
        id: flightInput
        anchors.top: text.bottom
        anchors.left: flightLabel.right
        anchors.leftMargin: _toolsMargin
        anchors.topMargin: _toolsMargin
        width: 400
        height: 30
        showHelp: false
        placeholderText:  qsTr("Enter Flight Name")
        text: controller.flightFileName
        onEditingFinished: {
            controller.flightFileName = text
        }
    }

}
