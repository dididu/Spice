import QtQuick 1.0

ListView {
    width: 200; height: 250
    anchors.fill: parent

    model: ToDoModel
    delegate: Text { text: "Text: " + itemtext }
}
