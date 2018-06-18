#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.c"

int main(){
    
    LinkedList* list = newLinkedList();
    addToLinkedListFront(list, 1);
    printLinkedList(list);  
    printf("size = %d\n", getLinkedListSize(list));
    addToLinkedListBack(list, 2);
    printLinkedList(list);
    printf("size = %d\n", getLinkedListSize(list));
    addToLinkedListBack(list, 3);
    printLinkedList(list);
    printf("size = %d\n", getLinkedListSize(list));
    addToLinkedListFront(list, 0);
    printLinkedList(list);
    printf("size = %d\n", getLinkedListSize(list));
    removeFromLinkedList(list, 2);
    printLinkedList(list);
    printf("size = %d\n", getLinkedListSize(list));
    removeFromLinkedList(list, 3);
    printLinkedList(list);
    printf("size = %d\n", getLinkedListSize(list));
    removeFromLinkedList(list, 0);
    printLinkedList(list);
    printf("size = %d\n", getLinkedListSize(list));
    removeFromLinkedList(list, 1);
    printLinkedList(list);
    printf("size = %d\n", getLinkedListSize(list));
    
    
    return 0;
}