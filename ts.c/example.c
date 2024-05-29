#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int mask[10] = {0};
int check1(int n, float a[][10], int i)
{
    for (int j = 0; j < n; j++)
    {
        if (fabs(a[i][j]) > fabs(a[i][i]) && i != j)
            return 0;
    }
    return 1;
}
int check2(int n, float a[][10], int i)
{
    int c;
    float max = -1e9;
    for (int j = 0; j < n; j++)
    {
        if (fabs(a[i][j]) > max)
        {
            max = fabs(a[i][j]);
            c = j;
        }
    }
    return c;
}
void swap(float *a, float *b)
{
    float c = *a;
    *a = *b;
    *b = c;
}
void swapRow(int n, float a[][10], int row1, int row2)
{
    for (int i = 0; i < n; i++)
    {
        swap(&a[row1][i], &a[row2][i]);
    }
}
void danhdau(int n, float a[][10]) // danh dau cac mang da dung vi tri
{
    for (int i = 0; i < n; i++)
    {
        if (check1(n, a, i))
        {
            mask[i] = 1;
        }
        else
        {
            mask[i] = 0;
        }
    }
}
void change(int n, float a[][10])
{
    for (int i = 0; i < n; i++)
    {
        if (mask[i] == 0)
        {
            int cot = check2(n, a, i);
            if (mask[cot] == 0)
            {
                swapRow(n, a, i, cot);
            }
        }
        else
        {
            printf("hang %d da dung \n ", i + 1);
        }
    }
}
int makeMax(int n, float a[][10], int i)
{
    int h = 0;
    for (; h < n; h++)
    {
        if (mask[h])
            printf("lay cot %d lam chuan \n", h);
        break;
    }
    for (int j = 0; j < n; j++)
    {
        if (i != j)
        {
            float cnst = -a[i][j] / a[h][j];
            for (int k = 0; j < n; j++)
            {
                a[i][k] = a[i][k] + a[h][k] * cnst;
                if (check1(n, a, k))
                    return 1;
            }
        }
    }
}
void makeMax_Row(int n, float a[][10])
{
    for (int i = 0; i < n; i++)
    {
        if (mask[i] == 0)
        {
            printf("Lam cho max hang %d \n", i + 1);
            if (makeMax(n, a, i))
                continue;
        }
    }
}
void inmask(int n, int mask[])
{
    for (int i = 0; i < n; i++)
    {

        printf("%d ", mask[i]);
    }
    printf("\n");
}
void in(int n, float a[][10])
{
    int x = 1;
    for (int i = 0; i < n; i++)
    {
        int c = check2(n, a, i);
        printf("%d :", x);
        x++;
        for (int j = 0; j < n; j++)
        {
            if (j == c)
                printf("\033[31m%.2f \033[0m", a[i][j]);
            else
                printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    float a[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    danhdau(n, a);
    printf("Cac hang thoa man dung hang \n");
    inmask(n, mask);
    change(n, a);
    printf("sau khi thay doi \n");
    in(n, a);
    danhdau(n, a);
    inmask(n, mask);
    makeMax_Row(n, a);
    printf("Sau khi thay doi \n");
    in(n, a);
}