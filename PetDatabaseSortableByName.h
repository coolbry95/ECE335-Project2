/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabaseSortableByName.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:43 AM
 */

#ifndef PETDATABASESORTABLEBYNAME_H
#define PETDATABASESORTABLEBYNAME_H

#include "PetDatabase.h"
#include "SortableVector.h"

class PetDatabaseSortableByName : public PetDatabase, public SortableVector {
public:
	
    PetDatabaseSortableByName(PetDatabase* db) : PetDatabase(db){}
    PetDatabaseSortableByName(vector<Pet*> petVector) : PetDatabase(petVector){}
    
	int getSize() const {
		return PetDatabase::getSize();
	}
	
	void swap(int i, int j) {
		PetDatabase::swap(i, j);
	}
	
	bool smaller(int i, int j) const {
		if(PetDatabase::getPet(i)->GetName() < PetDatabase::getPet(j)->GetName())
            return true;
        else
            return false;
	}
};


#endif /* PETDATABASESORTABLEBYNAME_H */

