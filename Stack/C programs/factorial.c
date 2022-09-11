// Write a C program to calculate factorial with the help of stack.

#include <stdio.h>
#define MAX 2
void push(int st[], int *, int);
int pop(int st[], int *);

int main()
{
    int st[MAX], top = -1, n, temp;
    printf("Enter a Number: ");
    scanf("%d", &n);
    push(st, &top, 1);
    for (int i = 2; i <= n; i++)
    {
        temp = pop(st, &top);
        push(st, &top, temp * i);
    }
    printf("Factorial: %d", pop(st, &top));
    return 0;
}

void push(int st[], int *top, int val)
{
    if (*top == MAX - 1)
        printf("Stack Overflow!");
    else
        st[++(*top)] = val;
}

int pop(int st[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow!");
        return -1;
    }
    else
        return st[(*top)--];
}

// OUTPUT 1
// Enter a Number: 0
// Factorial: 1

// OUTPUT 2
// Enter a Number: 5
// Factorial: 120