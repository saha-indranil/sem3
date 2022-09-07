// Write a C program to print the odd number and even
// number nodes separately from a single linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *createList(NODE *);
void displayList(NODE *);
void seperateOddEven(NODE *, NODE **, NODE **);

int main()
{
    NODE *head = NULL, *odd = NULL, *even = NULL;
    head = createList(head);
    printf("Initial Linked List is...\n");
    displayList(head);

    seperateOddEven(head, &odd, &even);
    printf("Odd Nodes Are: ");
    displayList(odd);
    printf("Even Nodes Are: ");
    displayList(even);

    return 0;
}

NODE *createList(NODE *head)
{
    NODE *newNode, *ptr;
    int num;
    printf("Creating Linked List...\n");
    printf("Enter -1 to end\n");
    printf("Enter the data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        newNode = (NODE *)malloc(sizeof(NODE));
        newNode->data = num;
        if (head == NULL)
        {
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = NULL;
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
        printf(" -> %d", ptr->data);
        ptr = ptr->next;
    }
    printf(" -> NULL\n");
}

void seperateOddEven(NODE *head, NODE **odd, NODE **even)
{
    if (head == NULL)
    {
        return;
    }
    int count = 1;
    NODE *ptr1 = NULL;
    NODE *ptr2 = NULL;

    while (head != NULL)
    {
        if (count % 2 != 0)
        {
            if (*odd == NULL)
            {
                *odd = head;
                ptr1 = head;
            }
            else
            {
                ptr1->next = head;
                ptr1 = ptr1->next;
            }
        }
        else
        {
            if (*even == NULL)
            {
                *even = head;
                ptr2 = head;
            }
            else
            {
                ptr2->next = head;
                ptr2 = ptr2->next;
            }
        }
        head = head->next;
        count++;
    }
    ptr1->next = NULL;
    ptr2->next = NULL;
}

// OUTPUT
// Creating Linked List...
// Enter -1 to end
// Enter the data: 10
// Enter the data: 20
// Enter the data: 30
// Enter the data: 40
// Enter the data: 50
// Enter the data: -1
// Initial Linked List is...
// HEAD -> 10 -> 20 -> 30 -> 40 -> 50 -> NULL
// Odd Nodes Are: HEAD -> 10 -> 30 -> 50 -> NULL
// Even Nodes Are: HEAD -> 20 -> 40 -> NULL