#ifndef SORTABLEITEMVECTOR_H
#define SORTABLEITEMVECTOR_H


class SortableItemVector : public ItemVector, public SortableVector {
public:

    //PetDatabaseSortableByName(PetDatabase* db) : PetDatabase(db){}
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
