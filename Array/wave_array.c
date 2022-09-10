/*
Sort the array into a wave-like array(In Place).
In other words, arrange the elements into a sequence such that
arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5]...
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).
*/

#include <stdio.h>
void sortinWave(int arr[], int n);
void swap(int *x, int *y);
int main()
{
    int arr[10], n, i, temp;
    printf("Enter Number of Elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    sortinWave(arr, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void sortinWave(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i += 2)
    {
        if (i > 0 && arr[i - 1] > arr[i])
        {
            swap(&arr[i - 1], &arr[i]);
        }
        if (i < n - 1 && arr[i] < arr[i + 1])
        {
            swap(&arr[i], &arr[i + 1]);
        }
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}