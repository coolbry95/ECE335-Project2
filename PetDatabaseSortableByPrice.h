/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabaseSortableByPrice.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:46 AM
 */

#ifndef PETDATABASESORTABLEBYPRICE_H
#define PETDATABASESORTABLEBYPRICE_H

#include "PetDatabase.h"
#include "SortableVector.h"

class PetDatabaseSortableByPrice : public PetDatabase, public SortableVector {
public:
    
        PetDatabaseSortableByPrice(PetDatabase* db) : PetDatabase(db){}
        PetDatabaseSortableByPrice(vector<Pet*> petVector) : PetDatabase(petVector){}

	int getSize() const {
	return PetDatabase::getSize();
}

	void swap(int i, int j) {
		PetDatabase::swap(i, j);
	}

	bool smaller(int i, int j) const {
		if(PetDatabase::getPet(i)->GetPrice() < PetDatabase::getPet(j)->GetPrice())
			return true;
		else
			return false;
	}
};

#endif /* PETDATABASESORTABLEBYPRICE_H */

