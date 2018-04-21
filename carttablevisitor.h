#ifndef CARTTABLEVISITOR_H
#define CARTTABLEVISITOR_H


#include <qtablewidget.h>
#include "PetDatabase.h"
#include "bundle.h"
#include "itemvector.h"
#include "Dog.h"
#include "Cat.h"
#include "Fish.h"
#include "Bird.h"

class CartTableVisitor : public Visitor {
protected:
    QTableWidget* table;
    unsigned int rows;

    void addRow(string name, double price){
        rows++;
        table->setRowCount(rows);

        QTableWidgetItem* name_item = new QTableWidgetItem(QString::fromStdString(name));
        table->setItem(rows - 1, 0, name_item);

        QTableWidgetItem* price_item = new QTableWidgetItem(QString::number(price));
        table->setItem(rows - 1, 1, price_item);
    }

    void VisitBundle(Bundle* bundle){
        addRow(bundle->getName(), bundle->getPrice());
    }


    void VisitDog(Dog* dog){
        addRow(dog->getName(), dog->getPrice());
    }

    void VisitCat(Cat* cat){
        addRow(cat->getName(), cat->getPrice());
    }

    void VisitBird(Bird* bird){
        addRow(bird->getName(), bird->getPrice());
    }

    void VisitFish(Fish* fish){
        addRow(fish->getName(), fish->getPrice());
    }

public:
    CartTableVisitor(){
    }

    void setTable(QTableWidget* table_in){
        table = table_in;
    }

    void fillTable(ItemVector* items){
        rows = 0;
        for(int i = 0; i < items->getSize(); i++){
            items->getItem(i)->Accept(this);
        }
    }
};

#endif // CARTTABLEVISITOR_H
