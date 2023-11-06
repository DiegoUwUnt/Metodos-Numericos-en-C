#include <stdio.h>
#include <math.h>

#define MAX 20

void bairstow(double a[], int n, double r, double s, double *b, double *c)
{
    int i, j, k;
    double g[MAX], h[MAX], dr, ds, det, f, delta_r, delta_s;

    for (i = 0; i <= n; i++)
        h[i] = g[i] = 0.0;

    do
    {
        h[n] = g[n] = a[n];
        h[n - 1] = g[n - 1] = a[n - 1] + r * h[n];
        for (i = n - 2; i >= 0; i--)
        {
            h[i] = a[i] + r * h[i + 1] + s * h[i + 2];
            g[i] = h[i + 1] + r * g[i + 1] + s * g[i + 2];
        }
        det = g[1] * g[1] - g[0] * g[2];
        delta_r = (-h[1] * g[1] + h[0] * g[2]) / det;
        delta_s = (-h[0] * g[1] + h[1] * g[0]) / det;
        r += delta_r;
        s += delta_s;
    } while ((fabs(delta_r) > 1.0e-6) || (fabs(delta_s) > 1.0e-6));

    *b = r;
    *c = s;
}

int main()
{
    int i, n;
    double a[MAX], b, c;

    printf("Enter degree of polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficients of polynomial: ");
    for (i = n; i >= 0; i--)
        scanf("%lf", &a[i]);

    printf("Enter initial guesses r and s: ");
    scanf("%lf %lf", &b, &c);

    bairstow(a, n, b, c, &b, &c);

    printf("The roots are:\n");
    while (n >= 2)
    {
        double d = b * b - 4.0 * c * a[n];
        double x1 = (-b + sqrt(d)) / 2.0;
        double x2 = (-b - sqrt(d)) / 2.0;
        printf("%f %f\n", x1, x2);
        n -= 2;
        b = a[n + 1] / a[n] - x1;
        c = a[n + 2] / a[n] - x2;
    }
    if (n == 1)
    {
        printf("%f\n", (-a[1] / a[0] - b) / c);
    }
    return 0;
}
