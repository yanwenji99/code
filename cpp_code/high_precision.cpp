#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int la, lb, lc, a[1010], b[1010], c[1010];
void add(string sa, string sb)
{
    lc = la > lb ? la : lb;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i=0; i<la; i++)
        a[i]=sa[la-i-1]-'0';
    for(int i=0; i<lb; i++)
        b[i]=sb[lb-i-1]-'0';
    memset(c, 0, sizeof(c));
    for(int i=0; i<lc; i++)
    {
        c[i]=a[i]+b[i]+c[i];
        if(c[i]>9)
        {
            c[i+1]++;
            c[i]-=10;
        }
    }
    if(c[lc])
        lc++;
    for(int i=lc-1; i>=0; i--)
        cout<<c[i];
}
void sub(string sa, string sb)
{
    lc = la > lb ? la : lb;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i=0; i<la; i++)
        a[i]=sa[la-i-1]-'0';
    for(int i=0; i<lb; i++)
        b[i]=sb[lb-i-1]-'0';
    memset(c, 0, sizeof(c));
    for(int i=0; i<lc; i++)
    {
        c[i]=a[i]-b[i]+c[i];
        if(c[i]<0)
        {
            c[i+1]--;
            c[i]+=10;
        }
    }
    while(lc>1 && c[lc-1]==0)
        lc--;
    for(int i=lc-1; i>=0; i--)
        cout<<c[i];
}
void mul(string sa, string sb)
{
    lc = la + lb;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i=0; i<la; i++)
        a[i]=sa[la-i-1]-'0';
    for(int i=0; i<lb; i++)
        b[i]=sb[lb-i-1]-'0';
    memset(c, 0, sizeof(c));
    for(int i=0; i<lc; i++)
        for(int j=0; j<lc; j++)
        {
            c[i+j]+=a[i]*b[j];
            if(c[i+j]>9)
            {
                c[i+j+1]+=c[i+j]/10;
                c[i+j]%=10;
            }
        }
    while(lc>1 && c[lc-1]==0)
        lc--;
    for(int i=lc-1; i>=0; i--)
        cout<<c[i];
}
int main()
{
    char sa[1010], sb[1010];
    char operater;
    cin >> sa >> operater >> sb;
    la = strlen(sa);
    lb = strlen(sb);
    switch(operater)
    {
        case '+':
            add(sa, sb);
            break;
        case '-':
            sub(sa, sb);
            break;
        case '*':
            mul(sa, sb);
            break;
    }
    return 0;
}