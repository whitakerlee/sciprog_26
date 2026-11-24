#define n 5
#define p 3
#define q 4

void matmult(double A[n][p],
             double B[p][q],
             double C[n][q])
{
    // Initialise C to zero
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            C[i][j] = 0.0;
        }
    }

    // Matrix multiplication
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            for (int k = 0; k < p; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
