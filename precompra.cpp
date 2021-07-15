#include "precompra.h"
#include "ui_precompra.h"

#include <QDebug>

Precompra::Precompra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Precompra)
{
    ui->setupUi(this);

}

Precompra::~Precompra()
{
    delete ui;
}

QString Precompra::usuario() const
{
    return m_usuario;
}

void Precompra::setUsuario(const QString &usuario)
{
    m_usuario = usuario;
}

void Precompra::setCliente(QString Cliente)
{
    ui->outDtaoUsuario->setPlainText(Cliente);  //seteamos en el dato de usuario
}

void Precompra::setProductosCliente(QString informacion)
{
    ui->outLista->setPlainText(informacion);
}

void Precompra::setSubtotal(QString subtotal)
{
    ui->outSubtotal->setText(subtotal);
}

void Precompra::setIva(QString iva)
{
    ui->outIva->setText(iva);
}

void Precompra::setTotal(QString total)
{
    ui->outTotal->setText(total);
}




