import QtQuick 1.0

Rectangle {

    id: inputPane
    width: parent.width
    height: 62


    Row {

        height: parent.height
        TextInput {


            x: parent.x + 10
            anchors.verticalCenter: parent.verticalCenter
            width: inputPane.width - 40
            font.pointSize: 14
            text: "lalal"
        }

        Rectangle {
            color: "white"
            border.color: "black"

            height: parent.height
            width: 60

            x: inputPane.width - width
        }
    }

}
