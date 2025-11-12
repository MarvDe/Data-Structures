#ifndef DLLIST_H
#define DLLIST_H


typedef struct DLList DLList;
struct DLList{
    struct DLNode *first;
    struct DLNode *last;
};

DLList *DLListCreate();
void DLListDestroy(DLList *list);
void DLListAppend(DLList *list, void *data, char ownsData);
void DLListInsert(DLList *list, void *data, char ownsData, int index);
void *DLListGet(DLList *list, int index);
size_t DLListLength(DLList *list);
void DLListRemove(DLList *list, int index);
void *DLListRemoveAndGet(DLList *list, int index);
void DLListTraverseAndApply(DLList *list, void (*func)(void *));

void DLListPrintStructure(DLList *list);

#endif