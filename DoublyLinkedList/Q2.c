/* Escreva uma funlão que ao receber um número, cria um nó e insere de forma ordenada na lista. Guarde o ponteiro do elemento inserido para saber se na próxima inserçã
você deve ir para a esquerda ou para a direita */
#include "LinkedList.c"
#include <stdio.h>

void addToLinkedListInSortedWay(LinkedList* list, int value){
    if(list == NULL)return;
    Node* node = newNode(value);
    Node* iterator;
    Node* temp;
    if(list->size == 0){
        list->front = list->back = node;
    } else {
        iterator = list->lastInserted;
        while(value > iterator->value && iterator->next != NULL){
            iterator = iterator->next;
        }
        while(value < iterator->value && iterator->prev != NULL){
            iterator = iterator->prev;
        }
        if(value >= iterator->value) {
            if(iterator->next == NULL){
                iterator->next = node;
                node->prev = iterator;
                list->back = node;
            } else {
                temp = iterator->next;
                iterator->next = node;
                node->prev = iterator;
                node->next = temp;
                temp->prev = node;
            }
        }else {
            if(iterator->prev == NULL){
                iterator->prev = node;
                node->next = iterator;
                list->front = node;
            } else {
                temp = iterator->prev;
                temp->next = node;
                node->prev = temp;
                node->next = iterator;
                iterator->prev = node;
            }
        }
    }
    ++list->size;
    list->lastInserted = node;
}

int main() {

    LinkedList* list = newLinkedList();

    addToLinkedListInSortedWay(list, 1);
    printDoublyLinkedListFowards(list);
    addToLinkedListInSortedWay(list, 3);
    printDoublyLinkedListFowards(list);
    addToLinkedListInSortedWay(list, 2);
    printDoublyLinkedListFowards(list);
    addToLinkedListInSortedWay(list, 4);
    printDoublyLinkedListFowards(list);
    addToLinkedListInSortedWay(list, 7);
    printDoublyLinkedListFowards(list);
    addToLinkedListInSortedWay(list, 6);
    printDoublyLinkedListFowards(list);
    addToLinkedListInSortedWay(list, 10);
    printDoublyLinkedListFowards(list);
    addToLinkedListInSortedWay(list, 9);
    printDoublyLinkedListFowards(list);
    addToLinkedListInSortedWay(list, 8);
    printDoublyLinkedListFowards(list);
    addToLinkedListInSortedWay(list, 5);
    printDoublyLinkedListFowards(list);

    printf("Backwards teste-> ");
    printDoublyLinkedListBackwards(list);

    return 0;
}