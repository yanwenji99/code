#include<iostream> 
#include<string>
using namespace std;
class student
{
public:
    string name, number;
    void get_info(string n,string ID)
    {
        name = n;
        number = ID;
    }
    void show_info()
    {
        cout << "The name of the student is: " << name << endl;
        cout << "The number of the student is: " << number << endl;
    }
};
int main()
{
    student s1;
    s1.get_info("zhangsan","123456");
    s1.show_info();
    return 0;
}