#include "Product_report.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

using namespace Report;

Product::Product(int id, QObject *parent) :
    QObject(parent),
    m_price(0.0),
    m_tax(0.0),
    m_priceTaxed(0.0),
    m_quantity(0)
{
    connect(this, SIGNAL(priceChanged(double)), this, SLOT(updatePriceTaxed()));
    connect(this, SIGNAL(taxChanged(double)), this, SLOT(updatePriceTaxed()));

    setId(id);
}

void Product::setId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT tab_invoices_details.name, tab_products.code, tab_invoices_details.price, tab_invoices_details.quantity, tab_invoices_details.tax FROM tab_invoices_details "
                  "INNER JOIN tab_products ON tab_invoices_details.id_product = tab_products.id "
                  "WHERE tab_invoices_details.id = :id");
    query.bindValue(":id", id);
    query.exec();

    if (query.next()) {
        setName(query.value(0).toString());
        setCode(query.value(1).toString());
        setPrice(query.value(2).toDouble());
        setQuantity(query.value(3).toInt());
        setTax(query.value(4).toDouble());
    }
    else {
        setName(query.lastError().text());
    }
}

void Product::setName(QString arg)
{
    if (m_name != arg) {
        m_name = arg;
        emit nameChanged(arg);
    }
}

void Product::setCode(QString arg)
{
    if (m_code != arg) {
        m_code = arg;
        emit codeChanged(arg);
    }
}

void Product::setPrice(double arg)
{
    if (m_price != arg) {
        m_price = arg;
        emit priceChanged(arg);
    }
}

void Product::setTax(double arg)
{
    if (m_tax != arg) {
        m_tax = arg;
        emit taxChanged(arg);
    }
}

void Product::setQuantity(int arg)
{
    if (m_quantity != arg) {
        m_quantity = arg;
        emit quantityChanged(arg);
    }
}

void Product::setPriceTaxed(double arg)
{
    if (m_priceTaxed != arg) {
        m_priceTaxed = arg;
        emit priceTaxedChanged(arg);
    }
}

void Product::updatePriceTaxed()
{
    setPriceTaxed(price() * (1.0 + tax() / 100.0));
}
