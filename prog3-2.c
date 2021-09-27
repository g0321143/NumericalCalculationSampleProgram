// 最小2乘法
#include <stdio.h>
#include <math.h>
#define N 6
#define M 4
#define EPS .0001

double a[M + 1][M + 2];

int jordan(void);

int main(int argc, char** argv)
{
    double x[N] = { 0.0, 1.0, 2.0, 3.0, 3.1, 5.0 };
    double y[N] = { 0.0, 1.1, 2.5, 4.0, 4.1, 5.0 };
    int i, j, k;

    for (i = 0; i <= M; i++)
        for (j = 0; j <= M + 1; j++)
            a[i][j] = 0.0;

    for (i = 0; i <= M; i++)
        for (j = 0; j <= M; j++)
            // 修正前：for (k = 0; k <= N; k++)
            // 修正後：for (k = 0; k < N; k++)
            for (k = 0; k < N; k++)
                a[j][i] += pow(x[k], (double)(i + j));

    for (j = 0; j <= M; j++)
        for (k = 0; k < N; k++)
            a[j][M + 1] += y[k] * pow(x[k], 1);

    if (jordan() == 1)
        return 1;

    for (i = 0; i <= M; i++)
        printf("A%2d = %7.3lf\n", i, a[i][M + 1]);

    return 0;
}

// ガウス- ジョルダン法による連立方程式の計算
int jordan(void)
{

    double pivot, delta;
    int i, j, k;

    for (i = 0; i <= M; i++)
    {
        pivot = a[i][i];
        if (fabs(pivot) < EPS)
        {
            printf("ピボットが許容誤差以下\n");
            return 1;
        }

        for (j = 0; j <= M + 1; j++)
            a[i][j] /= pivot;

        for (k = 0; k <= M; k++)
        {
            delta = a[k][i];
            for (j = 0; j <= M + 1; j++)
                if (k != i)
                    a[k][j] = delta * a[i][j];
        }
    }
    return 0;
}
