import QtQuick 1.0

ListView {
    width: 200; height: 250
    anchors.fill: parent
    model: ToDoModel
    spacing: 10

    delegate:
        Rectangle {

            id: itemRectangle
            x: parent.x + 10
            height: itemText.height + 10
            width:  parent.width - 20
            radius: 4
            color: "white"

            Row {

                x: parent.x + 5
                width: parent.width - 10
                anchors.verticalCenter: parent.verticalCenter

                Text {
                    id: itemText
                    anchors.verticalCenter: parent.verticalCenter
                    text: itemtext
                }

                Text {
                    id: itemDueDate
                    anchors.verticalCenter: parent.verticalCenter

                    anchors.right: parent.right
                    anchors.rightMargin: 20
                    text: itemduedate
                }
            }
        }
    }
