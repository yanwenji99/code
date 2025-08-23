#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType int
#define maxsize 100
typedef struct Stack
{
    ElemType *base;
    ElemType *top;
    int stacksize;
} Stack;
void InitStack(Stack *S)
{
    S->base = (ElemType *)malloc(maxsize * sizeof(ElemType));
    if (!S->base)
        exit(0);
    S->top = S->base;
    S->stacksize = maxsize;
}
void DestoryStack(Stack *S)
{
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->stacksize = 0;
}
void ClearStack(Stack *S)
{
    S->top = S->base;
}
bool StackEmpty(Stack *S)
{
    if(S->top==S->base)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int StackLength(Stack *S)
{
    return S->top - S->base;
}
bool GetTop(Stack *S,ElemType *e)
{
    if(StackEmpty(S))
    {
        return false;
    }
    *e = *(S->top - 1);
    return true;
}
bool Push(Stack *S,ElemType e)
{
    if(StackLength(S)>=S->stacksize)
    {
        return false;
    }
    *S->top++ = e;
    return true;
}
bool Pop(Stack *S,ElemType *e)
{
    if(StackEmpty(S))
    {
        return false;
    }
    *e = *--S->top;
    return true;
}
void PrintStack(Stack *S)
{
    ElemType *p = S->top;
    while(p>S->base)
    {
        p--;
        printf("%d\n", *p);
    }
}
int main()
{
    Stack S;
    InitStack(&S);
    return 0;
}