// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: root

    property alias invoiceItemsModel: invoiceItemList.model
    property real invoiceTotal: 0
    property real invoiceVAT: 0
    property real invoiceTotalVAT: 0
    property int tvaColumnWidth : 60
    property int priceColumnWidth: 70
    property int countColumnWidth: 70
    property int totalColumnWidth: 70

    Rectangle {
        border.color: "black"
        radius: 10
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: totalAmountText.top
        anchors.bottomMargin: 5

        // Title line
        Row {
            id: titleRow
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.rightMargin: 5
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 1

            Text {
                text: "Désignation"
                font.bold: true
                width: titleRow.width - root.tvaColumnWidth - root.priceColumnWidth - root.countColumnWidth - root.totalColumnWidth
            }
            Text {
                text: "TVA %"
                horizontalAlignment: Text.AlignRight
                font.bold: true
                width: root.tvaColumnWidth
            }
            Text {
                text: "Prix U (€)"
                horizontalAlignment: Text.AlignRight
                font.bold: true
                width: root.priceColumnWidth
            }
            Text {
                text: "Quantité"
                horizontalAlignment: Text.AlignRight
                font.bold: true
                width: root.countColumnWidth
            }
            Text {
                text: "Total (€)"
                horizontalAlignment: Text.AlignRight
                font.bold: true
                width: root.totalColumnWidth
            }
        }

        // Separator
        Rectangle {
            id: titleSeparator
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: titleRow.bottom
            anchors.topMargin: 2
            height: 1
            color: "black"
        }

        // Item List
        Column {
            id: itemList
            anchors.top: titleSeparator.bottom
            anchors.topMargin: 2
            anchors.left: parent.left
            anchors.right: parent.right

            Repeater {
                id: invoiceItemList

                Row {
                    id: itemRow
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.leftMargin: 5
                    anchors.rightMargin: 5

                    Text {
                        text: model.modelData.name
                        width: itemRow.width - root.tvaColumnWidth - root.priceColumnWidth - root.countColumnWidth - root.totalColumnWidth
                        wrapMode: Text.WordWrap
                    }
                    Text {
                        text: model.modelData.tax.toFixed(2)
                        horizontalAlignment: Text.AlignRight
                        width: root.tvaColumnWidth
                    }
                    Text {
                        text: model.modelData.price.toFixed(2)
                        horizontalAlignment: Text.AlignRight
                        width: root.priceColumnWidth
                    }
                    Text {
                        text: model.modelData.quantity
                        horizontalAlignment: Text.AlignRight
                        width: root.countColumnWidth
                    }
                    Text {
                        text: (model.modelData.price * model.modelData.quantity).toFixed(2)
                        horizontalAlignment: Text.AlignRight
                        width: root.totalColumnWidth
                    }
                }
            }
        }

        // Draw columns lines
        Rectangle {
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 1
            border.color: "black"
            x: parent.x + parent.width - root.totalColumnWidth
        }
        Rectangle {
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 1
            border.color: "black"
            x: parent.x + parent.width - root.totalColumnWidth - root.countColumnWidth
        }
        Rectangle {
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 1
            border.color: "black"
            x: parent.x + parent.width - root.totalColumnWidth - root.countColumnWidth - root.priceColumnWidth
        }
        Rectangle {
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 1
            border.color: "black"
            x: parent.x + parent.width - root.totalColumnWidth - root.countColumnWidth - root.priceColumnWidth - root.tvaColumnWidth
        }

    }

    Text {
        id: totalAmountText
        text: invoiceTotalVAT
        font.bold: true
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.rightMargin: 5
    }

    Text {
        text: "TOTAL :"
        font.bold: true
        anchors.verticalCenter: totalAmountText.verticalCenter
        x: totalAmountText.x - 100
    }
}
