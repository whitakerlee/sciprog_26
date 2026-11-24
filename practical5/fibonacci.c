#include <stdio.h>

// Function to calculate next Fibonacci number
void fibonacci(int *a, int *b)
{
    int temp = *a;

    *a = *a + *b;
    *b = temp;
}

int main(void)
{
    int n;
    int a = 1;
    int b = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("n must be a positive value.\n");
        return 1;
    }

    printf("Fibonacci series:\n");

    printf("%d\n", b);

    if (n >= 1)
    {
        printf("%d\n", a);
    }

    for (int i = 2; i <= n; i++)
    {
        fibonacci(&a, &b);
        printf("%d\n", a);
    }

    return 0;
}
