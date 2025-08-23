#include<stdio.h>
int max_num(int L[], int start,int end)
{
    if(start==end)
    {
        return L[start];
    }
    else
    {
        int mid = (start+end)/2;
        int max1 = max_num(L,start,mid);
        int max2 = max_num(L,mid+1,end);
        if(max1>max2)
        {
            return max1;
        }
        else
        {
            return max2;
        }
    }
}
int min_num(int L[], int start,int end)
{
    if(start==end)
    {
        return L[start];
    }
    else
    {
        int mid = (start+end)/2;
        int min1 = min_num(L,start,mid);
        int min2 = min_num(L,mid+1,end);
        if(min1<min2)
        {
            return min1;
        }
        else
        {
            return min2;
        }
    }
}
int sum(int L[], int start, int end)
{
    if(start==end)
    {
        return L[start];
    }
    else
    {
        int mid = (start+end)/2;
        int sum1 = sum(L,start,mid);
        int sum2 = sum(L,mid+1,end);
        return sum1+sum2;
    }
}
int ride(int L[], int start, int end)
{
    if(start==end)
    {
        return L[start];
    }
    else
    {
        int mid = (start+end)/2;
        int ride1 = ride(L,start,mid);
        int ride2 = ride(L,mid+1,end);
        return ride1*ride2;
    }
}
double average(int L[], int start, int end)
{
    double s=sum(L,start,end),n=end-start+1;
    return s/n;
}
int main()
{
    int n, i;
    scanf("%d", &n);
    int L[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", &L[i]);
    }
    printf("max:%d\n", max_num(L,0,n-1));
    printf("min:%d\n", min_num(L,0,n-1));
    printf("sum:%d\n", sum(L,0,n-1));
    printf("ride:%d\n", ride(L,0,n-1));
    printf("average:%lf\n", average(L,0,n-1));
    return 0;
}