import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        id: firstCol
        Text {
            id: txtCount
            text: dataStore.message
        }
        Button{
            id: btnUpdate
            text: "Just click me"
            onClicked: {
                dataStore.callMeFromQml();
            }
        }
    }
    Column{
        anchors.left: firstCol.right
        Button{
            id: btnClick
            text: "Click me"
            onClicked: {
                var result = dataStore.qInvokeExample("I pass whatever i want ");
                console.log("result got from c++ code into QML "+ result);
            }
        }
    }
    function functionInJavaScript(arg){
        console.log(arg);
        return "ReTurn Value From Js";
    }
}
