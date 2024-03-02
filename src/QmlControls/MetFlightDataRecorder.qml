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

    property real _toolsMargin:           ScreenTools.defaultFontPixelWidth * 0.75
    property bool _fileNameTouched:       false
    MetFlightDataRecorderController { id: controller; }

    Text {
        id: flightLabel
        text: "Flight:"
        font.pixelSize: 26
        color: qgcPal.text
        anchors.verticalCenter: flightInput.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: _toolsMargin
    }

    QGCTextField {
        id: flightInput
        anchors.top: parent.top
        anchors.left: flightLabel.right
        anchors.leftMargin: _toolsMargin
        anchors.topMargin: _toolsMargin
        width: 300
        showHelp: false
        placeholderText:  qsTr("Enter Flight Name")
        text: controller.flightFileName
        onTextChanged: {
            controller.flightFileName = text
            _fileNameTouched = true
        }
    }

    Text {
        id: flightNameError
        text: qsTr("Flight name is invalid")
        color: qgcPal.colorRed
        visible: _fileNameTouched && !controller.flightNameValid
        font.pixelSize: 18
        anchors.top: flightInput.bottom
        anchors.left: flightInput.left
        anchors.leftMargin: _toolsMargin
        anchors.topMargin: _toolsMargin
    }

    // Ascent Lable
    Text {
        id: ascentLabel
        text: `${qsTr("Ascent")}: ${controller.ascentNumber}`
        font.pixelSize: 26
        color: qgcPal.text
        visible: controller.ascentNumber > 0
        anchors.verticalCenter: flightInput.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: _toolsMargin
        anchors.topMargin: _toolsMargin
    }

    // divider line
    Rectangle {
        width: parent.width - 2 * _toolsMargin
        height: 1
        color: qgcPal.text
        anchors.top: flightNameError.bottom
        anchors.left: parent.left
        anchors.leftMargin: _toolsMargin
        anchors.topMargin: _toolsMargin
    }

}
