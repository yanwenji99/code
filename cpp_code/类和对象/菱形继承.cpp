#include<bits/stdc++.h>
using naespace std;

// 菱形继承
class Base
{
public:
    int m_num;
};
class one_1 : virtual public Base{}; // 虚继承
class one_2 : virtual public Base{};
class two : virtual public one_1, virtual public one_2{};

void test()
{
    two t;
    t.one_1::m_num = 10;
    t.one_2::m_num = 20;     // 通过虚继承，Base的成员m_num只存在一份
    cout << t.m_num << endl; // 输出20
}

int main()
{
    return 0;
}