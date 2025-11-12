#ifndef ARRAY_H
#define ARRAY_H

typedef long long unsigned size_t;

typedef struct Array Array;
struct Array{
    size_t numOfElements;
    size_t sizeOfElements;
    void *data;
};


Array *ArrayCreate(size_t numOfElements, size_t sizeOfElements);
void ArrayDestroy(Array *array);
void *ArrayGet(Array *array, size_t index);
void ArraySet(Array *array, void *element, size_t numOfElements, size_t index);
void ArrayResize(Array *array, size_t newNumOfElements);


#endif