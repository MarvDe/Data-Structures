#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue Queue;
struct Queue{
    struct QNode *head;
    struct QNode *tail;
};

Queue *QueueCreate();
void QueueDestroy(Queue *queue);
void Enqueue(Queue *queue, void *data, char ownsData);
void *Dequeue(Queue *queue);

#endif