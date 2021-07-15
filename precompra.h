#ifndef PRECOMPRA_H
#define PRECOMPRA_H

#include <QDialog>


namespace Ui {
class Precompra;
}

class Precompra : public QDialog
{
    Q_OBJECT
public:
    explicit Precompra(QWidget *parent = nullptr);
    ~Precompra();

    void datCliente(QString datosCliente);

    QString usuario() const;
    void setUsuario(const QString &usuario);

    //Metodos para tener poder mandar al ui de precompra

    void setCliente(QString Cliente);
    void setProductosCliente(QString informacion);
    void setSubtotal(QString subtotal);
    void setIva(QString iva);
    void setTotal(QString total);

private slots:

private:
    Ui::Precompra *ui;

    QString m_usuario;


};

#endif // PRECOMPRA_H
