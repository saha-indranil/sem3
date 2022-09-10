/* Given an unsorted array A of size N that contains only non-negative integers,
find a continuous sub-array which adds to a given number S.
In case of multiple subarrays, return the subarray which comes first on moving from left to right.

INPUT: A[]={1, 4, 20, 3, 10, 5} and SUM=33
OUTPUT: a[2] to a[4]
*/

#include <stdio.h>
void subarraySum(int arr[], int n, int sum);
int main()
{
    int arr[10], n, sum, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter Targeted Sum: ");
    scanf("%d", &sum);
    subarraySum(arr, n, sum);
    return 0;
}

void subarraySum(int arr[], int n, int sum)
{
    int currentSum = 0, left = 0, right = 0;
    while (left < n && right < n)
    {
        if (currentSum < sum)
        {
            currentSum += arr[right++];
        }
        if (currentSum > sum)
        {
            currentSum -= arr[left++];
        }
        if (currentSum == sum)
        {
            printf("Subarray found from array[%d] to array[%d]", left, right - 1);
            break;
        }
    }
    if (currentSum != sum)
    {
        printf("Subarray not found");
    }
}