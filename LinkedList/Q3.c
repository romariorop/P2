#include "LinkedList.c"
#include <stdio.h>

char text[] = "quando forem compilar meus codigos usem a flag -w pra remover os warnings =D";

int main() {
    int frequency[260] = {0};
    for(int i = 0; text[i]; ++i){
        frequency[text[i]]++;
    }
    LinkedList* list = newLinkedList();
    // se quiserem todas os caracteres é só fazer um for de 0~255 
    for(int i = 'a'; i < 'z'; ++i){
        addToLinkedListBackWithFrequency(list, (char)i, frequency[i]);
    }
    for(int i = 'A'; i < 'Z'; ++i){
        addToLinkedListBackWithFrequency(list, (char)i, frequency[i]);
    }
    printLinkedListQ3(list);
    return 0;
}