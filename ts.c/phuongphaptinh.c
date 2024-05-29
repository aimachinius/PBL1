#include <stdio.h>
#include <conio.h>
#include <math.h>
void nhap(int n, float c[])
{
    for (int i = 0; i <= n; i++)
    {
        scanf("%f", &c[i]);
    }
}

void lagrange(int n, float x[], float y[], float t)
{

    float A[n + 1][n + 2];
    for (int i = 1; i <= n; i++)
    {
        float X = x[i - 1], Y = y[i - 1];
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
            {
                A[i][j] = (Y * (x[i] - t) - y[i] * (X - t)) / (x[i] - X);
                printf("%f \n", A[i][j]);
            }
            else
                A[i][j] = 0;
        }
    }
}
// float noi_suy_lagrange(int n, float x[], float y[], float t)
// {
//     float ket_qua = 0.0;
//     for (int i = 0; i <= n; i++)
//     {
//         float term = y[i];
//         for (int j = 0; j <= n; j++)
//         {
//             if (j != i)
//             {
//                 term = term * (t - x[j]) / (x[i] - x[j]);
//                 printf("%f ", term);
//             }
//         }
//         ket_qua += term;
//         printf("%f ", term);
//     }
//     return ket_qua;
// }

int main()
{
    int n;
    char tt;
    float t;

    printf("\nNhap n = ");
    scanf("%d", &n);

    float x[n + 1], y[n + 1];

    printf("Nhap %d moc noi suy: ", n + 1);
    nhap(n, x);
    printf("\nNhap gia tri ham tai cac moc noi suy tuong ung: ");
    nhap(n, y);
    printf("\nNhap so can tinh ");
    scanf("%f", &t);
    lagrange(n, x, y, t);

    return 0;
}

// Phương pháp Lagrange
// #include <stdio.h>
// #include <math.h>
// float tinh(int n, float a[], int j, float x)
// {
//     float s = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (j != i)
//         {

//             s *= (x - a[i]) / (a[j] - a[i]);
//         }
//     }
//     return s;
// }
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     float a[n];
//     float b[n];
//     float x;

//     for (int i = 0; i < n; i++)
//     {
//         scanf("%f", &a[i]);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%f", &b[i]);
//     }
//     scanf("%f", &x);
//     float S = 0;
//     for (int i = 0; i < n; i++)
//     {
//         S += b[i] * tinh(n, a, i, x);
//     }
//     printf("%f ", S);
// }
// #include <stdio.h>
// #include <math.h>
// float Wx(int n, float a[], float x)
// {
//     float s = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (x != a[i])
//         {
//             s *= (x - a[i]);
//         }
//     }
//     return s;
// }
// float Lagrange(int n, float a[], float x, float b[], float c[])
// {
//     float s = 0;
//     for (int i = 0; i < n; i++)
//     {
//         s += c[i] / ((x - a[i]) * b[i]);
//     }
//     return s;
// }
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     float a[n];
//     float b[n];
//     float c[n];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%f", &a[i]);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%f", &c[i]);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         b[i] = Wx(n, a, a[i]);
//     }
//     float S = Wx(n, a, 5) * Lagrange(n, a, 5, b, c);
//     printf("%f ", S);
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// int check(float *x, float *c, int n)
// {
//     for (int i = 0; i < n; i++)

//     {
//         if (fabs(x[i] - c[i]) > 0.001)
//             return 1;
//     }
//     return 0;
// }
// void solution(int n, float **a, float *x)
// {
//     float *c = (float *)malloc(n * sizeof(float)); // tao mang luu phan tu
//     int ok = 1;
//     int cnt = 0;
//     while (ok)

//     {
//         printf("%d : ", ++cnt);

//         for (int i = 0; i < n; i++)
//         {
//             c[i] = x[i]; // gan cho c gia tri cu cua x
//             float s = 0;
//             for (int j = 0; j < n; j++)
//             {
//                 if (j != i)
//                     s += a[i][j] * x[j];
//             }
//             x[i] = (a[i][n] - s) / a[i][i];
//             printf("%f ", x[i]);
//         }
//         ok = check(x, c, n);
//         printf("\n");
//     }
//     free(c);
// }
// void nhap(int n, float **a)
// {
//     for (int i = 0; i < n; i++)

