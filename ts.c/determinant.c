// phương pháp krammer
#include <stdio.h>
#include <math.h>

void swap(float *a, float *b);
void change(int n, float a[][100]);
void renew1(int n, float a[][100]);
void renew2(int n, float a[][100], int j);
void nhap(int n, float a[][100]);
void in(int n, float a[][100]);
int check1(int n, float a[][100], int j);
int check2(int n, float a[][100], int i);
float det(int n, float a[][100]);
void solution(int n, float a[][100], float d);
void resetA(int n, float a[][100], float b[][100]);
int x = 0;         // đếm số lần hoán đổi hàng
float b[100][100]; // Tạo mảng b bằng mảng a để khi a bị hàm change biến đổi thì vẫn còn dữ liệu của mảng a để tính tiếp
int main()
{
    int n;
    scanf("%d", &n);
    float a[100][100];
    nhap(n, a);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            b[i][j] = a[i][j];
        }
    }
    float d = round(det(n, a));
    printf("det = %f \n", d);
    solution(n, a, d);
    return 0;
}
void resetA(int n, float a[][100], float b[][100])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}
void reset(int n, float a[][100], int j)
{
    for (int i = 0; i < n; i++)
    {
        swap(&a[i][j], &a[i][n]);
    }
}
void solution(int n, float a[][100], float d)
{
    if (d == 0)
        printf("phuong trinh vo nghiem \n");
    else
    {
        for (int i = 0; i < n; i++)
        {
            resetA(n, a, b);
            x = 0;           // trả lại x bằng 0 để đếm các lần tính tiếp theo
            renew2(n, a, i); // hoan doi
            change(n, a);
            float det_i = round(det(n, a));
            printf("detx%d = %.3f va nghiem x%d = %.3f \n", i + 1, det_i, i + 1, det_i / d);
        }
    }
}

float det(int n, float a[][100])
{
    float determinant = 1;
    for (int j = 0; j < n; j++)
    {
        if (check1(n, a, j))
        {
            printf("Sau khi check1 thi determinant = 0 \n");
            return determinant = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (check2(n, a, i))
        {
            printf("Sau khi check2 thi determinant = 0 \n");
            return determinant = 0;
        }
    }
    change(n, a);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                determinant *= a[i][j];
        }
    }
    return pow(-1, x) * determinant;
}

void swap(float *a, float *b)
{
    float c = *a;
    *a = *b;
    *b = c;
}

void renew2(int n, float a[][100], int j)
{
    for (int i = 0; i < n; i++)
    {
        swap(&a[i][j], &a[i][n]);
    }
}

void renew1(int n, float a[][100])
{
    for (int i = 0; i < n; i++)
    {
        if (a[i][i] == 0)
        {
            for (int j = 0; j <= n; j++)
            {
                swap(&a[i][j], &a[n - 1][j]);
            }
        }
    }
}

int check1(int n, float a[][100], int j)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i][j] != 0)
            return 0;
    }
    return 1;
}

int check2(int n, float a[][100], int i)
{
    for (int j = 0; j < n; j++)
    {
        if (a[i][j] != 0)
            return 0;
    }
    return 1;
}

void change(int n, float a[][100])
{
    for (int j = 0; j <= n; j++)
    {
        for (int i = j + 1; i < n; i++)
        {
            if (check1(n, a, j))
                continue;
            if (a[j][j] == 0)
            {
                renew1(n, a);
                x++;
            }
            float cnst = a[i][j] / a[j][j];
            for (int k = j; k <= n; k++)
            {
                float c = a[i][k];
                a[i][k] += -a[j][k] * cnst;
                if (fabs(a[i][k]) < 0.001)
                    a[i][k] = 0;
            }
        }
    }
}

void nhap(int n, float a[][100])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
}

void in(int n, float a[][100])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
}
