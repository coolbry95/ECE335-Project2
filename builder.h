#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include <vector>

using namespace std;

class Builder
{
public:
    virtual void addPet(string clas, string name, string type, double weight, double price, string specialAttribute) = 0;
    virtual void addBundle(string name, double price, vector<string> pets) = 0;
};

#endif // BUILDER_H
