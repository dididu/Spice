import QtQuick 1.0

ListView {
    width: 300

    height: 200


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

            Text {
                id: itemText
                x: parent.x + 10
                anchors.verticalCenter: parent.verticalCenter
                text: itemtext
            }

            Text {
                id: itemDueDate
                anchors.verticalCenter: parent.verticalCenter

                anchors.right: parent.right
                anchors.rightMargin: 10
                text: itemduedate
            }
        }
    }
