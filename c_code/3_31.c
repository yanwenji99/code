#include<stdio.h>
void isPalindrome(char *a)
{
    int i = 0;
    int j = 0;
    while(a[i]!='@')
    {
        i++;
    }
    i--;
    while(j<i)
    {
        if(a[j]!=a[i])
        {
            printf("No\n");
            return;
        }
        j++;
        i--;
    }
    printf("Yes\n");
}
int main()
{
    char a[100];
    int i = 0;
    while((a[i]=getchar())!='@')
    {
        i++;
    }
    isPalindrome(a);
    return 0;
}