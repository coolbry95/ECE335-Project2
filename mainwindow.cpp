#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shoppingcart.h"
#include "ui_shoppingcart.h"

#include <iostream>
#include <algorithm>

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
    connect(ui->addToCartButton, SIGNAL(pressed()), this, SLOT(on_addToCart()));
    connect(ui->databaseTable->selectionModel(), SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(petSelectionChanged(QItemSelection, QItemSelection)));
    connect(ui->bundleTable->selectionModel(), SIGNAL(selectionChanged(QItemSelection, QItemSelection)), this, SLOT(bundleSelectionChanged(QItemSelection,QItemSelection)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openShoppingCartWindow() {
    ui->showCartButton->setEnabled(false);
    ShoppingCart* window = new ShoppingCart(this);
    window->show();
    attachObserver(window);
    connect(window, SIGNAL(observerDestroyed(Observer*)), this, SLOT(observerDeleted(Observer*)));
    connect(window, SIGNAL(Delete(Item*)), this, SLOT(DeleteRecord(Item*)));
    connect(window, SIGNAL(Checkout()), this, SLOT(CheckoutCart()));
    notifyObservers();
}

void MainWindow::observerDeleted(Observer* observer){
    detachObserver(observer);
    ui->showCartButton->setEnabled(true);
}


void MainWindow::DeleteRecord(Item* item) {
    shopping_cart.removeItem(item);
    notifyObservers();
}

void MainWindow::CheckoutCart() {
    builder.writeOutfile("checkout.csv");
    this->setEnabled(false);
}

void MainWindow::loadDatabase(){
    ui->loadDatabaseButton->setEnabled(false);
    reader.setBuilder(&builder);
    reader.read("Pets.csv", "Bundles.csv");
    PetDatabaseSortableByName sortable = PetDatabaseSortableByName(builder.getPetDatabase());
    BubbleSortIncreasing bsi;
    bsi.sort(&sortable);
    pets = PetDatabaseSearchableByName(&sortable);

    pet_visitor.fillTable(&pets);
    bundles = builder.getBundleDatabase();

    std::sort(bundles.begin(), bundles.end(), [](const Bundle& a, const Bundle&b){
        return a.getName() < b.getName();
    });

    bundle_visitor.fillTable(bundles);
    ui->loadDatabaseButton->setEnabled(false);
}

void MainWindow::on_addToCart(){
    QModelIndexList selectedPets = ui->databaseTable->selectionModel()->selectedRows();
    for(int i = 0; i < selectedPets.count(); i++){
        int row = selectedPets[i].row();
        shopping_cart.insertItem(pets.getPet(row));
    }
    QModelIndexList selectedBundles = ui->bundleTable->selectionModel()->selectedRows();
    for(int i = 0; i < selectedBundles.count(); i++){
        int row = selectedBundles[i].row();
        shopping_cart.insertItem(&(bundles[row]));
    }
    notifyObservers();
}

void MainWindow::petSelectionChanged(QItemSelection to, QItemSelection from){
    if(!to.empty()){
        ui->bundleTable->clearSelection();
    }
}

void MainWindow::bundleSelectionChanged(QItemSelection to, QItemSelection from){
    if(!to.empty()){
        ui->databaseTable->clearSelection();
    }
}
