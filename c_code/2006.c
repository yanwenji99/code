#include<stdio.h>
int main()
{
    int n, m, k, i, p = 0;
    scanf("%d %d %d", &k, &m, &n);
    int jn1[m], jn2[m];
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &jn1[i], &jn2[i]);
        if(jn1[i]==0&&jn2[i!=0])
        {
            printf("%d ",i+1);
            p = 1;
        }
        else if(n-(jn2[i]*(k/jn1[i])) <= 0)
        {
            printf("%d ",i+1);
            p = 1;
        }
    }
    if(p==0)
    {
        printf("-1");
    }
    return 0;
}