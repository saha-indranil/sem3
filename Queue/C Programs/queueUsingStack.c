//  C Program to Implement Queues using Stacks

#include <stdio.h>
#include <stdlib.h>

void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue(int);
int dequeue();
void display();

int st1[10], st2[10];
int top1 = -1, top2 = -1;

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    enqueue(40);
    display();
    return 0;
}

/*Function to push the element on to the stack*/
void push1(int data)
{
    st1[++top1] = data;
}

/*Function to pop the element from the stack*/
int pop1()
{
    return (st1[top1--]);
}

/*Function to push an element on to stack*/
void push2(int data)
{
    st2[++top2] = data;
}

/*Function to pop an element from the stack*/

int pop2()
{
    return (st2[top2--]);
}

/*Function to add an element into the queue using stack*/
void enqueue(int data)
{
    push1(data);
    printf("\n%d inserted to queue", data);
}

/*Function to delete an element from the queue using stack*/

int dequeue()
{
    int i, val;
    while (top1 != -1)
    {
        push2(pop1());
    }
    val = pop2();
    printf("\n%d deleted from queue", val);
    while (top2 != -1)
    {
        push1(pop2());
    }
    return val;
}

/*Function to display the elements in the stack*/

void display()
{
    int i;
    printf("\nFRONT--> ");
    for (i = 0; i <= top1; i++)
    {
        printf(" %d ", st1[i]);
    }
    printf(" <--REAR");
}

// OUTPUT
// 10 inserted to queue
// 20 inserted to queue
// 30 inserted to queue
// 10 deleted from queue
// 40 inserted to queue
// FRONT-->  20  30  40  <--REAR