// Write a C program to reverse an already created single linked list.

#include "singlelinkedlist.h"

NODE *reverseList(NODE *);

int main()
{
    NODE *head = NULL;
    head = createList(head);
    printf("Original List:\n");
    displayList(head);

    head = reverseList(head);
    printf("Reversed List:\n");
    displayList(head);

    return 0;
}

NODE *reverseList(NODE *head)
{
    NODE *curr = head;
    NODE *prev = NULL;
    while (curr != NULL)
    {
        NODE *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

// OUTPUT
// Creating Linked List...
// Enter -1 to end
// Enter the data: 5
// Enter the data: 10
// Enter the data: 15
// Enter the data: 20
// Enter the data: 25
// Enter the data: -1
// Original List:
// HEAD -> 5 -> 10 -> 15 -> 20 -> 25 -> NULL
// Reversed List:
// HEAD -> 25 -> 20 -> 15 -> 10 -> 5 -> NULL