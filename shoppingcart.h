#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QMainWindow>
#include "observer.h"
#include "sortableitemvector.h"
#include "carttablevisitor.h"


namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QMainWindow, public Observer
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event);
public:
    explicit ShoppingCart(QWidget *parent = 0);
    Ui::ShoppingCart* getUi() const {return ui;}
    ~ShoppingCart();
    void update(Subject* s);

signals:
    void Delete(Item*);
    void Checkout();
    void observerDestroyed(Observer*);

private slots:
    void on_deleteButton_clicked();
    void on_checkoutButton_clicked();

private:
    Ui::ShoppingCart *ui;
    SortableItemVector shopping_cart;
    CartTableVisitor cart_visitor;
};

#endif // SHOPPINGCART_H
