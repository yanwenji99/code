#include<bits/stdc++.h>
using namespace std;

// 友元：全局函数，友元类，友元成员函数

class Building
{
    friend void goodfriend(Building &b);

public:
    Building()
    {
        m_settingroom = "1";
        m_bedroom = "2";  
    }
    string m_settingroom;
private:
    string m_bedroom;
};

//全局函数
void goodfriend(Building &b)
{
    // 友元函数可以访问类的私有成员
    cout << "settingroom: " << b.m_settingroom << endl;
    cout << "bedroom: " << b.m_bedroom << endl; // 访问私有成员
}

int main()
{
    Building b;
    goodfriend(b); // 调用友元函数
    return 0;
}