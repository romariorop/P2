/*Escreva uma funcão para inverter uma lista encadeada usando somente uma “passada” pela lista. */
#include <stdio.h>
#include "LinkedList.c"
void reverseList(LinkedList* list){
    if(list == NULL)return;
    if(list->size == 1)return;
    Node* newFront = list->front;
    Node* temp;
    Node* iterator = list->front->next;
    newFront->next = NULL;
    list->back = newFront;
    while(iterator != NULL){
        temp = iterator->next;
        iterator->next = newFront;
        newFront = iterator;
        iterator = temp;
    }
    list->front = newFront;
}

int main() {
    LinkedList* list = newLinkedList();
    for(int i = 0; i < 10; ++i){
        addToLinkedListBack(list, i);
    }
    printLinkedList(list);
    reverseList(list);  
    printLinkedList(list);
    return 0;
}