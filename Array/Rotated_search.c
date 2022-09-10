// a = [ 10, 20, 30, 40, 50, 60, 70 ] 0 times rotated array
// a = [ 60, 70, 10, 20, 30, 40, 50 ] 2 times rotated array
// a = [ 40, 50, 60, 70, 10, 20, 30 ] 4 times rotated array
// a = [ 20, 30, 40, 50, 60, 70, 10 ] 6 times rotated array
// Search an element in a sorted and rotated array

#include <stdio.h>
int binarySearch(int arr[], int n, int key);
int main()
{
    int arr[10], n, key, i, result;
    printf("Enter Number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter Key: ");
    scanf("%d", &key);
    result = binarySearch(arr, n, key);
    printf("Index: %d", result);
    return 0;
}
int binarySearch(int arr[], int n, int key)
{
    int low = 0, mid, high = n - 1;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        if (arr[mid] == key)
        {
            return mid;
        }
        // Left Part of mid is sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= key && key < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // Right part of mid is sorted
        else
        {
            if (arr[mid] < key && key <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// int search(int *nums, int numsSize, int target)
// {
//     int lo, hi;

//     for (lo = 0, hi = numsSize - 1; lo <= hi;)
//     {
//         int mid = (lo + hi) / 2;

//         if (nums[mid] == target)
//         {
//             return mid;
//         }

//         if (nums[lo] <= nums[mid])
//         {
//             // we are on the left of the peak
//             if (nums[lo] <= target && target < nums[mid])
//             {
//                 // go left
//                 hi = mid - 1;
//             }
//             else
//             {
//                 lo = mid + 1;
//             }
//         }
//         else
//         {
//             // we are on the right of the peak
//             if (nums[mid] < target && target <= nums[hi])
//             {
//                 // go right
//                 lo = mid + 1;
//             }
//             else
//             {
//                 hi = mid - 1;
//             }
//         }
//     }

//     return -1;
// }