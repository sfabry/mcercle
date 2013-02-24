#include "Customer_report.h"

#include <QSqlQuery>
#include <QVariant>

using namespace Report;

Customer::Customer(int id, QObject *parent) :
    QObject(parent),
    m_company(false),
    m_zipcode(0)
{
    setId(id);
}

void Customer::setId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT type, desc_compagny, lastname, firstname, address1, zipcode, city, country, phonenumber, email, comments FROM tab_customers WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();

    if (query.next()) {
        setCompany(query.value(0).toInt() == 1);
        setDescription(query.value(1).toString());
        setLastname(query.value(2).toString());
        setFirstname(query.value(3).toString());
        setAddress(query.value(4).toString());
        setZipcode(query.value(5).toInt());
        setCity(query.value(6).toString());
        setCountry(query.value(7).toString());
        setPhone(query.value(8).toString());
        setEmail(query.value(9).toString());
        setComment(query.value(10).toString());
    }
    else {
        setFirstname("Error, customer not found");
    }
}

void Customer::setLastname(QString arg)
{
    if (m_lastname != arg) {
        m_lastname = arg;
        emit lastnameChanged(arg);
    }
}

void Customer::setFirstname(QString arg)
{
    if (m_firstname != arg) {
        m_firstname = arg;
        emit firstnameChanged(arg);
    }
}

void Customer::setDescription(QString arg)
{
    if (m_description != arg) {
        m_description = arg;
        emit descriptionChanged(arg);
    }
}

void Customer::setCompany(bool arg)
{
    if (m_company != arg) {
        m_company = arg;
        emit companyChanged(arg);
    }
}

void Customer::setAddress(QString arg)
{
    if (m_address != arg) {
        m_address = arg;
        emit addressChanged(arg);
    }
}

void Customer::setZipcode(int arg)
{
    if (m_zipcode != arg) {
        m_zipcode = arg;
        emit zipcodeChanged(arg);
    }
}

void Customer::setCity(QString arg)
{
    if (m_city != arg) {
        m_city = arg;
        emit cityChanged(arg);
    }
}

void Customer::setCountry(QString arg)
{
    if (m_country != arg) {
        m_country = arg;
        emit countryChanged(arg);
    }
}

void Customer::setPhone(QString arg)
{
    if (m_phone != arg) {
        m_phone = arg;
        emit phoneChanged(arg);
    }
}

void Customer::setEmail(QString arg)
{
    if (m_email != arg) {
        m_email = arg;
        emit emailChanged(arg);
    }
}

void Customer::setComment(QString arg)
{
    if (m_comment != arg) {
        m_comment = arg;
        emit commentChanged(arg);
    }
}
