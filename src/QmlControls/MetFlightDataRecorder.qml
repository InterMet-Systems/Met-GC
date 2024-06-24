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
import QtQuick.Window   2.11

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

    property var textScale
    property real _toolsMargin:           ScreenTools.defaultFontPixelWidth
    property bool _fileNameTouched:       false
    property real _fontSize:              ScreenTools.defaultFontPointSize * textScale
    property real _altMsgMinWidth:        _fontSize * 10
    property real _smallFontSize:         ScreenTools.defaultFontPointSize * 0.75
    MetFlightDataRecorderController { id: controller; }

    // make goToFile function available outside of this file
    function goToFile() {
        controller.goToFile()
    }

    GridLayout {
        id: textInputs
        width: parent.width
        columns: 2
        rows: 2
        rowSpacing: 25

        Item {
            Layout.row: 0
            Layout.column: 0
            Layout.fillWidth: true
            height: flightInput.height

            Text {
                id: flightLabel
                text: "Flight:"
                font.pointSize: _fontSize
                color: qgcPal.text
                anchors.verticalCenter: flightInput.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: _toolsMargin
            }

            TextField {
                id: flightInput
                anchors.top: parent.top
                anchors.left: flightLabel.right
                anchors.right: parent.right
                anchors.leftMargin: _toolsMargin
                anchors.topMargin: _toolsMargin
                font.pointSize: _fontSize
                width: parent.width - flightLabel.width - _toolsMargin
                //showHelp: false
                placeholderText:  qsTr("Enter Flight Name")
                color: qgcPal.textFieldText
                text: controller.flightFileName
                onTextChanged: {
                    controller.flightFileName = text
                    _fileNameTouched = true
                }
            }
        }

        Item {
            Layout.row: 0
            Layout.column: 1
            Layout.fillWidth: true

            Text {
                id: flightNameError

                text: qsTr("Invalid Flight Name")
                color: qgcPal.colorRed
                visible: _fileNameTouched && !controller.flightNameValid
                font.pointSize: _smallFontSize

                anchors.leftMargin: _toolsMargin
                anchors.topMargin: _toolsMargin
            }

            // Ascent Label
            Text {
                id: ascentLabel
                text: `${qsTr("Ascent")}: ${controller.ascentNumber}`
                font.pointSize: _fontSize
                color: qgcPal.text
                visible: controller.ascentNumber > 0
                anchors.right: parent.right
                anchors.rightMargin: _toolsMargin
            }
        }

        Item {
            Layout.row: 1
            Layout.column: 0
            Layout.fillWidth: true
            anchors.topMargin: _toolsMargin
            height: opInput.height

            Text {
                id: opLabel
                text: "Operator ID:"
                font.pointSize: _fontSize
                color: qgcPal.text
                anchors.verticalCenter: opInput.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: _toolsMargin
            }

            TextField {
                id: opInput
                anchors.top: parent.top
                anchors.left: opLabel.right
                anchors.right: parent.right
                anchors.leftMargin: _toolsMargin
                font.pointSize: _fontSize

                placeholderText:  qsTr("Enter Operator ID")
                color: qgcPal.textFieldText
                text: controller.operatorId
                onTextChanged: {
                    controller.operatorId = text
                }
            }
        }

        Item {
            Layout.row: 1
            Layout.column: 1
            Layout.fillWidth: true
            height: craftInput.height
            anchors.topMargin: _toolsMargin

            Text {
                id: craftLabel
                text: "Airframe ID:"
                font.pointSize: _fontSize
                color: qgcPal.text
                anchors.verticalCenter: craftInput.verticalCenter
                anchors.left: parent.left
                anchors.rightMargin: _toolsMargin
            }

            TextField {
                id: craftInput
                anchors.top: parent.top
                anchors.left: craftLabel.right
                anchors.leftMargin: _toolsMargin
                anchors.right: parent.right
                anchors.rightMargin: _toolsMargin
                font.pointSize: _fontSize

                width: parent.width - craftLabel.width - _toolsMargin * 2
                placeholderText: qsTr("Enter Airframe ID")
                color: qgcPal.textFieldText
                text: controller.airframeId
                onTextChanged: {
                    controller.airframeId = text
                }
            }
        }
    }

    // altitude message data grid
    Rectangle {
        color: qgcPal.windowShade
        anchors.top: textInputs.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: _toolsMargin * 2
        anchors.bottom: parent.bottom
        width: parent.width
        // Layout.fillWidth: true

        GridLayout {
            id: almHeaders
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: _toolsMargin
            anchors.topMargin: _toolsMargin
            width: parent.width
            columns: 7
            rowSpacing: _toolsMargin
            columnSpacing: _toolsMargin

            QGCLabel {
                text: qsTr("Alt\n(m)")
                horizontalAlignment: Text.AlignRight
                font.pointSize: _fontSize
                color: qgcPal.text
                Layout.preferredWidth: _altMsgMinWidth * 0.9
                Layout.row: 0
                Layout.column: 0
            }

            QGCLabel {
                text: qsTr("Time\n(s)")
                horizontalAlignment: Text.AlignRight
                font.pointSize: _fontSize
                color: qgcPal.text
                Layout.preferredWidth: _altMsgMinWidth * 1.3
                Layout.row: 0
                Layout.column: 1
            }

            QGCLabel {
                text: qsTr("Press\n(mB)")
                horizontalAlignment: Text.AlignRight
                font.pointSize: _fontSize
                color: qgcPal.text
                Layout.preferredWidth: _altMsgMinWidth * 0.9
                Layout.row: 0
                Layout.column: 2
            }

            QGCLabel {
                text: qsTr("Temp\n(C)")
                horizontalAlignment: Text.AlignRight
                font.pointSize: _fontSize
                color: qgcPal.text
                Layout.preferredWidth: _altMsgMinWidth
                Layout.row: 0
                Layout.column: 3
            }

            QGCLabel {
                text: qsTr("RelHum\n(%)")
                horizontalAlignment: Text.AlignRight
                font.pointSize: _fontSize
                color: qgcPal.text
                Layout.preferredWidth: _altMsgMinWidth
                Layout.row: 0
                Layout.column: 4
            }

            QGCLabel {
                text: qsTr("WSpeed\n(m/s)")
                horizontalAlignment: Text.AlignRight
                font.pointSize: _fontSize
                color: qgcPal.text
                Layout.preferredWidth: _altMsgMinWidth
                Layout.row: 0
                Layout.column: 5
            }

            QGCLabel {
                text: qsTr("WDir\n(deg)")
                horizontalAlignment: Text.AlignRight
                font.pointSize: _fontSize
                color: qgcPal.text
                Layout.preferredWidth: _altMsgMinWidth * 0.9
                Layout.row: 0
                Layout.column: 6
            }
        }

        Flickable {
            id: altitudeFlickable
            anchors.top: almHeaders.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            width: parent.width
            anchors.bottom: parent.bottom
            boundsBehavior: Flickable.StopAtBounds
            contentWidth: width
            contentHeight: almGrid.implicitHeight + 2 * _toolsMargin
            clip: true
            flickableDirection: Flickable.VerticalFlick

            MouseArea {
                anchors.fill: parent

                onWheel: {
                    altitudeFlickable.cancelFlick()
                    if (wheel.angleDelta.y > 0) {
                        altitudeFlickable.flick(0, 500)
                    } else {
                        altitudeFlickable.flick(0, -500)
                    }
                    wheel.accepted = true
                }
            }

            GridLayout {
                id: almGrid
                anchors.fill: parent
                anchors.topMargin: _toolsMargin
                anchors.bottomMargin: _toolsMargin
                anchors.leftMargin: _toolsMargin
                columns: 7
                rowSpacing: _toolsMargin
                columnSpacing: _toolsMargin

                Repeater {
                    model: controller.tempAltLevelMsgList.count
                    delegate: QGCLabel {
                            Layout.row:         index
                            Layout.column:      0
                            Layout.preferredWidth: _altMsgMinWidth * 0.9
                            text: controller.tempAltLevelMsgList.get(index).altitude
                            font.pointSize: _fontSize
                            color: qgcPal.text
                            horizontalAlignment: Text.AlignRight
                    }
                }

                Repeater {
                    model: controller.tempAltLevelMsgList.count
                    delegate: QGCLabel {
                            Layout.row:         index
                            Layout.column:      1
                            Layout.preferredWidth: _altMsgMinWidth * 1.3
                            text: controller.tempAltLevelMsgList.get(index).time
                            font.pointSize: _fontSize
                            color: qgcPal.text
                            horizontalAlignment: Text.AlignRight
                    }
                }

                Repeater {
                    model: controller.tempAltLevelMsgList.count
                    delegate: QGCLabel {
                            Layout.row:         index
                            Layout.column:      2
                            Layout.preferredWidth: _altMsgMinWidth * 0.9
                            text: controller.tempAltLevelMsgList.get(index).pressure
                            font.pointSize: _fontSize
                            color: qgcPal.text
                            horizontalAlignment: Text.AlignRight
                    }
                }

                Repeater {
                    model: controller.tempAltLevelMsgList.count
                    delegate: QGCLabel {
                            Layout.row:         index
                            Layout.column:      3
                            Layout.preferredWidth: _altMsgMinWidth
                            text: controller.tempAltLevelMsgList.get(index).temperature
                            font.pointSize: _fontSize
                            color: qgcPal.text
                            horizontalAlignment: Text.AlignRight
                    }
                }

                Repeater {
                    model: controller.tempAltLevelMsgList.count
                    delegate: QGCLabel {
                            Layout.row:         index
                            Layout.column:      4
                            Layout.preferredWidth: _altMsgMinWidth
                            text: controller.tempAltLevelMsgList.get(index).relativeHumidity
                            font.pointSize: _fontSize
                            color: qgcPal.text
                            horizontalAlignment: Text.AlignRight
                    }
                }

                Repeater {
                    model: controller.tempAltLevelMsgList.count
                    delegate: QGCLabel {
                            Layout.row:         index
                            Layout.column:      5
                            Layout.preferredWidth: _altMsgMinWidth
                            text: controller.tempAltLevelMsgList.get(index).windSpeed
                            font.pointSize: _fontSize
                            color: qgcPal.text
                            horizontalAlignment: Text.AlignRight
                    }
                }

                Repeater {
                    model: controller.tempAltLevelMsgList.count
                    delegate: QGCLabel {
                            Layout.row:         index
                            Layout.column:      6
                            Layout.preferredWidth: _altMsgMinWidth * 0.9
                            text: controller.tempAltLevelMsgList.get(index).windDirection
                            font.pointSize: _fontSize
                            color: qgcPal.text
                            horizontalAlignment: Text.AlignRight
                    }
                }
            }

            ScrollBar.vertical: ScrollBar { id: vScrollBar }
        }
    }
}
