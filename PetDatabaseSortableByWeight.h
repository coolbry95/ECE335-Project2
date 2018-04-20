/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabaseSortableByWeight.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:45 AM
 */

#ifndef PETDATABASESORTABLEBYWEIGHT_H
#define PETDATABASESORTABLEBYWEIGHT_H

#include "PetDatabase.h"
#include "SortableVector.h"

class PetDatabaseSortableByWeight : public PetDatabase, public SortableVector {
public:
    
        PetDatabaseSortableByWeight(PetDatabase* db) : PetDatabase(db){}
        PetDatabaseSortableByWeight(vector<Pet*> petVector) : PetDatabase(petVector){}

	int getSize() const {
		return PetDatabase::getSize();
	}
	
	void swap(int i, int j) {
		PetDatabase::swap(i, j);
	}
	
	bool smaller(int i, int j) const {
		if(PetDatabase::getPet(i)->GetWeight() < PetDatabase::getPet(j)->GetWeight())
            return true;
        else
            return false;
	}
};

#endif /* PETDATABASESORTABLEBYWEIGHT_H */

