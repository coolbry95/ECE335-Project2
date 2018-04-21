/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bird.h
 * Author: dj2
 *
 * Created on February 19, 2018, 11:42 AM
 */

#ifndef BIRD_H
#define BIRD_H

#include "Pet.h"

class Bird : public Pet {
private:
	bool nocturnal;
	
public:
	Bird(string n, string t, double p, unsigned int w, bool f):
		Pet(n, t, p, w), nocturnal(f) {}
		
	Bird(const Bird& bird): Pet(bird) {
        if (this != &bird) {
			nocturnal = bird.nocturnal;
        }
    }
    
    Bird& operator=(const Bird& bird) {
        if (this != &bird) {
			Pet::operator=(bird);
			nocturnal = bird.nocturnal;
        }
        return *this;
    }
	
	virtual ~Bird() {}
	
    bool getNocturnal() const {
		return nocturnal;
	}
	void SetNocturnal(const bool n) {
		nocturnal = n;
	}
	void print() const {
		Pet::print();
		cout << "nocturnal: " << nocturnal << endl;
	}
    void Accept(Visitor *v){
        v->VisitBird(this);
    }
};

#endif /* BIRD_H */

