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

    // divider line
    Rectangle {
        width: parent.width - 2 * _toolsMargin
        height: 1
        color: qgcPal.text
        anchors.bottom: valueArea.top
        anchors.left: parent.left
        anchors.leftMargin: _toolsMargin
        anchors.topMargin: _toolsMargin
    }

    Rectangle {
        id: valueAreaBackground
        anchors.bottom: parent.bottom
        color: qgcPal.window
        width: parent.width / 2
        height: 250
        MetFactValueGrid {
            id:                     valueArea
            defaultSettingsGroup:   metDataDefaultSettingsGroup
            anchors.fill: parent
        }
    }

    QGCButton {
        id:                             _rootButton
        width:                          40 * 1.25
        height:                         40
        flat:                           true
        anchors.bottom:                 parent.bottom
        contentItem: Item {
            id:                         _content
            anchors.fill:               _rootButton
            Row {
                id:                     _edge
                spacing:                ScreenTools.defaultFontPixelWidth * 0.25
                anchors.left:           parent.left
                anchors.leftMargin:     ScreenTools.defaultFontPixelWidth
                anchors.verticalCenter: parent.verticalCenter
                Repeater {
                    model: [1,2,3]
                    Rectangle {
                        height:         ScreenTools.defaultFontPixelHeight
                        width:          ScreenTools.defaultFontPixelWidth * 0.25
                        color:          qgcPal.text
                        opacity:        0.75
                    }
                }
            }
            Image {
                id:                     _icon
                height:                 _rootButton.height * 0.75
                width:                  height
                smooth:                 true
                mipmap:                 true
                antialiasing:           true
                fillMode:               Image.PreserveAspectFit
                source:                 "/InstrumentValueIcons/folder.svg"
                sourceSize.height:      height
                anchors.left:           _edge.right
                anchors.leftMargin:     ScreenTools.defaultFontPixelWidth
                anchors.verticalCenter: parent.verticalCenter
            }
        }
        background: Item {
            anchors.fill: parent
        }
    }
}
