// DOUBLY LINKED LIST
// Write a C program to create a Double linked list along with the following functions:
// a) to display the elements of a Double Linked List.
// b) to add an element at beginning of a Double linked list.
// c) to add an element at the end of a Double linked list.
// d) to add an element at any user given position of a Double linked list.
// e) to search a user given element in a Double linked list.
// f) to count the number of nodes in a Double linked list.
// g) to delete a node at beginning of a Double linked list.
// h) to delete a node at end of a Double linked list.
// i) to delete a node from any position of a Double linked list.
// (Create a menu bar using switch case statement in the main)
// Mention the necessary algorithm.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} NODE;

NODE *createNode(int);
void displayList(NODE *);
void addAtBeg(NODE **);
void addAtEnd(NODE **);
void addAtAny(NODE **);
void searchEle(NODE *);
int countNodes(NODE *);
void delFromBeg(NODE **);
void delFromEnd(NODE **);
void delFromAny(NODE **);

int main()
{
    NODE *head = NULL;
    int option, n;
    printf("\n*** MAIN MENU ***");
    printf("\n1. Display Double Linked List");
    printf("\n2. Add At First");
    printf("\n3. Add At End");
    printf("\n4. Add At Any Position");
    printf("\n5. Search an Element");
    printf("\n6. Count No. Of Nodes");
    printf("\n7. Delete From First");
    printf("\n8. Delete From End");
    printf("\n9. Delete From Any Position");
    printf("\n10. Exit\n");
    do
    {
        printf("Enter Choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            displayList(head);
            break;
        case 2:
            addAtBeg(&head);
            break;
        case 3:
            addAtEnd(&head);
            break;
        case 4:
            addAtAny(&head);
            break;
        case 5:
            searchEle(head);
            break;
        case 6:
            n = countNodes(head);
            printf("Number of Nodes: %d\n", n);
            break;
        case 7:
            delFromBeg(&head);
            break;
        case 8:
            delFromEnd(&head);
            break;
        case 9:
            delFromAny(&head);
            break;
        case 10:
            exit(1);
        default:
            printf("Invalid Choice!\n");
            break;
        }
    } while (1);
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

void addAtBeg(NODE **head)
{
    int val;
    printf("Enter Data: ");
    scanf("%d", &val);
    NODE *newNode = createNode(val);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void addAtEnd(NODE **head)
{
    int val;
    printf("Enter Data: ");
    scanf("%d", &val);
    NODE *newNode = createNode(val);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    NODE *ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
}

void addAtAny(NODE **head)
{
    int val, pos;
    printf("Enter Position: ");
    scanf("%d", &pos);

    int n = countNodes(*head);
    if (pos <= 0 || pos > n + 1)
    {
        printf("Index Out of Bound!\n");
    }
    else if (pos == 1)
    {
        addAtBeg(head);
    }
    else if (pos == n + 1)
    {
        addAtEnd(head);
    }
    else
    {
        printf("Enter Data: ");
        scanf("%d", &val);
        NODE *newNode = createNode(val);
        NODE *ptr1 = *head;
        while (pos > 2)
        {
            ptr1 = ptr1->next;
            pos--;
        }
        NODE *ptr2 = ptr1->next;

        ptr1->next = newNode;
        ptr2->prev = newNode;
        newNode->prev = ptr1;
        newNode->next = ptr2;
    }
}

void searchEle(NODE *head)
{
    int val, count = 0;
    NODE *ptr = head;
    if (ptr == NULL)
    {
        printf("List is Empty!\n");
        return;
    }
    printf("Enter Element: ");
    scanf("%d", &val);
    while (ptr != NULL)
    {
        count++;
        if (ptr->data == val)
        {
            printf("Item found at Node: %d\n", count);
            return;
        }
        ptr = ptr->next;
    }
    printf("Element Not Found!\n");
}

int countNodes(NODE *head)
{
    NODE *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

void delFromBeg(NODE **head)
{
    if (*head == NULL)
    {
        printf("List is Empty! Can't Delete\n");
    }
    else if ((*head)->next == NULL)
    {
        free(head);
        *head = NULL;
    }
    else
    {
        *head = (*head)->next;
        free((*head)->prev);
        (*head)->prev = NULL;
    }
}

void delFromEnd(NODE **head)
{
    if (*head == NULL)
    {
        printf("List is Empty! Can't Delete\n");
    }
    else if ((*head)->next == NULL)
    {
        free(head);
        *head = NULL;
    }
    else
    {
        NODE *ptr = *head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        (ptr->prev)->next = NULL;
        free(ptr);
    }
}

void delFromAny(NODE **head)
{
    int pos;
    printf("Enter Position: ");
    scanf("%d", &pos);

    int n = countNodes(*head);
    if (pos <= 0 || pos > n)
    {
        printf("Index Out of Bound!\n");
    }
    else if (pos == 1)
    {
        delFromBeg(head);
    }
    else if (pos == n)
    {
        delFromEnd(head);
    }
    else
    {
        NODE *ptr = *head;
        while (pos > 1)
        {
            ptr = ptr->next;
            pos--;
        }
        NODE *preptr = ptr->prev;
        preptr->next = ptr->next;
        (ptr->next)->prev = preptr;
        free(ptr);
        ptr = NULL;
    }
}

// OUTPUT
// *** MAIN MENU ***
// 1. Display Double Linked List
// 2. Add At First
// 3. Add At End
// 4. Add At Any Position
// 5. Search an Element
// 6. Count No. Of Nodes
// 7. Delete From First
// 8. Delete From End
// 9. Delete From Any Position
// 10. Exit
// Enter Choice: 2
// Enter Data: 10
// Enter Choice: 3
// Enter Data: 20
// Enter Choice: 4
// Enter Position: 2
// Enter Data: 30
// Enter Choice: 1
// HEAD <-> 10 <-> 30 <-> 20 -> NULL
// Enter Choice: 5
// Enter Element: 20
// Item found at Node: 3
// Enter Choice: 6
// Number of Nodes: 3
// Enter Choice: 9
// Enter Position: 2
// Enter Choice: 1
// HEAD <-> 10 <-> 20 -> NULL
// Enter Choice: 8
// Enter Choice: 7
// Enter Choice: 1
// HEAD -> NULL
// Enter Choice: 10
