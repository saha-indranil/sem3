// Write a C program to reverse a string using appropriate ADT. (Assignment 2)
// Write a C program to reverse a string using stack. (Assignment 6)

#include <stdio.h>
#include <string.h>
#define MAX 10

char stack[MAX];
int top = -1;
void push(char);
char pop(void);

int main()
{
    char str[MAX];
    int len, i;
    printf("Enter a String: ");
    gets(str);
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        push(str[i]);
    }
    for (i = 0; i <= len; i++)
    {
        str[i] = pop();
    }
    printf("Reversed String is: %s", str);
    return 0;
}

void push(char c)
{
    if (top == MAX - 1)
        printf("Stack Overflow!");
    else
    {
        top++;
        stack[top] = c;
    }
}

char pop(void)
{
    char c;
    if (top == -1)
    {
        return '\0';
    }
    else
    {
        c = stack[top];
        top--;
        return c;
    }
}

// OUTPUT
// Enter a String: good day
// Reversed String is: yad doog