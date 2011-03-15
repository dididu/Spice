import QtQuick 1.0
import Spice 1.0


ToDoItem {

    id: todoitem
    property string text: ""

    Rectangle {
        width: 100
        height: 30

        color: "white"

        Text {
            id: txt
            text: todoitem.text
        }
    }
}
