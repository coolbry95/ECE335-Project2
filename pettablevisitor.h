#ifndef PETTABLEVISITOR_H
#define PETTABLEVISITOR_H

#include "PetDatabase.h"
#include "Dog.h"
#include "Cat.h"
#include "Fish.h"
#include "Bird.h"
#include "qtablewidget.h"

class PetTableVisitor {
protected:
    QTableWidget* table;

    VisitBundle(Bundle* bundle){

    }

    VisitDog(Dog* dog){
        table->setColumnCount(table->columnCount() + 1);

        QTableWidgetItem name_item(dog->GetName());
        table->setItem(0, table->columnCount() - 1, name_item);

        QTableWidgetItem class_item("Dog");
        table->setItem(1, table->columnCount() - 1, class_item);

        QTableWidgetItem price_item(dog->GetPrice());
        table->setItem(2, table->columnCount() - 1, price);

        QTableWidgetItem special_item(dog->GetType());
        table->setItem(3, table->columnCount() - 1, special_item);
    }

    VisitCat(Cat* cat){
        table->setColumnCount(table->columnCount() + 1);

        QTableWidgetItem name_item(cat->GetName());
        table->setItem(0, table->columnCount() - 1, name_item);

        QTableWidgetItem class_item("Cat");
        table->setItem(1, table->columnCount() - 1, class_item);

        QTableWidgetItem price_item(cat->GetPrice());
        table->setItem(2, table->columnCount() - 1, price);

        QString special_str = cat->GetFluffy() ? "Fluffy " : "";
        special_str += cat->GetType();
        QTableWidgetItem special_item(special_str);
        table->setItem(3, table->columnCount() - 1, special_item);
    }

    VisitBird(Bird* bird){
        table->setColumnCount(table->columnCount() + 1);

        QTableWidgetItem name_item(bird->GetName());
        table->setItem(0, table->columnCount() - 1, name_item);

        QTableWidgetItem class_item("Bird");
        table->setItem(1, table->columnCount() - 1, class_item);

        QTableWidgetItem price_item(bird->GetPrice());
        table->setItem(2, table->columnCount() - 1, price);

        QString special_str = bird->GetNocturnal() ? "Nocturnal " : "Diurnal ";
        special_str += bird->GetType();
        QTableWidgetItem special_item(special_str);
        table->setItem(3, table->columnCount() - 1, special_item);
    }

    VisitFish(Fish* fish){
        table->setColumnCount(table->columnCount() + 1);

        QTableWidgetItem name_item(fish->GetName());
        table->setItem(0, table->columnCount() - 1, name_item);

        QTableWidgetItem class_item("Bird");
        table->setItem(1, table->columnCount() - 1, class_item);

        QTableWidgetItem price_item(fish->GetPrice());
        table->setItem(2, table->columnCount() - 1, price);

        QString special_str = fish->GetWaterType();
        special_str += " " + fish->GetType();
        QTableWidgetItem special_item(special_str);
        table->setItem(3, table->columnCount() - 1, special_item);
    }

public:
    PetTableVisitor(QTableWidget* in_table){
        table = in_table;
    }

    fillTable(PetDatabase* database){
        table->clearContents();
        for(int i = 0; i < database->getSize(); i++){
            database->getPet(i)->Accept(this);
        }
    }
};
#endif // PETTABLEVISITOR_H
