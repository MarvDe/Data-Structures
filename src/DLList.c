#include <stdlib.h>
#include <stdio.h>

#include <DLList.h>

typedef struct DLNode DLNode;
struct DLNode{
    DLNode *next;
    DLNode *prev;
    void *data;
    char ownsData;
};

char DLNodeIsFirst(DLNode *node){
    if (node == NULL || node->prev != NULL) return 0;
    return 1;
}

char DLNodeIsLast(DLNode *node){
    if (node == NULL || node->next != NULL) return 0;
    return 1;
}

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
    node == NULL;
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

void DLListInsert(DLList *list, void *data, char ownsData, int index){
    if (list == NULL) return;
    DLNode *nodeNew = DLNodeCreate(data, ownsData);
    if (nodeNew == NULL) return;
    if (list->first == NULL){
        list->first = nodeNew;
        list->last = nodeNew;
    } else if (index < -1){
        DLNode *nodeOld = DLNodeGet(list->last, ++index);
        if (nodeOld == NULL) return;
        DLNode *nodePrev = nodeOld->prev;
        nodeOld->prev = nodeNew;
        nodeNew->next = nodeOld;
        nodeNew->prev = nodePrev;
        if (nodePrev == NULL){
            list->first = nodeNew;
        } 
        else{
            nodePrev->next = nodeNew;
        }
    } else if (index > 0){
        DLNode *nodeOld = DLNodeGet(list->first, --index);
        if (nodeOld == NULL) return;
        DLNode *nodeNext = nodeOld->next;
        nodeOld->next = nodeNew;
        nodeNew->prev = nodeOld;
        nodeNew->next = nodeNext;
        if (nodeNext != NULL){
            list->last = nodeNew;
        }
        else{
            nodeNext->prev = nodeNew;
        }
    } else if (index == -1){
        DLNode *nodeOld = list->last;
        nodeNew->prev = nodeOld;
        nodeOld->next = nodeNew;
        list->last = nodeNew;
    } else  /* index == 0 */{
        DLNode *nodeOld = list->first;
        nodeNew->next = nodeOld;
        nodeOld->prev = nodeNew;
        list->first = nodeNew;
    }
}

void *DLListGet(DLList *list, int index){
    if (list == NULL) return NULL;
    DLNode *node;
    if (index >= 0)  node =  DLNodeGet(list->first, index);
    else             node =  DLNodeGet(list->last, ++index);
    return DLNodeGetData(node);
}

size_t DLListLength(DLList *list){
    if (list == NULL || list->first == NULL) return 0;
    size_t length = 1;
    DLNode *node = list->first;
    while (!DLNodeIsLast(node)){
        node = node->next;
        length++;
    }
    return length;
}

DLNode *DLListRemoveAndGetNode(DLList *list, int index) {
    if (!list || !list->first) return NULL;

    DLNode *node = (index >= 0) ? DLNodeGet(list->first, index)
                                : DLNodeGet(list->last, ++index);
    if (!node) return NULL;

    DLNode *nodePrev = node->prev;
    DLNode *nodeNext = node->next;

    if (DLNodeIsFirst(node)) list->first = nodeNext;
    if (DLNodeIsLast(node))  list->last = nodePrev;

    if (nodePrev) nodePrev->next = nodeNext;
    if (nodeNext) nodeNext->prev = nodePrev;

    node->next = node->prev = NULL;
    return node;
}


void DLListRemove(DLList *list, int index){
    DLNode *node = DLListRemoveAndGetNode(list, index);
    DLNodeDestroy(node);
}

void *DLListRemoveAndGet(DLList *list, int index){
    DLNode *node = DLListRemoveAndGetNode(list, index);
    void *data = DLNodeGetData(node);
    DLNodeDestroy(node);
    return data;
}

void DLListTraverseAndApply(DLList *list, void (*func)(void *)){
    if (list == NULL) return;
    DLNode *nodeCurrent = list->first;
    while (nodeCurrent != NULL){
        func(nodeCurrent->data);
        nodeCurrent = nodeCurrent->next;
    }
}

void DLListPrintStructure(DLList *list){
    printf("DLList: \n");
    printf(" -- START -- \n");
    DLNode *node = list->first;
    while (node != NULL){
        if (node->prev == NULL) printf("NULL <-");
        else printf("<-");
        printf(" [%p] ", node->data);
        if (node->next == NULL) printf("-> NULL");
        else printf("->");
        node = node->next;
    }
    printf("\n -- END -- \n");
}








