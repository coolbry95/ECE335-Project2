/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dog.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:41 AM
 */

#ifndef DOG_H
#define DOG_H

#include "Pet.h"

#include <string>

using namespace std;

class Dog : public Pet {
private:
	string category;
	
public:
	Dog(string n, string t, double p, unsigned int w, string c):
		Pet(n, t, p, w), category(c) {}
	
	Dog(const Dog& dog): Pet(dog) {
        if (this != &dog) {
			category = dog.category;
        }
    }
    
    Dog& operator=(const Dog& dog) {
        if (this != &dog) {
			Pet::operator=(dog);
			category = dog.category;
        }
        return *this;
    }
	
	virtual ~Dog() {}
	
    string getCategory() const {
		return category;
	}
	void SetCategory(const string c) {
		category = c;
	}
	void print() const {
		Pet::print();
		cout << "category: " << category << endl;
	}
    void Accept(Visitor *v){
        v->VisitDog(this);
    }
};

#endif /* DOG_H */

