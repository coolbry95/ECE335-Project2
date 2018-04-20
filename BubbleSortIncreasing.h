/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSortIncreasing.h
 * Author: dj2
 *
 * Created on February 11, 2018, 12:42 PM
 */

#ifndef BUBBLESORTINCREASING_H
#define BUBBLESORTINCREASING_H

#include "BubbleSort.h"

class BubbleSortIncreasing : public BubbleSort {
public:

    virtual void sort(SortableVector* sortableVector) {
        bool sorted = false;
        int n=sortableVector->getSize();
        while( !sorted ){
            sorted = true;
            for(int i=1; i<n; i++){
                if(!sortableVector->smaller(i-1,i)){
                    sortableVector->swap(i-1,i);
                    sorted = false;
                }
            }
            n--;
        }
    }
};

#endif /* BUBBLESORTINCREASING_H */

