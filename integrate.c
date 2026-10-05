#include <stdio.h>
#include <math.h>

int main(void)
{
    double pi = acos(-1.0);
    double a = 0.0;
    double b = pi / 3.0;
    int N = 12;

    // Calculate spacing between points
    double h = (b - a) / N;

    // Start with the two endpoints
    double sum = tan(a) + tan(b);

    // Add the 11 interior points
    for (int i = 1; i < N; i++)
    {
        double x = a + i * h;
        sum += 2.0 * tan(x);
    }

    // Apply trapezoidal rule
    double integral = (b - a) / (2.0 * N) * sum;

    // Calculate exact result
    double exact = log(2.0);

    // Compare results
    double difference = fabs(integral - exact);
    double percentage = difference / exact * 100.0;

    printf("Trapezoidal approximation: %.10f\n", integral);
    printf("Exact result:             %.10f\n", exact);
    printf("Absolute difference:      %.10f\n", difference);
    printf("Percentage error:         %.6f%%\n", percentage);

    return 0;
}
