#ifndef BUNDLETABLEVISITOR_H
#define BUNDLETABLEVISITOR_H

#include <qtablewidget.h>
#include "PetDatabase.h"
#include "bundle.h"

class BundleTableVisitor : public Visitor {
protected:
    QTableWidget* table;

    void addRow(string name, double price, double savings){
        table->setRowCount(table->rowCount() + 1);

        QTableWidgetItem* name_item = new QTableWidgetItem(QString::fromStdString(name));
        table->setItem(table->rowCount() - 1, 0, name_item);

        QTableWidgetItem* price_item = new QTableWidgetItem(QString::number(price));
        table->setItem(table->rowCount() - 1, 1, price_item);

        QTableWidgetItem* savings_item = new QTableWidgetItem(QString::number(savings) + "%");
        table->setItem(table->rowCount() - 1, 2, savings_item);
    }

    void VisitBundle(Bundle* bundle){
        addRow(bundle->getName(), bundle->getPrice(), bundle->getSavings());
    }


    void VisitDog(Dog* dog){

    }

    void VisitCat(Cat* cat){

    }

    void VisitBird(Bird* bird){

    }

    void VisitFish(Fish* fish){

    }

public:
    BundleTableVisitor(){
    }

    void setTable(QTableWidget* table_in){
        table = table_in;
        table->setColumnCount(3);
    }

    void fillTable(vector<Bundle> bundles){
        for(uint i = 0; i < bundles.size(); i++){
            bundles[i].Accept(this);
        }
    }
};

#endif // BUNDLETABLEVISITOR_H
