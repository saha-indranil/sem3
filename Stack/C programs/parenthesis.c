// Write a C program to validate the parenthesis of an expression.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

void createStack(struct stack *s);
void push(struct stack *s, char val);
char pop(struct stack *s);
char peek(struct stack *s);
bool isOpening(char c);
bool isMatching(char a, char b);

int main()
{
    char str[10];
    printf("Enter Parenthesis:\n");
    scanf("%s", str);

    struct stack *s;
    s->size = strlen(str);
    createStack(s);
    int i, flag = 1;
    for (i = 0; i < s->size; i++)
    {
        char curr = str[i];
        if (isOpening(curr))
        {
            push(s, curr);
        }
        else
        {
            if (s->top == -1)
            {
                flag = 0;
                break;
            }
            else if (!isMatching(peek(s), curr))
            {
                flag = 0;
                break;
            }
            else
                pop(s);
        }
    }
    if (s->top == -1)
        flag = 1;
    if (flag == 1)
        printf("Parenthesis are matching!!!");
    else
        printf("Parenthesis are not matching");
    return 0;
}

void createStack(struct stack *s)
{
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
}

void push(struct stack *s, char val)
{
    if (s->top == s->size - 1)
    {
        printf("Stack Overflow!\n", val);
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}

char pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow!\n");
        return ' ';
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

char peek(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char val = s->arr[s->top];
        return val;
    }
}

bool isOpening(char c)
{
    if (c == '(' || c == '{' || c == '[')
        return true;
    return false;
}

bool isMatching(char a, char b)
{
    if (a == '(' && b == ')')
        return true;
    if (a == '{' && b == '}')
        return true;
    if (a == '[' && b == ']')
        return true;
    return false;
}

// OUTPUT 1
// Enter Parentheses:
// {[[]()]}
// Parentheses are matching!!!

// OUTPUT 2
// Enter Parentheses:
// [(])
// Parentheses are not matching