// Write a C program to implement queue using dynamic array.
// Execute all the necessary functions of queue.

#include <stdio.h>
#include <stdlib.h>

int *queue, front = -1, rear = -1, size;

void insert(int);
int del(void);
int peek(void);
void display(void);

int main()
{
    int n;
    printf("ENTER SIZE OF QUEUE: ");
    scanf("%d", &size);
    queue = (int *)malloc(sizeof(int) * size);

    insert(10);
    insert(20);
    insert(30);
    display();
    n = del();
    printf("\n%d is deleted", n);
    n = peek();
    printf("\nFirst value in queue is %d", n);

    free(queue);
    return 0;
}

void insert(int val)
{
    if (rear == size - 1)
    {
        printf("\nTHE QUEUE IS FULL");
    }
    else
    {
        if (front == -1)
        {
            front++;
        }
        rear++;
        *(queue + rear) = val;
        printf("\n%d has been inserted", val);
    }
}

int del()
{
    int val;
    if (front == -1 || front > rear)
    {
        printf("THE QUEUE IS EMPTY");
        return -1;
    }
    else
    {
        val = *(queue + front);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        return val;
    }
}

int peek(void)
{
    if (front == -1 || front > rear)
    {
        printf("THE QUEUE IS EMPTY");
        return -1;
    }
    else
    {
        return *(queue + front);
    }
}

void display(void)
{
    int i;
    if (front == -1 || front > rear)
    {
        printf("\nQUEUE IS EMPTY");
    }
    else
    {
        printf("\nFRONT --> ");
        for (i = front; i <= rear; i++)
        {
            printf(" %d ", *(queue + i));
        }
        printf("<-- REAR");
    }
}

// OUTPUT
// ENTER SIZE OF QUEUE: 4
// 10 has been inserted
// 20 has been inserted
// 30 has been inserted
// FRONT -->  10  20  30 <-- REAR
// 10 is deleted
// First value in queue is 20