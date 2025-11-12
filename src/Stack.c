#include <stdlib.h>

#include <Stack.h>
#include <List.h>

Stack *StackCreate(){
    Stack *stack = malloc(sizeof(Stack));
    stack->list = ListCreate();
    return stack;
}

void StackDestroy(Stack *stack){
    if (stack == NULL) return;
    ListDestroy(stack->list);
    free(stack);
}

void *StackPop(Stack *stack){
    if (stack == NULL) return NULL;
    return ListRemoveAndGet(stack->list, 0);
}

void StackPush(Stack *stack, void *data, char ownsData){
    if (stack == NULL) return;
    ListInsert(stack->list, data, ownsData, 0);
}

void *StackPeek(Stack *stack){
    if (stack == NULL) return NULL;
    return ListGet(stack->list, 0);
}