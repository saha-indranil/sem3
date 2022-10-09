// Write a program to implement Quick sort.

#include <stdio.h>

int partition(int arr[], int, int);
void quickSort(int arr[], int, int);
void swap(int *, int *);

int main()
{
    int arr[] = {3, 7, 5, 9, 1, 6, 2, 8, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    printf("Sorted Array is\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// OUTPUT
// Sorted Array is
// 1 2 3 4 5 6 7 8 9

// Class Sorting algorithm
// Worst-case performance	 O(n^2)
// Best-case performance	 O(nlog n) (simple partition) or  O(n) (three-way partition and equal keys)
// Average performance	 O(nlog n)
// Worst-case space complexity	 O(n) auxiliary(naive) O(log n) auxiliary(Hoare 1962)
