// Write a program to implement binary search.

#include <stdio.h>

int binarySearch(int arr[], int n, int key);

int main()
{
    int n, key, index;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    n = sizeof(arr) / sizeof(arr[0]);
    key = 6;
    index = binarySearch(arr, n, key);
    if (index == -1)
        printf("Item not found!");
    else
        printf("%d found at Index: %d", key, index);
    return 0;
}

int binarySearch(int arr[], int n, int key)
{
    int low = 0, mid, high = n - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else if (arr[mid] > key)
            high = mid - 1;
    }
    return -1;
}

// OUTPUT
// 6 found at Index: 5

// Worst complexity: O(log n)
// Average complexity: O(log n)
// Best complexity: O(1)
// Space complexity: O(1)
// Data structure: Array
// Class: Search algorithm