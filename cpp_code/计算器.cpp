#include<bits/stdc++.h>
using namespace std;

// 非面向对象的计算器实现，如需添加新功能，需要修改源码
// class calculator
// {
// public:
//     int m_num1, m_num2;
//     int getresult(string oper)
//     {
//         if (oper == "+")
//             return m_num1 + m_num2;
//         else if (oper == "-")
//             return m_num1 - m_num2;
//         else if (oper == "*")
//             return m_num1 * m_num2;
//         else if (oper == "/")
//             return m_num1 / m_num2;
//         else
//             cerr << "Invalid operator!" << endl;
//         return 0;
//     }
// };

// 利用多态实现计算器
class abstract_calculator
{
public:
    int m_num1, m_num2;
    virtural int getresult()
    {
        return 0;
    }
    // virtual int getresult() = 0; // 纯虚函数，强制子类实现
    // 当类中有纯虚函数时，称为抽象类，不能实例化
};
class add:public abstract_calculator
{
public:
    int getresult()
    {
        return m_num1 + m_num2;
    }
};

void test()
{
    // 多态的使用条件
    // 父类指针或引用指向子类对象
    abstract_calculator *calculator = new add;
    calculator->m_num1 = 10;
    calculator->m_num2 = 20;
    cout << "Result: " << calculator->getresult() << endl;
    delete calculator; // 释放内存
}

int main()
{
    test();
    return 0;
}