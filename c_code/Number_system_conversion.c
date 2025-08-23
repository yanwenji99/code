#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define maxsize 100
#define ElemType int
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
bool StackEmpty(Stack *S)
{
    if (S->top == S->base)
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
bool Push(Stack *S, ElemType e)
{
    if (StackLength(S) >= S->stacksize)
    {
        return false;
    }
    *S->top++ = e;
    return true;
}
bool Pop(Stack *S, ElemType *e)
{
    if (StackEmpty(S))
    {
        return false;
    }
    *e = *--S->top;
    return true;
}
int main()
{
    int num,system,new_system;
    scanf("%d", &system);
    switch(system)
    {
        case 10:
        {
            scanf("%d", &num);
            break;
        }
        case 8:
        {
            scanf("%o", &num);
            break;
        }
        case 16:
        {
            scanf("%x", &num);
            break;
        }
    }
    scanf("%d", &new_system);
    Stack S;
    InitStack(&S);
    while(num)
    {
        Push(&S,num%new_system);
        num/=new_system;
    }
    ElemType e;
    while(Pop(&S,&e))
    {
        switch(new_system)
        {
            case 10:
            {
                printf("%d",e);
                break;
            }
            case 8:
            {
                printf("%o",e);
                break;
            }
            case 16:
            {
                printf("%x",e);
                break;
            }
        }
    }
}