// Write a program to implement Insertion Sort.

#include <stdio.h>
void insertionSort(int arr[], int);

int main()
{
    int arr[] = {3, 7, 5, 9, 1, 6, 2, 8, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    printf("Sorted Array is\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}

void insertionSort(int arr[], int size)
{
    int i, j, curr;
    for (i = 1; i < size; i++)
    {
        curr = arr[i];
        j = i - 1;
        while (j >= 0 && curr < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

// OUTPUT
// Sorted Array is
// 1 2 3 4 5 6 7 8 9

// Worst complexity: n^2
// Average complexity: n^2
// Best complexity: n
// Space complexity: 1
// Method: Insertion
// Stable: Yes
// Class: Comparison sort