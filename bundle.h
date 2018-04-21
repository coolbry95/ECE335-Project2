#ifndef BUNDLE_H
#define BUNDLE_H


#include <vector>
#include <string>

#include "item.h"
#include "Pet.h"
#include "PetDatabase.h"
#include "PetDatabaseSearchableByName.h"
#include "PetDatabaseSortableByName.h"
#include "BubbleSortIncreasing.h"
#include "BinarySearch.h"

class Bundle: public Item {
protected:
    vector<Item*> entries;
    double price;
    string name;
    double savings;
public:
    Bundle(string n, double p): price(p), name(n) {}

    virtual ~Bundle() {
        for(uint i=0; i<entries.size(); i++) delete entries[i];
    }

    void addItem(Item* entry) {
        entries.push_back(entry);
    }

    double getPrice() const {
        return price;
    }

    double getSavings() const {
        return savings;
    }

    string getName() const {
        return name;
    }

    Item* getItem(int i) const {
        return entries[i];
    }

    virtual void Accept(Visitor *v) {
        v->VisitBundle(this);
    }

    void setPrice(double p) {
        price = p;
    }

    void setName(string n) {
        name = n;
    }

    void setSavings(double s) {
        savings = s;
    }
};

#endif // BUNDLE_H
