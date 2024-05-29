#include <stdio.h>
int n, a[100];
int cnt = 0;
int s = 0;
void in()
{
    printf("%d :", ++cnt);
    for (int i = 1; i <= 3; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        a[i] = j;
        s += j;
        if (i == 3 && s == n)
        {
            s = 0;
            in();
        }
        else if (i < 3)
            try(i + 1);
    }
}
int main()
{
    scanf("%d", &n);
    try(1);
}
/* bai toan xep hau
#include <stdio.h>
#include <math.h>
int n, a[100]; // can danh dau cac duong da co quan hau dat vao va cac quan kia se duoc dat o cho khac
// cac quan hau se duoc dat moi con mot hang
// moi con se khong trung duong cheo cau nhau
// moi con se nam khac cot voi nhau
int hang[100] = {0},                // quan li hang
    dc1[100] = {0}, dc2[100] = {0}; // quan li duong cheo suoi va duong cheo doc
int c[100][100];
int cnt = 0;
void in()
{
    printf("%d :", ++cnt);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (hang[j] == 0 && dc1[n + j - i] == 0 && dc2[i + j - 1] == 0)
        {
            a[i] = j;
            hang[j] = 1, dc1[n + j - i] = 1, dc2[i + j - 1] = 1;
            if (i == n)
                in();
            else
                try(i + 1);
            hang[j] = 0, dc1[n + j - i] = 0, dc2[i + j - 1] = 0;
        }
    }
}
int main()
{
    printf("nhap vao so cua ma tran ban co va n so quan hau \n");
    scanf("%d", &n);
    try(1);
}*/
// // thuat toan quay lui
// #include <stdio.h>
// #include <math.h>
// int n;
// int k;
// int cnt = 0;
// char a[100];
// char b[100] = {0};
// void in()
// {
//     printf("%d :", ++cnt);
//     for (int i = 1; i <= k; i++)
//     {
//         printf("%d", a[i]);
//     }
//     printf("\n");
// }
// void try(int i)
// {
//     for (int j = a[i - 1] + 1; j <= n - k + i; j++)
//     { //  các giá trị mà các phần tử nhận được tương ứng với vị trí của nó là từ giá trị trước nó +1 đến n - k + i
//         a[i] = j;
//         if (i == k)
//         {
//             in();
//         }
//         else
//         {
//             try(i + 1);
//         }
//     }
//     // for (int j = 1; j <= n; j++)
//     // {
//     //     if (j <= n - k + i) // giá trị tối đa của a[i] là j = n - k + i
//     //     {
//     //         a[i] = j;
//     //         if (a[i] <= a[i - 1]) // nếu phần tử đúng sau mà lớn hơn đứng trước thì bỏ qua , không nhận
//     //             continue;
//     //         else
//     //         {
//     //             if (i == k)
//     //                 in();
//     //             else
//     //                 try(i + 1);
//     //         }
//     //     }
//     // }
// }
// int main()
// {
//     scanf("%d", &n);
//     scanf("%d", &k);
//     a[0] = 0;
//     try(1);
// }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// thuat toan  sinh : hoan vi
//  #include <stdio.h>
//  #include <math.h>
//  int n, k;
//  int stop = 0, cnt = 1;
//  char a[100];
//  void khoitao()
//  {
//      for (int i = 1; i <= n; i++)
//      {
//          a[i] = i;
//      }
//  }
//  void in()
//  {
//      printf("%d :", cnt);
//      for (int i = 1; i <= n; i++)
//      {
//          printf("%d ", a[i]);
//      }
//      printf("\n");
//  }
//  void Sinh()
//  {
//      int i = n - 1;
//      while (i >= 1 && a[i] > a[i + 1]) // neu a[i] da max dung vi tri cua no thi bo qua
//      {
//          i--;
//      }
//      if (i < 1)
//      {
//          stop = 1;
//      }
//      else // luc nay da tim duoc cho ngat
//      {
//          for (int j = n; j >= 1; j--)
//          {
//              if (a[j] > a[i])
//              {
//                  int c = a[i];
//                  a[i] = a[j];
//                  a[j] = c;
//                  break;
//              }
//          } // da hoan doi so do voi so nho nhat lon hon no
//          int l = i + 1, r = n;
//          while (l < r)
//          {
//              int c = a[l];
//              a[l] = a[r];
//              a[r] = c;
//              l++, r--;
//          }
//      }
//  }
//  void Do()
//  {
//      while (stop == 0)
//      {
//          in();
//          cnt++;
//          Sinh();
//      }
//  }
//  int main()
//  {
//      printf("nhap n \n");
//      scanf("%d", &n);
//      khoitao();
//      Do();
//  }