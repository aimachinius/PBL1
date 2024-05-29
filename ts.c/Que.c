#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// First in first out
#define Minsize 5
#define Empty -INT_MAX
struct Element
{
    int value;
};
struct QueueRecord
{
    unsigned int capacity;
    int front;
    int rear;
    unsigned int count;
    struct Element *que_array;
};
typedef struct QueueRecord *Queue;
int is_empty(Queue Q)
{
    return Q->count == 0;
}
int is_full(Queue Q)
{
    return Q->count == Q->capacity;
}
void reset(Queue Q)
{
    Q->count = 0;
    Q->front = 1;
    Q->rear = 0;
}

void dispose(Queue Q)
{
    if (Q != NULL)
    {
        free(Q->que_array);
        free(Q);
    }
}
Queue createQueue(unsigned int capacity)
{
    if (capacity < Minsize)
    {
        printf("The queue's capacity is at least %d \n", Minsize);
        return NULL;
    }
    Queue Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
    {
        printf("Not enough memory \n", Minsize);
        return NULL;
    }
    Q->que_array = malloc(sizeof(struct Element) * capacity);
    Q->capacity = capacity;
    reset(Q);
    return Q;
}
int increase(unsigned int capacity, int index)
{
    index++;
    if (index == capacity)
        index = 0;
    return index;
}

struct Element dequeue(Queue Q)
{
    if (is_empty(Q))
    {
        printf("The queue is empty \n");
        struct Element return_value;
        return return_value;
    }
    struct Element temp = Q->que_array[Q->front];
    Q->front = increase(Q->capacity, Q->front);
    Q->count++;
    return temp;
}
void EnQueue(struct ELement e, Queue Q)
{
    if (is_full(Q))
    {
        printf("The queue is full \n");
        return;
    }
    Q->rear = increase(Q->capacity, Q->rear);
    Q->que_array[Q->rear] = e;
    Q->count++;
}
void Show(Queue Q, int index)
{
    if (is_empty(Q))
    {
        printf("The queue is empty \n");
        return;
    }
    if (index == Q->rear)
    {
        printf("%d ", Q->que_array[index].value);
    }
    else
    {
        Show(Q, increase(index, Q->capacity));
        printf("%d ", Q->que_array[index].value);
    }
}
int main()
{
    struct Element a, b, c, d;
    a.value = 2, b.value = 4, c.value = 1, d.value = 3;
    Queue Q = createQueue(10);
    Q->front = 8;
    Q->rear = 7;
    EnQueue(a, Q);
    EnQueue(b, Q);
    EnQueue(c, Q);
    EnQueue(d, Q);
    Show(Q, Q->front);
}