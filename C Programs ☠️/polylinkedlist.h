// 👇👇 Start writing from here 👇👇

// This is polylinkedlist.h header file
// for polynomial linked list creation and display

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;
    int expo;
    struct node *next;
} NODE;

NODE *create(NODE *head)
{
    int n, i, coeff, expo;
    printf("Enter the Number of Terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%d", &coeff);

        printf("Enter the Exponent of term %d: ", i + 1);
        scanf("%d", &expo);

        head = insert(head, coeff, expo);
    }
    return head;
}

NODE *insert(NODE *head, int co, int ex)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    NODE *ptr;
    newNode->coeff = co;
    newNode->expo = ex;

    if (head == NULL || ex < head->expo)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL && ex > ptr->next->expo)
        {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    return head;
}

void display(NODE *head)
{
    if (head == NULL)
    {
        printf("No Polynomial");
        exit(1);
    }
    printf("Polynomial Equation is\n");
    NODE *ptr = head;
    while (ptr != NULL)
    {
        printf("( %dx^%d )", ptr->coeff, ptr->expo);
        ptr = ptr->next;
        if (ptr != NULL)
        {
            printf(" + ");
        }
    }
}