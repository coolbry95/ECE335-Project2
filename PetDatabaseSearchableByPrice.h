/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabaseSearchableByPrice.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:47 AM
 */

#ifndef PETDATABASESEARCHABLEBYPRICE_H
#define PETDATABASESEARCHABLEBYPRICE_H

#include "PetDatabase.h"
#include "SearchableVector.h"


class PetDatabaseSearchableByPrice : public PetDatabase, public SearchableVector {
public:

    PetDatabaseSearchableByPrice(PetDatabase* db) : PetDatabase(db){}
    PetDatabaseSearchableByPrice(vector<Pet*> petVector) : PetDatabase(petVector){}
    
    int getSize() const {
        return PetDatabase::getSize();
    }

    Comparison compareAt(size_t i) const {
        double price = getPet(i)->GetPrice();

        if (price == query) {
            return EQUAL;
        } else if (price > query) {
            return GREATER_THAN;
        } else {
            return LESS_THAN;
        }
    }

    void setQuery(const double& q) {
        query = q;
    }

private:
    double query;
};

#endif /* PETDATABASESEARCHABLEBYPRICE_H */

