// Write a C program to solve the tower of Hanoi using stack.

#include <stdio.h>
void move(int, char, char, char);
int main()
{
    int n;
    printf("Enter Number of Rings: ");
    scanf("%d", &n);
    move(n, 'A', 'C', 'B');
    printf("Tower of Hanoi Solved!");
    return 0;
}

void move(int n, char src, char dest, char spare)
{
    if (n > 0)
    {
        move(n - 1, src, spare, dest);
        printf("Move disk %d from %c to %c \n", n, src, dest);
        move(n - 1, spare, dest, src);
    }
}

// OUTPUT
// Enter Number of Rings: 3
// Move disk 1 from A to C
// Move disk 2 from A to B
// Move disk 1 from C to B
// Move disk 3 from A to C
// Move disk 1 from B to A
// Move disk 2 from B to C
// Move disk 1 from A to C
// Tower of Hanoi Solved!