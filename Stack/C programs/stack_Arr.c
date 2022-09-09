// Write a C program to implement stack using dynamic array and perform
// the following operation • PUSH() • POP() • PEEK() • DISPLAY()

#include <stdio.h>
#include <stdlib.h>

int *st = NULL, top = -1, size = 0;
void push(int);
int pop(void);
int peek(void);
void display(void);

int main()
{
    int n;
    st = (int *)malloc(size * sizeof(int));
    push(10);
    push(20);
    push(30);
    display();
    n = pop();
    printf("\n%d is poped from stack", n);
    n = peek();
    printf("\n%d is peek element", n);

    free(st);
    return 0;
}

void push(int val)
{
    if (top == size - 1)
    {
        size++;
        st = (int *)realloc(st, size * sizeof(int));
    }
    top++;
    *(st + top) = val;
    printf("\n%d is pushed to the stack", val);
}

int pop(void)
{
    int val;
    if (top == -1)
    {
        printf("Stack is underflowed");
        return -1;
    }
    else
    {
        val = *(st + top);
        top--;
        size--;
        st = (int *)realloc(st, size * sizeof(int));
        return val;
    }
}

int peek(void)
{
    if (top == -1)
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        return *(st + top);
    }
}

void display(void)
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("\nStack[%d]: %d", i, *(st + i));
        }
    }
}

// OUTPUT
// 10 is pushed to the stack
// 20 is pushed to the stack
// 30 is pushed to the stack
// Stack[2]: 30
// Stack[1]: 20
// Stack[0]: 10
// 30 is poped from stack
// 20 is peek element

// Write the algorithms of push and pop
// after writing the output