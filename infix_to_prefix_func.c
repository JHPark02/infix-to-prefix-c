#include "infix_to_prefix_func.h"
#include "stack_func.h"

char stack[100];
int top = -1;

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    return 0;
}

int isNumber(char temp)
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
    static char output[10] = "";
    char infix_[12] = "";
    int len = 12;
    char temp;

    strcat(infix_, "(");
    strcat(infix_, infix);
    strcat(infix_, ")");

    printf("----------- Processes will appear below -----------\n");

    for (int i = 0; i < len - 1; i++)
    {
        // If the scanned character is an
        // operand, add it to output
        printf("current token : %c\n", infix_[i]);
        printf("isNumber() : %d\n", isNumber(infix_[i]));

        if (isNumber(infix_[i])) // return is 
        {
            strncat(output, &infix_[i], 1);
            printf("current output : %s\n", output);
            prtStack();
        }

        // If the scanned character is an
        // กฎ(กฎ, push it to the stack.
        else if (infix_[i] == '(')
        {
            push('(');
            printf("pushed : ( ");
            printf("current output : %s\n", output);
            prtStack();
        }


        // If the scanned character is an
        // กฎ)กฏ, pop and output from the stack
        // until an กฎ(กฎ is encountered.
        else if (infix_[i] == ')')
        {
            while (top_() != '(')
            {
                temp = pop();
                strncat(output, &temp, 1);
                printf("poped : %c\n", temp);
            }

            // Remove '(' from the stack
            pop();

            printf("poped : )\n");
            printf("current output : %s\n", output);
            prtStack();
        }

        // Operator found
        else
        {
            while (getPriority(infix_[i]) < getPriority(top_()))
            {
                temp = pop();
                strncat(output, &temp, 1);
                printf("poped : %c\n", temp);
            }

            // Push current Operator on stack
            push(infix_[i]);
            printf("pushed : %c\n", infix_[i]);
            printf("current output : %s\n", output);
            prtStack();
        }
        printf("\n");
    }
    printf("---------------------- done -----------------------\n\n");

    while (IsEmpty() == 0)
    {
        temp = top_();
        strncat(output, &temp, 1);
        pop();
        printf("poped : %c\n", temp);
    }

    return (char*)output;
}

char* reverse(char infix[])
{
    static char reversed_infix[10];
    int len = 10;
    int count = 0;

    for (int i = len - 2; i >= 0; i--)
    {
        reversed_infix[count] = infix[i];
        count++;
    }

    return (char*)reversed_infix;
}

char* infixToPrefix(char infix[]) // variable "infix" is a POINTER
{
    // Declare variable as static because this fuction will return this as a pointer
    static char prefix[10];

    int len = strlen(infix);
    char postfix[10];
    char reversed_infix[10];

    // Reverse infix
    strcpy(reversed_infix, reverse(infix));

    printf("reversed_infix : %s\n\n", reversed_infix);

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

    printf("Reversed postfix : %s\n\n", prefix);

    return (char*)prefix;
}