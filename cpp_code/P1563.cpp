#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int fx;
    string name;
} people;
typedef struct{
    int rl;
    int l;
} doing;
int main()
{
    int n, m;
    cin >> n >> m;
    people a[n];
    doing b[m];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].fx >> a[i].name;
    }
    int ptr = 0;
    for (int j = 0; j < m;j++)
    {
        cin >> b[j].rl >> b[j].l;
        if(a[ptr].fx==b[j].rl)
        {
            ptr=(ptr-b[j].l+n)%n;
        }
        else
        {
            ptr=(ptr+b[j].l+n)%n;
        }        
    }
    cout << a[ptr].name << endl;
    return 0;
}