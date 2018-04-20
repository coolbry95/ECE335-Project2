/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SearchableVector.h
 * Author: dj2
 *
 * Created on February 8, 2018, 8:29 PM
 */

#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H

typedef enum comparison {
    LESS_THAN,
    GREATER_THAN,
    EQUAL,
} Comparison;

class SearchableVector {
public:
    virtual int getSize() const = 0;
    virtual Comparison compareAt(size_t i) const = 0;
};


#endif /* SEARCHABLEVECTOR_H */

