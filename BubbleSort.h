#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "SortableVector.h"

class BubbleSort{
public:
    virtual void sort(SortableVector* sortableVector) = 0;
};
#endif /* BUBBLESORT_H */

