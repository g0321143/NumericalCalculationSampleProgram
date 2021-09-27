// 正規乱数検証計算

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10000

double gauss(int);
void print(double, double, int);

int main(int argc, char **argv)
{
    double sa = 0.0, sb = 0.0;
    double v;
    int i;

    printf(" 回数 平均値 標準偏差\n");

    for (i = 1; i <= N; i++)
    {
        v = gauss(12);
        sa += v;
        sb += v * v;
        if ((i % 1000) == 0)
            print(sa, sb, i);
    }

    return 0;
}

void print(double sa, double sb, int i)
{
    double ave = 0.0, hh, sig;

    ave = sa / (double)i;
    hh = sb - 2.0 * ave * sa + (double)i * ave * ave;
    sig = sqrt(hh / ((double)i - 1.0));
    printf("%6d %8.4lf %8.4lf\n", i, ave, sig);
}

double gauss(int num)
{
    double ss = 0.0;
    int i;

    for (i = 0; i < num; i++)
        ss += rand() / (double)RAND_MAX;
    return ss - 6.0;
}