#ifndef COMPANY_H
#define COMPANY_H

#include <QObject>

namespace Report {

class Company : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool tax READ tax WRITE setTax NOTIFY taxChanged)
    Q_PROPERTY(QString siret READ siret WRITE setSiret NOTIFY siretChanged)
    Q_PROPERTY(QString iban READ iban WRITE setIban NOTIFY ibanChanged)
    Q_PROPERTY(QString bic READ bic WRITE setBic NOTIFY bicChanged)
    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(int zipcode READ zipcode WRITE setZipcode NOTIFY zipcodeChanged)
    Q_PROPERTY(QString city READ city WRITE setCity NOTIFY cityChanged)
    Q_PROPERTY(QString phone READ phone WRITE setPhone NOTIFY phoneChanged)
    Q_PROPERTY(QString fax READ fax WRITE setFax NOTIFY faxChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString website READ website WRITE setWebsite NOTIFY websiteChanged)

public:
    explicit Company(int id, QObject *parent = 0);
    QString name() const { return m_name; }
    bool tax() const { return m_tax; }
    QString iban() const { return m_num; }
    QString address() const { return m_address; }
    int zipcode() const { return m_zipcode; }
    QString phone() const { return m_phone; }
    QString fax() const { return m_fax; }
    QString email() const { return m_email; }
    QString website() const { return m_website; }
    QString city() const { return m_city; }
    QString bic() const { return m_bic; }
    QString siret() const { return m_siret; }

signals:
    void nameChanged(QString arg);
    void taxChanged(bool arg);
    void ibanChanged(QString arg);
    void addressChanged(QString arg);
    void zipcodeChanged(int arg);
    void phoneChanged(QString arg);
    void faxChanged(QString arg);
    void emailChanged(QString arg);
    void websiteChanged(QString arg);
    void cityChanged(QString arg);
    void bicChanged(QString arg);
    void siretChanged(QString arg);

public slots:
    void setName(QString arg);
    void setTax(bool arg);
    void setIban(QString arg);
    void setAddress(QString arg);
    void setZipcode(int arg);
    void setPhone(QString arg);
    void setFax(QString arg);
    void setEmail(QString arg);
    void setWebsite(QString arg);
    void setCity(QString arg);
    void setBic(QString arg);
    void setSiret(QString arg);

private:
    QString m_name;
    bool m_tax;
    QString m_num;
    QString m_address;
    int m_zipcode;
    QString m_phone;
    QString m_fax;
    QString m_email;
    QString m_website;
    QString m_city;
    QString m_bic;
    QString m_siret;
};

}

#endif // COMPANY_H
