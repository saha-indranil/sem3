// Write a C program to validate the parenthesis of an expression.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *s)
{
    int s_len = strlen(s);
    if (s_len < 2)
        return false;
    char *open = "({[";
    char *close = ")}]";
    char *stack = malloc(sizeof(char) * (s_len));
    int top = -1;
    while (*s != '\0')
    {
        for (int i = 0; i < 3; i++)
        {
            if (*s == open[i])
            {
                stack[++top] = *s;
                break;
            }
            if (*s == close[i])
            {
                if (top == -1)
                    return false;
                if (stack[top] == open[i])
                {
                    top--;
                    break;
                }
                else
                    return false;
            }
        }
        s++;
    }
    return (top == -1) ? true : false;
}

int main()
{
    char str[10];
    printf("Enter a String: ");
    gets(str);
    if (isValid(str))
        printf("Parenthesis is Matching!");
    else
        printf("Parenthesis is not Matching");
    return 0;
}

// OUTPUT

// Enter a String: [5*{7+1-(4/(2))}]
// Parenthesis is Matching!

// Enter a String: ({[]}]
// Parenthesis is not Matching