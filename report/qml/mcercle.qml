import QtQuick 1.1

Rectangle {
    id: root
    width: 496
    height: 702

    Item {
        id: logoGroup
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.top: parent.top
        anchors.topMargin: 30
        width: childrenRect.width
        height: childrenRect.height

        Image {
            id: logo
            source: "mcercle-logo-256.png"
            width: 100
            height: 100
            anchors.horizontalCenter: addressText.horizontalCenter
            anchors.top: parent.top
        }

        Text {
            id: addressText
            text: company.name + "\n" + company.address + "\n" + company.zipcode + " " + company.city
            font.pixelSize: 11
            anchors.top: logo.bottom
            anchors.topMargin: 15
            anchors.left: parent.left
        }
    }

    Text {
        id: factureText
        text: qsTr("Facture")
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.top: parent.top
        anchors.topMargin: 30
        font.pixelSize: 22
    }

    Text {
        id: infoText
        text: qsTr("Code: ") + invoice.code + qsTr("\nRéfs.: ") + invoice.reference + "\nDate: " + Qt.formatDate(invoice.date, "dd MMMM yyyy")
        anchors.right: factureText.right
        anchors.top: factureText.bottom
        anchors.topMargin: 5
        horizontalAlignment: Text.AlignRight
    }

    Rectangle {
        id: customerView
        width: customerText.width + 20
        height: customerText.height + 20
        radius: 10
        border.color: "black"
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.top: if (addressText.y + addressText.height > infoText.y + infoText.height) logoGroup.bottom; else infoText.bottom;

        Text {
            id: customerText
            text: customer.lastname + " " + customer.firstname + "\n" + customer.address + "\n" + customer.zipcode + " " + customer.city
            anchors.centerIn: parent
        }
    }

    MCercleProducts {
        anchors.top: customerView.bottom
        anchors.topMargin: 30
        anchors.bottom: footerLine.top
        anchors.bottomMargin: 70
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.right: parent.right
        anchors.rightMargin: 30

        invoiceItemsModel: invoice.products
        invoiceTotal: invoice.total
        invoiceTotalVAT: invoice.totalTaxed
        invoiceVAT: invoice.totalTaxed - invoice.total
    }

    // Footer
    Rectangle {
        id: footerLine
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.bottom: footerText.top
        anchors.bottomMargin: 10
        height: 1
        border.color: "black"
    }

    Text {
        id: footerText
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        horizontalAlignment: Text.AlignHCenter
        text: company.address + " - " + company.zipcode + " " + company.city + "\nSiret : " + company.siret
    }
}
