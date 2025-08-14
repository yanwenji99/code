#include"Manager.h"

Manager::Manager(int ID, string name, int depart)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_department = depart;
}
void Manager::showinfo()
{
	cout << "职工编号：" << this->m_ID << endl;
	cout << "职工姓名：" << this->m_name << endl;
	cout << "职位：" << this->getposition() << endl;
	cout << "工作：完成老板布置的任务\n" << endl;
}
string Manager::getposition()
{
	return string("经理");
}