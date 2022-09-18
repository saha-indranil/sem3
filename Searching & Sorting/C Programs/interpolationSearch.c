// Write a program to implement interpolation search.

#include <stdio.h>
int interpolationSearch(int arr[], int, int, int);
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9;
    int index = interpolationSearch(arr, 0, size - 1, key);
    if (index == -1)
        printf("Item not found!");
    else
        printf("%d found at Index: %d", key, index);
    return 0;
}

int interpolationSearch(int arr[], int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) * ((key - arr[low]) / (arr[high] - arr[low]));
        if (key == arr[mid])
            return mid;
        if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// OUTPUT
// 9 found at Index: 4

// When n elements of a list to be sorted are uniformly distributed (average case), interpolation
// search makes about log(log n) comparisons. However, in the worst case, that is when the elements
// increase exponentially, the algorithm can make up to O(n) comparisons.
// Class : Search algorithm
// Data structure : Array
// Worst-case performance :	O(n)
// Best-case performance : O(1)
// Average performance : O(log(log(n)))
// Worst-case space complexity : O(1)