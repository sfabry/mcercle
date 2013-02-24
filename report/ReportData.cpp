#include "ReportData.h"

#include "Company.h"
#include "Customer_report.h"
#include "Invoice_report.h"

using namespace Report;

ReportData::ReportData(int invoiceId, QObject *parent) :
    QObject(parent)
{
    setCompanyId(1);
    setInvoiceId(invoiceId);
}

void ReportData::setCompanyId(int id)
{
    setCompany(new Company(id, this));
}

void ReportData::setCustomerId(int id)
{
    setCustomer(new Customer(id, this));
}

void ReportData::setInvoiceId(int id)
{
    Invoice* invoice = new Invoice(id, this);
    setInvoice(invoice);
    setCustomerId(invoice->customerId());
}

void ReportData::setCompany(QObject *arg)
{
    if (m_company != arg) {
        m_company = arg;
        emit companyChanged(arg);
    }
}

void ReportData::setCustomer(QObject *arg)
{
    if (m_customer != arg) {
        m_customer = arg;
        emit customerChanged(arg);
    }
}

void ReportData::setInvoice(QObject *arg)
{
    if (m_invoice != arg) {
        m_invoice = arg;
        emit invoiceChanged(arg);
    }
}
