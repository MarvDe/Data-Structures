#include <stdlib.h>
#include <string.h>

#include <Array.h>

Array *ArrayCreate(size_t numOfElements, size_t sizeOfElements){
    Array *array = malloc(sizeof(Array));
    array->numOfElements = numOfElements;
    array->sizeOfElements = sizeOfElements;
    array->data = malloc(numOfElements * sizeOfElements);
    return array;
}

void ArrayDestroy(Array *array){
    if (array == NULL) return;
    free(array->data);
    free(array);
}

void *ArrayGet(Array *array, size_t index){
    if (array == NULL || array->numOfElements <= index) return NULL;
    return array->data + array->sizeOfElements * index;
}

void ArraySet(Array *array, void *element, size_t numOfElements, size_t index){
    if (array == NULL || array->numOfElements <= index) return;
    if (array->numOfElements < index + numOfElements) ArrayResize(array, index + numOfElements);
    memcpy(ArrayGet(array, index), element, array->sizeOfElements * numOfElements);
}

void ArrayResize(Array *array, size_t newNumOfElements){
    if (array == NULL || array->numOfElements == newNumOfElements) return;
    array->numOfElements = newNumOfElements;
    array->data = realloc(array->data, array->sizeOfElements * newNumOfElements);
}