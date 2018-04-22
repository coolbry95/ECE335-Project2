#ifndef ShoppingCartVisitor_H
#define ShoppingCartVisitor_H


#include <qtablewidget.h>
#include "PetDatabase.h"
#include "bundle.h"
#include "itemvector.h"
#include "Dog.h"
#include "Cat.h"
#include "Fish.h"
#include "Bird.h"

class ShoppingCartVisitor : public Visitor {
protected:
    double total_price;

    void VisitBundle(Bundle* bundle){
        total_price += bundle->getPrice();
    }


    void VisitDog(Dog* dog){
        total_price += dog->getPrice();
    }

    void VisitCat(Cat* cat){
        total_price += cat->getPrice();
    }

    void VisitBird(Bird* bird){
        total_price += bird->getPrice();
    }

    void VisitFish(Fish* fish){
        total_price += fish->getPrice();
    }

public:
    ShoppingCartVisitor(){
        total_price = 0;
    }

    double calculateTotalPrice(ItemVector* items){
        total_price = 0;
        for(int i = 0; i < items->getSize(); i++){
            items->getItem(i)->Accept(this);
        }
        return total_price;
    }
};

#endif // ShoppingCartVisitor_H
