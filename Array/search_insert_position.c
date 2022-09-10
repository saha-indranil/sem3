// https://leetcode.com/problems/search-insert-position/description/

#include <stdio.h>
int searchInsert(int nums[], int numsSize, int target);
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
    index = searchInsert(arr, n, key);
    printf("Key should be inserted at Index: %d", index);
    return 0;
}
int searchInsert(int nums[], int numsSize, int target)
{
    int low = 0, mid, high = numsSize - 1;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
    }
    return low;
}