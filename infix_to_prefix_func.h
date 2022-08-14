#pragma once
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int getPriority(char C);
int isNumber(char temp);

char* infixToPostfix(char infix[]);
char* infixToPrefix(char infix[]);
char* reverse(char infix[]);