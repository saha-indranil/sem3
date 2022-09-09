// 3. Write a C program to find the minimum element
//    in an array using dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *arr, min;
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
    for (i = 0; i < n; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", arr + i);
    }

    min = *(arr + 0);
    for (i = 1; i < n; i++)
    {
        if (min > *(arr + i))
        {
            min = *(arr + i);
        }
    }

    free(arr);
    printf("Minimum Element is: %d", min);
    return 0;
}

// OUTPUT
// Enter Total Number of Elements: 5
// Enter Array[0]: 9
// Enter Array[1]: 8
// Enter Array[2]: 2
// Enter Array[3]: 7
// Enter Array[4]: 4
// Minimum Element is: 2