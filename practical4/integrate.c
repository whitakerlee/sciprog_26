#include <stdio.h>
#include <math.h>

double pi = acos(-1.0);

// Global array
float tanvalues[13];

// Convert degrees to radians
float degtorad(float arg) {
	return( (pi * arg)/180.0 ); 
}

// Calculate integral using trapezoidal rule
float trapezoidal(void)
{
    float a = 0.0;
    float b = pi / 3.0;
    int N = 12;

    float sum = tanvalues[0] + tanvalues[12];

    for (int i = 1; i < N; i++)
    {
        sum += 2.0 * tanvalues[i];
    }

    return (b - a) / (2.0 * N) * sum;
}

int main(void)
{
    // Calculate tan(x) and store in array
    for (int i = 0; i <= 12; i++)
    {
        float degrees = i * 5.0;
        float radians = degtorad(degrees);

        tanvalues[i] = tan(radians);
    }

    // Print array
    printf("Degrees\t tan(x)\n");

    for (int i = 0; i <= 12; i++)
    {
        printf("%d\t %.6f\n", i * 5, tanvalues[i]);
    }

    // Calculate integral
    float integral = trapezoidal();

    printf("\nTrapezoidal integral: %.8f\n", integral);

    return 0;
}
