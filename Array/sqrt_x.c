// Squareroot of x using binary search
#include <stdio.h>
int mySqrt(int x);
int main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    printf("squareroot of %d is: %d", x, mySqrt(x));
}
int mySqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }
    long int low = 1, mid = 0, high = x, ans = 0;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}