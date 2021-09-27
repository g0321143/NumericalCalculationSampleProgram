// 2分法
#include <stdio.h>
#include <math.h>

#define EPS .0001

void nibun(double, double);
void func_y(double);

int main(int argc, char **argv)
{
    double a = 0.0, b = 1.0;
    double x;

    printf("x^3+x-1=0 の2分法による数値計算\n");
    printf("初期値 a = %6.3lf\n", a);
    printf("初期値 b = %6.3lf\n", b);

    x = nibun(a, b);

    printf("近似解 x = %6.3lf\n", x);

    return 0;
}

double nibun(double a, double b)
{
    double c;

    do
    {
        c = (a + b) / 2.0;
        if ((func_y(c) * func_y(a)) < 0)
            b = c;
        else
            a = c;
    } while (fabs(a - b) > EPS);
    return c;
}

double func_y(double x)
{
    return pow(x, 3.0) + x - 1.0;
}