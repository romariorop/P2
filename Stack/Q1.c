/*
    Escreva uma função para verificar se uma string é palíndromo
*/

#include <stdio.h>
#include "Stack.c"

int isPal(char string[]){
    Stack* stack = newStack();
    int i;
    for(i = 0; string[i]; ++i){
        pushC(stack, string[i]);
    }
    i = 0;
    while(!isEmpty(stack)){
        if(getTopC(stack) != string[i]){
            return 0;
        }
        pop(stack);
        ++i;
    }
    return 1;
}

int main() {
    char pal[] = "arara";
    char nPal[] = "ararar";


    if(isPal(pal)){
        puts("Palindromo");
    }else {
        puts("Not palindromo");
    }

    if(isPal(nPal)){
        puts("Palindromo");
    }else {
        puts("Not palindromo");
    }



    return 0;
}