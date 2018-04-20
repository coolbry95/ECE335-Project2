/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarySearch.h
 * Author: dj2
 *
 * Created on February 8, 2018, 8:29 PM
 */

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "SearchableVector.h"

class BinarySearch {
public:
    ssize_t search(SearchableVector* v) {
        ssize_t left = 0;
        ssize_t right = v->getSize() - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            switch(v->compareAt(middle)){
                case EQUAL:
                    return middle;
                    break;
                case GREATER_THAN:
                    right = middle - 1;
                    break;
                case LESS_THAN:
                    left = middle + 1;
                    break;
            }
        }
        return -1;
    }
    
};


#endif /* BINARYSEARCH_H */

