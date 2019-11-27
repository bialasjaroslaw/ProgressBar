import QtQuick 2.12                    // for the Item
import QtQuick.Controls 2.12           // for ApplicationWindow
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 440
    height: 480
    title: qsTr("Progress Bar")
    ColumnLayout {
            spacing: 10
            width: parent.width
        GroupBox {
            id: box1
            title: "Start - Stop"
            font.pointSize: 20
            Layout.alignment: parent.width
            spacing: 10
            GridLayout {
                width: parent.width
                columns: 1
                RowLayout {
                    spacing: 200
                    Layout.fillWidth: true
                    Layout.fillHeight: false
                    Button {
                        id: buttonStart
                        text: "Start"
                        font.pointSize: 15
                        enabled: !progressDialog.active
                        onClicked: progressDialog.startComputation()
                    }
                    Button {
                        id: buttonFinish
                        text: progressDialog.running ? "Finish" : "Cancel"
                        font.pointSize: 15
                        enabled: progressDialog.running
                        onClicked: progressDialog.cancelComputation()
                    }
                }
            }
        }
        GroupBox {
            id: boxprogress
            title: "Progressbar"
            font.pointSize: 20
            Layout.alignment: parent.width
            spacing: 10
            GridLayout {
                width: parent.width
                columns: 1
                RowLayout {
                    Layout.fillWidth: true
                    Layout.fillHeight: false
                    ProgressBar {
                        id: progressbar_id
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        width: parent.width

                        // These are hard-coded values to confirm it is working
                        from: 0
                        to: 100
                        value: 5
                        onValueChanged: {
                            console.log("Progressbar value changed: ", progressbar_id.value)
                        }
                        onVisibleChanged: {
                            console.log("Progressbar visibility changed: ", progressbar_id.visible)
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: progressbar_id.value += 5;
                        }
                    }
                    Connections {
                        target: progressDialog
                        onProgressChanged: function(){
                            progressbar_id.value = progress;}
                    }
                    // This is working if clicking on the progressbar
                }
            }
    }
}
}
