#include<bits/stdc++.h>
using namespace std;

// 静态成员变量：
// 1.所有的对象共享同一个静态成员变量
// 2.静态成员变量在类的所有对象中只有一份拷贝
// 3.静态成员变量在类内声明，在类外定义和初始化
// 4.在编译阶段，静态成员变量的内存分配就已经完成
// 5.静态成员变量可以通过类名直接访问，也可以通过对象访问

// 静态成员函数
// 1.静态成员函数只能访问静态成员变量
// 2.所有对象共享同一个静态成员函数
// 3.静态成员函数可以在类内声明和定义，也可以在类外定义

class Kind
{
public:
    static int m_A;// 静态成员变量，类内声明

    static void func() // 静态成员函数
    {
        cout << "static func" << endl;
        cout << m_A << endl; // 静态成员函数只能访问静态成员变量
    }

private:
    static int m_B;
};

int Kind::m_A = 10; // 静态成员变量，类外定义和初始化
int Kind::m_B = 20; // 静态成员变量同访问权限

void test1()
{
    Kind k1, k2; // 创建两个对象
    cout << k1.m_A << endl;
    k2.m_A = 20;
    cout << k1.m_A << endl; // 所有的对象共享同一个静态成员变量, 所以k1和k2的m_A是同一个变量
    Kind::m_A = 10;
}

void test2()
{
    Kind k;
    cout << k.m_A << endl; // 通过对象访问静态成员变量
    cout << Kind::m_A << endl; // 通过类名访问静态成员变量
}

void test3()
{
    Kind::func(); // 通过类名访问静态成员函数
    Kind k;
    k.func(); // 通过对象访问静态成员函数
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}