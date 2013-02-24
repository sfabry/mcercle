#include "Invoice_report.h"
#include "Product_report.h"

#include <QSqlQuery>
#include <QVariant>

using namespace Report;

Invoice::Invoice(int id, QObject *parent) :
    QObject(parent),
    m_customerId(-1),
    m_total(0.0),
    m_totalTaxed(0.0)
{
    setId(id);
}

void Invoice::setId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT id_customer, date, code, description FROM tab_invoices WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();

    if (query.next()) {
        m_customerId = query.value(0).toInt();
        setDate(QDate::fromString(query.value(1).toString(), "yyyy-MM-dd"));
        setCode(query.value(2).toString());
        setDescription(query.value(3).toString());
    }

    // Look for all products of this invoice
    query.prepare("SELECT id FROM tab_invoices_details WHERE id_invoice = :id");
    query.bindValue(":id", id);
    query.exec();
    QList<QObject* > products;
    double total = 0.0;
    double totalTaxed = 0.0;
    while (query.next()) {
        Product* product = new Product(query.value(0).toInt(), this);
        products.append(product);
        total += product->price() * product->quantity();
        totalTaxed += product->priceTaxed() * product->quantity();
    }
    setProducts(products);
    setTotal(total);
    setTotalTaxed(totalTaxed);
}

int Invoice::customerId() const
{
    return m_customerId;
}


void Invoice::setDescription(QString arg)
{
    if (m_description != arg) {
        m_description = arg;
        emit descriptionChanged(arg);
    }
}

void Invoice::setDate(QDate arg)
{
    if (m_date != arg) {
        m_date = arg;
        emit dateChanged(arg);
    }
}

void Invoice::setCode(QString arg)
{
    if (m_code != arg) {
        m_code = arg;
        emit codeChanged(arg);
    }
}

void Invoice::setProducts(QList<QObject *> arg)
{
    if (m_products != arg) {
        qDeleteAll(m_products);
        m_products = arg;
        emit productsChanged(arg);
    }
}

void Invoice::setTotal(double arg)
{
    if (m_total != arg) {
        m_total = arg;
        emit totalChanged(arg);
    }
}

void Invoice::setTotalTaxed(double arg)
{
    if (m_totalTaxed != arg) {
        m_totalTaxed = arg;
        emit totalTaxedChanged(arg);
    }
}
