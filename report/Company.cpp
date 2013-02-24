#include "Company.h"

#include <QSqlQuery>
#include <QVariant>
#include <QStringList>

using namespace Report;

Company::Company(int id, QObject *parent) :
    QObject(parent),
    m_tax(false),
    m_zipcode(0)
{
    QSqlQuery query;
    query.prepare("SELECT name, tax, num, address1, zipcode, city, phonenumber, faxnumber, email, website FROM tab_informations WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();

    if (query.next()) {
        setName(query.value(0).toString());
        setTax(query.value(1).toBool());
        setSiret(query.value(2).toString());
        setAddress(query.value(3).toString());
        setZipcode(query.value(4).toInt());
        setCity(query.value(5).toString());
        setPhone(query.value(6).toString());
        setFax(query.value(7).toString());
        setEmail(query.value(8).toString());
        setWebsite(query.value(9).toString());
    }
    else {
        setName("Error, company not found");
    }

    query.prepare("SELECT code_bic, iban_1, iban_2, iban_3, iban_4, iban_5, iban_6, iban_7, iban_8, iban_9 FROM tab_bank WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
    if (query.next()) {
        setBic(query.value(0).toString());
        QStringList ibans;
        for (int i = 1; i <= 9; i++) ibans.append(query.value(i).toString());
        setIban(ibans.join(" "));
    }
}

void Company::setName(QString arg)
{
    if (m_name != arg) {
        m_name = arg;
        emit nameChanged(arg);
    }
}

void Company::setTax(bool arg)
{
    if (m_tax != arg) {
        m_tax = arg;
        emit taxChanged(arg);
    }
}

void Company::setIban(QString arg)
{
    if (m_num != arg) {
        m_num = arg;
        emit ibanChanged(arg);
    }
}

void Company::setAddress(QString arg)
{
    if (m_address != arg) {
        m_address = arg;
        emit addressChanged(arg);
    }
}

void Company::setZipcode(int arg)
{
    if (m_zipcode != arg) {
        m_zipcode = arg;
        emit zipcodeChanged(arg);
    }
}

void Company::setPhone(QString arg)
{
    if (m_phone != arg) {
        m_phone = arg;
        emit phoneChanged(arg);
    }
}

void Company::setFax(QString arg)
{
    if (m_fax != arg) {
        m_fax = arg;
        emit faxChanged(arg);
    }
}

void Company::setEmail(QString arg)
{
    if (m_email != arg) {
        m_email = arg;
        emit emailChanged(arg);
    }
}

void Company::setWebsite(QString arg)
{
    if (m_website != arg) {
        m_website = arg;
        emit websiteChanged(arg);
    }
}

void Company::setCity(QString arg)
{
    if (m_city != arg) {
        m_city = arg;
        emit cityChanged(arg);
    }
}

void Company::setBic(QString arg)
{
    if (m_bic != arg) {
        m_bic = arg;
        emit bicChanged(arg);
    }
}

void Company::setSiret(QString arg)
{
    if (m_siret != arg) {
        m_siret = arg;
        emit siretChanged(arg);
    }
}