//     {
//         for (int j = 0; j <= n; j++)

//         {
//             scanf("%f", &a[i][j]);
//         }
//     }
//     printf("\n");
// }
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     float **a = (float **)malloc(n * sizeof(float *));
//     for (int i = 0; i < n; i++)

//     {
//         a[i] = (float *)malloc((n + 1) * sizeof(float));
//     }
//     float *x = (float *)malloc(n * sizeof(float));
//     for (int i = 0; i < n; i++)

//     {
//         x[i] = 0;
//     }
//     nhap(n, a);
//     solution(n, a, x);
//     for (int i = 0; i < n; i++)

//     {
//         free(a[i]);
//     }
//     free(a);
//     free(x);
// }
// // #include <stdio.h>
// // #include <math.h>
// // void createB(int n, float a[][100])
// // {
// //     for (int i = 0; i < n; i++)
// //     {
// //         float c = a[i][i];
// //         for (int j = 0; j <= n; j++)
// //         {
// //             if (j != n)
// //                 a[i][j] = -a[i][j] / c;
// //             else
// //                 a[i][j] = a[i][j] / c;
// //         }
// //     }
// // }
// // void datain(int n, float a[][100])
// // {
// //     for (int i = 0; i < n; i++)
// //     {
// //         for (int j = 0; j <= n; j++)
// //         {
// //             scanf("%f", &a[i][j]);
// //         }
// //     }
// // }
// // void dataout(int n, float a[][100])
// // {
// //     for (int i = 0; i < n; i++)
// //     {
// //         for (int j = 0; j <= n; j++)
// //         {
// //             printf("%.3f ", a[i][j]);
// //         }
// //         printf("\n");
// //     }
// // }
// // float sigma(int n, float a[][100], int cnst, float x[]) // tim tong moi hang
// // {
// //     float s = 0;
// //     for (int j = 0; j < n; j++)
// //     {
// //         s += a[cnst][j] * x[j];
// //     }
// //     return s;
// // }
// // int findmax(int n, float r[])
// // {
// //     float max = -1e9;
// //     int c;
// //     for (int i = 0; i < n; i++)
// //     {
// //         if (fabs(r[i]) > max)
// //         {
// //             max = fabs(r[i]);
// //             c = i;
// //         }
// //     }
// //     return c;
// // }
// // int check(int n, float r[])
// // {
// //     for (int i = 0; i < n; i++)
// //     {
// //         if (fabs(r[i]) > 0.0001)
// //             return 1;
// //     }
// //     return 0;
// // }
// // void outXandR(int n, float x[], float r[])
// // {
// //     for (int i = 0; i < n; i++)
// //     {
// //         printf("%.3f ", x[i]);
// //     }
// //     for (int i = 0; i < n; i++)
// //     {
// //         printf("%.3f ", r[i]);
// //     }
// //     printf("\n");
// // }
// // void sol(int n, float a[][100], float x[])
// // {
// //     float r[100];
// //     for (int i = 0; i < n; i++)
// //     {
// //         r[i] = a[i][n] + sigma(n, a, i, x);
// //     }i
// //     outXandR(n, x, r);
// //     while (check(n, r))
// //     {
// //         int c = findmax(n, r);
// //         x[c] = x[c] + r[c];
// //         for (int i = 0; i < n; i++)
// //         {
// //             if (i != c)
// //             {
// //                 r[i] = r[i] + a[i][c] * r[c];
// //             }
// //         }
// //         r[c] = 0;
// //         outXandR(n, x, r);
// //     }
// // }

// // int main()
// // {
// //     printf("nhap so n \n");
// //     int n;
// //     scanf("%d", &n);
// //     float a[100][100];
// //     float x[100] = {0};
// //     datain(n, a);
// //     createB(n, a);
// //     printf("array B \n");
// //     dataout(n, a);
// //     printf("\n");
// //     sol(n, a, x);
// // }