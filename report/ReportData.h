#ifndef REPORTDATA_H
#define REPORTDATA_H

#include <QObject>

namespace Report {

class ReportData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* company READ company WRITE setCompany NOTIFY companyChanged)
    Q_PROPERTY(QObject* customer READ customer WRITE setCustomer NOTIFY customerChanged)
    Q_PROPERTY(QObject* invoice READ invoice WRITE setInvoice NOTIFY invoiceChanged)

public:
    explicit ReportData(int invoiceId, QObject *parent = 0);
    QObject* company() const { return m_company; }
    QObject* customer() const { return m_customer; }
    QObject* invoice() const { return m_invoice; }

public:
    void setCompanyId(int id);
    void setCustomerId(int id);
    void setInvoiceId(int id);

signals:
    void companyChanged(QObject* arg);
    void customerChanged(QObject* arg);
    void invoiceChanged(QObject* arg);

public slots:
    void setCompany(QObject* arg);
    void setCustomer(QObject* arg);
    void setInvoice(QObject* arg);

private:
    QObject* m_company;
    QObject* m_customer;
    QObject* m_invoice;
};

}

#endif // REPORTDATA_H
