/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSortDecreasing.h
 * Author: dj2
 *
 * Created on February 11, 2018, 12:43 PM
 */

#ifndef BUBBLESORTDECREASING_H
#define BUBBLESORTDECREASING_H

#include "BubbleSort.h"

class BubbleSortDecreasing : public BubbleSort {
    public:

        virtual void sort(SortableVector* sortableVector) {
        bool sorted = false;
        int n = sortableVector->getSize();
        while (!sorted) {
            sorted = true;
            for (int i = 1; i < n; i++) {
                if (sortableVector->smaller(i - 1, i)) {
                    sortableVector->swap(i - 1, i);
                    sorted = false;
                }
            }
            n--;
        }
    }
};


#endif /* BUBBLESORTDECREASING_H */

