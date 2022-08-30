// Please write down this header file one time and
// mention #include "singlylinkedlist.h" in all other programs
// We don't have to write this 50 lines of code in every code
// 👇👇 Start writing from here 👇👇

// This is singlylinkedlist.h file
// This header file contains Structure of linked list,
// createList and displayList function

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

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
