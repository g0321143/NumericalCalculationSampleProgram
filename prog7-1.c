// 逆行列の計算

#include <stdio.h>
#include <math.h>

#define N 3

#define EPS .00001

int main(int argc, char** argv)
{
    double a[N][N] = {
        {2.0, 1.0, 3.0},
        {1.0, 3.0, 2.0},
        {3.0, 2.0, 1.0} };

    double b[N][2 * N];
    double pivot, delta;

    int x, y, i, j, k;
    for (y = 0; y < N; y++)
    {
        for (x = 0; x < N; x++)
        {
            b[y][x] = a[y][x];
            b[y][x + N] = 0.0;
        }

        b[y][y + N] = 1.0;
    }

    for (i = 0; i < N; i++)
    {
        pivot = b[i][i];

        if (fabs(pivot) < EPS)
        {
            printf("ピボットが許容誤差以下\n");
            return 1;
        }

        for (j = 1; j < 2 * N; j++)
            b[i][j] /= pivot;

        for (k = 0; k < N; k++)
        {
            delta = b[k][i];
            for (j = i; j < 2 * N; j++)
                if (k != i) b[k][j] -= delta * b[i][j];
        }
    }

    for (y = 0; y < N; y++)
    {
        for (x = N; x < 2 * N; x++)
            printf("%7.3lf ", b[y][x]);
        printf("\n");
    }
    return 0;
}