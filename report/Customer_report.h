#ifndef CUSTOMER_REPORT_H
#define CUSTOMER_REPORT_H

#include <QObject>

namespace Report {

class Customer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString lastname READ lastname WRITE setLastname NOTIFY lastnameChanged)
    Q_PROPERTY(QString firstname READ firstname WRITE setFirstname NOTIFY firstnameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(bool company READ company WRITE setCompany NOTIFY companyChanged)
    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(int zipcode READ zipcode WRITE setZipcode NOTIFY zipcodeChanged)
    Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged)
    Q_PROPERTY(QString country READ country WRITE setCountry NOTIFY countryChanged)
    Q_PROPERTY(QString phone READ phone WRITE setPhone NOTIFY phoneChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString comment READ comment WRITE setComment NOTIFY commentChanged)

public:
    explicit Customer(int id, QObject *parent = 0);
    void setId(int id);
    
    QString lastname() const { return m_lastname; }
    QString firstname() const { return m_firstname; }
    QString description() const { return m_description; }
    bool company() const { return m_company; }
    QString address() const { return m_address; }
    int zipcode() const { return m_zipcode; }
    QString city() const { return m_city; }
    QString country() const { return m_country; }
    QString phone() const { return m_phone; }
    QString email() const { return m_email; }
    QString comment() const { return m_comment; }

signals:
    void lastnameChanged(QString arg);
    void firstnameChanged(QString arg);
    void descriptionChanged(QString arg);
    void companyChanged(bool arg);
    void addressChanged(QString arg);
    void zipcodeChanged(int arg);
    void cityChanged(QString arg);
    void countryChanged(QString arg);
    void phoneChanged(QString arg);
    void emailChanged(QString arg);
    void commentChanged(QString arg);

public slots:
    void setLastname(QString arg);
    void setFirstname(QString arg);
    void setDescription(QString arg);
    void setCompany(bool arg);
    void setAddress(QString arg);
    void setZipcode(int arg);
    void setCity(QString arg);
    void setCountry(QString arg);
    void setPhone(QString arg);
    void setEmail(QString arg);
    void setComment(QString arg);

private:
    QString m_lastname;
    QString m_firstname;
    QString m_description;
    bool m_company;
    QString m_address;
    int m_zipcode;
    QString m_city;
    QString m_country;
    QString m_phone;
    QString m_email;
    QString m_comment;

};

}

#endif // CUSTOMER_H
