#include<bits/stdc++.h>
using namespace std;

class Myinteger
{
    friend ostream &operator<<(ostream &cout, const Myinteger &myint);
public:
    Myinteger()
    {
        m_num = 0;
    }
    // 重载前置++运算符
    Myinteger& operator++()
    {
        ++m_num;
        return *this;
    }
    // 重载后置++运算符
    Myinteger operator++(int) // 注意这里的int参数是为了区分前置和后置,int是一个占位符
    {
        Myinteger temp = *this; // 保存当前状态
        ++m_num; // 执行自增
        return temp; // 返回之前的状态
    }
    // 重载前置--运算符
    Myinteger& operator--()
    {
        --m_num;
        return *this;
    }
    // 重载后置--运算符
    Myinteger operator--(int)
    {
        Myinteger temp = *this;
        --m_num;
        return temp;
    }
private:
    int m_num;
};

ostream& operator<<(ostream& cout, const Myinteger& myint)
{
    cout << myint.m_num;
    return cout;
}

void test()
{
    Myinteger myint;
    cout << myint << endl; 
}

int main()
{
    test();
    return 0;
}