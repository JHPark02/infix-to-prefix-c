#define _CRT_SECURE_NO_WARNINGS
// 08.14.2022 
// For my assignment of Data Structure class

#include <stdio.h>
#include <string.h> //For strlen() #
#include <ctype.h> // For isalpha(), isdigit()

char stack[100];
int top = -1;

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
        printf("스택이 가득 찼습니다.");
    else
        stack[++top] = value;
}

char pop() {
    if (IsEmpty() == 1)
        printf("스택이 비었습니다.");
    else
        return stack[top--];
}

char top_() {
    if (IsEmpty() == 1)
        printf("스택이 비었습니다.");
    else
        return stack[top];
}

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    return 0;
}

int isdigit_(char temp)
{
    switch (temp)
    {
    case '0':
    case '9':
    case '8':
    case '7':
    case '6':
    case '5':
    case '4':
    case '3':
    case '2':
    case '1':
        return 1;

    default:
        return 0;
    }
}

char* infixToPostfix(char infix[])
{
    printf("infix in infixToPostfin() : %s\n", infix);

    static char output[10] = "";
    char infix_[12] = "";
    int len = 12;

    strcat(infix_, "(");
    strcat(infix_, infix);
    strcat(infix_, ")");

    printf("result : %s\n", infix_);


    for (int i = 0; i < len - 1; i++)
    {
        // If the scanned character is an
        // operand, add it to output
        printf("\n");
        printf("infix_[i] : %c\n", infix_[i]);
        printf("isdigit() : %d\n", isdigit_(infix_[i]));

        if (isdigit_(infix_[i])) // return is 
        {
            printf("get");
            //strcat(output, infix_[i]);
            //output += infix_[i];
            strncat(output, &infix_[i], 1);
            printf("ll%sll\n", output);
        }

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (infix_[i] == '(')
            push('(');

        // If the scanned character is an
        // ‘)’, pop and output from the stack
        // until an ‘(‘ is encountered.
        else if (infix_[i] == ')')
        {
            while (top_() != '(')
            {
                char temp2 = top_();
                strncat(output, &temp2, 1);
                pop();
            }

            // Remove '(' from the stack
            pop();
        }

        // Operator found
        else
        {
            printf("test %c\n", top_());
            char temp3;
            char ptemp;
            while (getPriority(infix_[i]) < getPriority(top_()))
            {
                temp3 = top_();
                strncat(output, &temp3, 1);
                ptemp = pop();
                printf("poped : %c\n", ptemp);
            }

            // Push current Operator on stack
            push(infix_[i]);
            printf("pushed : %c\n", infix_[i]);
        }
    }

    printf("output : %s\n", output);

    char temp4;

    while (IsEmpty() == 0)
    {
        printf("enter\n\n\n");
        temp4 = top_();
        strncat(output, &temp4 , 1);
        pop();
    }

    printf("output : %s\n", output);
    return (char*)output;
}

char* reverse(char infix[])
{
    printf("&&&\n");
    printf("%s\n", infix);
    printf("&&&\n");

    static char reversed_infix[10];
    int len = 10;
    int count = 0;

    for (int i = len - 2; i >= 0; i--)
    {
        printf("%d %d\n", i, count);
        reversed_infix[count] = infix[i];
        count++;
    }
    //reversed_infix[9]

    printf("***************\n");
    printf("%s\n", reversed_infix);
    printf("***************\n");

    return (char*)reversed_infix;
}

char* infixToPrefix(char infix[])
{
    printf("%s\n", infix);

    // variable infix is POINTER

    int len = strlen(infix);
    static char prefix[10];
    char postfix[10];
    char reversed_infix[10];

    // Reverse infix
    strcpy(reversed_infix, reverse(infix));

    printf("here\n");
    printf("reversed_infix : %s\n", reversed_infix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < len; i++)
    {
        if (reversed_infix[i] == '(')
            infix[i] = ')';
        else if (reversed_infix == ')')
            infix[i] = '(';
    }

    strcpy(postfix, infixToPostfix(reversed_infix));

    printf("postfix : %s\n", postfix);

    // Reverse postfix
    strcpy(prefix, reverse(postfix));

    printf("%s\n\n", prefix);

    return (char*)prefix;
}

int main(void)
{
    char infix[] = "3+5*4/8+6";
    printf("%c", infixToPrefix(infix));
    printf("\n\n\n");
    return 0;
}