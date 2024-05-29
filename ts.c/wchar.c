#include <stdio.h>
#include <wchar.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, ""); // Thiết lập locale để hỗ trợ Unicode

    wchar_t vietnamese[] = L"Xin chào! Mỗi ngày code là một ngày vui"; // Chuỗi tiếng Việt
    wprintf(L"Chuỗi tiếng Việt: %ls\n", vietnamese);
}