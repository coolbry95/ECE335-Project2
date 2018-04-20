/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabaseSearchableByWeight.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:47 AM
 */

#ifndef PETDATABASESEARCHABLEBYWEIGHT_H
#define PETDATABASESEARCHABLEBYWEIGHT_H

#include "PetDatabase.h"
#include "SearchableVector.h"

class PetDatabaseSearchableByWeight : public PetDatabase, public SearchableVector {
public:

    PetDatabaseSearchableByWeight(PetDatabase* db) : PetDatabase(db){}
    PetDatabaseSearchableByWeight(vector<Pet*> petVector) : PetDatabase(petVector){}
    
    int getSize() const {
        return PetDatabase::getSize();
    }

    Comparison compareAt(size_t i) const {
        unsigned int weight = getPet(i)->GetWeight();

        if (weight == query) {
            return EQUAL;
        } else if (weight > query) {
            return GREATER_THAN;
        } else {
            return LESS_THAN;
        }
    }

    void setQuery(const unsigned int& q) {
        query = q;
    }

private:
    unsigned int query;
};

#endif /* PETDATABASESEARCHABLEBYWEIGHT_H */

