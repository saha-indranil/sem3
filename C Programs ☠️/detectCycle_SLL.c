// Write a C program to detect a loop in a single linked list.

#include "singlylinkedlist.h"

void detectCycle(NODE *);

int main()
{
    NODE *head = NULL;
    printf("Please Enter More Than 3 data\n");
    head = createList(head);
    displayList(head);
    detectCycle(head);

    NODE *tail = head;
    int size = 1;
    while (tail->next != NULL)
    {
        tail = tail->next;
        size++;
    }

    if (size >= 3)
    {
        tail->next = head->next->next;
        printf("\nLinked List Successfully Created with Cycle");
        detectCycle(head);
    }
    return 0;
}

void detectCycle(NODE *head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("\nNo Cycle");
        return;
    }

    NODE *fast = head;
    NODE *slow = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            printf("\nCycle Detected");
            return;
        }
    }
    printf("\nNo Cycle");
}

// OUTPUT
// Please Enter More Than 3 data
// Creating Linked List...
// Enter -1 to end
// Enter the data: 1
// Enter the data: 2
// Enter the data: 3
// Enter the data: 4
// Enter the data: -1
// HEAD -> 1 -> 2 -> 3 -> 4 -> NULL

// No Cycle
// Linked List Successfully Created with Cycle
// Cycle Detected