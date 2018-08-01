#include <stdlib.h>
#include <stdio.h>
typedef struct node_ {
    int value;
    struct Node* next;
    struct Node* previous;
}Node;

typedef struct linkedList_ {
    Node* front;
    Node* back;
    int size;
}LinkedList;

Node* newNode(int x){
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = x;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

LinkedList* newLinkedList(){
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->size = 0;
    list->front = NULL;
    list->back = NULL;
    return list;
}

int isEmpty(LinkedList* l){
    if(l == NULL)return 1;
    return(l->size == 0);
}

void add_front(LinkedList* list, int value){
    Node* node = newNode(value);
    if(list->size == 0){
        list->size = 1;
        list->front = list->back = node;
    } else {
        node->next = list->front;
        list->front->previous = node;
        list->front = node;
        list->size++;
    }
}

void add_back(LinkedList* list, int value){
    Node* node = newNode(value);
    if(list->size == 0){
        list->size = 1;
        list->front = list->back = node;
    } else {
        node->previous = list->back;
        list->back->next = node;
        list->back = node;
        list->size++;
    }
}

void print_fowards(LinkedList* list){
    if(list == NULL || list->size == 0)return;
    Node* node = list->front;
    while(node != NULL){
        printf("%d ", node->value);
        node = node->next;
    }
    puts("");
}

void print_backwards(LinkedList* list){
    if(list == NULL || list->size == 0)return;
    Node* node = list->back;
    while(node != NULL){
        printf("%d ", node->value);
        node = node->previous;
    }
    puts("");
}
void removeFromList(LinkedList* list, int value) {
    if(list == NULL || list->size == 0)return;
    Node* aux;
    Node* current;
    if(list->front->value == value){
        aux = list->front;
        list->front = list->front->next;
        list->front->previous = NULL;
        list->size--;
        free(aux);
    } else if(list->back->value == value){
        aux = list->back;
        list->back = list->back->previous;
        list->back->next = NULL;
        list->size--;
        free(aux);
    } else {
        current = list->front;
        while(current != NULL){
            if(current->value == value){
                Node* nodePrevious = current->previous;
                Node* nodeNext = current->next;
                nodePrevious->next = nodeNext;
                nodeNext->previous = nodePrevious;
                list->size--;
                free(current);
                return;
            }
            current = current->next;
        }
    }
}

int main() {
    LinkedList* list = newLinkedList();
    add_back(list, 1);
    add_front(list, 2);
    add_back(list, 3);
    add_front(list, 4);
    add_back(list, 5);
    add_front(list, 6);

    print_fowards(list);
    print_backwards(list);

    removeFromList(list, 5);
    print_fowards(list);
    print_backwards(list);
}