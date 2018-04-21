#include "shoppingcart.h"
#include "ui_shoppingcart.h"

ShoppingCart::ShoppingCart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShoppingCart)
{
    ui->setupUi(this);
}

ShoppingCart::~ShoppingCart()
{
    delete ui;
}

void ShoppingCart::on_checkoutButton_clicked()
{
    emit Checkout();
}

void ShoppingCart::on_deleteButton_clicked()
{
    emit Delete();
}
