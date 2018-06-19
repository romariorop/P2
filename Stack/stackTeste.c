#include <stdio.h>
#include "Stack.c"


int main() {


    Stack* stack  = newStack();

    push(stack, 1);
    printf("%d\n", getTop(stack));
    push(stack, 2);
    printf("%d\n", getTop(stack));
    push(stack, 3);
    printf("%d\n", getTop(stack));
    pop(stack);
    printf("%d\n", getTop(stack));
    pop(stack);
    printf("%d\n", getTop(stack));
    pop(stack);


    return 0;
}