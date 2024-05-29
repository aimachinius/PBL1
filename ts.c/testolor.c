#include <windows.h>
#include <stdio.h>

// Định nghĩa các màu
#define RED FOREGROUND_RED | FOREGROUND_INTENSITY
#define GREEN FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define BLUE FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define YELLOW FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define WHITE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE

void setColor(WORD color)
{
    // Lấy handle của console output
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Đặt màu sắc cho văn bản
    SetConsoleTextAttribute(hConsole, color);
}

int main()
{
    // In các ô màu
    setColor(RED);
    printf("  ");

    setColor(GREEN);
    printf("  ");

    setColor(YELLOW);
    printf("  ");

    setColor(BLUE);
    printf("  ");

    setColor(WHITE);
    printf("  ");

    // Đặt lại màu sắc về mặc định (màu trắng)
    setColor(WHITE);
    printf("\n");

    return 0;
}
