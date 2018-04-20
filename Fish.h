/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Fish.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:42 AM
 */

#ifndef FISH_H
#define FISH_H

#include "Pet.h"

#include <string>

using namespace std;

class Fish : public Pet {
private:
	string waterType;
	
public:
	Fish(string n, string t, double p, unsigned int w, string wt):
		Pet(n, t, p, w), waterType(wt) {}
	
	Fish(const Fish& fish): Pet(fish) {
        if (this != &fish) {
			waterType = fish.waterType;
        }
    }
    
    Fish& operator=(const Fish& fish) {
        if (this != &fish) {
			Pet::operator=(fish);
			waterType = fish.waterType;
        }
        return *this;
    }
	
	virtual ~Fish() {}
	
	string GetWaterType() const {
		return waterType;
	}
	void SetWaterType(const string w) {
		waterType = w;
	}
	void print() const {
		Pet::print();
		cout << "water type: " << waterType << endl;
	}
    void Accept(Visitor *v){
        v->VisitFish(this);
    }
};

#endif /* FISH_H */

