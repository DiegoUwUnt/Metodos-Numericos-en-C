//Villagran Salazar Diego

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float function(float x) {
    return pow(x, 3) - (13 * x) - 12;
}

float muller(float x0, float h, float eps, int maxit) {
    float x2 = x0;
    float x1 = x0 + h * x0;
    x0 = x0 - h * x0;
    int itera = 0;
    float h0;
    float h1;
    float del0;
    float del1;
    float erro_aprox = 0;
    float dx;

    do {
        itera++;
        printf("%d: %f | ", itera, x2);
        if (x2 != 0) {
            erro_aprox = fabs((x2 - x0) / x2) * 100;
        }

        h0 = x1 - x0;
        h1 = x2 - x1;
        del0 = (function(x1) - function(x0)) / h0;
        del1 = (function(x2) - function(x1)) / h1;

        float a = (del1 - del0) / (h1 + h0);
        float b = a * h1 + del1;
        float c = function(x2);

        float discri = sqrt((b * b) - 4 * a * c);
        float denom;
        if (fabs(b + discri) > fabs(b - discri)) {
            denom = b + discri;
        } else {
            denom = b - discri;
        }
        dx = -2 * c / denom;
        x2 = x2 + dx;

        x0 = x1;
        x1 = x2;

    } while (fabs(dx) > (eps * x2) && itera < maxit);

    return x2;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Uso: %s <xr> <h> <eps> <maxit>\n", argv[0]);
        return 1;
    }

    float xr = atof(argv[1]);
    float h = atof(argv[2]);
    float eps = atof(argv[3]);
    int maxit = atoi(argv[4]);

    float result = muller(xr, h, eps, maxit);

    printf("Resultado: %f\n", result);

    return 0;
}
