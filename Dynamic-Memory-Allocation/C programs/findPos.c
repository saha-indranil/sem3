// 2. Write a C program to find the 3rd / user defined position based
//    maximum element in an array using dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *arr, rank;
    int i, j, temp;
    printf("Enter Total Number of Elements (Minimum 3): ");
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
    printf("Enter Rank: ");
    scanf("%d", &rank);
    if (rank > n)
    {
        printf("Error!");
        exit(0);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (*(arr + j) > *(arr + (j + 1)))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + (j + 1));
                *(arr + (j + 1)) = temp;
            }
        }
    }

    printf("3rd Maximum Number: %d \n", *(arr + (n - 3)));
    printf("%dth Maximum Number: %d \n", rank, *(arr + (n - rank)));
    free(arr);
    return 0;
}

// OUTPUT
// Enter Total Number of Elements (Minimum 3): 5
// Enter Array[0]: 7
// Enter Array[1]: 4
// Enter Array[2]: 9
// Enter Array[3]: 1
// Enter Array[4]: 3
// Enter Rank: 4
// 3rd Maximum Number: 4
// 4th Maximum Number: 3