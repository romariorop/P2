#include <stdio.h>
#include "LinkedList.c"

int main(){
    LinkedList* list = createList();
    for(int i = 9; i >= 0; --i)addFront(list, i);
    printList(list); // expected 0 1 2 3 4 5 6 7 8 9
    reverseList(list);
    printList(list);// expected 9 8 7 6 5 4 3 2 1 0
    addFront(list, 25);
    addFront(list, -1);
    sortList(list);
    printList(list);
    return 0;
}