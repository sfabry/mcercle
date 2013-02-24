#include "PreviewDialog.h"

#include <QtGui>
#include <QtDeclarative>

PreviewDialog::PreviewDialog(int invoiceId, QWidget *parent) :
    QDialog(parent)
{
    m_data = new Report::ReportData(invoiceId, this);

    // List qml file available in QML dir
    QDir qmlDir("qml", "*.qml");
    QStringList qmlFiles = qmlDir.entryList();

    QVBoxLayout* vbox = new QVBoxLayout();
    QHBoxLayout* hbox = new QHBoxLayout();
    QPushButton* button = new QPushButton(tr("Print"), this);
    connect(button, SIGNAL(clicked()), this, SLOT(printClicked()));
    hbox->addWidget(button);
    QComboBox* qmlCombo = new QComboBox(this);
    foreach (QString qmlFile, qmlFiles) {
        if (qmlFile.isEmpty()) continue;
        if (qmlFile.at(0).isUpper()) continue;      // avoid components
        qmlCombo->addItem(qmlFile);
    }
    connect(qmlCombo, SIGNAL(currentIndexChanged(QString)), this, SLOT(setQmlFile(QString)));
    hbox->addWidget(qmlCombo);
    hbox->addStretch();
    vbox->addLayout(hbox);
    QScrollArea* scrollArea = new QScrollArea(this);
    vbox->addWidget(scrollArea);
    this->setLayout(vbox);

    m_view = new QDeclarativeView(this);
    m_view->engine()->rootContext()->setContextObject(m_data);
    m_view->setResizeMode(QDeclarativeView::SizeViewToRootObject);
    scrollArea->setWidget(m_view);
    m_view->show();

    setQmlFile(qmlCombo->currentText());
    this->resize(600, 800);
}

void PreviewDialog::printClicked()
{
    QDeclarativeView* view = new QDeclarativeView(this);
    view->engine()->rootContext()->setContextObject(m_data);
    view->setResizeMode(QDeclarativeView::SizeViewToRootObject);
    view->setSource(QUrl::fromLocalFile("qml/cutesoft.qml"));

    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Portrait);
    QPrintDialog *printDialog = new QPrintDialog(&printer, this);
    printDialog->setWindowTitle(tr("Print Document"));
    if (printDialog->exec() != QDialog::Accepted) return;

    QPainter painter;
    painter.begin(&printer);
    view->render(&painter, QRectF(), QRect(0, 0, 496, 702), Qt::KeepAspectRatio);
    painter.end();
}

void PreviewDialog::setQmlFile(QString file)
{
    m_view->setSource(QUrl::fromLocalFile("qml/" + file));
}
