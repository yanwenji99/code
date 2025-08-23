#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
    void set_name(string name)
    {
        p_name = name;
    }
    string get_name()
    {
        return p_name;
    }
    void set_age(int age)
    {
        p_age = age;
    }
    int get_age()
    {
        return p_age;
    }
    void set_phone(string phone)
    {
        p_phone = phone;
    }
private:
    string p_name; //可读可写
    int p_age;     //可读可写
    string p_phone;  //只写
};
int main()
{
    Person p1;
    p1.set_name("John Doe");
    p1.set_age(30);
    p1.set_phone("123-456-7890");
    cout << "Name: " << p1.get_name() << endl;
    cout << "Age: " << p1.get_age() << endl;
    return 0;
}