#ifndef DATABASEBUILDER_H
#define DATABASEBUILDER_H

#include "builder.h"
#include <string>
#include <vector>

#include "Dog.h"
#include "Bird.h"
#include "Cat.h"
#include "Fish.h"
#include "Pet.h"
#include "PetDatabase.h"
#include "PetDatabaseSearchableByName.h"
#include "PetDatabaseSortableByName.h"
#include "BubbleSortIncreasing.h"
#include "BinarySearch.h"

using namespace std;

class DatabaseBuilder : public Builder {
private:
    PetDatabase pet_database;
    vector<Bundle> bundle_database;
public:
    addPet(string clas, string name, string type, double weight, double price, string specialAttribute) {
        switch(clas) {
        case "Dog":
            addDog(name,type,weight,price,specialAttribute);
        case "Cat":
            if (specialAttribute == "true") {
                addCat(name,type,weight,price,true);
            } else {
                addCat(name,type,weight,price,false);
            }
        case "Fish":
            addFish(name,type,weight,price,specialAttribute);
        case "Bird":
            if (specialAttribute == "true") {
                addBird(name,type,weight,price,true);
            } else {
                addBird(name,type,weight,price,false);
            }
        }
    }

    addBundle(string name, double price, vector<string> pets) {
        // look up pet and add to bundle
        Bundle b(name, price);

        BubbleSortIncreasing bs;
        PetDatabaseSortableByName petDatabaseSortableByName(pet_database);
        bs.sort(&petDatabaseSortableByName);
        BinarySearch s;
        PetDatabaseSearchableByName SName(&petDatabaseSortableByName);
        double sum = 0.0;
        Pet *p;
        for (int i=0; i<pets.size(); i++) {
            SName.setQuery(pet[i]);
            p = SName.getPet(s.search(&SName));
            sum += p.GetPrice();
            b.addItem(p);
        }
        double savings = (double)(sum-price) / sum;

        b.setSavings(savings);
        bundle_database.push_back(b);
    }

    addDog(string name, string type, double weight, double price, string category) {
        Dog dog(name,type,price,weight,category);
        pet_database.insertPet(&dog);
    }
    addCat(string name, string type, double weight, double price, bool fluffy) {
        Cat cat(name,type,price,weight,fluffy);
        pet_database.insertPet(&cat);
    }
    addFish(string name, string type, double weight, double price, string waterType) {
        Fish fish(name,type,price,weight,waterType);
        pet_database.insertPet(&fish);
    }
    addBird(string name, string type, double weight,double price, bool nocturnal) {
        Bird bird(name,type,price,weight,nocturnal);
        pet_database.insertPet(&bird);
    }
    vector<Bundle> getBundleDatabase() {
        return bundle_database;
    }

    PetDatabase getPetDatabase() {
        return pet_database;
    }
}



#endif // DATABASEBUILDER_H
