// Given a singly linked list of size N. The task is
// to left-shift the linked list by k nodes,
// where k is a given positive integer smaller
// than or equal to length of the linked list.

#include "singlylinkedlist.h"

NODE *leftShift(NODE *, int);

int main()
{
    NODE *head = NULL;
    head = createList(head);
    displayList(head);

    NODE *curr = head;
    int n = 1, k;
    while (curr->next && ++n)
        curr = curr->next;
    printf("Enter k (should be <=%d): ", n);
    scanf("%d", &k);

    if (k < 0 || k > n)
    {
        printf("Invalid!");
        exit(1);
    }

    head = leftShift(head, k);
    printf("\nLinked List Left shifted by %d nodes\n", k);
    displayList(head);

    return 0;
}

NODE *leftShift(NODE *head, int k)
{
    if (!head || !head->next || k == 0)
    {
        return head;
    }
    NODE *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = head;
    NODE *curr = head;
    for (int i = 1; i < k; i++)
    {
        curr = curr->next;
    }
    NODE *res = curr->next;
    curr->next = NULL;
    return res;
}

// OUTPUT
// Creating Linked List...
// Enter -1 to end
// Enter the data: 1
// Enter the data: 2
// Enter the data: 3
// Enter the data: 4
// Enter the data: 5
// Enter the data: -1
// HEAD -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL
// Enter k (should be <=5): 2

// Linked List Left shifted by 2 nodes
// HEAD -> 3 -> 4 -> 5 -> 1 -> 2 -> NULL