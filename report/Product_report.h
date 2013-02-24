#ifndef PRODUCT_REPORT_H
#define PRODUCT_REPORT_H

#include <QObject>

namespace Report {

class Product : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString code READ code WRITE setCode NOTIFY codeChanged)
    Q_PROPERTY(double price READ price WRITE setPrice NOTIFY priceChanged)
    Q_PROPERTY(double tax READ tax WRITE setTax NOTIFY taxChanged)
    Q_PROPERTY(double priceTaxed READ priceTaxed WRITE setPriceTaxed NOTIFY priceTaxedChanged)
    Q_PROPERTY(int quantity READ quantity WRITE setQuantity NOTIFY quantityChanged)

public:
    explicit Product(int id, QObject *parent = 0);      // Id in invoices_details table !
    void setId(int id);
    QString name() const { return m_name; }
    QString code() const { return m_code; }
    double price() const { return m_price; }
    double tax() const { return m_tax; }
    int quantity() const { return m_quantity; }
    double priceTaxed() const { return m_priceTaxed; }

signals:
    void nameChanged(QString arg);
    void codeChanged(QString arg);
    void priceChanged(double arg);
    void taxChanged(double arg);
    void quantityChanged(int arg);
    void priceTaxedChanged(double arg);

public slots:
    void setName(QString arg);
    void setCode(QString arg);
    void setPrice(double arg);
    void setTax(double arg);
    void setQuantity(int arg);
    void setPriceTaxed(double arg);

private slots:
    void updatePriceTaxed();

private:
    QString m_name;
    QString m_code;
    double m_price;
    double m_tax;
    int m_quantity;
    double m_priceTaxed;
};

}

#endif // PRODUCT_REPORT_H
