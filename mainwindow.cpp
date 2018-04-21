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
    ui->loadDatabaseButton->setEnabled(false);
    reader.setBuilder(&builder);
    reader.read("Pets.csv", "Bundles.csv");
    pets = PetDatabaseSortableByName(builder.getPetDatabase());
    cout << " Made it here" << endl;

    bundles = builder.getBundleDatabase();

    pet_visitor.fillTable(&pets);
    bundle_visitor.fillTable(bundles);
}
