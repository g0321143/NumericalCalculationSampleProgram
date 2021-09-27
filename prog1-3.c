// ペアストウ法のプログラム
#include <stdio.h>
#include <math.h>

#define EPS .0001

void bairstow(double *, double *, double[], int);
void root(double, double);

int main(int argc, char *argv)
{
    int n = 4;                        // 式次数宣言
    double a[] = {1, -2, 2, -50, 62}; // 係数
    double p, q;

    // メインルーチン
    printf("実数部\t\t虚数部\n");
    while (1)
    {
        if (n == 1)
        {
            printf("%8.5lf\t\t%8.5lf\n", -a[1] / a[0], 0.0);
            return 0;
        }
        if (n == 2)
        {
            root(a[1], a[2]);
            return 0;
        }
        if (n == 0)
            return 0;

        //2次因数分解
        bairstow(&p, &q, a, n);
        root(p, q);
        n -= 2;
    }
}

// 2次式の積に変換する
void bairstow(double *p, double *q, double a[], int n)
{
    double b[n + 1], c[n + 1];
    double dp, dq, e;
    int k, i;

    *p = 1.0; // 2次因数初期值
    *q = 1.0; // 2次因数初期值

    do
    {
        b[0] = a[0];
        b[1] = a[1] - (*p) * b[0]; // 商の係数行列

        for (k = 2; k <= n; k++)
            b[k] = a[k] - (*p) * b[k - 1] - (*q) * b[k - 2];

        c[0] = b[0];
        c[1] = b[1] - (*p) * c[0];

        for (k = 2; k <= n; k++)
            c[k] = b[k] - (*p) * c[k - 1] - (*q) * c[k - 2];

        e = c[n - 2] * c[n - 2] - c[n - 3] * (c[n - 1] - b[n - 1]); // 式(1.31)

        dp = (b[n - 1] * c[n - 2] - b[n] * c[n - 3]) / e; // 式(1.29)

        dq = (b[n] * c[n - 2] - b[n - 1] * (c[n - 1] - b[n - 1])) / e; // 式(1.30)

        *p += dp; // 收束保数
        *q += dq;
    } while ((fabs(dp) > EPS) && (fabs(dq) > EPS));

    //余剰0判定
    for (i = 0; i < -n - 2; i++)
        a[i] = b[i];
}

// 2次式の求根
void root(double p, double q)
{
    double d, f;
    double r1, r2, i1, i2;

    d = p * p - 4.0 * q;

    if (d <= 0)
    {
        f = sqrt(-d);
        r1 = -p / 2.0;
        r2 = -p / 2.0;
        i1 = f / 2.0;
        i2 = -f / 2.0;
    }
    else
    {
        f = sqrt(d);
        r1 = (-p + f) / 2.0;
        r2 = (-p - f) / 2.0;
        i1 = 0.0;
        i2 = 0.0;
    }

    printf("%8.5lf\t%8.5lf¥n%8.5lf\t%8.5lf\n", r1, i1, r2, i2);
}