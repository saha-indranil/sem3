// Write a C program to validate the parenthesis of an expression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

void createStack(struct stack *s);
int isEmpty(struct stack *s);
int isFull(struct stack *s);
void push(struct stack *s, char val);
char pop(struct stack *s);
char peek(struct stack *s);
int isOpening(char c);
int isMatching(char a, char b);

int main()
{
    char str[10];
    printf("Enter Parentheses:\n");
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
            if (isEmpty(s))
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
    if (isEmpty(s))
        flag = 1;
    if (flag == 1)
        printf("\nParentheses are matching!!!");
    else
        printf("\nParentheses are not matching");
    return 0;
}

void createStack(struct stack *s)
{
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    printf("Stack is created successfully\n");
}

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s, char val)
{
    if (isFull(s))
    {
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
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
    if (isEmpty(s))
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

int isOpening(char c)
{
    if (c == '(' || c == '{' || c == '[')
    {
        return 1;
    }
    return 0;
}

int isMatching(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

// 1st TEST:
// Enter Parentheses:
// ()[{()}]{}
// Stack is created successfully
// Parentheses are matching!!!

// 2nd TEST
// Enter Parentheses:
// ({)}
// Stack is created successfully
// Parentheses are not matching