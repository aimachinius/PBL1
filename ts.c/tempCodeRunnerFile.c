
}
int main()
{
    Heap H = createHeap(10);
    int data[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    for (int i = 1; i <= 10; i++)
    {
        H->heap_array[i].value = data[i - 1];
    }
    Show(H);
    build_max_heap(H);
    Show(H);
}
