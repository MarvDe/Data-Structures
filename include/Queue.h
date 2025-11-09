#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node Node;

typedef struct Queue Queue;
struct Queue{
    Node *head;
    Node *tail;
};

Queue *QueueCreate();
void QueueDestroy(Queue *queue);
void Enqueue(Queue *queue, void *data);
void *Dequeue(Queue *queue);

#endif