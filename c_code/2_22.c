#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
} list;
void Initlist(list *L)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, i;
    list *tail = L;
    for (i = 0; i < 10; i++)
    {
        list *p = (list *)malloc(sizeof(list));
        p->data = a[i];
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
}
void Inverselist(list *L)
{
    list *head = L;
    list *p = NULL;
    list *q = head->next;
    list *next = NULL;
    while (q != NULL)
    {
        next = q->next; // 保存q的下一个节点
        q->next = p; // q的指针指向p
        p = q; // p等于q
        q = next; // q等于下一个节点
    } // 改变指针指向
    head->next = p;
}
void Printlist(list *L)
{
    list *head = L, *p = NULL;
    if (head->next != NULL)
    {
        p = head->next;
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main()
{
    list *L = (list *)malloc(sizeof(list));
    Initlist(L);
    Inverselist(L);
    Printlist(L);
    while (L != NULL)
    {
        list *p = L;
        L = L->next;
        free(p);
    }
    return 0;
}