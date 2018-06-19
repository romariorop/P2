/* Escreva uma função que ordena em ordem crescente uma lista encadeada sem criar uma nova lista. */

#include <stdio.h>
#include "LinkedList.c"


void sortLinkedList(LinkedList* list) {
    if(list == NULL)return;
    if(list->size == 1)return;
    Node* front = list->front;
    Node* iterator;
    int temp;
    while(front->next != NULL){
        iterator = front->next;

        while(iterator != NULL){
            if(front->value > iterator->value) {
                temp = front->value;
                front->value = iterator->value;
                iterator->value = temp;
            }
            iterator = iterator->next;
        }

        front = front->next;
    }
}

int main() {
    LinkedList* list = newLinkedList();

    for(int i = 0; i < 10; ++i){
        if(i&1)addToLinkedListBack(list, i);
        else addToLinkedListBack(list, -i);
    }

    printLinkedList(list);
    sortLinkedList(list);
    printLinkedList(list);

    return 0;
}