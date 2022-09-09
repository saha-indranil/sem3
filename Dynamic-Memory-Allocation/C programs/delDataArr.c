// 9. Write a C program to delete a range
//    of data from a dynamic array.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr, n, i, left, right;
    printf("Enter Size of the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", arr + i);
    }

    printf("Enter left index to delete: "); // Should be between 0 to n and <=right index
    scanf("%d", &left);
    printf("Enter right index to delete: "); // Should be between 0 to n and >=left index
    scanf("%d", &right);

    for (i = right; i < n; i++)
    {
        *(arr + left) = *(arr + (right + 1));
        left++;
        right++;
    }
    arr = (int *)realloc(arr, (n + left - right - 1) * sizeof(int));

    printf("\nFinal Array is\n");
    for (i = 0; i < n + left - right - 1; i++)
    {
        printf("%d ", *(arr + i));
    }

    free(arr);
    return 0;
}

// OUTPUT
// Enter Size of the array: 7
// Enter Array[0]: 2
// Enter Array[1]: 4
// Enter Array[2]: 6
// Enter Array[3]: 8
// Enter Array[4]: 10
// Enter Array[5]: 12
// Enter Array[6]: 14
// Enter left index to delete: 2
// Enter right index to delete: 4

// Final Array is
// 2 4 12 14