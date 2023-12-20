//  Bairtow's method for finding the roots of a polynomial
// Villagran Salazar Diego

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 6 /* degree of polynomial */
#define EPS 1.0e-6
#define NTRY 10
#define TINY 1.0e-5

void qroot(float p[], int degree, float *b, float *c, float eps);

int main(void)
{
    int i, j, nroot = 0;
    static float p[N + 1] = {10.0, -18.0, 25.0, -24.0, 16.0, -6.0, 1.0};
    float *b, *c;

    b = (float *)malloc(NTRY * sizeof(float));
    c = (float *)malloc(NTRY * sizeof(float));

    printf("\nP(x)=x^6-6x^5+16x^4-24x^3+25x^2-18x+10\n");
    printf("Quadratic factors x^2+bx+c\n\n");
    printf("%6s %10s %12s\n\n", "factor", "b", "c");

    for (i = 0; i < NTRY; i++)
    {
        c[i] = 0.5 * (i + 1);
        b[i] = -0.5 * (i + 1);
        qroot(p, N, &b[i], &c[i], EPS);

        int duplicate = 0;
        for (j = 0; j < i; j++)
        {
            if ((fabs(b[i] - b[j]) < TINY) && (fabs(c[i] - c[j]) < TINY))
            {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate)
        {
            printf("%4d %15.6f %12.6f\n", nroot++, b[i], c[i]);
        }
    }

    free(c);
    free(b);
    return 0;
}

void qroot(float p[], int degree, float *b, float *c, float eps)
{
    // Simplified implementation of qroot
    // This function should be replaced with an actual method to find quadratic roots of a polynomial
    *b = 0; // Dummy values
    *c = 0; // Dummy values
}
