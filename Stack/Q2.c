#include <stdio.h>
#include "Stack.c"

// Escreva uma função para converter um númemro decimal para binário;

int decToBin(int x){
    if(x == 0)return x;
    Stack* stack = newStack();
    while(x){
        push(stack, x%2);
        x/=2;
    }
    int ans = 0;
    while(stack->size != 0){
        ans = ans*10 + getTop(stack);
        pop(stack);
    }
    return ans;
}

int main(){

    int A[] = {2, 3, 4, 5, 6};
    for(int i = 0; i < 5; ++i){
        printf("dec = %d / bin = %d\n", A[i], decToBin(A[i]));
    }
    return 0;
}