// 08.14.2022 
// Assignment of Data Structure class

#include "infix_to_prefix_func.h"
#include "calculate.h"

int main(void)
{
    char infix[10] = "3+8*4/8+6";
    char result[10];

    printf("This is a program that can convert infix to prefix.\n\n");

    printf("This program takes some following steps.\n\n");

    printf("step1. Reverse the origin infix equation.\n");
    printf("step2. Convert the reversed infix equation to postfix equation.\n");
    printf("step3. This is the last step. Reverse the postfix equation. Then this is the result, prefix equation.\n\n");

    printf("infix : %s\n\n", infix);
    printf("Invoking infixToPreFix function..\n\n");

    strcpy(result, infixToPrefix(infix));

    printf("result : %s\n\n", result);

    printf("calculate : %d", calculatePrefix(result));

    return 0;
}