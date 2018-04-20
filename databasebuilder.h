#ifndef DATABASEBUILDER_H
#define DATABASEBUILDER_H

#include "builder.h"
#include <string>
#include <vector>

using namespace std;

class DatabaseBuilder : public Builder {
private:
    PetDatabase pet_database;
    vector<Bundle> bundle_database;
public:
    addPet(string clas, string name, string type, double weight, double price, string specialAttribute);
    addBundle(string name, double price, vector<string>);
    addDog(string name, string type, double weight, string category);
    addCat(string name, string type, double weight, bool fluffy);
    addFish(string name, string type, double weight, string waterType);
    addBird(string name, string type, double weight, bool nocturnal);
    vector<Bundle> getBundleDatabase();

}



#endif // DATABASEBUILDER_H
