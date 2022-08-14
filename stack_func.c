#include "stack_func.h"

int IsEmpty() {
    if (top < 0)
        return 1;
    else
        return 0;
}

int IsFull() {
    if (top >= 100 - 1)
        return 1;
    else
        return 0;
}

void push(char value) {
    if (IsFull() == 1)
        printf("Stack is Full.");
    else
        stack[++top] = value;
}

char pop() {
    if (IsEmpty() == 1)
        printf("Stack is empty.");
    else
        return stack[top--];
}

char top_() {
    if (IsEmpty() == 1)
        printf("Stack is empty.");
    else
        return stack[top];
}

void prtStack()
{
    printf("current stack : ");
    for (int i = 0; i <= top; i++)
        printf("%c", stack[i]);
    printf("\n");
}