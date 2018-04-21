#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shoppingcart.h"
#include "ui_shoppingcart.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    builder()
{
    ui->setupUi(this);
    pet_visitor.setTable(ui->databaseTable);
    bundle_visitor.setTable(ui->bundleTable);
    connect(ui->loadDatabaseButton, SIGNAL(pressed()), this, SLOT(loadDatabase()));
    connect(ui->showCartButton, SIGNAL(pressed()), this, SLOT(openShoppingCartWindow()));
}

MainWindow::~MainWindow()
{
    if (SCWindow) delete SCWindow;
    delete ui;
}

void MainWindow::openShoppingCartWindow() {
    if (!SCWindow) {
    ui->showCartButton->setEnabled(false);
    ShoppingCart* window = new ShoppingCart(this);
    window->show();
    attachObserver(window);
    connect(window, SIGNAL(observerDestroyed(Observer*)), this, SLOT(observerDeleted(Observer*)));
    connect(window, SIGNAL(Delete()), this, SLOT(DeleteRecord()));
    connect(window, SIGNAL(Checkout()), this, SLOT(CheckoutCart()));
}

void MainWindow::observerDeleted(Observer* observer){
    detachObserver(observer);
}


void MainWindow::DeleteRecord() {

}

void MainWindow::CheckoutCart() {
    // call add pets here
    // filled in from
    // SCWindow->ui->deleteButton->setEnabled(false);
    builder.writeOutfile("checout.csv");
    SCWindow->getUi()->checkoutButton->setEnabled(false);
}

void MainWindow::loadDatabase(){
    ui->loadDatabaseButton->setEnabled(false);
    reader.setBuilder(&builder);
    reader.read("Pets.csv", "Bundles.csv");
    pets = PetDatabaseSortableByName(builder.getPetDatabase());

    bundles = builder.getBundleDatabase();

    pet_visitor.fillTable(&pets);
    bundle_visitor.fillTable(bundles);
    ui->loadDatabaseButton->setEnabled(false);
}
