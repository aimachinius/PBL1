// Phương pháp Gauss_Siedel
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int check(float *x, float *c, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (fabs(x[i] - c[i]) > 0.000001)
            return 1;
    }
    return 0;
}
void solution(int n, float **a, float *x)
{
    float *c = (float *)malloc(n * sizeof(float)); // tao mang luu phan tu
    int ok = 1;
    int cnt = 0;
    while (ok)
    {
        printf("%d : ", ++cnt);

        for (int i = 0; i < n; i++)
        {
            c[i] = x[i]; // gan cho c gia tri cu cua x
            float s = 0;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                    s += a[i][j] * x[j];
            }
            x[i] = (a[i][n] - s) / a[i][i];
            printf("%f  ", x[i]);
        }
        ok = check(x, c, n);
        printf("\n");
    }
    free(c);
}
void nhap(int n, float **a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    float **a = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (float *)malloc((n + 1) * sizeof(float));
    }
    float *x = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
    {
        x[i] = 0;
    }
    nhap(n, a);
    solution(n, a, x);
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);
    free(x);
}
