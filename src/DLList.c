#include <stdlib.h>

#include <DLList.h>

typedef struct DLNode DLNode;
struct DLNode{
    DLNode *next;
    DLNode *prev;
    void *data;
    char ownsData;
};

DLNode *DLNodeCreate(void *data, char ownsData){
    DLNode *node = malloc(sizeof(DLNode));
    node->next = NULL;
    node->prev = NULL;
    node->data = data;
    node->ownsData = ownsData;
    return node;
}

void DLNodeDestroy(DLNode *node){
    if (node == NULL) return;
    if (node->ownsData) free(node->data);
    free(node);
}

void DLNodeDestroyRec(DLNode *node){
    if (node == NULL) return;
    DLNodeDestroyRec(node->next);
    DLNodeDestroy(node);
}

DLNode *DLNodeGetFirst(DLNode *node){
    if (node == NULL) return NULL;
    if (DLNodeIsFirst(node)) return node;
    DLNodeGetFirst(node->prev);
}

DLNode *DLNodeGetLast(DLNode *node){
    if (node == NULL) return NULL;
    if (DLNodeIsLast(node)) return node;
    DLNodeGetLast(node->next);
}

DLNode *DLNodeGet(DLNode *node, int index){
    if (node == NULL || index == 0) return node;
    if (index < 0)  DLNodeGet(node->prev, ++index);
    else            DLNodeGet(node->next, --index);
}

char DLNodeIsFirst(DLNode *node){
    if (node == NULL || node->prev != NULL) return 0;
    return 1;
}

char DLNodeIsLast(DLNode *node){
    if (node == NULL || node->next != NULL) return 0;
    return 1;
}

void *DLNodeGetData(DLNode *node){
    if (node == NULL) return NULL;
    node->ownsData = 0;
    return node->data;
}

DLList *DLListCreate(){
    DLList *list = malloc(sizeof(DLList));
    list->first = NULL;
    list->last = NULL;
    return list;
}

void DLListDestroy(DLList *list){
    if (list == NULL) return;
    DLNodeDestroyRec(list->first);
    free(list);
}

void DLListAppend(DLList *list, void *data, char ownsData){
    if (list == NULL) return;
    DLNode *nodeNewLast = DLNodeCreate(data, ownsData);
    DLNode *nodeLast = list->last;
    if (nodeLast == NULL){
        list->first = nodeNewLast;
        list->last = nodeNewLast;
    }
    else{
        nodeLast->next = nodeNewLast;
        nodeNewLast->prev = nodeLast;
        list->last = nodeNewLast;
    }
}

void DLListInsert(DLList *list, void *data, char ownsData, int index){
    if (list == NULL) return;
    DLNode *nodeNew = DLNodeCreate(data, ownsData);
    DLNode *nodeOld = DLListGet(list, index);

}

void *DLListGet(DLList *list, int index){
    if (list == NULL) return NULL;
    DLNode *node;
    if (index > 0)  node = DLNodeGet(list->first, index);
    else            node = DLNodeGet(list->last, index);
    return DLNodeGetData(node);
}

void *DLListGetLast(DLList *list){
    if (list == NULL) return NULL;
    return DLNodeGetData(list->last);
}

size_t DLListLength(DLList *list){
    if (list == NULL) return 0;
    size_t length = 0;
    DLNode *node = list->first;
    while (!DLNodeIsLast(node)){
        node = node->next;
        length++;
    }
    return length;
}

void DLListRemove(DLList *list, int index){
    if (list == NULL) return;
    DLNode *node;
    if (index > 0)  node = DLNodeGet(list->first, index);
    else            node = DLNodeGet(list->last, index);
    if (node == NULL) return;
    DLNode *nodePrev, *nodeNext;
    nodePrev = node->prev;
    nodeNext = node->next;
    if (DLNodeIsFirst(node)){
        nodeNext->prev = NULL;
        list->first = nodeNext;    
    } 
    else{
        nodePrev->next = nodeNext;
    }
    if (DLNodeIsLast(node)){
        
        nodeNext->prev = nodePrev;
    }
    DLNodeDestroy(node);
}

void DLListRemoveLast(DLList *list);
void *DLListRemoveAndGet(DLList *list, int index);
void *DLListRemoveAndGetLast(DLList *list);
void DLListTraverseAndApply(DLList *list, void (*func)(void *));








