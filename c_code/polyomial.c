#include<stdio.h>
#include <stdlib.h>
typedef struct polyomial {
    int coef;
    int exp;
    struct polyomial *next;
}poly;
poly* creatpoly()
{
    poly *L=(poly*)malloc(sizeof(poly));
    poly *tail=L;
    int a, b;
    scanf("%d^%d",&a,&b);
    while(a!=0)
    {
        poly* p=(poly*)malloc(sizeof(poly));
        p->coef=a;
        p->exp=b;
        p->next=NULL;
        tail->next=p;
        tail=p;
        scanf("%d^%d",&a,&b);
    }
    return L;
}
poly* addpoly(poly* la,poly* lb)
{
    poly *pa=la->next;
    poly *pb=lb->next;
    
}
int main()
{
    poly *La=creatpoly();
    poly *Lb=creatpoly();
    return 0;
}