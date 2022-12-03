// 10. Write a C program to modify the size of an array and utilize that during run time.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr, n, m;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", arr + i);
    }

    printf("\nHow many extra elements you want to add: ");
    scanf("%d", &m);
    arr = (int *)realloc(arr, sizeof(int) * (m + n));

    for (int i = n; i < m + n; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", arr + i);
    }

    printf("\nNew array after reallocation is\n");
    for (int i = 0; i < m + n; i++)
    {
        printf("%d ", *(arr + i));
    }

    free(arr);
    return 0;
}

// OUTPUT
// Enter size of the array: 2
// Enter Array[0]: 2
// Enter Array[1]: 4

// How many extra elements you want to add: 2
// Enter Array[2]: 6
// Enter Array[3]: 8

// New array after reallocation is
// 2 4 6 8