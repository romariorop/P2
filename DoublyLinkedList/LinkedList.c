#include <stdlib.h>
#include <stdio.h>

typedef struct _node{
    struct Node* next;
    struct Node* prev;
    int value;
}Node;

typedef struct _linkedList{
    Node* front;
    Node* back;
    Node* lastInserted; // only for Q2
    int size;
}LinkedList;

Node* newNode(int x){
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = x;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

LinkedList* newLinkedList(){
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->size = 0;
    list->front = NULL;
    list->back = NULL;
    list->lastInserted = NULL;
    return list;
}

void addToLinkedListFront(LinkedList* list, int value){
    if(list == NULL)return;
    Node* node = newNode(value);
    if(list->size == 0){
        list->front = list->back = node;
    } else {
        node->next = list->front;
        list->front->prev = node;
        list->front = node;
    }
    ++list->size;
}

void addToLinkedListBack(LinkedList* list, int value){
    if(list == NULL)return;
    Node* node = newNode(value);
    if(list->size == 0){
        list->front = list->back = node;
    } else {
        node->prev = list->back;
        list->back->next = node;
        list->back = node;
    }
    ++list->size;
}

void printDoublyLinkedListFowards(LinkedList* list){
    if(list == NULL)return;
    Node* iterator = list->front;
    while(iterator != NULL){
        printf("%d ", iterator->value);
        iterator = iterator->next;
    }
    puts("");
}

void printDoublyLinkedListBackwards(LinkedList* list) {
    if(list == NULL)return;
    Node* iterator = list->back;
    while(iterator != NULL){
        printf("%d ", iterator->value);
        iterator = iterator->prev;
    }
    puts("");
}

void deleteFromLinkedList(LinkedList* list, int value){
    if(list == NULL)return;
    if(list->size == 1){
        free(list->front);
        list->size = 0;
        list->front = list->back = NULL;
    }else if(list->front->value == value){
        Node* temp = list->front;
        list->front = list->front->next;
        list->front->prev = NULL;
        free(temp);
        list->size--;
    }else if(list->back->value == value){
        Node* temp = list->back;
        list->back = list->back->prev;
        list->back->next = NULL;
        free(temp);
        --list->size;
    }else {
        Node* iterator = list->front;
        Node* prev;
        Node* next;
        while(iterator!= NULL){
            if(iterator->value == value){
                prev = iterator->prev;
                prev->next = iterator->next;
                next = iterator->next;
                next->prev = iterator->prev;
                free(iterator);
                list->size--;
                return;
            }
            iterator = iterator->next;
        }
    }
}