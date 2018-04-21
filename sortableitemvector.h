#ifndef SORTABLEITEMVECTOR_H
#define SORTABLEITEMVECTOR_H

#include "itemvector.h"
#include "SortableVector.h"

class SortableItemVector : public ItemVector, public SortableVector {
public:
    SortableItemVector() : ItemVector(){}

    SortableItemVector(ItemVector* db) : ItemVector(db){}
    //PetDatabaseSortableByName(vector<Pet*> petVector) : PetDatabase(petVector){}

    int getSize() const {
        return ItemVector::getSize();
    }

    void swap(int i, int j) {
        ItemVector::swap(i, j);
    }

    bool smaller(int i, int j) const {
        if(ItemVector::getItem(i)->getPrice() < ItemVector::getItem(j)->getPrice())
            return true;
        else
            return false;
    }
};

#endif // SORTABLEITEMVECTOR_H
