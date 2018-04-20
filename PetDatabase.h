/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PetDatabase.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:43 AM
 */

#ifndef PETDATABASE_H
#define PETDATABASE_H

#include <vector>
#include "Pet.h"

using namespace std;


class PetDatabase {
public:
    
    PetDatabase(PetDatabase* db){
        pets = vector<Pet*>();
        for(int i = 0; i < db->pets.size(); i++){
            insertPet(*db->pets[i]);
        }
    }
    
    PetDatabase(vector<Pet*> petVector){
        pets = vector<Pet*>();
        for(int i = 0; i < petVector.size(); i++){
            insertPet(*petVector[i]);
        }
    }
	
    PetDatabase(const PetDatabase& db) {
        if (this != &db) {
            pets = vector<Pet*>();
            for(int i = 0; i < db.pets.size(); i++){
                insertPet(*db.pets[i]);
            }
        }
    }
    
    PetDatabase& operator=(const PetDatabase& db) {
        if (this != &db) {
            pets = vector<Pet*>();
            for(int i = 0; i < db.pets.size(); i++){
                insertPet(*db.pets[i]);
            }
        }
        return *this;
    }
	
    virtual ~PetDatabase() {}
    
    int getSize() const {
        return pets.size();
    }
    
    void swap(int i, int j){
        Pet* temp = pets[i];
        pets[i] = pets[j];
        pets[j] = temp;
    }
    
    void DisplayRecords() const {
        for(int i = 0; i < pets.size(); i++){
            pets[i]->print();
        }
    }
    
    Pet* getPet(int i) const {
        return pets[i];
    }
    
    void insertPet(Pet& pet){
        pets.push_back(&pet);
    }
    
private:
    vector<Pet*> pets;
};


#endif /* PETDATABASE_H */

