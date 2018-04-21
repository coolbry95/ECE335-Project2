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
#include "bundle.h"

using namespace std;

class DatabaseBuilder : public Builder {
private:
    PetDatabase pet_database;
    vector<Bundle> bundle_database;
public:
    void addPet(string clas, string name, string type, double weight, double price, string specialAttribute) {
        if(clas == "Dog"){
            addDog(name,type,weight,price,specialAttribute);
        }
        else if (clas == "Cat"){
            if (specialAttribute == "true") {
                addCat(name,type,weight,price,true);
            } else {
                addCat(name,type,weight,price,false);
            }
        }
        else if (clas == "Fish"){
            addFish(name,type,weight,price,specialAttribute);
        }
        else if (clas == "Bird"){
            if (specialAttribute == "true") {
                addBird(name,type,weight,price,true);
            } else {
                addBird(name,type,weight,price,false);
            }
        }
    }

    void addBundle(string name, double price, vector<string> pets) {
        // look up pet and add to bundle
        Bundle* b = new Bundle(name, price);

        BubbleSortIncreasing bs;
        PetDatabaseSortableByName petDatabaseSortableByName(&pet_database);
        bs.sort(&petDatabaseSortableByName);
        BinarySearch s;
        PetDatabaseSearchableByName SName(&petDatabaseSortableByName);
        double sum = 0.0;
        Pet *p;
        for (uint i=0; i<pets.size(); i++) {
            SName.setQuery(pets[i]);
            p = SName.getPet(s.search(&SName));
            sum += p->getPrice();
            b->addItem(p);
        }
        double savings = (double)(sum-price) / sum;

        b->setSavings(savings);
        bundle_database.push_back(*b);
    }

    void addDog(string name, string type, double weight, double price, string category) {
        Dog* dog = new Dog(name,type,price,weight,category);
        pet_database.insertPet(*dog);
    }
    void addCat(string name, string type, double weight, double price, bool fluffy) {
        Cat* cat = new Cat(name,type,price,weight,fluffy);
        pet_database.insertPet(*cat);
    }
    void addFish(string name, string type, double weight, double price, string waterType) {
        Fish* fish = new Fish(name,type,price,weight,waterType);
        pet_database.insertPet(*fish);
    }
    void addBird(string name, string type, double weight,double price, bool nocturnal) {
        Bird* bird = new Bird(name,type,price,weight,nocturnal);
        pet_database.insertPet(*bird);
    }
    vector<Bundle> getBundleDatabase() {
        return bundle_database;
    }

    PetDatabase* getPetDatabase() {
        return &pet_database;
    }
};



#endif // DATABASEBUILDER_H
