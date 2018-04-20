/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pet.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:40 AM
 */

#ifndef PET_H
#define PET_H

#include <string>
#include <iostream>

using namespace std;

class Pet{
private:
	string name;
	string type;
	unsigned int weight;
	double price;

public:
	Pet(string n, string t, double p, unsigned int w):
		name(n), type(t), price(p), weight(w) {}
		
	Pet(const Pet& pet) {
        if (this != &pet) {
			name = pet.name;
			type = pet.type;
			price = pet.price;
			weight = pet.weight;
        }
    }
    
    Pet& operator=(const Pet& pet) {
        if (this != &pet) {
			name = pet.name;
			type = pet.type;
			price = pet.price;
			weight = pet.weight;
        }
        return *this;
    }
	
	virtual ~Pet() {}
		
	string GetName() const {
		return name;
	}
	string GetType() const {
		return type;
	}
	unsigned int GetWeight() const {
		return weight;
	}
	double GetPrice() const {
		return price;
	}
	void SetPrice(const double p) {
		price = p;
	}
	void SetWeight(const unsigned int w) {
		weight = w;
	}
	void SetType(const string t) {
		type = t;
	}
	void SetName(const string n) {
		name = n;
	}
	virtual void print() const{
		cout << "name: " << name << " ";
		cout << "type: " << type << " ";
		cout << "weight: " << weight << " ";
		cout << "price: " << price << " ";
	}
};


#endif /* PET_H */

