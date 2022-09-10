// Create an Array With a Missing number &a Repeating Number
// Enter Range: 5 [Elements should be between 1 to n]
// Example : 3 4 4 1 5
// Missing Number=2 , Repeating Number = 4

#include <stdio.h>
#include <stdlib.h>
void getTwoElements(int arr[], int n, int *x, int *y);
int main()
{
    int n, arr[10], i, result = 0, missing, repeating;
    printf("Enter Range: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Array[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int *x = (int *)malloc(sizeof(int));
    int *y = (int *)malloc(sizeof(int));
    getTwoElements(arr, n, x, y);
    printf("The missing element is %d\nThe repeating element is %d", *x, *y);
    getchar();
}
void getTwoElements(int arr[], int n, int *x, int *y)
{
    int xor1 = arr[0], setBitNo, i;
    *x = *y = 0;
    // Get XOR of all array elements
    for (i = 1; i < n; i++)
    {
        xor1 = xor1 ^ arr[i];
    }
    // XOR the previous result number with numbers from 1 to n
    for (i = 1; i <= n; i++)
    {
        xor1 = xor1 ^ i;
    }

    // Now, xor1 = missing number ^ repeating number
    // Get the rightmost set bit in setBitNo

    setBitNo = xor1 & ~(xor1 - 1);

    /*Now divide elements in two sets by comparing rightmost
    set bit of xor1 with bit at same position in each element.
    Also, get XORs of two sets. The two XORs are the output
    elements. The following two for loops serve the purpose.*/

    for (i = 0; i < n; i++)
    {
        if (arr[i] & setBitNo) // arr[i] belongs to first set
        {
            *x = *x ^ arr[i];
        }
        else // arr[i] belongs to second set
        {
            *y = *y ^ arr[i];
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (i & setBitNo) // i belongs to first set
        {
            *x = *x ^ i;
        }
        else // i belongs to second set
        {
            *y = *y ^ i;
        }
    }
}