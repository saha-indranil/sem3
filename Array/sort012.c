/*
Given an array of size N containing only 0s, 1s, and2s;
Sort the array in ascending order.
Expected Time Complexity : O(N)
Expected Auxiliary Space : O(1)
INPUT: 0 1 2 2 1 0 2 1
OUTPUT: 0 0 1 1 1 2 2 2
*/

#include <stdio.h>

void swap(int *x, int *y);
void sort012(int arr[], int n);

int main()
{
    int n, arr[10], i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    sort012(arr, n);
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    return 0;
}

void sort012(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}