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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadDatabase(){
    cout << "Loading" << endl;
    reader.setBuilder(&builder);
    reader.read("Pets.csv", "Bundles.csv");
    PetDatabase pet_database = builder.getPetDatabase();
    builder.getPetDatabase().DisplayRecords();
    cout << " Made it here" << endl;

    bundles = builder.getBundleDatabase();

    pets.DisplayRecords();
    cout << "Loaded" << endl;
}
