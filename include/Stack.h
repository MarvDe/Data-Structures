#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;
struct Stack{
    struct List *list;
};

Stack *StackCreate();
void StackDestroy(Stack *stack);
void *StackPop(Stack *stack);
void StackPush(Stack *stack, void *data, char ownsData);

#endif