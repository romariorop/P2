#include <stdio.h>
#include "Stack.c"

/* 
Escreva uma função para verificar se parênteses, colchetes e chaves estão balanceados 
Ex: [[]]() (balanced)
    [[[)]] (not balanced)
*/

int isBalanced(char string[]){
    char open[] = "[{(";
    char close[] = "]})";
    Stack* stack = newStack();
    for(int i = 0; string[i]; ++i){
        for(int j = 0; j < 3; ++j){
            if(string[i] == open[j]){
                pushC(stack, string[i]);
            }
        }
        for(int j = 0; j < 3; ++j){
            if(string[i] == close[j]){
                if(stack->size > 0 && getTopC(stack) == open[j]){
                    pop(stack);
                }else {
                    return 0;
                }
            }
        }
    }
    return (stack->size == 0);
}

int main() {
    char balanced[]  = "[[]]()";
    char notBalanced[] = "[[[)]]";
    puts(isBalanced(balanced) == 1?"balanced":"not balanced");
    puts(isBalanced(notBalanced) == 1?"balanced":"not balanced");


    return 0;
}