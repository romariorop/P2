#include "LinkedList.c"
#include <stdio.h>


int main(){
    LinkedList* list = newLinkedList();
    addToLinkedListBack(list, 1);
    printDoublyLinkedListFowards(list);
    addToLinkedListBack(list, 2);
    printDoublyLinkedListFowards(list);
    addToLinkedListFront(list, 0);
    printDoublyLinkedListFowards(list);
    addToLinkedListFront(list, -1);
    printDoublyLinkedListFowards(list);
    addToLinkedListBack(list, 3);
    printDoublyLinkedListFowards(list);

    printf("backwards ->");
    printDoublyLinkedListBackwards(list);

    deleteFromLinkedList(list, 2);
    printDoublyLinkedListFowards(list);
    deleteFromLinkedList(list, 0);
    printDoublyLinkedListFowards(list);
    deleteFromLinkedList(list, 1);
    printDoublyLinkedListFowards(list);
    deleteFromLinkedList(list, -1);
    printDoublyLinkedListFowards(list);
    deleteFromLinkedList(list, 3);
    printDoublyLinkedListFowards(list);
    return 0;
}