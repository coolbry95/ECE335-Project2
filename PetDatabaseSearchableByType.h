/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabaseSearchableByType.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:47 AM
 */

#ifndef PETDATABASESEARCHABLEBYTYPE_H
#define PETDATABASESEARCHABLEBYTYPE_H

#include "PetDatabase.h"
#include "SearchableVector.h"

class PetDatabaseSearchableByType : public PetDatabase, public SearchableVector {
public:

    PetDatabaseSearchableByType(PetDatabase* db) : PetDatabase(db){}
    PetDatabaseSearchableByType(vector<Pet*> petVector) : PetDatabase(petVector){}
    
    int getSize() const {
        return PetDatabase::getSize();
    }

    Comparison compareAt(size_t i) const {
        string type = getPet(i)->GetType();

        if (type == query) {
            return EQUAL;
        } else if (type > query) {
            return GREATER_THAN;
        } else {
            return LESS_THAN;
        }
    }

    void setQuery(const string& q) {
        query = q;
    }

private:
    string query;
};

#endif /* PETDATABASESEARCHABLEBYTYPE_H */

