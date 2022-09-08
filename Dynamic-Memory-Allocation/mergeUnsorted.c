// 8. Write a C program to merge two unsorted
//    dynamic array in sorted order

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n);
void sortedMerge(int *arr1, int *arr2, int *res, int m, int n);

int main()
{
    int *arr1, *arr2, *res;
    int n, m, i;
    printf("Enter Size of first Array: ");
    scanf("%d", &m);
    printf("Enter Size of second Array: ");
    scanf("%d", &n);
    arr1 = (int *)malloc(m * sizeof(int));
    arr2 = (int *)malloc(n * sizeof(int));
    res = (int *)malloc((m + n) * sizeof(int));

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

    sortedMerge(arr1, arr2, res, m, n);

    printf("\nThe merged and sorted array is\n");
    for (i = 0; i < m + n; i++)
    {
        printf("%d ", *(res + i));
    }

    free(arr1);
    free(arr2);
    free(res);
    return 0;
}

void bubbleSort(int *arr, int n)
{
    int i, j, temp;
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
}

void sortedMerge(int *arr1, int *arr2, int *res, int m, int n)
{
    int i, j = 0;
    for (i = 0; i < m; i++)
    {
        *(res + j) = *(arr1 + i);
        j++;
    }
    for (i = 0; i < n; i++)
    {
        *(res + j) = *(arr2 + i);
        j++;
    }
    bubbleSort(res, m + n);
}

// OUTPUT
// Enter Size of first Array: 3
// Enter Size of second Array: 4
// Enter first Array[0]: 7
// Enter first Array[1]: 2
// Enter first Array[2]: 9

// Enter Second Array[0]: 4
// Enter Second Array[1]: 6
// Enter Second Array[2]: 2
// Enter Second Array[3]: 8

// The merged and sorted array is
// 2 2 4 6 7 8 9