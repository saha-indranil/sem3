#include <stdio.h>
#include <limits.h>

struct item
{
    int value;
    int priority;
};
struct item q[10];
int size = -1;

void enqueue(int, int);
int peek(void);
void dequeue(void);

int main()
{
    enqueue(10, 2);
    enqueue(15, 4);
    enqueue(20, 1);
    enqueue(25, 4);
    enqueue(30, 3);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}

void enqueue(int value, int priority)
{
    size++;
    q[size].value = value;
    q[size].priority = priority;
}

int peek()
{
    int highestPriority = INT_MIN;
    int ind = -1;
    for (int i = 0; i <= size; i++)
    {
        if (highestPriority < q[i].priority)
        {
            highestPriority = q[i].priority;
            ind = i;
        }
    }
    return ind;
}

void dequeue()
{
    if (size == -1)
    {
        printf("Priority Queue is Empty!");
        return;
    }
    int ind = peek();
    printf("%d is Removed from Queue\n", q[ind].value);
    for (int i = ind; i < size; i++)
    {
        q[i] = q[i + 1];
    }
    size--;
}

// OUTPUT
// 15 is Removed from Queue
// 25 is Removed from Queue
// 30 is Removed from Queue
// 10 is Removed from Queue
// 20 is Removed from Queue
// Priority Queue is Empty!