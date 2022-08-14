// 08.14.2022 
// For my assignment of Data Structure class

// Step 1: Reverse the infix expression i.e A+B*C will become C*B+A. Note while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
// Step 2: Obtain the “nearly” postfix expression of the modified expression i.e CB * A + .
// Step 3 : Reverse the postfix expression.Hence in our example prefix is + A * BC.
#include <stdio.h>
#include <string.h> //For strlen()

char infixToPostfix(char infix[], int len)
{
    char output[len];

    infix = '(' + infix + ')';
    

    for (int i = 0; i < len; i++)
    {
        
    }
}

char reverse(char infix[])
{
    char reversed_infix[len];

    for (int i = len, int count = 0; i >= 0; i--, count++)
        reversed_infix[count] = infix[i];
    
    return reversed_infix;
}

char infixToPrefix(char infix[])
{
	// variable infix is POINTER

	int len = strlen(infix);
    char prefix[len];

	// Reverse infix
	reversed_infix = reverse(infix)

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < len; i++)
    {
        if (reversed_infix[i] == '(')
            infix[i] = ')';
        else if (reversed_infix == ')')
            infix[i] = '(';
    }
    
    prefix = infixToPostfix()

	printf("%d\n", len);
	printf("23");

	return 'c';
}

int main(void)
{
	char infix[] = "x+y*z/w+u";
	printf("%c", infixToPrefix(infix));
	printf("\n");
	return 0;
}