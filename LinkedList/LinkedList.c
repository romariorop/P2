#include <stdio.h>
#include <stdlib.h>
#include "Node.c"

typedef struct LinkedList{
    int size;
    Node *head;
}LinkedList;

LinkedList *createList() {
    LinkedList *newList = (LinkedList*) malloc(sizeof(LinkedList));
    newList->size = 0;
    newList->head = NULL;
    return newList;
}

void addFront(LinkedList *list, int value) {
    list->head = appendInFront(list->head, value);
    list->size++;
}

void printList(LinkedList *list){
    Node *temp = list->head;
    if(temp == NULL){
        printf("Empty List!");
    }
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    puts("");
}

int isEmpty(LinkedList *list){
    return list->size == 0;
}

void reverseList(LinkedList *list) {
    Node *firstHead, *secondHead, *aux;
    if(list == NULL || list->size < 2)return;
    secondHead = list->head;
    firstHead = secondHead->next;
    secondHead->next = NULL;

    while(firstHead != NULL) {
        aux = firstHead->next;
        firstHead->next = secondHead;
        secondHead = firstHead;
        firstHead = aux;
    }

    list->head = secondHead;
}

int getMaxPos(LinkedList*list, int upper){
    int pos = 0;
    int cur = 0;
    int bigger = list->head->value;
    Node *current = list->head;
    while(current != NULL && cur < upper){
        if(current->value > bigger){
            bigger = current->value;
            pos = cur;
        }
        ++cur;
        current = current->next;
    }
    return pos;
}

void shiftNode(LinkedList*list, int begin, int end){
    int pos = 0;
    Node *current = list->head;
    Node *previous = NULL;
    Node *next;
    while(pos != begin){
        previous = current;
        current = current->next;
        ++pos;
    }
    while(pos < end - 1){
        if(previous == NULL){
            previous = current->next;
            current->next = previous->next;
            previous->next = current;
            list->head = previous;
        } else {
            next = current->next->next;
            previous->next = current->next;
            previous->next->next = current;
            current->next = next;
            previous = previous->next;
        }
        ++pos;
    }
}

void sortList(LinkedList* list){
    if(list == NULL || list->size < 2)return;
    for(int i = 0; i < list->size; ++i){
        int pos = getMaxPos(list, list->size-i);
        shiftNode(list, pos, list->size-i);
    }
}