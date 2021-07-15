#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "producto.h"
#include "precompra.h"
#include "ui_precompra.h"
#include <QMessageBox>
#include "clientef.h"
#define IVA 12

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    void mostrar();
    ~Principal();

private slots:
    void on_cmdAgregar_released();

    void on_inProducto_currentIndexChanged(int index);

    void on_cmdFactura_released();


private:
    Ui::Principal *ui;
    QList <Producto*> m_productos;
    float m_subtotal;                      //Variables globales para el calculo de las facturas
    float m_iva;
    float m_total;
    void Calcular(float stlProducto);       //metodo para calcular el precio
    void validar ();                        //metodo de validacion de cedula y nombre
    void borrarData();                      // metodo para setar y borrar datos
    QString informacion;



};
#endif // PRINCIPAL_H
