#ifndef LIST_H
#define LIST_H



typedef unsigned long long size_t;

typedef struct List List;
struct List {
    struct Node *next;
};

List *ListCreate();
void ListDestroy(List *list);
void ListAppend(List *list, void *data, char ownsData);
void ListInsert(List *list, void *data, char ownsData, size_t index);
void *ListGet(List *list, size_t index);
void *ListGetLast(List *list);
size_t ListLength(List *list);
void *ListRemove(List *list, size_t index);
void *ListRemoveLast(List *list);
void ListTraverseAndApply(List *list, void (*func)(void *));

#endif