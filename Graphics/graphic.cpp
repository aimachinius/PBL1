#include <graphics.h> // Bao gồm file header BGI

int main()
{
    // Khởi tạo chế độ đồ họa
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Thiết lập màu sắc
    setcolor(RED); // Màu đỏ

    // Vẽ hình vuông
    rectangle(100, 100, 200, 200); // (x1, y1, x2, y2)

    // Chờ người dùng nhấn phím để thoát
    getch();

    // Giải phóng tài nguyên đồ họa
    closegraph();

    return 0;
}