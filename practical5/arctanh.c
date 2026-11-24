#include <stdio.h>
#include <math.h>

#define N 181

// Method 1: Maclaurin series
double artanh1(double x, double delta)
{
    double sum = 0.0;
    double power = x;
    double term;
    int n = 0;

    do
    {
        term = power / (2 * n + 1);

        if (fabs(term) < delta)
        {
            break;
        }

        sum += term;

        power = power * x * x;
        n++;

    } while (1);

    return sum;
}

// Method 2: Natural logarithms
double artanh2(double x)
{
    return 0.5 * (log(1.0 + x) - log(1.0 - x));
}

int main(void)
{
    double delta;
    double values1[N];
    double values2[N];

    printf("Enter precision delta: ");
    if (scanf("%lf", &delta) != 1 || delta <= 0.0)
    {
        printf("Please enter a positive number.\n");
        return 1;
    }

    // Calculate values for x from -0.9 to 0.9
    for (int i = 0; i < N; i++)
    {
        double x = -0.9 + i * 0.01;

        values1[i] = artanh1(x, delta);
        values2[i] = artanh2(x);
    }

    // Print column headings
	printf("\n%8s %18s %18s %18s %18s\n",
			"x", "Maclaurin", "Logarithm",
       			"Abs Difference", "% Difference");

	// Print results
	for (int i = 0; i < N; i++)
	{
		double x = -0.9 + i * 0.01;
		
		double difference = fabs(values1[i] - values2[i]);
		
		double percentage = 0.0;
		
		if (values2[i] != 0.0)
		{
			percentage = difference / fabs(values2[i]) * 100.0;
		}
		
		printf("%8.2f %18.10g %18.10g %18.6e %17.6f%%\n",
				x, values1[i], values2[i],
           			difference, percentage);
	}

    return 0;
}
