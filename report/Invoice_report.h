#ifndef INVOICE_REPORT_H
#define INVOICE_REPORT_H

#include <QObject>
#include <QDate>

namespace Report {

class Invoice : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QDate date READ date WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(QString code READ code WRITE setCode NOTIFY codeChanged)
    Q_PROPERTY(QList<QObject* > products READ products WRITE setProducts NOTIFY productsChanged)
    Q_PROPERTY(double total READ total WRITE setTotal NOTIFY totalChanged)
    Q_PROPERTY(double totalTaxed READ totalTaxed WRITE setTotalTaxed NOTIFY totalTaxedChanged)

public:
    explicit Invoice(int id, QObject *parent = 0);
    void setId(int id);
    int customerId() const;
    
    QString description() const { return m_description; }
    QDate date() const { return m_date; }
    QString code() const { return m_code; }
    QList<QObject* > products() const { return m_products; }
    double total() const { return m_total; }
    double totalTaxed() const { return m_totalTaxed; }

signals:
    void descriptionChanged(QString arg);
    void dateChanged(QDate arg);
    void codeChanged(QString arg);
    void productsChanged(QList<QObject* > arg);
    void totalChanged(double arg);
    void totalTaxedChanged(double arg);

public slots:
    void setDescription(QString arg);
    void setDate(QDate arg);
    void setCode(QString arg);
    void setProducts(QList<QObject* > arg);
    void setTotal(double arg);
    void setTotalTaxed(double arg);

private:
    int m_customerId;
    QString m_description;
    QDate m_date;
    QString m_code;
    QList<QObject* > m_products;
    double m_total;
    double m_totalTaxed;
};

}

#endif // INVOICE_REPORT_H
