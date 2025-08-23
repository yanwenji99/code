#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef enum Status
{
    ERROR,
    OK
}Status;
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct 
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;
Status InitQueue(LinkQueue *Q)
{
    Q->front = (QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
        exit(0);
    Q->rear = Q->front;
    return OK;
}
Status DestoryQueue(LinkQueue *Q)
{
    QueuePtr p = Q->front;
    while(p)
    {
        Q->front = Q->front->next;
        free(p);
        p = Q->front;
    }
    return OK;
}
Status ClearQueue(LinkQueue *Q)
{
    QueuePtr p = Q->front->next;
    Q->front->next = NULL;
    while(p)
    {
        Q->front = p;
        p = p->next;
        free(Q->front);
    }
    Q->rear = Q->front;
    return OK;
}
Status QueueEnpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return OK;
    else
        return ERROR;
}
int QueueLenth(LinkQueue Q)
{
    int i = 0;
    QueuePtr p = Q.front;
    while(Q.rear !=p)
    {
        i++;
        p = p->next;
    }
    return i;
}
Status GetHead(LinkQueue Q,ElemType *e)
{
    if(Q.front==Q.rear)
    {
        return ERROR;
    }
    QueuePtr p = Q.front->next;
    *e = p->data;
    return OK;
}
Status EnQueue(LinkQueue *Q,ElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)
    {
        exit(0);
    }
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}
Status DeQueue(LinkQueue *Q,ElemType *e)
{
    if(Q->front==Q->rear)
    {
        return ERROR;
    }
    QueuePtr p = Q->front->next;
    *e = p->data;
    Q->front = p->next;
    free(p);
    return OK;
}
Status PrintQueue(LinkQueue Q)
{
    if(Q.front==Q.rear)
    {
        return ERROR;
    }
    QueuePtr p = Q.front->next;
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    return OK;
}
int main()
{
    LinkQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    PrintQueue(Q);
    return 0;
}