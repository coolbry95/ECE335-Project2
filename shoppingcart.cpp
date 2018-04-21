#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include "subject.h"

#include <iostream>
using std::endl;
using std::cout;

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

void ShoppingCart::update(Subject* s){
    shopping_cart = SortableItemVector(s->getShoppingCart());
}

void ShoppingCart::closeEvent(QCloseEvent *event){
    cout << "Closed" << endl;
    emit observerDestroyed(this);
    Delete();
}

