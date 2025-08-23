#include"myArray.hpp"
#include<string>
using namespace std;
class person
{
public:
	person() {};
	person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
void printarray(myArray<int>& arr)
{
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr[i] << " ";
	}
}
void test1()
{
	myArray<int> arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.push(i);
	}
	cout << "arr1:" << endl;
	printarray(arr1);
	cout << endl;
}
void printarray(myArray<person>& arr)
{
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr[i].m_name << " " << arr[i].m_age << endl;
	}
}
void test2()
{
	myArray<person> arr2(10);
	person p1("zhang", 20);
	person p2("li", 18);
	person p3("yan", 19);
	arr2.push(p1);
	arr2.push(p2);
	arr2.push(p3);
	cout << "arr2:" << endl;
	printarray(arr2);
}
int main()
{
	test1();
	test2();
	return 0;
}