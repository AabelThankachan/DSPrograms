// addition of polynomials using array of structures
#include <stdio.h>
void main()
{
    int term1, term2;
    printf("Enter degree of first and second polynomial: \n");
    scanf("%d %d", &term1, &term2);
    struct
    {
        int coeff;
        int expon;
    } p1[term1 + 1], p2[term2 + 1], p3[term1 + term2 + 1];

    printf("Enter polynomial 1:\n");
    for (int i = 0, j = term1; i <= term1; i++, j--)
    {
        printf("Enter coefficient of x^%d: ", j);
        scanf("%d", &p1[i].coeff);
        p1[i].expon = j;
    }

    printf("Enter polynomial 2:\n");
    for (int i = 0, j = term2; i <= term2; i++, j--)
    {
        printf("Enter coefficient of x^%d: ", j);
        scanf("%d", &p2[i].coeff);
        p2[i].expon = j;
    }
    int length;
    if (term1 > term2)
        length = term1;
    else
        length = term2;

    // Adding the two polynomials
    int i = 0, j = 0, k = 0;
    while (i <= term1 && j <= term2)
    {
        if (p1[i].expon == p2[j].expon)
        {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expon = p2[j].expon;
            i++;
            j++;
            k++;
        }
        else if (p1[i].expon > p2[j].expon)
        {
            p3[k] = p1[i];
            i++;
            k++;
        }
        else
        {
            p3[k] = p2[j];
            j++;
            k++;
        }
    }

    // Display first polynomial
    printf("First polynomial is:\n");
    for (i = 0; i < term1; i++)
    {
        printf("%dx^%d + ", p1[i].coeff, p1[i].expon);
    }
    printf("%dx^%d \n", p1[term1].coeff, p1[term1].expon);

    // Display second polynomial
    printf("Second polynomial is:\n");
    for (i = 0; i < term2; i++)
    {
        printf("%dx^%d + ", p2[i].coeff, p2[i].expon);
    }
    printf("%dx^%d \n", p2[term2].coeff, p2[term2].expon);

    // Display the resultant polynomial
    printf("Resultant polynomial:\n");
    for (i = 0; i < length; i++)
    {
        printf("%dx^%d + ", p3[i].coeff, p3[i].expon);
    }
    printf("%dx^%d", p3[length].coeff, p3[length].expon);
}