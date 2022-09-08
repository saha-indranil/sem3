// 7. Write a C program to merge two sorted dynamic array.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr1, *arr2, *arr3;
    int m, n, i;
    printf("Enter Size of first Array: ");
    scanf("%d", &m);
    printf("Enter Size of second Array: ");
    scanf("%d", &n);
    arr1 = (int *)malloc(m * sizeof(int));
    arr2 = (int *)malloc(n * sizeof(int));
    arr3 = (int *)malloc((m + n) * sizeof(int));

    // Getting array elements
    for (i = 0; i < m; i++)
    {
        printf("Enter first Array[%d]: ", i);
        scanf("%d", arr1 + i);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter Second Array[%d]: ", i);
        scanf("%d", arr2 + i);
    }

    // Merging Both Arrays
    i = 0;
    int j = 0, k = 0;
    while (i < m && j < n)
    {
        if (*(arr1 + i) < *(arr2 + j))
        {
            *(arr3 + k) = *(arr1 + i);
            k++;
            i++;
        }
        else
        {
            *(arr3 + k) = *(arr2 + j);
            k++;
            j++;
        }
    }
    while (i < m)
    {
        *(arr3 + k) = *(arr1 + i);
        k++;
        i++;
    }
    while (j < n)
    {
        *(arr3 + k) = *(arr2 + j);
        k++;
        j++;
    }

    printf("\nPrintng Merged Array\n");
    for (i = 0; i < m + n; i++)
    {
        printf("%d ", *(arr3 + i));
    }

    free(arr1);
    free(arr2);
    free(arr3);
    return 0;
}

// OUTPUT
// Enter Size of first Array: 4
// Enter Size of second Array: 3
// Enter first Array[0]: 1
// Enter first Array[1]: 4
// Enter first Array[2]: 9
// Enter first Array[3]: 10

// Enter Second Array[0]: 2
// Enter Second Array[1]: 3
// Enter Second Array[2]: 12

// Printng Merged Array
// 1 2 3 4 9 10 12