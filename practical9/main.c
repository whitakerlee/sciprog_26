#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square.h"

int getlines(char filename[MAX_FILE_NAME]);

int main(void)
{
    // Define file variable and filename
    FILE *f;
    char filename[MAX_FILE_NAME];

    printf("Enter file name: ");
    scanf("%99s", filename);

    // Get the number of lines in the file
    int n = getlines(filename);

    if (n <= 0)
    {
        printf("Invalid matrix size.\n");
        return 1;
    }

    // Open the file
    f = fopen(filename, "r");

    if (f == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int i, j;

    // Allocate an array of pointers
    int **square = malloc(n * sizeof(int *));

    if (square == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(f);
        return 1;
    }

    // Allocate memory for each row
    for (i = 0; i < n; i++)
    {
        square[i] = malloc(n * sizeof(int));

        if (square[i] == NULL)
        {
            printf("Memory allocation failed.\n");

            for (j = 0; j < i; j++)
            {
                free(square[j]);
            }

            free(square);
            fclose(f);
            return 1;
        }
    }

    // Read integer data into the matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (fscanf(f, "%d", &square[i][j]) != 1)
            {
                printf("Invalid matrix data.\n");

                for (int k = 0; k < n; k++)
                {
                    free(square[k]);
                }

                free(square);
                fclose(f);
                return 1;
            }
        }
    }

    // Print the matrix
    printf("\nMatrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%5d", square[i][j]);
        }

        printf("\n");
    }

    // Check whether the matrix is magic
    if (isMagicSquare(square, n))
    {
        printf("\nThis is a magic square.\n");
    }
    else
    {
        printf("\nThis is not a magic square.\n");
    }

    // Free each row separately
    for (i = 0; i < n; i++)
    {
        free(square[i]);
    }

    // Free the array of pointers
    free(square);

    // Close the file
    fclose(f);

    return 0;
}

// Count the number of lines in the file
int getlines(char filename[MAX_FILE_NAME])
{
    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Could not open file.\n");
        return -1;
    }

    int ch_read;
    int last_ch = '\n';
    int count = 0;

    while ((ch_read = fgetc(fp)) != EOF)
    {
        if (ch_read == '\n')
        {
            count++;
        }

        last_ch = ch_read;
    }

    // Count the final line if it has no newline
    if (last_ch != '\n')
    {
        count++;
    }

    printf("No. lines: %d\n", count);

    fclose(fp);

    return count;
}
