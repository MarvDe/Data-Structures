#include <stdlib.h>
#include <List.h>

typedef struct Node Node;
struct Node {
    char ownsData;
    void *data;
    struct Node *next;
};

List *ListCreate(){
    List *list = malloc(sizeof(List));
    list->next = NULL;
    return list;
}

Node *NodeCreate(void *data, char ownsData){
    Node *node = malloc(sizeof(Node));
    node->next = NULL;
    node->data = data;
    node->ownsData = ownsData;
    return node;
}

Node *NodeGet(Node *node, size_t index){
    if (index == 0 || node == NULL) return node;
    NodeGet(node->next, --index);
}

Node *NodeGetLast(Node *node){
    if (node->next == NULL) return node;
    NodeGetLast(node->next);
}

void NodeDestroy(Node *node){
    if (node == NULL) return;
    NodeDestroy(node->next);
    if (node->ownsData) free(node->data);
    free(node);
}

void ListDestroy(List *list){
    if (list == NULL) return;
    NodeDestroy(list->next);
}

void *ListGet(List *list, size_t index){
    if (list == NULL) return NULL;
    return NodeGet(list->next, index)->data;
}

void *ListGetLast(List *list){
    if (list == NULL) return NULL;
    return NodeGetLast(list->next)->data;
}

void ListAppend(List *list, void *data, char ownsData){
    if (list == NULL) return;
    if (list->next == NULL){
        Node *node = NodeCreate(data, ownsData);
       list->next = node; 
    } 
    else{
        Node *nodeCurrent = NodeGetLast(list->next);
        if (nodeCurrent == NULL) return;
        Node *node = NodeCreate(data, ownsData);
        nodeCurrent->next = node;
    }
}

void ListInsert(List *list, void *data, char ownsData, size_t index){
    if (list == NULL) return;
    Node *node = NodeCreate(data, ownsData);
    if (index == 0){
        Node *nodeNext = list->next;
        list->next = node;
        node->next = nodeNext;
    }
    else{
       Node *nodePrev = NodeGet(list->next, index-1); 
       if (nodePrev == NULL) return;
       Node *nodeCurrent = nodePrev->next;
       nodePrev->next = node;
       node->next = nodeCurrent;
    }
}

size_t ListLength(List *list){
    if (list == NULL || list->next == NULL) return 0;
    size_t length = 1;
    Node *nodeCurrent = list->next;
    while (nodeCurrent->next != NULL) {
        nodeCurrent = nodeCurrent->next;
        length++;
    }
    return length;
}

void *ListRemove(List *list, size_t index){
    if (list == NULL) return NULL;
    if (index == 0){
        if (list->next == NULL) return NULL;
        Node *nodeCurrent = list->next;
        list->next = list->next->next;
        return nodeCurrent->data;
    }
    else{
       Node *nodePrev = NodeGet(list->next, index-1); 
       if (nodePrev == NULL || nodePrev->next == NULL) return NULL;
       Node *nodeCurrent = nodePrev->next;
       nodePrev->next = nodePrev->next->next;
       return nodeCurrent->data;
    }
}

void *ListRemoveLast(List *list){
    if (list == NULL || list->next == NULL) return NULL;
    Node *nodePrev = list->next;
    if (nodePrev->next == NULL){

        list->next = NULL; 
    } 
    while (nodePrev->next->next != NULL) nodePrev = nodePrev->next; 
    Node *nodeCurrent = nodePrev->next;
    nodePrev->next = NULL;
    return nodeCurrent->data;
}

void ListTraverseAndApply(List *list, void (*func)(void *)){
    if (list == NULL) return;
    Node *nodeCurrent = list->next;
    while (nodeCurrent != NULL){
        func(nodeCurrent->data);
        nodeCurrent = nodeCurrent->next;
    }
}