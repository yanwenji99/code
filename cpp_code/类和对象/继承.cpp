#include<bits/stdc++.h>
using namespace std;

// 继承的基本用法  class 子类 : 继承方式 父类1，继承方式 父类2，...
// 继承方式：public、protected、private
// public继承：子类可以访问父类的public和protected成员，父类的private成员对子类不可见，访问权限与父类一致
// protected继承：子类可以访问父类的protected和public成员，父类的private成员对子类不可见，访问权限变为protected
// private继承：子类可以访问父类的protected和public成员，父类的private成员对子类不可见，访问权限变为private

// 继承中同名成员（函数或变量）需要加上作用域

class PublicClass
{
public:
    void header()
    {
        cout << "PublicClass header" << endl;
    }
    void footer()
    {
        cout << "PublicClass footer" << endl;
    }
protected:
    void like()
    {
        cout << "Favorite content" << endl;
    }
private:
    void data()
    {
        cout << "Private data" << endl;
    }
};

class CPP : public PublicClass
{
// public:
//     void header()
//     {
//         cout << "PublicClass header" << endl;
//     }
//     void footer()
//     {
//         cout << "PublicClass footer" << endl;
//     }
// protected:
//     void like()
//     {
//         cout << "Favorite content" << endl;
//     }
public:
    void content()
    {
        cout << "CPP content" << endl;
    }
};

class Python : protected PublicClass
{
// protected:
//     void header()
//     {
//         cout << "PublicClass header" << endl;
//     }
//     void footer()
//     {
//         cout << "PublicClass footer" << endl;
//     }
// protected:
//     void like()
//     {
//         cout << "Favorite content" << endl;
//     }
public:
    void content()
    {
        cout << "Python content" << endl;
    }
};

class Java : private PublicClass
{
// private:
//    void header()
//     {
//         cout << "PublicClass header" << endl;
//     }
//     void footer()
//     {
//         cout << "PublicClass footer" << endl;
//     }
// private:
//     void like()
//     {
//         cout << "Favorite content" << endl;
//     }
public:
    void content()
    {
        cout << "Java content" << endl;
    }
};

void test()
{
    CPP cpp;
    cpp.header();
    cpp.content();
    // cpp.like(); // 继承的protected成员不可以访问
    // cpp.data(); // private成员不可访问
    cpp.footer();

    cout << endl;

    Python python;
    // python.header();
    python.content();
    // python.like(); // protected成员不可访问
    // python.data(); // private成员不可访问
    // python.footer();

    cout << endl;

    Java java;
    // java.header();
    java.content();
    // java.like(); // protected成员不可访问
    // java.data(); // private成员不可访问
    // java.footer();
}

int main()
{
    test();
    return 0;
}