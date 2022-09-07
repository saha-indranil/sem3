// Write a C program to merge two already sorted list

#include "singlylinkedlist.h"

NODE *sortedMerge(NODE *, NODE *);

int main()
{
    NODE *head1 = NULL, *head2 = NULL;
    printf("Enter First List\n");
    head1 = createList(head1);
    displayList(head1);

    printf("\nEnter Second List\n");
    head2 = createList(head2);
    displayList(head2);

    NODE *res = sortedMerge(head1, head2);
    printf("\nSorted Merge list is\n");
    displayList(res);

    return 0;
}

NODE *sortedMerge(NODE *list1, NODE *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    if (list1->data > list2->data)
    {
        NODE *temp = list1;
        list1 = list2;
        list2 = temp;
    }

    NODE *res = list1;
    while (list1 != NULL && list2 != NULL)
    {
        NODE *tmp = NULL;
        while (list1 != NULL && list1->data <= list2->data)
        {
            tmp = list1;
            list1 = list1->next;
        }
        tmp->next = list2;

        // swap
        NODE *temp = list1;
        list1 = list2;
        list2 = temp;
    }
    return res;
}

// OUTPUT

// Enter First List
// Creating Linked List...
// Enter -1 to end
// Enter the data: 5
// Enter the data: 7
// Enter the data: 9
// Enter the data: -1
// HEAD -> 5 -> 7 -> 9 -> NULL

// Enter Second List
// Creating Linked List...
// Enter -1 to end
// Enter the data: 3
// Enter the data: 4
// Enter the data: 8
// Enter the data: 10
// Enter the data: -1
// HEAD -> 3 -> 4 -> 8 -> 10 -> NULL

// Sorted Merge list is
// HEAD -> 3 -> 4 -> 5 -> 7 -> 8 -> 9 -> 10 -> NULL