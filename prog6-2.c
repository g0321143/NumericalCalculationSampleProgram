// 双曲型偏微分方程式

#include <stdio.h>
#include <math.h>

#define N 20

// 刻み設定
int main(int argc, char** argv)
{
    double u[N + 1], v[N + 1], w[N + 1];
    double k = .01, h, r, s, q;
    int i, j;

    h = 1.0 / (double)N;
    r = k / h;
    q = r * r;
    s = 2.0 * (1.0 - q);

    for (i = 0; i <= N / 2; i++)
        u[i] = (double)i / (double)N;

    for (i = N / 2; i <= N; i++)
        u[i] = 1.0 - (double)i / (double)N;

    for (i = 0; i <= N; i++)
        v[i] = u[i];

    for (i = 0; i <= N; i++)
        w[1] = 0.0;

    for (j = 0; j <= 200; j++)
    {
        if ((j % 10) == 0)
        {
            printf("%5.3lf ", (double)j * k);

            for (i = 0; i <= N; i += 2)
                printf("%6.2lf", u[i]);

            printf("\n");
        }

        // 差分計算
        for (i = 1; i < N; i++)
            w[i] = q * (u[i + 1] + u[i - 1]) + s * u[i] - v[i];

        for (i = 0; i <= N; i++)
        {
            v[i] = u[i];
            u[i] = w[i];
        }
    }
    return 0;
}
