#include "principal.h"
#include "ui_principal.h"
#include "ui_principal.h"
#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    //LISTA DE PRODUCTOS
    m_productos.append(new Producto(1, "Leche", 10, 0.85));
    m_productos.append(new Producto(1, "Pan", 10, 0.15));
    m_productos.append(new Producto(1, "Queso", 10, 2.00));

    //MOSTRAR LA LISTA EN VENTANA
    for (int i=0;i<m_productos.size() ;++i ) {
        ui->inProducto->addItem(m_productos.at(i)->nombre());
    }
    //colocar cabezera de la tabla

    QStringList cabecera = {"Cantidad", "Producto", "Subtotal"};
    ui->outDetalle->setColumnCount(3);
    ui->outDetalle->setHorizontalHeaderLabels(cabecera);

    //incializar subtotal global
    m_subtotal = 0;
}

////*//*/**/
void Principal::mostrar()
{
    QString nombre = ui->inNombre->text();
    QString cedula = ui->inCedula->text();

}

//Obtenemos los datos del usuario

Principal::~Principal()
{
    delete ui;
}

void Principal::on_cmdAgregar_released()
{
    //OBTENER DATOS DE GUI

    int cantidad = ui->inCantidad->value();
    //validamos que mientras sea cero productos no hace nada
    if(cantidad==0){
        return;
    }
    int index = ui->inProducto->currentIndex(); //saber el producto seleccionado actual

    Producto *p = m_productos.at(index);

    //cantidad

    //int cantidad = ui->inCantidad->value();

    //Calcular el subtotal del producto

    float subtotal = cantidad * p->precio();

    //Agregar datos a la tabla de muestra

    int fila = ui->outDetalle->rowCount(); //me dice el numero de filas
    ui->outDetalle->insertRow(fila); //Insertar una fila en el numero de posicion
    ui->outDetalle->setItem(fila, 0, new QTableWidgetItem(QString::number(cantidad))); //insertar un item en la posicion y en la columna 0
    ui->outDetalle->setItem(fila, 1, new QTableWidgetItem(p->nombre()));
    ui->outDetalle->setItem(fila, 2, new QTableWidgetItem(QString::number(subtotal, 'f', 2)));

    //damos valores a infromacion de productos

    informacion = informacion +"\nCantidad : "+QString::number(cantidad)+
            "\nProductos: "+p->nombre();

    //limpiar datos
    ui->inCantidad->setValue(0);
    ui->inProducto->setFocus();

    //Invocamos a calcular

    Calcular(subtotal);

}

void Principal::on_inProducto_currentIndexChanged(int index)
{
    qDebug () <<index;
    //obtener precio producto
    float precio = m_productos.at(index)->precio();
    //mostrar precio
    ui->outPrecio->setText("S "+ QString::number(precio, 'f',2));


}

//limpiamos los datos ya antes registrados

void Principal::borrarData()
{
    //Borramos el contendo del ui, es decir lo seteamos

    this->ui->inNombre->setText("\0");
    this->ui->inCedula->setText("\0");
    this->ui->inTelefono->setText("\0");
    this->ui->inDireccion->setText("\0");
    this->ui->inEmail->setText("\0");


    //borramos la informacion del detalle, de la ventana principal

    ui->outDetalle->setRowCount(0);

    //seteamos variables globales y redondeamos a 2 decimale s

    this->m_subtotal=0;
    this->m_iva=0;
    this->m_total=0;

    //seteamos lo que mostramos enpantalla, los objetos del ui

    ui->outSubtotal->setText("$ " + QString::number(m_subtotal, 'f', 2));
    ui->outIva->setText("$ " + QString::number(0.0, 'f', 2));
    ui->outTotal->setText("$ " + QString::number(0.0, 'f', 2));

}



void Principal::Calcular(float stlProducto)
{

   m_subtotal +=stlProducto;
   float iva = m_subtotal* IVA/100;
   float total = m_subtotal + iva;

   //damos valores a variables globales

   m_iva = iva;
   m_total = total;



   ui->outSubtotal->setText(QString::number(m_subtotal, 'f', 2));
   ui->outIva->setText(QString::number(iva, 'f', 2));
   ui->outTotal->setText(QString::number(total, 'f', 2));
}

void Principal::validar()
{
    //Mandamos los datos del cliente

    QString cedula = ui->inCedula->text(); //Obtenemos el valor de la cedula digitada por el ususario
    QString nombre = ui->inNombre->text();
    QString direccion = ui->inDireccion->toPlainText();
    QString telefono = ui->inTelefono->text();
    QString email = ui->inEmail->text();

    //evaluamos si el nombre del cliente esta lleno

    if((nombre.isEmpty()) && (cedula.isEmpty())){
        QMessageBox :: warning(this, "Error de registro", "Recuerda llenar con informacion veridica y correcta");
    return;
    }else{

        //mandamos datos

        ClienteF *cliente = new ClienteF (cedula,nombre,telefono, direccion, email);
        Precompra *compra = new Precompra();

        compra->setCliente(cliente->mostrar());
        compra->setProductosCliente(informacion);
        compra->setSubtotal(" "+ QString::number(m_subtotal, 'f', 2));
        compra->setIva(" " + QString::number(m_iva, 'f', 2));
        compra->setTotal(" " + QString::number(m_total, 'f', 2));
        compra->show();
        borrarData();

    }

}


void Principal::on_cmdFactura_released()
{
    //validamo si el nombre y cedula estan llenos
     validar();
}
