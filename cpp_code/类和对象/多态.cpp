#include<bits/stdc++.h>
using namespace std;

// 多态：同一操作作用于不同对象时，表现出不同的行为

// 静态多态：编译时多态，编译时确定地址，函数重载和运算符重载
// 动态多态：运行时多态，运行时确定地址，虚函数和继承

// 动态多态：
// 1. 父类中声明虚函数
// 2. 子类中重写虚函数

class animal
{
public:
    virtual void speak() // 虚函数，地址在运行时确定
    {
        cout << "Animal speaks" << endl;
    }
    // 虚函数的本质是指向基类的指针
};
class dog : public animal
{
public:
    void speak() override // 重写虚函数,override不是必须的
    {
        cout << "Dog barks" << endl;
    }
};
class cat : public animal
{
public:
    void speak() override
    {
        cout << "Cat meows" << endl;
    }
};

void makeSound(animal& a) // C++中允许父子类的类型转换，父类的引用执行子类对象
{
    a.speak();
}

void test()
{
    dog d;
    makeSound(d);
}

int main()
{
    test();
    return 0;
}