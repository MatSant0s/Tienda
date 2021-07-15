#include "producto.h"


int Producto::codigo() const
{
    return m_codigo;
}

void Producto::setCodigo(int codigo)
{
    m_codigo = codigo;
}

QString Producto::nombre() const
{
    return m_nombre;
}

void Producto::setNombre(const QString &nombre)
{
    m_nombre = nombre;
}

int Producto::cantidad() const
{
    return m_cantidad;
}

void Producto::setCantidad(int cantidad)
{
    m_cantidad = cantidad;
}

float Producto::precio() const
{
    return m_precio;
}

void Producto::setPrecio(float precio)
{
    m_precio = precio;
}

Producto::Producto(QObject *parent) : QObject(parent)
{
    m_codigo = 0;
    m_nombre = "";
    m_cantidad = 0;
    m_precio = 0;
}

Producto::Producto(int codigo, QString nombre, int cantidad, float precio)
{
    m_codigo = codigo;
    m_nombre = nombre;
    m_cantidad = cantidad;
    m_precio = precio;
}




