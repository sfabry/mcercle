import QtQuick 1.1

Rectangle {
    id: root
    width: 496
    height: 702

    Text {
        id: cutesoftAddress
        width: 200
        text: company.name + "\n" + company.address + "\n" + company.zipcode + " " + company.city
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.top: parent.top
        anchors.topMargin: 30
        font.pixelSize: 11
    }

    Text {
        id: cutesoftContact
        text: qsTr("Tél. : ") + company.phone + "\nEmail : " + company.email + "\nTVA : " + company.siret + "\nIBAN : " + company.iban + "\nBIC : " + company.bic
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.top: cutesoftAddress.bottom
        anchors.topMargin: 20
        font.pixelSize: 11
    }

    Text {
        id: customerName
        x: 365
        text: customer.lastname + " " + customer.firstname
        font.bold: true
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.top: cutesoftContact.bottom
        anchors.topMargin: 20
        font.pixelSize: 11
    }

    Text {
        id: customerAddress
        text: customer.address + "\n" + customer.zipcode + " " + customer.city
        anchors.topMargin: 5
        anchors.top: customerName.bottom
        anchors.left: customerName.left
        anchors.leftMargin: 0
        font.pixelSize: 11
    }

    Text {
        id: customerVAT
        text: customer.comment
        anchors.topMargin: 5
        anchors.top: customerAddress.bottom
        anchors.left: customerAddress.left
        anchors.leftMargin: 0
        font.pixelSize: 11
    }

    Text {
        id: invoiceDate
        text: "Ans, le " + Qt.formatDate(invoice.date, "dd MMMM yyyy") + "."
        anchors.topMargin: 20
        anchors.top: customerVAT.bottom
        anchors.left: customerVAT.left
        anchors.leftMargin: 0
        font.pixelSize: 11
    }

    Text {
        id: invoiceTitle
        text: "Objet : Facture n°" + invoice.code + " - " + invoice.description
        anchors.left: root.left
        anchors.leftMargin: 50
        anchors.top: invoiceDate.bottom
        anchors.topMargin: 30
        font.bold: true
        font.pixelSize: 11
    }

    Text {
        id: invoiceDescription
        text: qsTr("Projet RW QIR-2 n°6662 : Qualité Image en Radiologie.")
        anchors.left: root.left
        anchors.leftMargin: 50
        anchors.top: invoiceTitle.bottom
        anchors.topMargin: 10
        font.pixelSize: 10
    }

    InvoiceArray {
        id: invoiceArray
        invoiceItemsModel: invoice.products
        invoiceTotal: invoice.total
        invoiceTotalVAT: invoice.totalTaxed
        invoiceVAT: invoice.totalTaxed - invoice.total

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: 50
        anchors.rightMargin: 50
        anchors.top: invoiceDescription.bottom
        anchors.topMargin: 30
    }

    Text {
        id: paiementTerms
        width: 300
        text: qsTr("Paiement 15 jours après réception\nA payer sur le compte ") + company.iban
        scale: 1
        verticalAlignment: Text.AlignTop
        horizontalAlignment: Text.AlignHCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 10
    }
}
