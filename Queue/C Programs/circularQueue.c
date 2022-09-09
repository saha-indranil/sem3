// Write a C program to implement circular queue.

#include <stdio.h>
#define MAX 3

int queue[MAX];
int front = -1, rear = -1;
void insert(int);
int delete_element(void);
int peek(void);
void display(void);

int main()
{
    insert(10);
    insert(20);
    insert(30);
    delete_element();
    display();
    peek();
    insert(40);
    display();
    delete_element();
    return 0;
}

void insert(int num)
{
    if (front == 0 && rear == MAX - 1)
        printf("\nOVERFLOW");
    else
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            queue[rear] = num;
        }
        else if (rear == MAX - 1 && front != 0)
        {
            rear = 0;
            queue[rear] = num;
        }
        else
        {
            rear++;
            queue[rear] = num;
        }
        printf("\n%d is inserted", num);
    }
}

int delete_element()
{
    int val;
    if (front == -1 && rear == -1)
    {
        printf("\nUNDERFLOW");
        return -1;
    }
    val = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
    printf("\n%d is deleted from queue", val);
    return val;
}

int peek()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQUEUE IS EMPTY");
        return -1;
    }
    else
    {
        printf("\nTop element is %d: ", queue[front]);
        return queue[front];
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1)
        printf("\nQUEUE IS EMPTY");
    else
    {
        printf("\nFRONT --> ");
        if (front < rear)
        {
            for (i = front; i <= rear; i++)
            {
                printf("%d  ", queue[i]);
            }
        }
        else
        {
            for (i = front; i < MAX; i++)
                printf("%d  ", queue[i]);
            for (i = 0; i <= rear; i++)
                printf("%d  ", queue[i]);
        }
        printf("<-- REAR");
    }
}

// OUTPUT
// 10 is inserted
// 20 is inserted
// 30 is inserted
// 10 is deleted from queue
// FRONT --> 20  30  <-- REAR
// Top element is 20:
// 40 is inserted
// FRONT --> 20  30  40  <-- REAR
// 20 is deleted from queue