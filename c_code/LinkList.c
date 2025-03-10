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
} LNode, *Node, *Link;
typedef struct
{
    Link head, tail;
    int len;
} LinkList;
LinkList InitList()
{
    LinkList L;
    L.head = (Link)malloc(sizeof(LNode));
    if (!L.head)
    {
        exit(0);
    }
    L.head->next = NULL;
    L.tail = L.head;
    L.len = 0;
    int data;
    scanf("%d", &data);
    while (data != -1)
    {
        Node p = (Node)malloc(sizeof(LNode));
        p->data = data;
        p->next = NULL;
        L.tail->next = p;
        L.tail = p;
        L.len++;
        scanf("%d", &data);
    }
    return L;
}
void DestoryList(LinkList L)
{
    Node p = L.head;
    while (p)
    {
        L.head = L.head->next;
        free(p);
        p = L.head;
    }
}
void ClearList(LinkList L)
{
    Node p = L.head->next;
    while (p)
    {
        L.head->next = p->next;
        free(p);
        p = L.head->next;
    }
}
Status ListEmpty(LinkList L)
{
    if (L.head->next)
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
    return L.len;
}
Status GetElem(LinkList L, int i, ElemType *e)
{
    int j = 0;
    Node p = L.head;
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
    if(L.len==0)
    {
        return 0;
    }
    int i = 0;
    Node p = L.head;
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
    Node p = L.head, q = NULL;
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
        q = q->next;
        p = p->next;
    }
    return ERROR;
}
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
    Node p = L.head, q = NULL;
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
        q = q->next;
        p = p->next;
    }
    return ERROR;
}
Status ListInsert(LinkList L, int i, ElemType e)
{
    if (i < 1 || i > ListLength(L) + 1)
    {
        return ERROR;
    }
    Node p = L.head;
    int j = 1;
    while (j < i && p)
    {
        p = p->next;
        j++;
    }
    Node q = (Link)malloc(sizeof(LNode));
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
    Node p = L.head;
    int j = 1;
    while (j < i && p)
    {
        p = p->next;
        j++;
    }
    Node q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}
void ListTraverse(LinkList L)
{
    Node p = L.head->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main()
{
    LinkList L = InitList();
    ListTraverse(L);
    DestoryList(L);
    return 0;
}