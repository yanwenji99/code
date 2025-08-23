#include<stdio.h>
#include<stdlib.h>
typedef struct list 
{
    int data;
    struct list* next;
} list;
void Initlist(list* L)
{
    int a[10]={1,2,3,4,5,6,7,8,9,10}, i;
    list *tail= L;
    for(i=0; i<10; i++)
    {
        list *p = (list *)malloc(sizeof(list));
        p->data = a[i];
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
}//时间复杂度为O(n)
void Deletelist(list* L, int mink, int maxk)
{
    list *head = L;
    list *p = head, *q = NULL;
    if(p->next!=NULL)
    {
        q = p->next;
    }
    while(q!=NULL)
    {
        if(q->data>mink && q->data<maxk)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
} // 时间复杂度为O(n)
void Printlist(list* L)
{
    list *head = L, *p = NULL;
    if(head->next!=NULL)
    {
        p = head->next;
    }
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
} // 时间复杂度为O(n)
int main()
{
    list *L = (list*)malloc(sizeof(list));
    Initlist(L);
    int mink, maxk;
    scanf("%d %d", &mink, &maxk);
    Deletelist(L, mink, maxk);
    Printlist(L);
    while(L!=NULL)
    {
        list *p = L;
        L = L->next;
        free(p);
    }
    return 0;
} // 时间复杂度为O(n)