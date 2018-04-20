/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabaseSortableByType.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:44 AM
 */

#ifndef PETDATABASESORTABLEBYTYPE_H
#define PETDATABASESORTABLEBYTYPE_H

#include "PetDatabase.h"
#include "SortableVector.h"

class PetDatabaseSortableByType : public PetDatabase, public SortableVector {
public:

    PetDatabaseSortableByType(PetDatabase* db) : PetDatabase(db) {
    }

    PetDatabaseSortableByType(vector<Pet*> petVector) : PetDatabase(petVector) {
    }

    int getSize() const {
        return PetDatabase::getSize();
    }

    void swap(int i, int j) {
        PetDatabase::swap(i, j);
    }

    bool smaller(int i, int j) const {
        if (PetDatabase::getPet(i)->GetType() < PetDatabase::getPet(j)->GetType())
            return true;
        else
            return false;
    }
};

#endif /* PETDATABASESORTABLEBYTYPE_H */

