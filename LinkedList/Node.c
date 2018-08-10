#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* createNode(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Node* appendInFront(Node* head, int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->next = head;
    newNode->value = value;
    return newNode;
}