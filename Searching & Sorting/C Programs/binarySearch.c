// Binary Search in C

#include <stdio.h>

int binarySearch(int arr[], int n, int key);

int main()
{
    int arr[10], n, key, index;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter Key: ");
    scanf("%d", &key);
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