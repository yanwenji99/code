#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef enum Status
{
    ERROR,
    OK
}Status;
typedef struct SNode
{
    ElemType data;
    struct SNode *next;
} SNode, *StackPtr;
typedef struct 
{
    StackPtr top;
    StackPtr base;
} LinkStack;
Status InitStack(LinkStack *S)
{
    S->base = (StackPtr)malloc(sizeof(SNode));
    if(!S->base)
        exit(0);
    S->top = S->base;
    S->top->next = NULL;
    return OK;
}
Status DestoryStack(LinkStack *S)
{
    StackPtr p = S->top;
    while(p)
    {
        S->top = S->top->next;
        free(p);
        p = S->top;
    }
    return OK;
}
Status ClearStack(LinkStack *S)
{
    if(S->top==S->base)
    {
        return ERROR;
    }
    StackPtr p = S->top;
    while(p)
    {
        S->top = p->next;
        free(p);
        p = S->top;
    }
    return OK;
}
Status StackEmpty(LinkStack S)
{
    if(S.top==S.base)
    {
        return OK;
    }
    else
    {
        return ERROR;
    }
}
int StackLength(LinkStack S)
{
    int i = 0;
    StackPtr p = S.top;
    while(S.base!=p)
    {
        i++;
        p = p->next;
    }
    return i;
}
Status GetTop(LinkStack S,ElemType *e)
{
    if(S.top==S.base)
    {
        return ERROR;
    }
    *e = S.top->data;
    return OK;
}
Status Push(LinkStack *S,ElemType e)
{
    StackPtr p = (StackPtr)malloc(sizeof(SNode));
    if(!p)
    {
        exit(0);
    }
    p->data = e;
    p->next = S->top;
    S->top = p;
    return OK;
}
Status Pop(LinkStack *S,ElemType *e)
{
    if(S->top==S->base)
    {
        return ERROR;
    }
    StackPtr p = S->top;
    *e = p->data;
    S->top = p->next;
    free(p);
    return OK;
}
Status PrintStack(LinkStack S)
{
    StackPtr p = S.top;
    while(S.base!=p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}
int main()
{
    LinkStack S;
    int i = 0;
    InitStack(&S);
    for(i=0;i<10;i++)
    {
        Push(&S,i);
    }
    ClearStack(&S);
    for(i=0;i<15;i++)
    {
        Push(&S,i);
    }
    PrintStack(S);
    return 0;
}