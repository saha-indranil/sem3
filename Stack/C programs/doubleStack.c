// Write a C program to implement the concept of double
// stack, where both end can be used for operations.

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX], topA = -1, topB = MAX;

void pushA(int val)
{
    if (topA == topB - 1)
        printf("\nStack A Overflow");
    else
    {
        topA += 1;
        stack[topA] = val;
    }
}

int popA(void)
{
    int val;
    if (topA == -1)
    {
        printf("\nStack A Underflow");
        val = -1;
    }
    else
    {
        val = stack[topA];
        topA--;
    }
    return val;
}

void display_stackA(void)
{
    int i;
    if (topA == -1)
        printf("\nStack A is Empty");
    else
    {
        printf("\nContents of Stack A are:");
        for (i = topA; i >= 0; i--)
            printf("\nStack[%d]: %d", i, stack[i]);
    }
}

void pushB(int val)
{
    if (topB - 1 == topA)
        printf("\nStack B Overflow");
    else
    {
        topB -= 1;
        stack[topB] = val;
    }
}

int popB(void)
{
    int val;
    if (topB == MAX)
    {
        printf("\nStack B Underflow");
        val = -1;
    }
    else
    {
        val = stack[topB];
        topB++;
    }
    return val;
}

void display_stackB(void)
{
    int i;
    if (topB == MAX)
        printf("\nStack B is Empty");
    else
    {
        printf("\nContents of Stack B are:");
        for (i = topB; i < MAX; i++)
            printf("\nStack[%d]: %d", i, stack[i]);
    }
}

int main()
{
    int option, val;
    printf("\n*** MAIN MENU***");
    printf("\n1. PUSH IN STACK A");
    printf("\n2. PUSH IN STACK B");
    printf("\n3. POP FROM STACK A");
    printf("\n4. POP FROM STACK B");
    printf("\n5. DISPLAY STACK A");
    printf("\n6. DISPLAY STACK B");
    printf("\n7. EXIT");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nEnter value to push in Stack A: ");
            scanf("%d", &val);
            pushA(val);
            break;
        case 2:
            printf("\nEnter value to push in Stack B: ");
            scanf("%d", &val);
            pushB(val);
            break;
        case 3:
            val = popA();
            if (val != -1)
                printf("%d poped from Stack A", val);
            break;
        case 4:
            val = popB();
            if (val != -1)
                printf("%d poped from Stack B", val);
            break;
        case 5:
            display_stackA();
            break;
        case 6:
            display_stackB();
            break;
        case 7:
            exit(1);
        default:
            printf("\nInvalid Choice");
            break;
        }

    } while (option != 7);
    return 0;
}

// OUTPUT
// *** MAIN MENU***
// 1. PUSH IN STACK A
// 2. PUSH IN STACK B
// 3. POP FROM STACK A
// 4. POP FROM STACK B
// 5. DISPLAY STACK A
// 6. DISPLAY STACK B
// 7. EXIT
// Enter your choice: 1

// Enter value to push in Stack A: 15

// Enter your choice: 1

// Enter value to push in Stack A: 25

// Enter your choice: 5

// Contents of Stack A are:
// Stack[1]: 25
// Stack[0]: 15
// Enter your choice: 4

// Stack B Underflow
// Enter your choice: 7