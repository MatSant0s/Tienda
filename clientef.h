#ifndef CLIENTEF_H
#define CLIENTEF_H

#include <QObject>

class ClienteF : public QObject
{
    Q_OBJECT

private:

    QString m_nombre;
    QString m_cedula;
    QString m_telefono;
    QString m_direccion;
    QString m_email;


public:

    explicit ClienteF(QObject *parent = nullptr);
    ClienteF (QString nombre,QString cedula,QString telefono,QString direccion,QString email);

    QString nombre() const;
    void setNombre(const QString &nombre);

    QString cedula() const;
    void setCedula(const QString &cedula);

    QString telefono() const;
    void setTelefono(const QString &telefono);

    QString direccion() const;
    void setDireccion(const QString &direccion);

    QString email() const;
    void setEmail(const QString &email);

    //metodo para mostrar informacion

    QString mostrar ();

signals:

};

#endif // CLIENTEF_H
