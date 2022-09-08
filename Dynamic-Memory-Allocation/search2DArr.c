// 4. Write a C program to search an element in a
//    2D - Array using dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col, *arr, key, flag = 0;
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

    printf("Enter an Element to find index: ");
    scanf("%d", &key);

    // searching element
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (*(arr + (i * col + j)) == key)
            {
                flag = 1;
                printf("\nElement found at Array[%d][%d]", i, j);
                break;
            }
        }
    }

    if (flag == 0)
    {
        printf("\nNumber is not available");
    }

    free(arr);
    return 0;
}

// OUTPUT
// Enter Number of Rows: 2
// Enter Number of Columns: 3
// Enter Array[0][0]: 1
// Enter Array[0][1]: 2
// Enter Array[0][2]: 3
// Enter Array[1][0]: 4
// Enter Array[1][1]: 5
// Enter Array[1][2]: 6
// Enter an Element to find index: 4

// Element found at Array[1][0]