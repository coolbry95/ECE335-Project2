#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include <vector>
#include "PetDatabase.h"

using namespace std;

class Builder
{
public:
    virtual void addPet(string clas, string name, string type, double weight, double price, string specialAttribute) = 0;
    virtual void addBundle(string name, double price, vector<string> pets) = 0;
    //virtual PetDatabase* getPetDatabase() = 0;
    //virtual vector<Bundle> getBundleDatabase() = 0;
};

#endif // BUILDER_H
