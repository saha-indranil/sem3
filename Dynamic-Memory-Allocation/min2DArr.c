// 6. Write a C program to find the minimum element in
//    a 2D - array using dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col, *arr, min;
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

    // searching min element
    min = *(arr + 0);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (*(arr + (i * col + j)) < min)
            {
                min = *(arr + (i * col + j));
            }
        }
    }
    printf("Minimum Element is %d", min);
    free(arr);
    return 0;
}

// OUTPUT
// Enter Number of Rows: 2
// Enter Number of Columns: 2
// Enter Array[0][0]: 5
// Enter Array[0][1]: 7
// Enter Array[1][0]: 3
// Enter Array[1][1]: 9
// Minimum Element is 3