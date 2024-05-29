#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"
struct Number
{
    float num;
};
struct Node
{
    struct Number nub;
    struct Node *next;
};
typedef struct Node *List;
typedef struct Node *Position;

List createHeader()
{
    Position header;
    header = (struct Node *)malloc(sizeof(struct Node));
    header->next = NULL;
    return header;
}
Position Insert(struct Number x, Position p)
{
    Position newNum;
    newNum = (struct Node *)malloc(sizeof(struct Node));
    newNum->nub = x;
    newNum->next = p->next;
    p->next = newNum;
    return newNum;
}
void Delete(Position current, Position p)
{
    while (current != NULL)
    {
        if (current->next == p)
        {
            current->next = p->next;
            free(p);
            break;
        }
        current = current->next;
    }
}
void Printf(List *col, int N)
{
    List fp;
    for (int i = 0; i < N; i++)
    {
        fp = col[i]->next;
        while (fp != NULL)
        {
            printf("%g ", fp->nub.num);

            fp = fp->next;
        }
        printf("\n");
    }
}
void Display()
{
    char line[100];
    line[99] = '\0';
    for (int i = 0; i < 99; i++)
    {
        line[i] = '-';
    }
    printf("%s\n", line);
}
void Write(FILE *f, List fp)
{
    fp = fp->next;
    while (fp != NULL)
    {
        fprintf(f, "%f ", fp->nub.num);
        fp = fp->next;
    }
    fprintf(f, "\n");
}
void SaveX(FILE *f, float *x, int N)
{
    f = fopen("RESULT2.OUT.txt", "w");
    for (int i = 0; i < N; i++)
    {
        fprintf(f, "%f ", x[i]);
    }
    printf("Nghiem da duoc luu o file RESULT2 \n");
    fclose(f);
}
void nhap(int n, float *b)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &b[i]);
        getchar();
    }
}
int check(float *x, float *c, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (fabs(x[i] - c[i]) > 0.000001)
            return 1;
    }
    return 0;
}
void swapRow(int row1, int row2, List *col, int N)
{
    List a = col[row1]->next;
    List b = col[row2]->next;
    struct Number c;
    while (a != NULL)
    {
        c = a->nub;
        a->nub = b->nub;
        b->nub = c;
        a = a->next;
        b = b->next;
    }
}
int checkConvergence(List *col, int N)
{
    int a[N]; // đánh dấu hàng đã đúng phần tử trên đường chéo chính
    int c[N];
    for (int i = 0; i < N; i++)
    {
        c[i] = 0;
    }
    List current;
    int mark;
    for (int i = 0; i < N; i++)
    {
        float max = -1e9;
        current = col[i]->next;
        for (int j = 0; j < N; j++)
        {
            if (current->nub.num > max)
            {
                max = current->nub.num; // tìm ra cột có max
                mark = j;
            }
            current = current->next;
        }
        if (i == mark)
        { // nếu nó nằm trên dường chéo chính thì đánh dấu là đúng
            a[i] = -1;
            c[mark] = 1;
        }
        else
        {
            a[i] = mark;
            c[mark] = 1;
        } // nếu không thì cho nó giữ nguyên vị trí cột đó
    }
    for (int i = 0; i < N; i++)
    {
        if (c[i] == 0)
            return 0;
    }
    for (int i = 0; i < N; i++)
    {
        if (a[i] != -1)
        {
            int c = a[a[i]];
            swapRow(i, a[i], col, N); // đổi hàng i và hàng c[i] (tức hàng mark)
            a[a[i]] = -1;
            a[i] = c; // swap xong phải cập nhật lại vị trí các hàng
        }
    }
    return 1;
}
int Convergence_test(List col, int i) // truyển i và hàng tương ứng
{
    List current = col->next;
    float max;
    int j = 0;
    float cmax;
    while (current != NULL)
    {
        if (current->nub.num > max)
        {
            max = current->nub.num;
            cmax = j;
        }
        j++;
        current = current->next;
    }
    if (cmax != i)
        return 0;
    else
        return 1;
}
void solution(int N, float *b, List *col, float *x)
{
    int ok = 1;
    for (int i = 0; i < N; i++)
    {
        x[i] = 0;
    }
    float *c = (float *)malloc(N * sizeof(float));
    int cnt = 0;
    float cnst;
    Display();
    while (ok)
    {
        printf("|%d |", ++cnt);
        for (int i = 0; i < N; i++)
        {
            List current = col[i]->next;
            c[i] = x[i];
            float s = 0;
            for (int j = 0; j < N; j++)
            {
                if (j != i)
                {
                    s += current->nub.num * x[j];
                }
                else
                {
                    cnst = current->nub.num;
                }
                current = current->next;
            }
            x[i] = (b[i] - s) / cnst;
            if (x[i] < 0)
                printf(" x[%d] = %f| ", i, x[i]);
            else
                printf(" x[%d] = %f |", i, x[i]);
        }
        printf("\n");
        Display();
        ok = check(x, c, N);
    }
    printf("\033[0;35mVay nghiem vua tim duoc la :\033[0m");
    for (int i = 0; i < N; i++)
    {
        printf("\033[31mx[%d] = %f \033[0m;", i + 1, x[i]);
    }
    printf("\n");
    free(c);
}
void PrintfTry(List col, int M, float b, float *x, float s)
{
    List current = col->next;
    int j = 0;
    while (current != NULL)
    {

        if (current->nub.num < 0)
        {
            printf("(%f)", current->nub.num);
        }
        else
        {
            printf("%f", current->nub.num);
        }
        printf("*");
        if (x[j] < 0)
        {
            printf("(%f)", x[j]);
        }
        else
        {
            printf("%f", x[j]);
        }
        if (j == M - 1)
        {
        }
        else
        {
            printf(" + ");
        }
        j++;
        current = current->next;
    }
    printf("= \033[31m%f\033[0m %c \033[31m%f\033[0m \033[32m%c\033[0m\n", s, 247, b, 251);
}
void TryN0(List col, int M, float b, float *x)
{
    float s = 0;
    List current = col->next;
    int j = 0;
    while (current != NULL)
    {
        s += current->nub.num * x[j];
        current = current->next;
        j++;
    }
    if (fabs(s - b) <= 0.1)
        PrintfTry(col, M, b, x, s);
}
void choosetodel(Position p, List *col, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        Position current = col[i];
        p = current->next; // p chỉ đến phần tử đầu tiên vì là header.next
        for (int j = 0; j < M; j++)
        {
            if (j == M / 2 - 1)
            {
                Delete(current, p);
                break;
            }
            else
                p = p->next; // tăng p đến khi gặp M/2
        }
    }
}
void Menu(List *col, struct Number *row, int N, int M, FILE *f, int mn);
void Work(int N, int M, Position p, List *col, struct Number *row, FILE *f, int menu)
{
    Printf(col, N);

    printf("Cau b) \033[31mXoa phan tu o hang N/2 \nAfter Delete !!\033[0m\n");
    choosetodel(p, col, N, M);
    --M;
    f = fopen("RESULT1.OUT.txt", "w");

    for (int i = 0; i < N; i++)
    {
        Write(f, col[i]); // luu va in ra mang a
    }
    Printf(col, N);
    fclose(f);
    // check tại đây
    printf(YELLOW "Kiem tra tinh hoi tu \n" RESET);
    printf("------------------------------------------------------------------------\n");
    printf("He phuong trinh hoi tu khi tri tuyet doi cua phan tu tren duong cheo   |\nchinh lon hon tong cac tri tuyet doi cua cac phan tu con lai tran hang |\n");
    printf("------------------------------------------------------------------------\n");

    if (checkConvergence(col, N) == 0)
    {
        printf(RED "He phuong trinh chua hoi tu \n" RESET);
        Menu(col, row, N, M, f, menu);
    }
    else
    {
        printf(CYAN "Sau khi kiem tra thi he da hoi tu \n" RESET);
        Printf(col, N);
        printf("************\n");
        printf(RED "Cau c) Nhap vao mang B bat ki co %d phan tu \n" RESET, N);

        float *b = (float *)malloc(N * sizeof(float));
        nhap(N, b);
        float *x = (float *)malloc(N * sizeof(float));
        printf(MAGENTA "Bang ket qua sau khi dung phuong phap lap Gauss-Seidel\n" RESET);
        solution(N, b, col, x);
        printf("#########################");
        printf(BLUE "\nSau khi thu lai nghiem :\n" RESET);
        for (int i = 0; i < N; i++)
        {
            TryN0(col[i], M, b[i], x);
        }
        SaveX(f, x, N);
        free(b);
        free(x);
        free(row);
    }
    Menu(col, row, N, M, f, 3);
}
void arraybykeyboard(int N, int M, List *col, struct Number *row, FILE *f)
{
    Position p;
    printf("Nhap ma tran tu ban phim \n");
    printf("Nhap so hang N va so cot N+1 cho ma tran . Nhap N :\n");
    scanf("%d", &N);
    getchar();
    M = N + 1;

    row = (struct Number *)malloc(M * sizeof(struct Number));
    col = (List *)malloc(N * sizeof(List));
    printf("Nhap cac he so cho ma tran %d*%d \n:", N, M);
    for (int i = 0; i < N; i++)
    {
        col[i] = createHeader();
        for (int j = 0; j < M; j++)
        {
            scanf("%f", &row[j].num);
            getchar();
            if (j == 0)
                p = Insert(row[j], col[i]);
            else
                p = Insert(row[j], p);
        }
    }
    Work(N, M, p, col, row, f, 1);
}
void arraybyfile(int N, int M, List *col, struct Number *row, FILE *f)
{
    f = fopen("DAYSO.IN.txt", "r"); // Mở tệp để đọc
    if (f == NULL)
    {
        printf("Khong the mo file\n");
        exit(1);
    }
    printf("Nhap ma tran tu file \n");
    fscanf(f, "%d", &N); // đọc số hàng và cột của ma trận
    fscanf(f, "%d", &M);

    row = (struct Number *)malloc(M * sizeof(struct Number));

    col = (List *)malloc(N * sizeof(List)); // con tro bac cao hon

    Position p; // tạo node để lưu vị trí
    for (int i = 0; i < N; i++)
    {
        col[i] = createHeader();
        for (int j = 0; j < M; j++)
        {
            fscanf(f, "%f", &row[j].num);
            if (j == 0)
                p = Insert(row[j], col[i]);
            else
                p = Insert(row[j], p);
        }
    }
    Work(N, M, p, col, row, f, 2);
}
void RearraybyKeyboard(FILE *f, List *col, struct Number *row, int N)
{
    printf("Nhap lai cho mang da thay doi %d*%d\n", N, N);
    printf("Hay nhap he so tuong ung de ma tran co duong cheo troi \n");
    int run;
    do
    {
        for (int i = 0; i < N; i++)
        {
            List current = col[i]->next;
            for (int j = 0; j < N; j++)
            {
                scanf("%f", &current->nub.num);
                getchar();
                current = current->next;
            }
        }
        printf("Kiem tra hoi tu cua ham vua nhap lai \n");
        printf("_________________________\n");
        for (int i = 0; i < N; i++)
        {
            run = checkConvergence(col, N);
            if (!run)
            {
                printf("He phuong trinh khong thoa dieu kien hoi tu \n");
                printf("-------------------------------------------------------\n");
                break;
            }
        }
    } while (run);
    printf("Cau c) Nhap vao mang B bat ki co %d phan tu \n", N);

    float *b = (float *)malloc(N * sizeof(float));
    nhap(N, b);
    float *x = (float *)malloc(N * sizeof(float));

    printf("Bang ket qua sau khi dung phuong phap lap Gauss-Seidel\n");
    solution(N, b, col, x);
    printf("#########################");

    printf("\nSau khi thu lai nghiem :\n");

    for (int i = 0; i < N; i++)
    {
        TryN0(col[i], N, b[i], x);
    }
    SaveX(f, x, N);

    free(b);
    free(x);
    Menu(col, row, N, N + 1, f, 3);
}
void Menu(List *col, struct Number *row, int N, int M, FILE *f, int mn)
{
    if (mn == 0)
    {
        printf("\033[0;31mChao ban den voi chuong trinh tinh nghiem \033[0m\n");
        printf("\033[0;31mCau a) Tao danh sach lien ket don va nhap cac phan tu vao !!\033[0m\n");
        printf("\033[0;32mBan co cac lua chon \033[0m\n");
        printf("\033[0;33m1)Nhap he tu ban phim \033[0m\n");
        printf("\033[0;34m2)Nhap he tu file co san\033[0m\n");
        printf("\033[0;36m0)Neu ban muon ket thuc chuong trinh \033[0m\n");

        printf("Nhap lua chon cua ban \n");
        char n = 'x';
        while (n != '0')
        {
            scanf(" %c", &n);

            if (n == '\n')
            {
                scanf("%c", &n);
            }
            switch (n)
            {
            case '1':
                arraybykeyboard(N, M, col, row, f);
                break;
            case '2':
                arraybyfile(N, M, col, row, f);
                break;
            case '0':
                printf("Ket thuc chuong trinh \n");
                exit(0);
            }
            if (n != '1' && n != '2' && n != '0')
            {
                printf("!!!NHAP LUA CHON KHONG HOP LE !!! . Vui long nhap lai \n");
            }
        }
    }
    else if (mn == 1)
    {
        printf("\033[0;36mBan co the nhap he tu file hoac co the nhap lai ma tran da thay doi hoac co the ket thuc chuong trinh\033[0m\n");
        printf("\033[0;33m1) Nhap tu file co san\033[0m\n");
        printf("\033[0;35m2) Nhap lai ma tran da thay doi tu ban phim\033[0m\n");
        printf("\033[0;32m0) Ket thuc chuong trinh\033[0m\n");

        printf("Nhap lua chon cua ban\n");

        char n = 'x';
        while (n != '0')
        {
            scanf(" %c", &n);
            if (n == '\n')
            {
                scanf("%c", &n);
            }
            switch (n)
            {
            case '1':
                arraybyfile(N, M, col, row, f);
                break;
            case '2': // Nhap lai ma tran da thay doi
                RearraybyKeyboard(f, col, row, N);
                break;
            case '0':
                printf("Ket thuc chuong trinh \n");
                exit(0);
            }
            if (n != '1' && n != '2' && n != '0')
            {
                printf("!!!NHAP LUA CHON KHONG HOP LE !!! . Vui long nhap lai \n");
            }
        }
    }
    else if (mn == 2)
    {
        printf("\033[0;32mBan co the nhap he tu ban phim hoac co the nhap lai ma tran da thay doi hoac co the ket thuc chuong trinh\033[0m\n");
        printf("\033[0;33m1)Nhap tu ban phim \033[0m\n");
        printf("\033[0;33m2)Nhap lai ma tran da thay doi tu ban phim\033[0m\n");
        printf("\033[0;36m0)Ket thuc chuong trinh\033[0m\n");
        printf("Nhap lua chon cua ban\n");

        char n = 'x';
        while (n != '0')
        {
            scanf(" %c", &n);
            if (n == '\n')
            {
                scanf("%c", &n);
            }
            switch (n)
            {
            case '1':
                arraybykeyboard(N, M, col, row, f);
                break;
            case '2':
                RearraybyKeyboard(f, col, row, N);
                break;
            case '0':
                printf("Ket thuc chuong trinh \n");
                exit(0);
            }
            if (n != '1' && n != '2' && n != '0')
            {
                printf("!!!NHAP LUA CHON KHONG HOP LE !!! . Vui long nhap lai \n");
            }
        }
    }
    else if (mn == 3)
    {
        for (int i = 0; i < 15; i++)
        {
            printf("%c", 176);
        }
        printf("\n");
        printf("\033[0;31mNeu ban muon tinh them he thi nhap cac lua chon hoac ket thuc\033[0m\n");
        printf("\033[0;31mBan co cac lua chon \033[0m\n");
        printf("\033[0;32m1)Nhap he tu ban phim \033[0m\n");
        printf("\033[0;32m2)Nhap he tu file co san\033[0m\n");
        printf("\033[0;33m0)Neu ban muon ket thuc chuong trinh \033[0m\n");

        printf("Nhap lua chon cua ban \n");
        char n = 'x';
        while (n != '0')
        {
            scanf(" %c", &n);
            if (n == '\n')
            {
                scanf("%c", &n);
            }
            switch (n)
            {
            case '1':
                arraybykeyboard(N, M, col, row, f);

                break;
            case '2':
                arraybyfile(N, M, col, row, f);
                break;
            case '0':
                printf("Ket thuc chuong trinh \n");
                exit(0);
            }
            if (n != '1' && n != '2' && n != '0')
            {
                printf("!!!NHAP LUA CHON KHONG HOP LE !!! . Vui long nhap lai \n");
            }
        }
    }
}
int main()
{
    FILE *f; // khai báo file

    struct Number *row; // khai báo danh sách
    List *col;
    int N;
    int M;

    Menu(col, row, N, M, f, 0);
    fclose(f); // Đóng tệp
    free(col);
}
//\033[31m%.2f \033[0m