#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct HeapNode
{
    int value;
};

struct HeapRecord
{
    int length;
    int heap_size;
    struct HeapNode *heap_array;
};

typedef struct HeapRecord *Heap;

Heap createHeap(int length)
{
    Heap H = malloc(sizeof(struct HeapRecord));
    if (H == NULL)
    {
        printf("Không đủ bộ nhớ \n");
        return NULL;
    }
    H->heap_array = malloc(sizeof(struct HeapNode) * (length + 1)); // Cấp phát bộ nhớ cho length + 1 phần tử
    if (H->heap_array == NULL)
    {
        printf("Không đủ bộ nhớ để tạo mảng \n");
        free(H); // Giải phóng bộ nhớ đã cấp phát cho H
        return NULL;
    }
    H->length = length;
    H->heap_size = length;
    return H;
}

void Swap(struct HeapNode *a, struct HeapNode *b)
{
    struct HeapNode c = *a;
    *a = *b;
    *b = c;
}

void maxHeap(Heap H, int i)
{
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;
    largest = i;
    if (l <= H->heap_size && H->heap_array[l].value > H->heap_array[largest].value)
    {
        largest = l;
    }
    if (r <= H->heap_size && H->heap_array[r].value > H->heap_array[largest].value)
    {
        largest = r;
    }
    if (largest != i)
    {
        Swap(&H->heap_array[i], &H->heap_array[largest]);
        maxHeap(H, largest);
    }
}

void Show(Heap H)
{
    if (H->heap_size == 0)
    {
        printf("Heap rỗng\n");
        return;
    }
    for (int i = 1; i <= H->length; i++)
    {
        printf("%d ", H->heap_array[i].value);
    }
    printf("\n");
}

void build_max_heap(Heap H)
{
    for (int i = H->heap_size / 2; i > 0; i--)
    {
        maxHeap(H, i);
    }
}

void HeapSort(Heap H)
{
    build_max_heap(H);
    for (int i = H->heap_size; i > 1; i--)
    {
        Swap(&H->heap_array[1], &H->heap_array[i]);
        H->heap_size--; // Giảm kích thước heap
        maxHeap(H, 1);
    }
    H->heap_size = original_size; // Khôi phục kích thước ban đầu
}
void heap_insert(Heap H, int key)
{
    if (H->heap_size < H->length)
    {
        H->heap_size++;
        H->heap_array[H->heap_size].value = INT_MIN;
        heap_increase_key();
    }
    else
    {
        struct HeapNode newNode;
        H->length++;
        H->heap_array[H->length] = newNode;
        H->heapsize++;
    }
}
int main()
{
    Heap H = createHeap(10);
    if (H == NULL)
    {
        return 1; // Thoát nếu cấp phát bộ nhớ thất bại
    }
    int data[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    for (int i = 1; i <= 10; i++)
    {
        H->heap_array[i].value = data[i - 1];
    }
    Show(H);
    HeapSort(H);
    Show(H);
    free(H->heap_array); // Giải phóng mảng heap
    free(H);             // Giải phóng cấu trúc heap
    return 0;
}
