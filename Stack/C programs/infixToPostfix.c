// Write a C program to convert an
// infix expression to postfix expression.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

char st[MAX];
int top = -1;

void push(char st[], char);
char pop(char st[]);
int precedence(char);
void infixToPostfix(char infix[], char postfix[]);
bool isOpening(char);
bool isClosing(char);
bool isOperator(char);
bool hasPriority(char, char);

int main()
{
    char infix[MAX], postfix[MAX];
    printf("Enter a Infix Expression: ");
    gets(infix);
    strcpy(postfix, "");
    infixToPostfix(infix, postfix);
    printf("Corresponding Postfix Expression is :\n%s", postfix);
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isOpening(infix[i]))
            push(st, infix[i]);
        else if (isClosing(infix[i]))
        {
            while (top != -1 && !isOpening(st[top]))
                postfix[j++] = pop(st);
            if (top == -1)
            {
                printf("\nIncorrect Expression\n");
                exit(1);
            }
            pop(st);
        }
        else if (isdigit(infix[i]) || isalpha(infix[i]))
            postfix[j++] = infix[i];
        else if (isOperator(infix[i]))
        {
            while ((top != -1) && !isOpening(st[top]) && hasPriority(st[top], infix[i]))
                postfix[j++] = pop(st);
            push(st, infix[i]);
        }
        else
        {
            printf("\nINCORRECT ELEMENT IN EXPRESSION");
            exit(1);
        }
        i++;
    }
    while ((top != -1) && !isOpening(st[top]))
    {
        postfix[j] = pop(st);
        j++;
    }
    postfix[j] = '\0';
}

void push(char st[], char val)
{
    if (top == MAX - 1)
        printf("\nSTACK OVERFLOW!");
    else
        st[++top] = val;
}

char pop(char st[])
{
    char val = ' ';
    if (top == -1)
        printf("\nSTACK UNDERFLOW!");
    else
        val = st[top--];
    return val;
}

bool isOpening(char c)
{
    if (c == '(' || c == '{' || c == '[')
        return true;
    return false;
}

bool isClosing(char c)
{
    if (c == ')' || c == '}' || c == ']')
        return true;
    return false;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
        return true;
    return false;
}

int precedence(char operator)
{
    if (operator== '+' || operator== '-')
        return 2;
    else if (operator== '/' || operator== '*' || operator== '%')
        return 3;
    else if (operator== '^')
        return 4;
    return -1;
}

bool hasPriority(char op1, char op2)
{
    int op1Weight = precedence(op1);
    int op2Weight = precedence(op2);
    if (op1Weight == op2Weight)
        return op1Weight == 4 ? false : true;
    return op1Weight > op2Weight ? true : false;
}

// OUTPUT
// Enter a Infix Expression: [A+B]*C/D^E^F%(G-H)
// Corresponding Postfix Expression is :
// AB+C*DEF^^/GH-%