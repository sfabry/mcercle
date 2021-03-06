# -------------------------------------------------
# mcercle - Logiciel de gestion libre
# -------------------------------------------------

# Test la version de Qt
#lessThan(QT_VERSION, 4.6) {
#    error("mcercle requires Qt 4.6 or greater")
#}

QT += sql declarative
TARGET = mcercle
TEMPLATE = app
CONFIG += ordered

# Add more folders to ship with the application, here
folder_01.source = report/qml
folder_01.target = .
DEPLOYMENTFOLDERS = folder_01
include(qtquick2applicationviewer.pri)
qtcAddDeployment()

# Fichiers sources
SOURCES += src/mainwindow.cpp \
    src/main.cpp \
    src/board.cpp \
    src/customerView.cpp \
    src/productView.cpp \
    src/about.cpp \
    src/dialogcustomer.cpp \
    src/customer.cpp \
    src/invoice.cpp \
    src/product.cpp \
    src/dialogproduct.cpp \
    src/provider.cpp \
    src/dialogproviders.cpp \
    src/dialogwaiting.cpp \
    src/settings.cpp \
    src/dialogsettings.cpp \
    src/dbase.cpp \
    src/dialogcategory.cpp \
    src/productcategory.cpp \
    src/services.cpp \
    src/dialogservices.cpp \
    src/dialogprovidersedit.cpp \
    src/dialogservicesedit.cpp \
    src/proposal.cpp \
    src/dialoginvoice.cpp \
    src/services_commons.cpp \
    src/dialogprintchoice.cpp \
    src/dialogtax.cpp \
    src/tax.cpp \
    src/dialoginvoicelist.cpp \
    report/Company.cpp \
    report/PreviewDialog.cpp \
    report/ReportData.cpp \
    report/Customer_report.cpp \
    report/Product_report.cpp \
    report/Invoice_report.cpp



HEADERS += src/mainwindow.h \
    src/board.h \
    src/customerView.h \
    src/productView.h \
    src/about.h \
    src/dialogcustomer.h \
    src/customer.h \
    src/invoice.h \
    src/product.h \
    src/dialogproduct.h \
    src/provider.h \
    src/dialogproviders.h \
    src/dialogwaiting.h \
    src/settings.h \
    src/dialogsettings.h \
    src/dbase.h \
    src/dialogcategory.h \
    src/productcategory.h \
    src/services.h \
    src/dialogservices.h \
    src/dialogprovidersedit.h \
    src/dialogservicesedit.h \ 
    src/proposal.h \
    src/dialoginvoice.h \
    src/services_commons.h \
    src/dialogprintchoice.h \
    src/dialogtax.h \
    src/tax.h \
    src/dialoginvoicelist.h \
    report/Company.h \
    report/PreviewDialog.h \
    report/ReportData.h \
    report/Customer_report.h \
    report/Product_report.h \
    report/Invoice_report.h



FORMS += src/mainwindow.ui \
    src/board.ui \
    src/customerView.ui \
    src/productView.ui \
    src/about.ui \
    src/dialogcustomer.ui \
    src/dialogproduct.ui \
    src/dialogproviders.ui \
    src/dialogwaiting.ui \
    src/dialogsettings.ui \
    src/dialogcategory.ui \
    src/dialogservices.ui \
    src/dialogprovidersedit.ui \
    src/dialogservicesedit.ui \
    src/dialoginvoice.ui \
    src/dialogprintchoice.ui \
    src/dialogtax.ui \
    src/dialoginvoicelist.ui

# Liste des fichiers qui seront incorpores au binaire en tant que ressources
RESOURCES += ressources.qrc

# Description de l'installation
target.path = /usr/bin/

copyright.path     = /usr/share/doc/mcercle/
copyright.files    = License Changelog

desktop.path       = /usr/share/applications/
desktop.files      = art/mcercle.desktop art/logo/mcercle-logo-64.png

# Icon
win32 {
    ICON = art/logo/mcercle.ico
}
macx {
    ICON = art/logo/mcercle.icns
}

# L installation comprend la copie du binaire, du fichier LICENSE
INSTALLS += target desktop copyright 

OTHER_FILES += \
    Todo.txt \
    Changelog.txt \
    report/qml/cutesoft.qml
