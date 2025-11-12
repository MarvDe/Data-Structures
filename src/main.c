#include <stdio.h>
#include <List.h>
#include <Queue.h>
#include <Array.h>

void ListTest();
void QueueTest();
void ArrayTest();

int main(int argc, char *argv[]){
    //ListTest();
    //QueueTest();
    
    return 0;
}


void PrintInt(void *integer){
    if (integer == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d\n", *(int *)integer);
}

void ListTest(){

    int a[] = {1,2,3,4,5,6};

    List *list = ListCreate();
    for (int i = 0; i < sizeof(a) / sizeof(int); i++){
        ListAppend(list, a + i, 0);
    }
    
    printf("Printing List: \n");
    ListTraverseAndApply(list, PrintInt);
    
    printf("Removing First Element: \n");
    ListRemove(list, 0);
    ListTraverseAndApply(list, PrintInt);

    printf("Inserting 100 At Index 0\n");
    int b = 100;
    ListInsert(list, &b, 0, 0);
    ListTraverseAndApply(list, PrintInt);

    printf("Removing Last Element: \n");
    ListRemoveLast(list);
    ListTraverseAndApply(list, PrintInt);

    printf("Last Element: \n");
    PrintInt(ListGetLast(list));

    printf("Second Element: \n");
    PrintInt(ListGet(list, 1));

    printf("Length Of List: \n");
    printf("%llu\n", ListLength(list));

    printf("Removing And Showing Last Element: \n");
    PrintInt(ListRemoveAndGetLast(list));

    printf("Removing And Showing Second: \n");
    PrintInt(ListRemoveAndGet(list, 1));

    printf("Removing And Showing First: \n");
    PrintInt(ListRemoveAndGet(list, 0));

    printf("Final List: \n");
    ListTraverseAndApply(list, PrintInt);

}

void QueueTest(){

    int a[] = {1,2,3,4,5,6,7,8,9,10};
    Queue *queue = QueueCreate();
    
    printf("Enqueue Data: \n");
    for (int i = 0; i < sizeof(a) / sizeof(int); i++){
        Enqueue(queue, a + i, 0);
    }

    printf("Dequeue First Five Elements: \n");
    for (int i = 0; i < 5; i++){
        PrintInt(Dequeue(queue));
    }

    printf("Enqueue 100: \n");
    int b = 100;
    Enqueue(queue, &b, 0);

    printf("Deqeue Six Elements: \n");
    for (int i = 0; i < 6; i++){
        PrintInt(Dequeue(queue));
    }

    printf("Dequeue Empty Queue: \n");
    PrintInt(Dequeue(queue));

    QueueDestroy(queue);

}

void ArrayTest(){
    Array *array = ArrayCreate(10, sizeof(int));
    printf("First Element: \n");
    PrintInt(ArrayGet(array, 0));
    printf("Set Second Element To 100: \n");
    int b = 100;
    ArraySet(array, &b, 1);
    for (int i = 0; i < array->numOfElements; i++){
        PrintInt(ArrayGet(array, i));  
    }
    ArrayDestroy(array);
}