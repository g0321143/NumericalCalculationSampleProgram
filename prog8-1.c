// DFTの計算

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define P 10

double func_y(double);

int main(int argc, char** argv)
{
    double f[P];
    double ar, ai, x;
    int m, n;

    for (m = 0; m < P; m++)
        f[m] = func_y(2.0 * M_PI / (double)P * (double)m);

    printf("次数\t実数部\t虚数部\t絶対値\n");

    for (n = 0; n < P; n++)
    {
        ar = 0.0;
        ai = 0.0;

        for (m = 0; m < P; m++)
        {
            x = 2.0 * M_PI / (double)P * (double)m * (double)n;
            ar += f[m] * cos(-x);
            ai += f[m] * sin(-x);
        }

        ar /= (double)P;
        ai /= (double)P;
        x = sqrt(ar * ar + ai * ai);
        printf("%4d %9.3lf %9.3lf %9.3lf\n", n, ar, ai, x);
    }
    return 0;
}

double func_y(double x)
{
    return 3.0 * sin(x) + 7.0 * cos(3.0 * x);
}