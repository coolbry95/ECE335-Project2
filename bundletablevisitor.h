#ifndef BUNDLETABLEVISITOR_H
#define BUNDLETABLEVISITOR_H

#include <qtablewidget.h>
#include "PetDatabase.h"
#include "bundle.h"

class BundleTableVisitor : public Visitor {
protected:
    QTableWidget* table;

    void VisitBundle(Bundle* bundle){
        table->setColumnCount(table->columnCount() + 1);

        QTableWidgetItem name_item(QString::fromStdString(bundle->getName()));
        table->setItem(0, table->columnCount() - 1, &name_item);

        QTableWidgetItem price_item(QString::number(bundle->getPrice()));
        table->setItem(1, table->columnCount() - 1, &price_item);

        QTableWidgetItem savings_item(QString::number(bundle->getSavings()) + "%");
        table->setItem(3, table->columnCount() - 1, &savings_item);
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
    }

    void fillTable(vector<Bundle> bundles){
        for(uint i = 0; i < bundles.size(); i++){
            bundles[i].Accept(this);
        }
    }
};

#endif // BUNDLETABLEVISITOR_H
