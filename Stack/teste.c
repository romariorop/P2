#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

typedef struct List{
    Node *head;
}List;

Node *createNode(int value){
    Node* node = (Node*) malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    return node;
}

List *createList(){
    List* list = (List*) malloc(sizeof(List));
    list->head = createNode(-1);
    return list;
}

void addFront(List* list, int value){
    Node *node = createNode(value);
    node->next = list->head->next;
    list->head->next = node;
}

void printList(List *list){
    printf("Lista = ");
    Node *head = list->head;
    if(head->next == NULL){
        puts("vazio");
    }else{
        head = head->next;

        while(head != NULL){
            printf("%d ", head->value);
            head = head->next;
        }
        puts("");
    }
}

int achaPosMaior(List* list, int upper){
    int maior = -2;
    int pos = -1;
    Node* head = list->head;
    head = head->next;
    int i = 0;
    while(head != NULL && i < upper){
        if(head->value > maior){
            maior = head->value;
            pos = i;
        }
        head = head->next;
        ++i;
    }
    return pos;
}

void deslocaAteFinal(List *list, int primeiro, int ultimo){
    Node* anterior = list->head;
    Node* atual = anterior->next;
    Node* proximo;
    int i = 0;
    while(i < primeiro){
        anterior = atual;
        atual = atual->next;
        ++i;
    }
    printf("%d %d\n", anterior->value, atual->value); // estamos no maior
    
    while(i < ultimo - 1){
        proximo = atual->next;
        anterior->next = proximo;
        atual->next = proximo->next;
        proximo->next = atual;
        atual = proximo;
        ++i;
        anterior = atual;
        atual = atual->next;
        printf("%d %d\n", i, ultimo);
    }
    

    printf("acabou\n");

}

int main() {
    int x;
    List *list = createList();
    while(scanf("%d", &x) != EOF){
        addFront(list, x);
    }
    printList(list);

    int posMaior = achaPosMaior(list, 7);
    printf("posicao do maior = %d\n", posMaior);
    deslocaAteFinal(list, 3, 7);
    printList(list);
    return 0;
}