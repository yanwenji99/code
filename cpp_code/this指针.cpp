#include<bits/stdc++.h>
using namespace std;

// this指针：指向调用成员函数的对象
// 特点：
// this指针是一个隐含的指针，指向调用成员函数的对象
// 不需要定义，编译器会自动生成
// 使用：
// 当形参与成员变量同名时，使用this指针来区分
// 在类的非静态成员函数中，可使用return *this

class Person
{
public:
    Person(int age)
    {
        this->age = age; // 使用this指针来区分成员变量和形参
    }
    Person& Personaddage(int age) // 返回值为Person的引用
    {
        this->age += age; // 使用this指针来区分成员变量和形参
        return *this; // 返回当前对象的引用
    }
    int age;
};

void test01()
{
    Person p(18);
    cout<< "Person age: " << p.age << endl; // 输出Person age: 18
}

void test02()
{
    Person p(30);
    p.Personaddage(10).Personaddage(10). Personaddage(10);
    cout << "Person age after adding: " << p.age << endl; // 输出Person age after adding: 60
}
int main()
{
    test01();
    test02();
    return 0;
}