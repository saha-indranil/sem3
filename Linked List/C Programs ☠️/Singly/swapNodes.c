// Given a singly linked list of size N. The task
// is to swap elements in the linked list pairwise.

#include "singlylinkedlist.h"

NODE *swapNodes(NODE *head);

int main()
{
    NODE *head = NULL;
    head = createList(head);
    printf("Original List:\n");
    displayList(head);

    head = swapNodes(head);
    printf("After Swapping:\n");
    displayList(head);

    return 0;
}

NODE *swapNodes(NODE *head)
{
    NODE *dummy = (NODE *)malloc(sizeof(NODE));
    dummy->next = head;
    NODE *prev = dummy;
    NODE *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        prev->next = curr->next;
        curr->next = curr->next->next;
        prev->next->next = curr;
        curr = curr->next;
        prev = prev->next->next;
    }
    return dummy->next;
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
// Original List:
// HEAD -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL
// After Swapping:
// HEAD -> 2 -> 1 -> 4 -> 3 -> 5 -> NULL