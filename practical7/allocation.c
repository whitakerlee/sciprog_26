#include <stdio.h>
#include <stdlib.h>

// Allocate an array of integers
int *allocatearray(int size)
{
    return malloc(size * sizeof(int));
}

// Fill array with ones
void fillwithones(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 1;
    }
}

// Print array
void printarray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

// Free allocated memory
void freearray(int *array)
{
    free(array);
}

int main(void)
{
    int size;

    printf("Enter array size: ");
    if (scanf("%d", &size) != 1 || size <= 0)
    {
        printf("Invalid array size.\n");
        return 1;
    }

    // Allocate memory
    int *array = allocatearray(size);

    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Fill array
    fillwithones(array, size);

    // Print array
    printf("Array contents:\n");
    printarray(array, size);

    // Free memory
    freearray(array);

    return 0;
}
