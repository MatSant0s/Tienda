#include "clientef.h"

QString ClienteF::nombre() const
{
    return m_nombre;
}

void ClienteF::setNombre(const QString &nombre)
{
    m_nombre = nombre;
}

QString ClienteF::cedula() const
{
    return m_cedula;
}

void ClienteF::setCedula(const QString &cedula)
{
    m_cedula = cedula;
}

QString ClienteF::telefono() const
{
    return m_telefono;
}

void ClienteF::setTelefono(const QString &telefono)
{
    m_telefono = telefono;
}

QString ClienteF::direccion() const
{
    return m_direccion;
}

void ClienteF::setDireccion(const QString &direccion)
{
    m_direccion = direccion;
}

QString ClienteF::email() const
{
    return m_email;
}

void ClienteF::setEmail(const QString &email)
{
    m_email = email;
}

QString ClienteF::mostrar()
{
    return "Cedula: " + m_cedula +
           "\nNombre: " + m_nombre +
           "\nTelefono: " + m_telefono +
           "\nE-mail: " + m_email +
           "\nDirección: " + m_direccion;
}

ClienteF::ClienteF(QObject *parent) : QObject(parent)
{

}

ClienteF::ClienteF(QString nombre, QString cedula, QString telefono, QString direccion, QString email)
{
     this->m_nombre=nombre;
     this->m_cedula=cedula;
     this->m_telefono=telefono;
     this->m_direccion=direccion;
     this->m_email=email;

}
