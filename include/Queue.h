#ifndef QUEUE_H
#define QUEUE_H

#include <List.h>

typedef struct Queue Queue;
struct Queue{
    List *Head;
};

Queue *QueueCreate();
void QueueDestroy(Queue *queue);
void Enqueue(Queue *queue, void *data);
void *Dequeue(Queue *queue);

#endif