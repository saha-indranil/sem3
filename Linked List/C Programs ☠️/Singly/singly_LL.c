// Write a C program to implement all the insert and delete functions and
// display function along with an appropriate menu for a single linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *createList(NODE *);
void displayList(NODE *);
void insertAtFirst(NODE **);
void insertAtLast(NODE **);
void insertAtAny(NODE **);
void deleteFromFirst(NODE **);
void deleteFromLast(NODE **);
void deleteFromAny(NODE **);

int main()
{
    NODE *head = NULL;
    head = createList(head);
    printf("Initial List: ");
    displayList(head);
    int option;
    printf("\n*** MAIN MENU ***");
    printf("\n1. Insert at First");
    printf("\n2. Insert at Last");
    printf("\n3. Insert at Any");
    printf("\n4. Delete from First");
    printf("\n5. Delete from Last");
    printf("\n6. Delete from Any");
    printf("\n7. Display List");
    printf("\n8. Exit\n");

    do
    {
        printf("Enter Choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insertAtFirst(&head);
            break;
        case 2:
            insertAtLast(&head);
            break;
        case 3:
            insertAtAny(&head);
            break;
        case 4:
            deleteFromFirst(&head);
            break;
        case 5:
            deleteFromLast(&head);
            break;
        case 6:
            deleteFromAny(&head);
            break;
        case 7:
            displayList(head);
            break;
        case 8:
            exit(1);
        default:
            printf("Invalid Choice!");
            break;
        }
    } while (1);

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
    if (pos < 1 || ptr == NULL)
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
    int pos;
    printf("Enter Position of Deletation: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("Invalid Position!\n");
        return;
    }
    if (pos == 1)
    {
        deleteFromFirst(head);
        return;
    }
    while (pos > 1)
    {
        preptr = ptr;
        ptr = ptr->next;
        pos--;
        if (ptr == NULL)
        {
            printf("Index Out of Bound!\n");
            return;
        }
    }
    preptr->next = ptr->next;
    free(ptr);
}

// OUTPUT
// Creating Linked List...
// Enter -1 to end
// Enter the data: 3
// Enter the data: 8
// Enter the data: -1
// Initial List: HEAD -> 3 -> 8 -> NULL

// *** MAIN MENU ***
// 1. Insert at First
// 2. Insert at Last
// 3. Insert at Any
// 4. Delete from First
// 5. Delete from Last
// 6. Delete from Any
// 7. Display List
// 8. Exit
// Enter Choice: 1
// Enter the data: 10
// Enter Choice: 2
// Enter the data: 20
// Enter Choice: 3
// Enter Position of insertion: 3
// Enter the data: 15
// Enter Choice: 7
// HEAD -> 10 -> 3 -> 15 -> 8 -> 20 -> NULL
// Enter Choice: 4
// Enter Choice: 5
// Enter Choice: 6
// Enter Position of Deletation: 2
// Enter Choice: 7
// HEAD -> 3 -> 8 -> NULL
// Enter Choice: 8