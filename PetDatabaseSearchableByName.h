/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabaseSearchableByName.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:46 AM
 */

#ifndef PETDATABASESEARCHABLEBYNAME_H
#define PETDATABASESEARCHABLEBYNAME_H

#include <vector>

#include "PetDatabase.h"
#include "SearchableVector.h"

using namespace std;

class PetDatabaseSearchableByName : public PetDatabase, public SearchableVector {
public:

    PetDatabaseSearchableByName() : PetDatabase(){}

    PetDatabaseSearchableByName(PetDatabase* db) : PetDatabase(db){}
    PetDatabaseSearchableByName(vector<Pet*> petVector) : PetDatabase(petVector){}
    
    int getSize() const {
        return PetDatabase::getSize();
    }

    Comparison compareAt(size_t i) const {
        string name = getPet(i)->getName();

        if (name == query) {
            return EQUAL;
        } else if (name > query) {
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

#endif /* PETDATABASESEARCHABLEBYNAME_H */

