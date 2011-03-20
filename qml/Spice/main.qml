import QtQuick 1.0

Rectangle {
    width: 360
    height: 360 

    color: "gray"

    Column {
        spacing: 10
        AddTaskField {

        }

        ToDoListView{
        }
    }
}
