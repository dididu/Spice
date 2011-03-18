import QtQuick 1.0

ListView {
    width: 200; height: 250
    anchors.fill: parent
    model: ToDoModel
    spacing: 10

    delegate:
        Rectangle {

            x: parent.x + 10
            height: itemText.height + 10
            width:  parent.width - 20
            radius: 4
            color: "white"

            Text {

                id: itemText
                x: parent.x + 5
                anchors.verticalCenter: parent.verticalCenter
                text: itemtext
            }
        }
    }
