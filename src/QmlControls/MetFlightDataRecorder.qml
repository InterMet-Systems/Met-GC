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
    property real _altMsgMinWidth:        ScreenTools.defaultFontPixelWidth * 10
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
        height: _fileNameTouched && !controller.flightNameValid ? 0 : undefined
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

    // altitude message data grid
    RowLayout {
        id: almHeaders
        anchors.top: flightNameError.bottom
        anchors.left: parent.left
        anchors.leftMargin: _toolsMargin
        anchors.topMargin: _toolsMargin

        QGCLabel {
            text: qsTr("Alt\n(m)")
            font.pixelSize: 26
            color: qgcPal.text
            Layout.minimumWidth: _altMsgMinWidth
        }
        
        QGCLabel {
            text: qsTr("Time\n(s)")
            font.pixelSize: 26
            color: qgcPal.text
            Layout.minimumWidth: _altMsgMinWidth
        }

        QGCLabel {
            text: qsTr("Press\n(mB)")
            font.pixelSize: 26
            color: qgcPal.text
            Layout.minimumWidth: _altMsgMinWidth
        }

        QGCLabel {
            text: qsTr("Temp\n(C)")
            font.pixelSize: 26
            color: qgcPal.text
            Layout.minimumWidth: _altMsgMinWidth
        }

        QGCLabel {
            text: qsTr("RelHum\n(%)")
            font.pixelSize: 26
            color: qgcPal.text
            Layout.minimumWidth: _altMsgMinWidth
        }

        QGCLabel {
            text: qsTr("WSpeed\n(m/s)")
            font.pixelSize: 26
            color: qgcPal.text
            Layout.minimumWidth: _altMsgMinWidth
        }

        QGCLabel {
            text: qsTr("WDir\n(deg)")
            font.pixelSize: 26
            color: qgcPal.text
            Layout.minimumWidth: _altMsgMinWidth
        }
    }
    Flickable {
        id: altitudeFlickable
        anchors.top: almHeaders.bottom
        width: parent.width - 2 * _toolsMargin
        height: Math.min(contentHeight, 200)
        contentWidth: width
        contentHeight: almGrid.implicitHeight
        clip: true
        flickableDirection: Flickable.VerticalFlick
    
        GridLayout {
            id: almGrid
            anchors.fill: parent
            columns: 7
            rowSpacing: _toolsMargin
            columnSpacing: _toolsMargin
        
            Repeater {
                model: controller.tempAltLevelMsgList.count
                delegate: QGCLabel {
                        Layout.row:         index
                        Layout.column:      0
                        Layout.minimumWidth: _altMsgMinWidth
                        text: controller.tempAltLevelMsgList.get(index).altitude.toFixed(2)
                        font.pixelSize: 26
                        color: qgcPal.text
                }
            }

            Repeater {
                model: controller.tempAltLevelMsgList.count
                delegate: QGCLabel {
                        Layout.row:         index
                        Layout.column:      1
                        Layout.minimumWidth: _altMsgMinWidth
                        text: controller.tempAltLevelMsgList.get(index).time.toFixed(2)
                        font.pixelSize: 26
                        color: qgcPal.text
                }
            }

            Repeater {
                model: controller.tempAltLevelMsgList.count
                delegate: QGCLabel {
                        Layout.row:         index
                        Layout.column:      2
                        Layout.minimumWidth: _altMsgMinWidth
                        text: controller.tempAltLevelMsgList.get(index).pressure.toFixed(2)
                        font.pixelSize: 26
                        color: qgcPal.text
                }
            }

            Repeater {
                model: controller.tempAltLevelMsgList.count
                delegate: QGCLabel {
                        Layout.row:         index
                        Layout.column:      3
                        Layout.minimumWidth: _altMsgMinWidth
                        text: controller.tempAltLevelMsgList.get(index).temperature.toFixed(2)
                        font.pixelSize: 26
                        color: qgcPal.text
                }
            }

            Repeater {
                model: controller.tempAltLevelMsgList.count
                delegate: QGCLabel {
                        Layout.row:         index
                        Layout.column:      4
                        Layout.minimumWidth: _altMsgMinWidth
                        text: controller.tempAltLevelMsgList.get(index).relativeHumidity.toFixed(2)
                        font.pixelSize: 26
                        color: qgcPal.text
                }
            }

            Repeater {
                model: controller.tempAltLevelMsgList.count
                delegate: QGCLabel {
                        Layout.row:         index
                        Layout.column:      5
                        Layout.minimumWidth: _altMsgMinWidth
                        text: controller.tempAltLevelMsgList.get(index).windSpeed.toFixed(2)
                        font.pixelSize: 26
                        color: qgcPal.text
                }
            }

            Repeater {
                model: controller.tempAltLevelMsgList.count
                delegate: QGCLabel {
                        Layout.row:         index
                        Layout.column:      6
                        Layout.minimumWidth: _altMsgMinWidth
                        text: controller.tempAltLevelMsgList.get(index).windDirection.toFixed(2)
                        font.pixelSize: 26
                        color: qgcPal.text
                }
            }
        }

        ScrollBar.vertical: ScrollBar { }
    }
}
