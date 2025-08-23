#include<bits/stdc++.h>
using namespace std;

class Drinking
{
public:
    // 煮水
    virtual void boil() = 0;
    // 冲泡
    virtual void brew() = 0;
    // 倒入杯中
    virtual void pourInCup() = 0;
    // 添加调料
    virtual void addCondiments() = 0;
    void makedrinking()
    {
        boil();
        brew();
        pourInCup();
        addCondiments();
    }
};
class juice:public Drinking
{
public:
    void boil() override {
        cout << "boiling water..." << endl;
    }
    void brew() override {
        cout << "brewing the drink..." << endl;
    }
    void pourInCup() override {
        cout << "pouring the drink into the cup..." << endl;
    }
    void addCondiments() override {
        cout << "adding condiments..." << endl;
    }
};
void dowork(Drinking *d)
{
    d->makedrinking();
}
int main()
{
    dowork(new juice);
    return 0;
}