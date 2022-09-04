// Write a C program to merge two already sorted double list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} NODE;

NODE *createNode(int);
NODE *createList(NODE *);
void displayList(NODE *);
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

NODE *createNode(int val)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = val;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

NODE *createList(NODE *head)
{
    int num;
    printf("Enter -1 to end\n");
    printf("Enter the data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        NODE *newNode = createNode(num);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            NODE *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->prev = ptr;
        }
        printf("Enter the data: ");
        scanf("%d", &num);
    }
    return head;
}

void displayList(NODE *head)
{
    NODE *ptr;
    ptr = head;
    printf("HEAD");
    while (ptr != NULL)
    {
        printf(" <-> %d", ptr->data);
        ptr = ptr->next;
    }
    printf(" -> NULL\n");
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
        NODE *ptr1 = NULL;
        while (list1 != NULL && list1->data <= list2->data)
        {
            ptr1 = list1;
            list1 = list1->next;
        }
        ptr1->next = list2;
        list2->prev = ptr1;

        // swap
        NODE *temp = list1;
        list1 = list2;
        list2 = temp;
    }
    return res;
}

// OUTPUT
// Enter First List
// Enter -1 to end
// Enter the data: 5
// Enter the data: 7
// Enter the data: 9
// Enter the data: -1
// HEAD <-> 5 <-> 7 <-> 9 -> NULL

// Enter Second List
// Enter -1 to end
// Enter the data: 3
// Enter the data: 4
// Enter the data: 8
// Enter the data: 10
// Enter the data: -1
// HEAD <-> 3 <-> 4 <-> 8 <-> 10 -> NULL

// Sorted Merge list is
// HEAD <-> 3 <-> 4 <-> 5 <-> 7 <-> 8 <-> 9 <-> 10 -> NULL