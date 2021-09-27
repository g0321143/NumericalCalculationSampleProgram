// ニュートン法

#include <stdio.h>
#include <math.h>

double func_y(double);
double func_z(double);

#define EPS .0001

int main(int argc, char **argv)
{
    double a = 1.0;
    double b;

    while (1)
    {
        b = a - func_y(a) / func_z(a);
        if (fabs(a - b) < EPS)
            break;
        else
            a = b;
    }

    printf("近似解 x = %6.3lf\n", b);
    return 0;
}

double func_y(double x)
{
    return (pow(x, 3.0) + x - 1.0);
}

double func_z(double x)
{
    return (3.0 * pow(x, 2.0) + 1.0);
}
