#include<stdio.h>
#include<stdlib.h>
#define ElemType int
#define max 5
typedef enum Status
{
    ERROR,
    OK
}Status;
typedef struct Queue
{
    ElemType *base;
    int front;
    int rear;
} Queue;
Status InitQueue(Queue *Q)
{
    Q->base = (ElemType *)malloc(max * sizeof(ElemType));
    if (!Q->base)
    {
        return ERROR;
    }
    Q->front = Q->rear = 0;
    return OK;
}
int QueueLength(Queue *Q)
{
    return (Q->rear - Q->front + max) % max;
}
Status EnQueue(Queue *Q, ElemType e)
{
    if ((Q->rear + 1) % max == Q->front)
    {
        return ERROR;
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % max;
    return OK;
}
Status DeQueue(Queue *Q, ElemType *e)
{
    if (Q->front == Q->rear)
    {
        return ERROR;
    }
    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % max;
    return OK;
}
int main()
{
    Queue Q;
    InitQueue(&Q);
    return 0;
}