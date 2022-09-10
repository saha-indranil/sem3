/*
Given an array Arr[] of N integers.
Find the contiguous sub-array(containing at least one number)
which has the maximum sum and return its sum.
Input:
Arr[] = {-5, 4, 6, -3, 4, -2}
Output:
11
Explanation:
Max subarray sum is 11
of elements (4, 6, -3, 4) which is a contiguous subarray.
*/

#include <stdio.h>
#include <limits.h>
#define MAX(a, b) (a > b ? a : b)

int maxSubarray(int arr[], int n);
int main()
{
    int arr[10], n, maxSum, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    maxSum = maxSubarray(arr, n);
    printf("Max Subarray Sum is %d", maxSum);
    return 0;
}

int maxSubarray(int arr[], int n)
{
    int maxSum = INT_MIN, currSum = 0, i;
    for (i = 0; i < n; i++)
    {
        currSum = MAX(currSum + arr[i], arr[i]);
        maxSum = MAX(maxSum, currSum);
    }
    return maxSum;
}