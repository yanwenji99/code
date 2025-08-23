#include<stdio.h>
#define MAXINT 100000000
#define arrsize 100000
int main()
{
    int a[arrsize], i, n;
    scanf("%d", &n);
    if(n>arrsize)
    {
        printf("Error\n");
        return 1;
    }
    a[0] = 1;
    for(i = 1; i < n; i++)
    {
        a[i] = a[i-1]*i*2;
        if(a[i] > MAXINT)
        {
            printf("Error\n");
            return 1;
        }
    }
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}