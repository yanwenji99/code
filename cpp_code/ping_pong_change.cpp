#include<bits/stdc++.h>
using namespace std;
int main()
{
    string line;
    int win11[6000]={0}, win21[3000]={0}, lose11[6000]={0}, lose21[3000]={0};
    int i = 0, j = 0;
    while(getline(cin, line)) {
        for(char c: line)
        {
            if(c=='E')
            {
                goto a;
            }
            else if(c=='W')
            {
                win11[i]++;
                win21[j]++;
            }
            else if(c=='L')
            {
                lose11[i]++;
                lose21[j]++;
            }
            if((win11[i]>=11 || lose11[i]>=11)&&abs(win11[i]-lose11[i])>=2)
            {
                i++;
            }
            if((win21[j]>=21 || lose21[j]>=21)&&abs(win21[j]-lose21[j])>=2)
            {
                j++;
            }
        }
    }
a:  for (int m=i; m >= 0; m--)
    {
        cout << win11[i-m] << ":" << lose11[i-m] << endl;
    }
    cout << endl;
    for (int m=j; m >= 0; m--)
    {
        cout << win21[j-m] << ":" << lose21[j-m] << endl;
    }
    return 0;
}