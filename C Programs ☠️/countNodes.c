// Write a function to count the number of node present in a linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *createList(NODE *);
int countNodes(NODE *);

int main()
{
    int n;
    NODE *head = NULL;
    head = createList(head);
    n = countNodes(head);
    printf("Number Of Nodes in this Linked List is %d", n);
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

int countNodes(NODE *head)
{
    int count = 0;
    NODE *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

// OUTPUT
// Creating Linked List...
// Enter -1 to end
// Enter the data: 5
// Enter the data: 6
// Enter the data: 7
// Enter the data: 8
// Enter the data: -1
// Number Of Nodes in this Linked List is 4