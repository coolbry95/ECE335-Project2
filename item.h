#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "visitor.h"

using namespace std;

class Item {
public:
    virtual ~Item() {}
    virtual double getPrice() const = 0;

    virtual void Accept(Visitor* visitor) = 0;

    virtual string getName() const = 0;
};

#endif // ITEM_H
