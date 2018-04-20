#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "visitor.h"

using namespace std;

class Item {
public:
    virtual double getPrice() const;

    virtual void Accept(Visitor* visitor);

    virtual string getName() const;
}

#endif // ITEM_H
