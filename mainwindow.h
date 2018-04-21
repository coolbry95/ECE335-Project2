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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void loadDatabase();

private:
    Ui::MainWindow *ui;
    PetDatabaseSortableByName pets;
    vector<Bundle> bundles;
    CSVReader reader;
    DatabaseBuilder builder;
    BundleTableVisitor bundle_visitor;
    PetTableVisitor pet_visitor;

};

#endif // MAINWINDOW_H
