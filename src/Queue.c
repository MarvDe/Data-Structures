#include <stdlib.h>

#include <Queue.h>

Queue *QueueCreate(){
    Queue *queue = malloc(sizeof(Queue));
    queue->Head = ListCreate(NULL, 0);
}

void QueueDestroy(Queue *queue){
    ListDestroy(queue->Head);
}

void Enqueue(Queue *queue, void *data, char ownsData){
    List *listNew = ListCreate(data, ownsData);
    ListAppend(queue->Head, listNew);
}

void *Dequeue(Queue *queue);