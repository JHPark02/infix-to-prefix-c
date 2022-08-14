#include "calculate.h"
#include "stack_func.h"

int calculatePrefix(char prefix[])
{
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) 
    {
        if (isNumber(prefix[i]))
            push(prefix[i] - '0');
        else 
        {
            int o1 = pop();
            int o2 = pop();

            switch (prefix[i]) 
            {
            case '+':
                push(o1 + o2);
                break;
            case '-':
                push(o1 - o2);
                break;
            case '*':
                push(o1 * o2);
                break;
            case '/':
                push(o1 / o2);
                break;
            }
        }
    }
    return pop();
}