#ifndef MAGIC_SQUARE_H
#define MAGIC_SQUARE_H

#include <stdio.h>

// Checks if a matrix is a magic square.
// Returns 1 if the square is magic and 0 otherwise.
int isMagicSquare(int **square, const int n)
{
    // Eliminate invalid matrix sizes
    if (n <= 0)
    {
        return 0;
    }

    // Calculate the magic constant
    int M = (n * (n * n + 1)) / 2;

    int i, j;
    int rowSum, colSum;

    // Check that every row and column adds up to M
    for (i = 0; i < n; i++)
    {
        rowSum = 0;
        colSum = 0;

        for (j = 0; j < n; j++)
        {
            rowSum += square[i][j];
            colSum += square[j][i];
        }

        if (rowSum != M || colSum != M)
        {
            return 0;
        }
    }

    // Check the main and secondary diagonals
    int mainDiag = 0;
    int secondDiag = 0;

    for (i = 0; i < n; i++)
    {
        mainDiag += square[i][i];
        secondDiag += square[i][n - 1 - i];
    }

    if (mainDiag != M || secondDiag != M)
    {
        return 0;
    }

    // If all checks passed, it is a magic square
    return 1;
}

#endif
