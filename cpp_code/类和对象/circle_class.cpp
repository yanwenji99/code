#include<iostream>
using namespace std;
#define PI 3.14
class circle //class设计一个圆类
{
//访问权限
public:
    //属性
    
    int r; //半径
    //行为
    double calculateZC() //求圆的周长
    {
        return 2 * PI * r;
    }
    double caculateMJ() //求圆的面积
    {
        return PI * r * r;
    }
};
int main()
{
    circle c1;
    c1.r = 10;
    cout << c1.calculateZC() << endl;
    cout << c1.caculateMJ() << endl;
    return 0;
}