#include <stdio.h>
#include <math.h>
#define n 3
#define EPS .001

int main(int argc, char **argv)
{
    double a[n][n + 1] = {
        {2, 1, 3, 13},
        {1, 3, 2, 13},
        {3, 2, 1, 10}};
    double pivot, del;
    int i, j, k, l;

    for (i = 0; i < n; i++)
    {
        pivot = a[i][i];
        if (fabs(pivot) < EPS)
        {
            printf("ピボットが許容誤差以下\n");
            return 1;
        }
        for (j = i; j < n + 1; j++)
            a[i][j] = a[i][j] / pivot;

        for (k = 0; k < n; k++)
        {
            del = a[k][i];
            for (j = i; j < n + 1; j++)
                if (k != i)
                    a[k][j] -= del * a[i][j];
        }
    }
    for (l = 0; l < n; l++)
        printf("x%d = %6.2lf\n", l, a[l][n]);
    return 0;
}