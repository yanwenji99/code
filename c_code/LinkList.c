#include <stdio.h>
#include <stdlib.h>
#define ElemType int
typedef enum Status
{
    ERROR = 0,
    OK = 1
} Status;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
LinkList InitList()
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LinkList tail = L;
    int data;
    scanf("%d", &data);
    while (data != -1)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));
        p->data = data;
        p->next = NULL;
        tail->next = p;
        tail = p;
        scanf("%d", &data);
    }
    return L;
}
void DestoryList(LinkList L)
{
    LinkList p = L;
    while (L)
    {
        L = L->next;
        free(p);
        p = L;
    }
}
void ClearList(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        L->next = p->next;
        free(p);
        p = L->next;
    }
}
Status ListEmpty(LinkList L)
{
    if (L->next)
    {
        return ERROR;
    }
    else
    {
        return OK;
    }
}
int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}
Status GetElem(LinkList L, int i, ElemType *e)
{
    int j = 0;
    LinkList p = L;
    while (j < i && p)
    {
        j++;
        p = p->next;
        if (j == i)
        {
            *e = p->data;
            return OK;
        }
    }
    return ERROR;
}
int LocateElem(LinkList L, ElemType e)
{
    int i = 0;
    LinkList p = L;
    while (p)
    {
        i++;
        p = p->next;
        if (e == p->data)
        {
            return i;
        }
    }
    return 0;
}
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
    LinkList p = L, q = NULL;
    if (p->next)
    {
        q = p->next;
    }
    while (q)
    {
        if (q->data == cur_e)
        {
            *pre_e = p->data;
            return OK;
        }
    }
    return ERROR;
}
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
    LinkList p = L, q = NULL;
    if (p->next)
    {
        q = p->next;
    }
    while (q)
    {
        if (p->data == cur_e)
        {
            *next_e = q->data;
            return OK;
        }
    }
    return ERROR;
}
Status ListInsert(LinkList L, int i, ElemType e)
{
    if (i < 1 || i > ListLength(L) + 1)
    {
        return ERROR;
    }
    LinkList p = L;
    int j = 1;
    while (j < i && p)
    {
        p = p->next;
        j++;
    }
    LinkList q = (LinkList)malloc(sizeof(LNode));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}
Status ListDelete(LinkList L, int i, ElemType *e)
{
    if (i < 1 || i > ListLength(L))
    {
        return ERROR;
    }
    LinkList p = L;
    int j = 1;
    while (j < i && p)
    {
        p = p->next;
        j++;
    }
    LinkList q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}
void ListTraverse(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main()
{
    LinkList H = InitList();
    return 0;
}