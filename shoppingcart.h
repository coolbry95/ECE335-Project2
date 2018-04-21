#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>


namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent = 0);
    Ui::ShoppingCart* getUi() const {return ui;}
    ~ShoppingCart();

signals:
    void Delete();
    void Checkout();
    void Close();

private slots:
    void on_deleteButton_clicked();
    void on_checkoutButton_clicked();

private:
    Ui::ShoppingCart *ui;
};

#endif // SHOPPINGCART_H
