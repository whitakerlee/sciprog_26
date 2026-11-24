#include <stdio.h>

#define n 5
#define p 3
#define q 4

// Function declaration
void matmult(double A[n][p],
             double B[p][q],
             double C[n][q]);

int main(void)
{
    double A[n][p];
    double B[p][q];
    double C[n][q];

    // Initialise A
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            A[i][j] = i + j;
        }
    }

    // Initialise B
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            B[i][j] = i - j;
        }
    }

    // Call matrix multiplication function
    matmult(A, B, C);

    // Print A
    printf("Matrix A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
            printf("%8.2f", A[i][j]);

        printf("\n");
    }

    // Print B
    printf("\nMatrix B:\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
            printf("%8.2f", B[i][j]);

        printf("\n");
    }

    // Print C
    printf("\nMatrix C:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
            printf("%8.2f", C[i][j]);

        printf("\n");
    }

    return 0;
}
