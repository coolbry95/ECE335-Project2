#include "mainwindow.h"
#include "ui_mainwindow.h"

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
        SCWindow = new ShoppingCart(this);
        SCWindow->show();
        connect(SCWindow, SIGNAL(Delete()), this, SLOT(DeleteRecord()));
        connect(SCWindow, SIGNAL(Checkout()), this, SLOT(CheckoutCart()));
    }
    ui->showCartButton->setEnabled(false);
}


void MainWindow::DeleteRecord() {

}

void MainWindow::CheckoutCart() {
    // call add pets here
    // filled in from
    // SCWindow->ui->deleteButton->setEnabled(false);
    builder.writeOutfile("checout.csv");
}

void MainWindow::loadDatabase(){
    ui->loadDatabaseButton->setEnabled(false);
    reader.setBuilder(&builder);
    reader.read("Pets.csv", "Bundles.csv");
    pets = PetDatabaseSortableByName(builder.getPetDatabase());
    cout << " Made it here" << endl;

    bundles = builder.getBundleDatabase();

    pet_visitor.fillTable(&pets);
    bundle_visitor.fillTable(bundles);
    ui->loadDatabaseButton->setEnabled(false);
}
