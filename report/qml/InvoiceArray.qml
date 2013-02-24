// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item {
    id: root

    property alias invoiceItemsModel: invoiceItemList.model
    property real invoiceTotal: 0
    property real invoiceVAT: 0
    property real invoiceTotalVAT: 0
    property int priceColumnWidth: 50
    property int countColumnWidth: 70
    property int totalColumnWidth: 100

    // Title line
    Row {
        id: titleRow
        anchors.left: root.left
        anchors.right: root.right
        anchors.top: root.top

        Text {
            text: "Désignation"
            font.bold: true
            width: root.width - root.priceColumnWidth - root.countColumnWidth - root.totalColumnWidth
        }
        Text {
            text: "Prix unitaire"
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
            text: "Montant (€)"
            horizontalAlignment: Text.AlignRight
            font.bold: true
            width: root.totalColumnWidth
        }
    }

    // Separator
    Rectangle {
        id: titleSeparator
        anchors.left: root.left
        anchors.right: root.right
        anchors.top: titleRow.bottom
        anchors.topMargin: 2
        height: 1
        color: "#000000"
    }

    // Item List
    Column {
        id: itemList
        anchors.top: titleSeparator.bottom
        anchors.topMargin: 2
        anchors.left: root.left
        anchors.right: root.right

        Repeater {
            id: invoiceItemList

            Row {
                id: itemRow
                anchors.left: parent.left
                anchors.right: parent.right

                Text {
                    text: model.modelData.name
                    width: root.width - root.priceColumnWidth - root.countColumnWidth - root.totalColumnWidth
                    wrapMode: Text.WordWrap
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

    // Separator
    Rectangle {
        id: totalSeparator
        anchors.left: root.left
        anchors.right: root.right
        anchors.top: itemList.bottom
        anchors.topMargin: 2
        height: 1
        color: "#000000"
    }

    // Total and VAT
    Text {
        id: htvaTotal
        anchors.left: root.left
        anchors.top: totalSeparator.bottom
        anchors.topMargin: 2
        text: "Total HT"
    }
    Text {
        anchors.right: root.right
        anchors.top: totalSeparator.bottom
        anchors.topMargin: 2
        horizontalAlignment: Text.AlignRight
        text: invoiceTotal.toFixed(2)
    }
    Text {
        id: vatAmount
        anchors.left: root.left
        anchors.top: htvaTotal.bottom
        anchors.topMargin: 2
        text: "TVA 21.0 %"
    }
    Text {
        anchors.right: root.right
        anchors.top: htvaTotal.bottom
        anchors.topMargin: 2
        horizontalAlignment: Text.AlignRight
        text: invoiceVAT.toFixed(2)
    }

    // Double Separator
    Rectangle {
        id: doubleSeparator1
        anchors.left: root.left
        anchors.right: root.right
        anchors.top: vatAmount.bottom
        anchors.topMargin: 2
        height: 1
        color: "#000000"
    }
    Rectangle {
        id: doubleSeparator2
        anchors.left: root.left
        anchors.right: root.right
        anchors.top: doubleSeparator1.bottom
        anchors.topMargin: 2
        height: 1
        color: "#000000"
    }

    // Full total
    Text {
        id: fullTotal
        anchors.left: root.left
        anchors.top: doubleSeparator2.bottom
        anchors.topMargin: 2
        font.bold: true
        text: "Total TTC"
    }
    Text {
        anchors.right: root.right
        anchors.top: doubleSeparator2.bottom
        anchors.topMargin: 2
        horizontalAlignment: Text.AlignRight
        font.bold: true
        text: invoiceTotalVAT.toFixed(2)
    }
}
