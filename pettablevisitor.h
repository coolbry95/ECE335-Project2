#ifndef PETTABLEVISITOR_H
#define PETTABLEVISITOR_H

#include "PetDatabase.h"
#include "Dog.h"
#include "Cat.h"
#include "Fish.h"
#include "Bird.h"
#include "qtablewidget.h"
#include "visitor.h"
#include <string>
using std::string;

class PetTableVisitor : public Visitor {
protected:
    QTableWidget* table;

    void addRow(string name, string clas, double price, string special){
        table->setRowCount(table->rowCount() + 1);

        QTableWidgetItem* name_item = new QTableWidgetItem(QString::fromStdString(name));
        table->setItem(table->rowCount() - 1, 0, name_item);

        QTableWidgetItem* class_item = new QTableWidgetItem(QString::fromStdString(clas));
        table->setItem(table->rowCount() - 1, 1, class_item);

        QTableWidgetItem* price_item = new QTableWidgetItem(QString::number(price));
        table->setItem(table->rowCount() - 1, 2, price_item);

        QTableWidgetItem* special_item  = new QTableWidgetItem(QString::fromStdString(special));
        table->setItem(table->rowCount() - 1, 3, special_item);
    }
    void VisitBundle(Bundle* bundle){

    }

    void VisitDog(Dog* dog){
        addRow(dog->getName(), "Dog", dog->getPrice(), dog->getType());
    }

    void VisitCat(Cat* cat){
        string special_str = cat->getFluffy() ? "Fluffy " : "";
        special_str += cat->getType();
        addRow(cat->getName(), "Cat", cat->getPrice(), special_str);
    }

    void VisitBird(Bird* bird){
        string special_str = bird->getNocturnal() ? "Nocturnal " : "Diurnal ";
        special_str += bird->getType();
        addRow(bird->getName(), "Bird", bird->getPrice(), special_str);
    }

    void VisitFish(Fish* fish){
        string special_str = fish->getWaterType();
        special_str += " " + fish->getType();
        addRow(fish->getName(), "Fish", fish->getPrice(), special_str);
    }

public:
    PetTableVisitor(){}

    void setTable(QTableWidget* in_table){
        table = in_table;
    }

    void fillTable(PetDatabase* database){
        table->clearContents();
        for(int i = 0; i < database->getSize(); i++){
            database->getPet(i)->Accept(this);
        }
    }
};
#endif // PETTABLEVISITOR_H
