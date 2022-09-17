// Write a program to implement Selection Sort.

#include <stdio.h>
void selectionSort(int arr[], int);

int main()
{
    int arr[] = {3, 7, 5, 9, 1, 6, 2, 8, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    printf("Sorted Array is\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}

void selectionSort(int arr[], int size)
{
    int i, j, smallest, swap;
    for (i = 0; i < size - 1; i++)
    {
        smallest = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[smallest])
            {
                smallest = j;
            }
        }
        swap = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = swap;
    }
}

// OUTPUT
// Sorted Array is
// 1 2 3 4 5 6 7 8 9

// Worst complexity: n^2
// Average complexity: n^2
// Best complexity: n^2
// Space complexity: 1
// Method: Selection
// Stable: No
// Class: Comparison sort