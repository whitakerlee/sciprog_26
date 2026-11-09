#include <stdio.h>
#include <stdlib.h>

// Calculate GCD using the iterative method
int gcd_iterative(int a, int b)
{
    int temp;

    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

// Calculate GCD using the recursive method
int gcd_recursive(int a, int b)
{
    // Base case
    if (b == 0)
    {
        return a;
    }

    // Recursive case
    else
    {
        return gcd_recursive(b, a % b);
    }
}

int main(void)
{
    int a, b;

    // Get two integers from the user
    printf("Enter two integers: ");

    if (scanf("%d %d", &a, &b) != 2)
    {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert negative integers to positive
    a = abs(a);
    b = abs(b);

    // Calculate GCD using both methods
    int iterative = gcd_iterative(a, b);
    int recursive = gcd_recursive(a, b);

    // Print results
    printf("\nIterative GCD: %d\n", iterative);
    printf("Recursive GCD: %d\n", recursive);

    return 0;
}
