#include"Boss.h"

Boss::Boss(int ID, string name, int depart)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_department = depart;
}
void Boss::showinfo()
{
	cout << "职工编号：" << this->m_ID << endl;
	cout << "职工姓名：" << this->m_name << endl;
	cout << "职位：" << this->getposition() << endl;
	cout << "工作：制定公司发展方向\n" << endl;
}
string Boss::getposition()
{
	return "Boss";
}