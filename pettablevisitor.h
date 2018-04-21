#ifndef PETTABLEVISITOR_H
#define PETTABLEVISITOR_H

#include "PetDatabase.h"
#include "Dog.h"
#include "Cat.h"
#include "Fish.h"
#include "Bird.h"
#include "qtablewidget.h"
#include "visitor.h"

class PetTableVisitor : public Visitor {
protected:
    QTableWidget* table;

    void VisitBundle(Bundle* bundle){

    }

    void VisitDog(Dog* dog){
        table->setColumnCount(table->columnCount() + 1);

        QTableWidgetItem name_item(QString::fromStdString(dog->getName()));
        table->setItem(0, table->columnCount() - 1, &name_item);

        QTableWidgetItem class_item("Dog");
        table->setItem(1, table->columnCount() - 1, &class_item);

        QTableWidgetItem price_item(dog->getPrice());
        table->setItem(2, table->columnCount() - 1, &price_item);

        QTableWidgetItem special_item(QString::fromStdString(dog->getType()));
        table->setItem(3, table->columnCount() - 1, &special_item);
    }

    void VisitCat(Cat* cat){
        table->setColumnCount(table->columnCount() + 1);

        QTableWidgetItem name_item(QString::fromStdString(cat->getName()));
        table->setItem(0, table->columnCount() - 1, &name_item);

        QTableWidgetItem class_item("Cat");
        table->setItem(1, table->columnCount() - 1, &class_item);

        QTableWidgetItem price_item(cat->getPrice());
        table->setItem(2, table->columnCount() - 1, &price_item);

        string special_str = cat->getFluffy() ? "Fluffy " : "";
        special_str += cat->getType();
        QTableWidgetItem special_item(QString::fromStdString(special_str));
        table->setItem(3, table->columnCount() - 1, &special_item);
    }

    void VisitBird(Bird* bird){
        table->setColumnCount(table->columnCount() + 1);

        QTableWidgetItem name_item(QString::fromStdString(bird->getName()));
        table->setItem(0, table->columnCount() - 1, &name_item);

        QTableWidgetItem class_item("Bird");
        table->setItem(1, table->columnCount() - 1, &class_item);

        QTableWidgetItem price_item(bird->getPrice());
        table->setItem(2, table->columnCount() - 1, &price_item);

        string special_str = bird->getNocturnal() ? "Nocturnal " : "Diurnal ";
        special_str += bird->getType();
        QTableWidgetItem special_item(QString::fromStdString(special_str));
        table->setItem(3, table->columnCount() - 1, &special_item);
    }

    void VisitFish(Fish* fish){
        table->setColumnCount(table->columnCount() + 1);

        QTableWidgetItem name_item(QString::fromStdString(fish->getName()));
        table->setItem(0, table->columnCount() - 1, &name_item);

        QTableWidgetItem class_item("Bird");
        table->setItem(1, table->columnCount() - 1, &class_item);

        QTableWidgetItem price_item(fish->getPrice());
        table->setItem(2, table->columnCount() - 1, &price_item);

        string special_str = fish->getWaterType();
        special_str += " " + fish->getType();
        QTableWidgetItem special_item(QString::fromStdString(special_str));
        table->setItem(3, table->columnCount() - 1, &special_item);
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
