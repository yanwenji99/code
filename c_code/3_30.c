#include <stdio.h>
#include <stdlib.h>
#define ElemType int
#define max 5
typedef enum Status
{
    ERROR,
    OK
} Status;
typedef struct Queue
{
    ElemType *base;
    int front;
    int rear;
    int length;
} Queue;
Status InitQueue(Queue *Q)
{
    Q->base = (ElemType *)malloc(max * sizeof(ElemType));
    if (!Q->base)
    {
        return ERROR;
    }
    Q->front = Q->rear = 0;
    Q->length = 0;
    return OK;
}
Status EnQueue(Queue *Q, ElemType e)
{
    if (Q->length == max) // 队满条件为队列长度等于max
    {
        printf("Queue is full\n");
        return ERROR;
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % max;
    Q->length++;
    return OK;
}
Status DeQueue(Queue *Q, ElemType *e)
{
    if (Q->length == 0) // 队空条件为队列长度等于0
    {
        return ERROR;
    }
    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % max;
    Q->length--;
    return OK;
}
int main()
{
    Queue Q;
    InitQueue(&Q);
    int i = 0;
    for (i = 0; i < 6; i++)
    {
        EnQueue(&Q, i);
    }
    int e;
    for (i = 0; i < 6; i++)
    {
        if(DeQueue(&Q, &e))
            printf("%d\n", e);
    }
    return 0;
}