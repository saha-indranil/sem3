// Write a C program to implement the following functions for single linked list.
// • createList • deleteFromFirst • deleteFromLast • deleteFromAny • displayList
// Mention the necessary algorithm

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *createList(NODE *);
void deleteFromFirst(NODE **);
void deleteFromLast(NODE **);
void deleteFromAny(NODE **);
void displayList(NODE *);

int main()
{
    NODE *head = NULL;
    head = createList(head);
    printf("Initial List\n");
    displayList(head);

    printf("Deleting from First\n");
    deleteFromFirst(&head);
    displayList(head);

    printf("Deleting from Last\n");
    deleteFromLast(&head);
    displayList(head);

    printf("Deleting from Any\n");
    deleteFromAny(&head);
    displayList(head);

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

void deleteFromFirst(NODE **head)
{
    if (*head == NULL)
    {
        printf("Underflow!\n");
        return;
    }
    NODE *ptr;
    ptr = *head;
    *head = ptr->next;
    free(ptr);
}

void deleteFromLast(NODE **head)
{
    if (*head == NULL)
    {
        printf("Underflow!\n");
        return;
    }
    NODE *ptr, *preptr;
    ptr = *head;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
}

void deleteFromAny(NODE **head)
{
    if (*head == NULL)
    {
        printf("Underflow!\n");
        return;
    }
    NODE *ptr, *preptr;
    ptr = *head;
    int pos, i = 0;
    printf("Enter Position of Deletation: ");
    scanf("%d", &pos);
    while (i < pos - 1)
    {
        preptr = ptr;
        ptr = ptr->next;
        i++;
    }
    preptr->next = ptr->next;
    free(ptr);
}

// OUTPUT
// Creating Linked List...
// Enter -1 to end
// Enter the data: 7
// Enter the data: 3
// Enter the data: 9
// Enter the data: 11
// Enter the data: 5
// Enter the data: 2
// Enter the data: -1
// Initial List
// HEAD -> 7 -> 3 -> 9 -> 11 -> 5 -> 2 -> NULL
// Deleting from First
// HEAD -> 3 -> 9 -> 11 -> 5 -> 2 -> NULL
// Deleting from Last
// HEAD -> 3 -> 9 -> 11 -> 5 -> NULL
// Deleting from Any
// Enter Position of Deletation: 3
// HEAD -> 3 -> 9 -> 5 -> NULL