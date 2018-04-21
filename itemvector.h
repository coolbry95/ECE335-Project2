#ifndef ITEMVECTOR_H
#define ITEMVECTOR_H

#include "item.h"
#include <vector>

using namespace std;


class ItemVector {
private:
    vector<Item*> items;
public:
    ItemVector(){}
    ItemVector(ItemVector* v){
        items = v->items;
    }
    int getSize() const {
        return items.size();
    }

    // need this?
    virtual bool smaller(int i, int j) const {
        if(getItem(i) < getItem(j))
            return true;
        else
            return false;
    }

    virtual void swap(int i, int j){
        Item *temp = items[i];
        items[i]=items[j];
        items[j]=temp;
    }

    Item* getItem(int i) const{
        return items[i];
    }

    void insertItem(Item* i) {
        items.push_back(i);
    }
};

#endif // ITEMVECTOR_H
