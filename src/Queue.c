#include <stdlib.h>

#include <Queue.h>

typedef struct QNode QNode;
struct QNode{
    struct QNode *next;
    struct QNode *prev;
    void *data;
    char ownsData;
};

QNode *QNodeCreate(void *data, char ownsData);
void *QNodeGetData(QNode *node);
void QNodeDestroyRec(QNode *node);
void QNodeDestroy(QNode *node);


Queue *QueueCreate(){
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL) return NULL;
    queue->head = NULL;
    queue->tail = NULL;
}

void QueueDestroy(Queue *queue){
    QNodeDestroyRec(queue->head);
    free(queue);
}

QNode *QNodeCreate(void *data, char ownsData){
    QNode *node = malloc(sizeof(QNode));
    if (node == NULL) return NULL;
    node->next = NULL;
    node->prev = NULL;
    node->data = data;
    node->ownsData = ownsData;
    return node;
}

void *QNodeGetData(QNode *node){
    if (node == NULL) return NULL;
    node->ownsData = 0;
    return node->data;
}

void QNodeDestroy(QNode *node){
    if (node == NULL) return;
    if (node->ownsData) free(node->data);
    free(node);
}

void QNodeDestroyRec(QNode *node){
    if (node == NULL) return;
    QNodeDestroyRec(node->next);
    QNodeDestroy(node);
}

void Enqueue(Queue *queue, void *data, char ownsData){
    if (queue == NULL) return;
    QNode *node = QNodeCreate(data, ownsData);
    if (queue->tail == NULL){
        queue->tail = node;
        queue->head = node;
    } 
    else{
        node->prev = queue->tail;
        queue->tail->next = node;
        queue->tail = node; 
    }
}

void *Dequeue(Queue *queue){
    if (queue == NULL || queue->head == NULL) return NULL;
    QNode *nodeHead = queue->head;
    QNode *nodeHeadNew = queue->head->next;
    if (nodeHeadNew == NULL){
        queue->head = NULL;
        queue->tail = NULL;
    } 
    else{
        nodeHeadNew->prev = NULL;
        queue->head = nodeHeadNew;
    }
    void *data = QNodeGetData(nodeHead);
    QNodeDestroy(nodeHead);
    return data;
}