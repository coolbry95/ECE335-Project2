#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include "subject.h"
#include "shoppingcartvisitor.h"

#include <iostream>
using std::endl;
using std::cout;

ShoppingCart::ShoppingCart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShoppingCart)
{
    ui->setupUi(this);
    cart_table_visitor.setTable(ui->tableWidget);

}

ShoppingCart::~ShoppingCart()
{
    delete ui;    
}

void ShoppingCart::on_checkoutButton_clicked()
{
    emit Checkout();
    BubbleSortIncreasing bsi;
    bsi.sort(&shopping_cart);
    cart_table_visitor.fillTable(&shopping_cart);
    ShoppingCartVisitor shopping_cart_visitor;
    this->ui->label->setText("Total Price: " + QString::number(shopping_cart_visitor.calculateTotalPrice(&shopping_cart)));
    this->setEnabled(false);
}

void ShoppingCart::on_deleteButton_clicked()
{
    QModelIndexList selectedPets = ui->tableWidget->selectionModel()->selectedRows();
    for(int i = 0; i < selectedPets.count(); i++){
        int row = selectedPets[i].row();
        emit Delete(shopping_cart.getItem(row));
    }
}

void ShoppingCart::update(Subject* s){
    shopping_cart = SortableItemVector(s->getShoppingCart());
    cart_table_visitor.fillTable(&shopping_cart);
}

void ShoppingCart::closeEvent(QCloseEvent *event){
    emit observerDestroyed(this);
}

