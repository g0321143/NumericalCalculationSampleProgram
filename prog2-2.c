// ガウス ザイデル法
#include <stdio.h>
#include <math.h>
#define n 3
#define EPS .0001
#define MAX_LOOP 30

int main(int argc, char** argv)
{
    double a[n][n + 1] = { {5, 1, 1, 10}, {1, 4, 1, 12}, {2, 1, 3, 13} };
    double x[n], y[n], s, q;
    int i, j, k;

    for (i = 0; i < n; i++)
        x[i] = 1.0;

    for (k = 0; k < 30; k++)
    {
        q = 0.0;
        for (i = 0; i < n; i++)
        {
            s = 0.0;
            for (j = 0; j < n; j++)
                if (i != j)
                    s += a[i][j] * x[j];
            y[i] = (a[i][n] - s) / a[i][i];
            q += fabs(x[i] - y[i]);
            x[i] = y[i];
        }
        if (q < EPS)
        {
            for (i = 0; i < n; i++)
                printf("x%d = %9.6lf\n", i, x[i]);
            return 0;
        }
    }
    printf("収束せず\n");
    return 1;
}