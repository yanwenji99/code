#include<bits/stdc++.h>
using namespace std;

// 成员函数重载
class Person
{
public:
    int m_a, m_b;
    Person operator+(const Person & p);
};
Person Person::operator+(const Person & p)
{
    Person temp;
    temp.m_a = this->m_a + p.m_a;
    temp.m_b = this->m_b + p.m_b;
    return temp;
}
// 例如：Person p3 = p1.operator+(p2) —— Person p3 = p1 + p2

// 全局函数重载
// Person operator+(const Person & p1, const Person & p2)
// {
//     Person temp;
//     temp.m_a = p1.m_a + p2.m_a;
//     temp.m_b = p1.m_b + p2.m_b;
//     return temp;
// }
// 例如：Person p3 = operator+(p1, p2) —— Person p3 = p1 + p2

// 运算符重载也可以发生函数重载
// 例如：person operator+(const Person & p1, const Person & p2) 和 Person operator+(const Person & p1, int value) 都是合法的重载

// 全局重载右移运算符
istream &operator>>(istream &cin, Person &p)
{
    cin >> p.m_a >> p.m_b;
    return cin;
}

// 全局函数重载左移运算符
ostream& operator<<(ostream & cout, const Person & p)
{
    cout << "m_a: " << p.m_a << ", m_b: " << p.m_b;
    return cout;
}

void test()
{
    Person p1, p2, p3;
    p1.m_a = 1; p1.m_b = 2;
    p2.m_a = 3; p2.m_b = 4;
    // 使用成员函数重载
    p3 = p1 + p2; // 调用成员函数重载
    cout << p3 << endl; // 使用全局函数重载左移运算符输出
    
    // 使用全局函数重载
    // p3 = operator+(p1, p2); // 调用全局函数重载
    // cout << "p3.m_a: " << p3.m_a << ", p3.m_b: " << p3.m_b << endl;
}

int main()
{
    test();
    return 0;
}