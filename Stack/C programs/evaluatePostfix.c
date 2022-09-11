// Write a C program to evaluate a postfix expression.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 10

float st[MAX];
int top = -1;
enum sType
{
    operator, operand };
void push(float st[], float);
float pop(float st[]);
float evaluatePostfixExp(char exp[]);
enum sType SymType(char);

int main()
{
    float val;
    char exp[20];
    printf("Enter any Postfix Expression: ");
    gets(exp);
    val = evaluatePostfixExp(exp);
    printf("Value of Postfix Expression: %2.f", val);
    return 0;
}

float evaluatePostfixExp(char exp[])
{
    int i = 0;
    char ch;
    float op1, op2, val;
    while (exp[i] != '\0')
    {
        ch = exp[i];
        if (ch == ' ')
            continue;
        switch (SymType(ch))
        {
        case operand:
            fflush(stdin);
            printf("Enter the value of %c: ", ch);
            scanf("%f", &val);
            push(st, val);
            break;

        case operator:
            op1 = pop(st);
            op2 = pop(st);
            switch (ch)
            {
            case '+':
                val = op2 + op1;
                break;
            case '-':
                val = op2 - op1;
                break;
            case '*':
                val = op2 * op1;
                break;
            case '/':
                val = op2 / op1;
                break;
            case '%':
                val = (int)op2 % (int)op1;
                break;
            case '^':
                val = (float)pow(op1, op2);
                break;
            default:
                break;
            }
            push(st, val);
            break;
        }
        i++;
    }
    return (pop(st));
}

void push(float st[], float val)
{
    if (top == MAX - 1)
        printf("Stack Overflow!");
    else
        st[++top] = val;
}

float pop(float st[])
{
    float val = -1;
    if (top == -1)
        printf("Stack Underflow!");
    else
        val = st[top--];
    return val;
}

enum sType SymType(char c)
{
    enum sType sym;
    if (isalpha(c))
        sym = operand;
    else
        sym = operator;
    return sym;
}

// OUTPUT
// Enter any Postfix Expression: ABC/+D*
// Enter the value of A: 10
// Enter the value of B: 18
// Enter the value of C: 9
// Enter the value of D: 2
// Value of Postfix Expression: 24

/*
Do not write this part
(A+B/C)*D = ABC/+D*
(10+18/9)*2 = 24
*/