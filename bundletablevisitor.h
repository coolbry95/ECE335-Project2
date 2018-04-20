#ifndef BUNDLETABLEVISITOR_H
#define BUNDLETABLEVISITOR_H

#include <qtablewidget.h>
#include "PetDatabase.h"

class BundleTableVisitor {
protected:
    QTableWidget* table;

    VisitBundle(Bundle* bundle){
        table->setColumnCount(table->columnCount() + 1);

        QTableWidgetItem name_item(bundle->getName());
        table->setItem(0, table->columnCount() - 1, name_item);

        QTableWidgetItem price_item(QString::number(bundle->getPrice()));
        table->setItem(1, table->columnCount() - 1, price);

        QTableWidgetItem savings_item(QString::number(bundle->getSavings()) + "%");
        table->setItem(3, table->columnCount() - 1, savings_item);
    }


    VisitDog(Dog* dog){

    }

    VisitCat(Cat* cat){

    }

    VisitBird(Bird* bird){

    }

    VisitFish(Fish* fish){

    }

public:
    BundleTableVisitor(QTableWidget* in_table){
        table = in_table;
    }

    fillTable(PetDatabase* database){

    }
};

#endif // BUNDLETABLEVISITOR_H
