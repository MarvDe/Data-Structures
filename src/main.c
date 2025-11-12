#include <stdio.h>
#include <List.h>
#include <Queue.h>
#include <Array.h>
#include <DLList.h>

void ListTest();
void DLListTest();
void QueueTest();
void ArrayTest();

int main(int argc, char *argv[]){
    //ListTest();
    //QueueTest();
    //ArrayTest();
    DLListTest();
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

void DLListTest(){

    int a[] = {1,2,3,4,5,6};

    DLList *list = DLListCreate();
    for (int i = 0; i < sizeof(a) / sizeof(int); i++){
        DLListInsert(list, a + i, 0, -1);
    }
    DLListPrintStructure(list);
    printf("Printing List: \n");
    DLListTraverseAndApply(list, PrintInt);

    printf("Removing First Element: \n");
    DLListRemove(list, 0);
    DLListTraverseAndApply(list, PrintInt);

    printf("Inserting 100 At Index 0\n");
    int b = 100;
    DLListInsert(list, &b, 0, 0);
    DLListTraverseAndApply(list, PrintInt);

    printf("Removing Last Element: \n");
    DLListRemove(list, -1);
    DLListTraverseAndApply(list, PrintInt);

    printf("Last Element: \n");
    PrintInt(DLListGet(list, -1));

    printf("Second Element: \n");
    PrintInt(DLListGet(list, 1));

    printf("Length Of List: \n");
    printf("%llu\n", DLListLength(list));

    printf("Removing And Showing Last Element: \n");
    PrintInt(DLListRemoveAndGet(list, -1));

    printf("Removing And Showing Second: \n");
    PrintInt(DLListRemoveAndGet(list, 1));

    printf("Removing And Showing First: \n");
    PrintInt(DLListRemoveAndGet(list, 0));

    DLListPrintStructure(list);
    
    printf("Inserting 55 At Index -2: \n");
    int c = 55;
    DLListInsert(list, &c, 0, -2);

    printf("Inserting 24 At Index 2: \n");
    int d = 24;
    DLListInsert(list, &d, 0, 2);

    printf("Changing Value At Index 1: \n");
    int *ptr = DLListGet(list, 1);
    *ptr = 666;

    printf("Final List: \n");
    DLListTraverseAndApply(list, PrintInt);
    
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
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    Array *array = ArrayCreate(10, sizeof(int));
    printf("Add Elements: \n");
    ArraySet(array, a, 10, 0);
    for (int i = 0; i < array->numOfElements; i++){
        PrintInt(ArrayGet(array, i));  
    }
    printf("First Element: \n");
    PrintInt(ArrayGet(array, 0));
    printf("Set Second Element To 100: \n");
    int b = 100;
    ArraySet(array, &b, 1, 1);
    for (int i = 0; i < array->numOfElements; i++){
        PrintInt(ArrayGet(array, i));  
    }
    ArrayDestroy(array);
}