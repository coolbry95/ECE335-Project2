/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cat.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:41 AM
 */

#ifndef CAT_H
#define CAT_H

#include "Pet.h"

using namespace std;

class Cat : public Pet {
private:
		bool fluffy;
		
public:
	Cat(string n, string t, double p, unsigned int w, bool f):
		Pet(n, t, p, w), fluffy(f) {}
		
	Cat(const Cat& cat): Pet(cat) {
        if (this != &cat) {
			fluffy = cat.fluffy;
        }
    }
    
    Cat& operator=(const Cat& cat) {
        if (this != &cat) {
			Pet::operator=(cat);
			fluffy = cat.fluffy;
        }
        return *this;
    }
	
	virtual ~Cat() {}
	
	bool GetFluffy() const {
		return fluffy;
	}
	void SetFluffy(const bool f) {
		fluffy = f;
	}
	void print() const {
		Pet::print();
		cout << "fluffy: " << fluffy << endl;
	}
};
#endif /* CAT_H */

