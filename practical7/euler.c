#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int order;

    printf("Enter polynomial order (1-15): ");
    if (scanf("%d", &order) != 1 || order < 1 || order > 15)
    {
        printf("Please enter an integer between 1 and 15.\n");
        return 1;
    }

    // Dynamically allocate array
    double *terms = malloc((order + 1) * sizeof(double));

    if (terms == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Calculate each term of the series
    terms[0] = 1.0;

    for (int i = 1; i <= order; i++)
    {
        terms[i] = terms[i - 1] / i;
    }

    // Sum the terms and compare with exact value
    double estimate = 0.0;
    double exact = exp(1.0);

    for (int i = 0; i <= order; i++)
    {
        estimate += terms[i];

	printf("\nPolynomial order: %d\n", i);
        printf("Estimated e:     %.15f\n", estimate);
        printf("Exact e:         %.15f\n", exact);
        printf("Difference:      %.15e\n", fabs(estimate - exact));
        printf("Percentage error: %.15e%%\n", fabs(estimate - exact) / exact * 100.0);
    }

    // Free allocated memory
    free(terms);

    return 0;
}
