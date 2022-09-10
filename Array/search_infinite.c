// Find position of an element in a sorted array of infinite numbers
#include <stdio.h>
int searchInfinite(int arr[], int key);
int binarySearch(int arr[], int low, int high, int key);
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
    index = searchInfinite(arr, key);
    printf("Key found at Index: %d", index);
    return 0;
}
int searchInfinite(int arr[], int key)
{
    int low = 0, high = 1, val = arr[0];
    while (arr[high] < key)
    {
        low = high;
        high = high << 1;
        val = arr[high];
    }
    return binarySearch(arr, low, high, key);
}
int binarySearch(int arr[], int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) >> 1;
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