#ifndef CSVREADER_H
#define CSVREADER_H

#include "builder.h"
#include "PetDatabase.h"
#include <fstream>
#include <sstream>

class CSVReader
{
public:
    void read(string pet_file, string bundle_file) {
        ifstream file(pet_file);
        vector<string> result;
        if (file.is_open()) {
                string line;

                while (getline(file, line))   {
                    stringstream ss(line);
                    while(ss.good()) {
                        string substr;
                        getline(ss, substr, ',');
                        if(substr.length() != 0 && *substr.rbegin() == '\r'){
                            substr.erase(substr.length() -1);
                        }
                        result.push_back( substr );
                    }

                    string clas = result[0];
                    string name = result[1];
                    string type = result[2];
                    double weight = stod(result[3]);
                    double price = stod(result[4]);
                    string special = result[5];   // you might have to look at 4 cases (Gogs, Fish, Bird, Cat cases to store values in special)

                    builder->addPet(clas, name, type, weight, price, special);

                    result.clear();
                    //update table widget rows here
            }
            file.close();
        }

        file = ifstream(bundle_file);
        result.clear();
        vector<string> pets;
        if (file.is_open()) {
                string line;

                while (getline(file, line))   {
                    stringstream ss(line);
                    while(ss.good()) {
                        string substr;
                        getline(ss, substr, ',');
                        if(substr.length() != 0 && *substr.rbegin() == '\r'){
                            substr.erase(substr.length() -1);
                        }
                        result.push_back( substr );
                    }
                    string name = result[0];
                    double price = stod(result[1]);
                    for (uint i=2; i<result.size(); i++) {
                            pets.push_back(result[i]);
                    }

                    builder->addBundle(name, price, pets);

                    result.clear();
                    pets.clear();
                    //update table widget rows here
            }
            file.close();
        }
    };

    //void write(string out_file) {
    //    builder->writeCSV();
    //}

    void setBuilder(Builder* b) {
        builder = b;
    };

private:
    Builder* builder;
};

#endif // CSVREADER_H
