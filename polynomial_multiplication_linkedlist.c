// multiplication of polynomials using arrays
#include <stdio.h>

struct Term
{
    int coeff;
    int expon;
};

// Function to read a polynomial
void readPolynomial(struct Term *poly, int degree)
{
    for (int i = 0, j = degree; i <= degree; i++, j--)
    {
        printf("Enter coefficient of x^%d: ", j);
        scanf("%d", &poly[i].coeff);
        poly[i].expon = j;
    }
}

// Function to display a polynomial
void displayPolynomial(struct Term *poly, int degree)
{
    for (int i = 0; i <= degree; i++)
    {
        if (poly[i].coeff != 0)
        {
            printf("%dx^%d", poly[i].coeff, poly[i].expon);
            if (i < degree)
            {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

// Function to add two polynomials
void addPolynomials(struct Term *p1, int term1, struct Term *p2, int term2, struct Term *result, int *length)
{
    int i = 0, j = 0, k = 0;

    while (i <= term1 && j <= term2)
    {
        if (p1[i].expon == p2[j].expon)
        {
            result[k].coeff = p1[i].coeff + p2[j].coeff;
            result[k].expon = p2[j].expon;
            i++;
            j++;
            k++;
        }
        else if (p1[i].expon > p2[j].expon)
        {
            result[k] = p1[i];
            i++;
            k++;
        }
        else
        {
            result[k] = p2[j];
            j++;
            k++;
        }
    }

    // Copy the remaining terms from the longer polynomial
    while (i <= term1)
    {
        result[k] = p1[i];
        i++;
        k++;
    }

    while (j <= term2)
    {
        result[k] = p2[j];
        j++;
        k++;
    }

    // Set the length of the result polynomial
    *length = k - 1;
}

// Function to multiply two polynomials
void multiplyPolynomials(struct Term *p1, int term1, struct Term *p2, int term2, struct Term *result, int *length)
{
    // Initialize the result array with zeros
    for (int i = 0; i <= term1 + term2; i++)
    {
        result[i].coeff = 0;
        result[i].expon = 0;
    }

    // Multiply each term of p1 with each term of p2
    for (int i = 0; i <= term1; i++)
    {
        for (int j = 0; j <= term2; j++)
        {
            // Multiply coefficients and add exponents
            result[i + j].coeff += p1[i].coeff * p2[j].coeff;
            result[i + j].expon = p1[i].expon + p2[j].expon;
        }
    }

    // Combine terms with the same exponent
    for (int i = 0; i <= term1 + term2; i++)
    {
        for (int j = i + 1; j <= term1 + term2; j++)
        {
            if (result[i].expon == result[j].expon)
            {
                result[i].coeff += result[j].coeff;
                result[j].coeff = 0;
                result[j].expon = 0;
            }
        }
    }

    // Set the length of the result polynomial
    *length = term1 + term2;
}

int main()
{
    int term1, term2;
    printf("Enter degree of first and second polynomial: \n");
    scanf("%d %d", &term1, &term2);

    struct Term p1[term1 + 1], p2[term2 + 1], p3[term1 + term2 + 1], p4[term1 * term2 + 1];

    printf("Enter polynomial 1:\n");
    readPolynomial(p1, term1);

    printf("Enter polynomial 2:\n");
    readPolynomial(p2, term2);

    int length;

    // Add polynomials
    addPolynomials(p1, term1, p2, term2, p3, &length);

    // Multiply polynomials
    multiplyPolynomials(p1, term1, p2, term2, p4, &length);

    // Display polynomials
    printf("First polynomial is:\n");
    displayPolynomial(p1, term1);

    printf("Second polynomial is:\n");
    displayPolynomial(p2, term2);

    // Display the resultant polynomials
    printf("Resultant polynomial after addition:\n");
    displayPolynomial(p3, length);

    printf("Resultant polynomial after multiplication:\n");
    displayPolynomial(p4, length);

    return 0;
}
