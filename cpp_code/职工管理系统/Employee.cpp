#include"Employee.h"

Employee::Employee(int ID, string name, int depart)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_department = depart;
}
void Employee::showinfo()
{
	cout << "职工编号：" << this->m_ID << endl;
	cout << "职工姓名：" << this->m_name << endl;
	cout << "职位：" << this->getposition() << endl;
	cout << "工作：完成经理布置的任务\n" << endl;
}
string Employee::getposition()
{
	return string("职工");
}