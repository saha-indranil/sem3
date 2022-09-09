// 5. Write a C program to find the maximum element in
//    a 2D - array using dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col, *arr, max;
    printf("Enter Number of Rows: ");
    scanf("%d", &row);
    printf("Enter Number of Columns: ");
    scanf("%d", &col);

    arr = (int *)malloc(row * col * sizeof(int));

    // storing numbers entered by the user
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter Array[%d][%d]: ", i, j);
            scanf("%d", arr + (i * col + j));
        }
    }

    // searching max element
    max = *(arr + 0);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (*(arr + (i * col + j)) > max)
            {
                max = *(arr + (i * col + j));
            }
        }
    }
    printf("Maximum Element is %d", max);
    free(arr);
    return 0;
}

// OUTPUT
// Enter Number of Rows: 2
// Enter Number of Columns: 2
// Enter Array[0][0]: 8
// Enter Array[0][1]: 4
// Enter Array[1][0]: 6
// Enter Array[1][1]: 7
// Maximum Element is 8