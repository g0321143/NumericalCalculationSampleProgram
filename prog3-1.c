// ラグランジュの補間法
#include <stdio.h>
#include <math.h>
#define N 6
double x[N] = { 0.0, 1.0, 2.0, 3.0, 3.1, 5.0 };
double y[N] = { 0.0, 1.1, 2.5, 4.0, 4.1, 5.0 };
double lagrange(double);
int main(int argc, char** argv)
{
    double xx, yy;
    printf("XX\t\t\tYY\n");
    for (xx = 0.0; xx <= 5.0; xx += .2)
    {
        yy = lagrange(xx);
        printf(" %8.2lf\t%8.2lf\n", xx, yy);
    }
    return 0;
}

double lagrange(double xx)
{
    double z[N];
    double yy = 0.0;
    int i, k;
    for (k = 0; k < N; k++)
    {
        z[k] = 1.0;
        for (i = 0; i < N; i++)
            if (i != k)
                z[k] *= (xx - x[i]) / (x[k] - x[i]);

        yy += y[k] * z[k];
    }
    return yy;
}
