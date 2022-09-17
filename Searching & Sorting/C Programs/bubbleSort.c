// Write a program to implement Bubble Sort.

#include <stdio.h>
void bubbleSort(int arr[], int);

int main()
{
    int arr[] = {3, 7, 5, 9, 1, 6, 2, 8, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    printf("Sorted Array is\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}

void bubbleSort(int arr[], int size)
{
    int i, j, swap;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
}

// OUTPUT
// Sorted Array is
// 1 2 3 4 5 6 7 8 9

// Worst complexity: n^2
// Average complexity: n^2
// Best complexity: n
// Space complexity: 1
// Method: Exchanging
// Stable: Yes
// Class: Comparison sort