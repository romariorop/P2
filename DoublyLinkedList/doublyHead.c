#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    struct Node* next;
    struct Node* prev;
    int value;
}Node;


Node* createList() {
    return NULL;
}

Node* newNode(int value) {
    Node* node = (Node*) malloc (sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Node* addFront(Node* head, int value) {
    Node* node = newNode(value);
    if(head == NULL)return node;
    node->next = head;
    head->prev = node;
    return node;
}

int main() {
    Node * head = createList();

    head = addFront(head, 10);
}