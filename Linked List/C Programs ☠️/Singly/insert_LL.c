// Write a C program to implement the following functions for single linked list.
// • createList • insertAtFirst • insertAtLast • insertAtAny • displayList
// Mention the necessary algorithm

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *createList(NODE *);
void insertAtFirst(NODE **);
void insertAtLast(NODE **);
void insertAtAny(NODE **);
void displayList(NODE *);

int main()
{
    NODE *head = NULL;
    head = createList(head);
    printf("Initial List\n");
    displayList(head);

    printf("Inserting at First\n");
    insertAtFirst(&head);
    displayList(head);

    printf("Inserting at Last\n");
    insertAtLast(&head);
    displayList(head);

    printf("Inserting at Any\n");
    insertAtAny(&head);
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

void insertAtFirst(NODE **head)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    int num;
    printf("Enter the data: ");
    scanf("%d", &num);
    newNode->data = num;
    newNode->next = *head;
    *head = newNode;
}

void insertAtLast(NODE **head)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    NODE *ptr;
    int num;
    printf("Enter the data: ");
    scanf("%d", &num);
    newNode->data = num;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void insertAtAny(NODE **head)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    NODE *ptr = *head;
    int num, pos;
    printf("Enter Position of insertion: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid!\n");
        return;
    }
    if (pos == 1)
    {
        insertAtFirst(head);
        return;
    }
    while (pos > 2)
    {
        ptr = ptr->next;
        pos--;
        if (ptr == NULL)
        {
            printf("Index Out of Bound!\n");
            return;
        }
    }
    printf("Enter the data: ");
    scanf("%d", &num);
    newNode->data = num;
    newNode->next = ptr->next;
    ptr->next = newNode;
}

// OUTPUT
// Creating Linked List...
// Enter -1 to end
// Enter the data: 3
// Enter the data: 9
// Enter the data: 5
// Enter the data: -1
// Initial List
// HEAD -> 3 -> 9 -> 5 -> NULL
// Inserting at First
// Enter the data: 10
// HEAD -> 10 -> 3 -> 9 -> 5 -> NULL
// Inserting at Last
// Enter the data: 99
// HEAD -> 10 -> 3 -> 9 -> 5 -> 99 -> NULL
// Inserting at Any
// Enter Position of insertion: 3
// Enter the data: 55
// HEAD -> 10 -> 3 -> 55 -> 9 -> 5 -> 99 -> NULL

