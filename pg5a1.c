#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double eval_sinx(double xrad, long int NT, long int (*funcptr)(long int));
long int fact(long int n);
#define PI 3.141592653589793

void main() {
    long int NT;
    double sinx, xrad, xdeg;

    // Prompt user for input
    printf("Enter the angle in degrees: ");
    scanf("%lf", &xdeg);

    printf("Enter the number of terms: ");
    scanf("%ld", &NT);

    // Convert degrees to radians
    xrad = xdeg * PI / 180;

    // Evaluate sin(x) using the series
    sinx = eval_sinx(xrad, NT, fact);

    // Display result
    printf("\nSin(%lf) = %lf\n", xdeg, sinx);
}

double eval_sinx(double xrad, long int NT, long int (*funcptr)(long int)) {
    int i;
    double sinx = 0;
    int sign = 1;

    // Compute the series sum
    for (i = 1; i <= 2 * NT - 1; i += 2) {
        sinx = sinx + sign * pow(xrad, i) / (*funcptr)(i);
        sign = -sign; // Alternate signs
    }
    return sinx;
}

long int fact(long int n) {
    // Recursive factorial function
    if (n == 0 || n == 1)
        return 1;
    return n * fact(n - 1);
}
