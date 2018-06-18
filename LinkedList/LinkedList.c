#include <stdlib.h>

typedef struct node_ {
    int value;
    struct Node *next;
}Node;

typedef struct linkedList_ {
    Node *front;
    Node *back;
    int size;
}LinkedList;

Node* newNode(int x){
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = x;
    node->next = NULL;
    return node;
}

LinkedList* newLinkedList(){
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->size = 0;
    list->front = NULL;
    list->back = NULL;
    return list;
}

int getLinkedListSize(LinkedList* list){
    if(list == NULL){
        return -1;
    }
    return list->size;
}

void addToLinkedListFront(LinkedList* list, int value) {
    Node* node = newNode(value);
    if(list->size == 0){
        list->front = list->back = node;
    } else {
        node->next = list->front;
        list->front = node;
    }
    ++list->size;
}

void addToLinkedListBack(LinkedList* list, int value) {
    Node* node = newNode(value);
    if(list->size == 0){
        list->front = list->back = node;
    } else {
        list->back->next = node;
        list->back = node;
    }
    ++list->size;
}

void removeFromLinkedList(LinkedList* list, int value){
    if(list == NULL)return;
    if(list->size == 1 && list->front->value == value){
        free(list->front);
        --list->size;
        list->front = list->back = NULL;
    } else if(list->size > 1) {
        Node* previous = list->front;
        Node* current = previous->next;
        if(previous->value == value){
            list->front = current;
            free(previous);
            --list->size;
            return;
        }
        while(current != NULL){
            if(current->value == value){
                previous->next = current->next;
                --list->size;
                free(current);
                return;
            }
            previous = previous->next;
            current = current->next;
        }
    }

}

void printLinkedList(LinkedList* list) {
    if(list == NULL)return;
    Node* temp = list->front;
    while(temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
