// 1. Write a C program to search an element in an Array using dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *arr, key, flag = 0;
    printf("Enter Total Number of Elements: ");
    scanf("%d", &n);

    // Allocating Memory for n elements
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory is not allocated");
        exit(0);
    }

    // storing numbers entered by the user
    for (int i = 0; i < n; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", arr + i);
    }

    printf("Enter an Element to find index: ");
    scanf("%d", &key);

    // Searching the element
    for (int i = 0; i < n; i++)
    {
        if (*(arr + i) == key)
        {
            flag = 1;
            printf("Element found at index %d", i);
            break;
        }
    }
    if (flag == 0)
    {
        printf("Number is not available");
    }

    free(arr);
    return 0;
}