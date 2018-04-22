#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "PetDatabaseSortableByName.h"
#include "bundle.h"
#include "csvreader.h"
#include "databasebuilder.h"
#include "bundletablevisitor.h"
#include "pettablevisitor.h"
#include "BubbleSortIncreasing.h"
#include "shoppingcart.h"
#include "subject.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Subject
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ItemVector* getShoppingCart(){
        return &shopping_cart;
    }


public slots:
    void loadDatabase();
    void openShoppingCartWindow();
    void CheckoutCart();
    void DeleteRecord(Item*);
    void observerDeleted(Observer*);
    void on_addToCart();
    void petSelectionChanged(QItemSelection, QItemSelection);
    void bundleSelectionChanged(QItemSelection, QItemSelection);


private:
    Ui::MainWindow *ui;
    ShoppingCart* SCWindow;
    PetDatabaseSearchableByName pets;
    vector<Bundle> bundles;
    CSVReader reader;
    DatabaseBuilder builder;
    BundleTableVisitor bundle_visitor;
    PetTableVisitor pet_visitor;
    ItemVector shopping_cart;

};

#endif // MAINWINDOW_H
