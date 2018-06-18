/* Dadas duas listas encadeadas A e B, escreva uma função para verificar se B é um subconjunto de A */
#include <stdio.h>
#include "LinkedList.c"

int belongToList(LinkedList* list, int value){
    if(list == NULL)return 0;
    Node* temp = list->front;
    while(temp != NULL){
        if(temp->value == value){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int bIsSubsetOfA(LinkedList* A, LinkedList* B){
    if(B == NULL){//conjunto vazio pertence a todos os conjuntos(eu acho rs)
        return 1;
    }
    if(A == NULL){
        return 0;
    }
    Node* temp = B->front;
    while(temp != NULL){
        if(belongToList(A, temp->value) == 0){
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

int main() {
    LinkedList* list = newLinkedList();
    LinkedList* subconjunto = newLinkedList();
    LinkedList* conjuntoQualquer = newLinkedList();

    for(int i = 0; i < 10; ++i) {
        addToLinkedListBack(list, i);
    }
    for(int i = 3; i < 8; ++i) {
        addToLinkedListBack(subconjunto, i);
    }

    addToLinkedListBack(conjuntoQualquer, 11);
    addToLinkedListBack(conjuntoQualquer, 7);

    puts(bIsSubsetOfA(list, subconjunto) ? "subconjunto" : "n subconjunto");
    puts(bIsSubsetOfA(list, conjuntoQualquer) ? "subconjunto" : "n subconjunto");

    return 0;
}