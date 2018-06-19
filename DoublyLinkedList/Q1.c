/* escreva uma função que criauma lista duplamente encadeada circular 

    basta tratar os casos na hora de inserir e deletar na lista e alterar os ponteiros do back e do front
    obs: essa eu n testei 

*/
#include "LinkedList.c"


void updateBackAndFrontPointers(LinkedList* list){
    if(list == NULL)return;
    list->front->prev = list->back;
    list->back->next = list->front;
}

void addToLinkedListFront(LinkedList* list, int value){
    if(list == NULL)return;
    Node* node = newNode(value);
    if(list->size == 0){
        list->front = list->back = node;
       updateBackAndFrontPointers(list);
    } else {
        node->next = list->front;
        list->front->prev = node;
        list->front = node;
        updateBackAndFrontPointers(list);
    }
    ++list->size;
}

void addToLinkedListBack(LinkedList* list, int value){
    if(list == NULL)return;
    Node* node = newNode(value);
    if(list->size == 0){
        list->front = list->back = node;
        updateBackAndFrontPointers(list);
    } else {
        node->prev = list->back;
        list->back->next = node;
        list->back = node;
        updateBackAndFrontPointers(list);
    }
    ++list->size;
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
        updateBackAndFrontPointers(list);
        free(temp);
        list->size--;
    }else if(list->back->value == value){
        Node* temp = list->back;
        list->back = list->back->prev;
        updateBackAndFrontPointers(list);
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