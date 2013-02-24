#ifndef PREVIEWDIALOG_H
#define PREVIEWDIALOG_H

#include <QDialog>
#include "ReportData.h"
class QDeclarativeView;

class PreviewDialog : public QDialog
{
    Q_OBJECT
public:
    explicit PreviewDialog(int invoiceId, QWidget *parent = 0);
    
signals:
    
private slots:
    void printClicked();
    void setQmlFile(QString file);

private:
    int m_invoiceId;
    Report::ReportData* m_data;
    QDeclarativeView* m_view;
};

#endif // PREVIEWDIALOG_H
