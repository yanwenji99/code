#include<iostream>
using namespace std;

// 函数模板
template<typename T> // 声明一个模板,typename可以替换为class
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void test()
{
    int a = 5;
    int b = 10;
    //Swap(a, b); // 自动类型推导
    Swap<int>(a, b); // 显式指定类型
    cout << "a: " << a << ", b: " << b << endl;
}
int main()
{
    test();
    return 0;
}