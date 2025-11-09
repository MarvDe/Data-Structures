#include <stdio.h>
#include <List.h>

void ListTest();

int main(int argc, char *argv[]){
    ListTest();
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
    
}