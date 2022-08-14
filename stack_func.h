#pragma once
#include <stdio.h>

extern char stack[100];
extern int top;

int IsEmpty();
int IsFull();
void push(char value);
char pop();
char top_();
void prtStack();