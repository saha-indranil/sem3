// Write a C program to perform multiplication
// of two polynomials using linked list

#include "polynomialLL.h"

NODE *polyMult(NODE *, NODE *);

int main()
{
    NODE *poly1 = NULL, *poly2 = NULL;

    printf("Enter First Polynomial\n");
    poly1 = create(poly1);
    display(poly1);

    printf("\nEnter Second Polynomial\n");
    poly2 = create(poly2);
    display(poly2);

    NODE *product = polyMult(poly1, poly2);
    printf("\nPolynomial Multiplied\n");
    display(product);
    return 0;
}

NODE *polyMult(NODE *p1, NODE *p2)
{
    NODE *product = NULL;
    if (p1 == NULL || p2 == NULL)
    {
        printf("Cannot Multiply");
        return product;
    }
    NODE *poly1 = p1, *poly2 = p2;
    int co, ex;
    while (poly1 != NULL)
    {
        while (poly2 != NULL)
        {
            co = poly1->coeff * poly2->coeff;
            ex = poly1->expo + poly2->expo;
            product = insert(product, co, ex);
            poly2 = poly2->next;
        }
        poly1 = poly1->next;
        poly2 = p2;
    }
    return product;
}

// OUTPUT
// Enter First Polynomial
// Enter the Number of Terms: 3
// Enter the coefficient of term 1: 4
// Enter the Exponent of term 1: 2
// Enter the coefficient of term 2: 7
// Enter the Exponent of term 2: 1
// Enter the coefficient of term 3: 9
// Enter the Exponent of term 3: 0
// Polynomial Equation is
// ( 4x^2 ) + ( 7x^1 ) + ( 9x^0 )
// Enter Second Polynomial
// Enter the Number of Terms: 2
// Enter the coefficient of term 1: 6
// Enter the Exponent of term 1: 1
// Enter the coefficient of term 2: 3
// Enter the Exponent of term 2: 0
// Polynomial Equation is
// ( 6x^1 ) + ( 3x^0 )
// Polynomial Multiplied
// Polynomial Equation is
// ( 24x^3 ) + ( 42x^2 ) + ( 12x^2 ) + ( 54x^1 ) + ( 21x^1 ) + ( 27x^0 )
