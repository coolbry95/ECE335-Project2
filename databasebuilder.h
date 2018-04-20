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
            addFish(name,type,weight,specialAttribute);
        case "Bird":
            if (specialAttribute == "true") {
                addBird(name,type,weight,price,true);
            } else {
                addBird(name,type,weight,price,false);
            }
        }
    };

    addBundle(string name, double price, vector<string>);

    addDog(string name, string type, double weight, double price, string category) {
        Dog dog(name,type,price,weight,category);
        pet_database.insertPet(&dog);
    };
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
    };
}



#endif // DATABASEBUILDER_H
