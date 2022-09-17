// Binary Search in C

#include <stdio.h>

int binarySearch(int arr[], int n, int key);

int main()
{
    int n, key, index;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    n = 9;
    key = 6;
    index = binarySearch(arr, n, key);
    printf("Key found at Index: %d", index);
    return 0;
}

int binarySearch(int arr[], int n, int key)
{
    int low = 0, mid, high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
    }
    return -1;
}