#include"Manager.h"

Manager::Manager(int ID, string name, int depart)
{
	this->m_ID = ID;
	this->m_name = name;
	this->m_department = depart;
}
void Manager::showinfo()
{
	cout << "ְ����ţ�" << this->m_ID << endl;
	cout << "ְ��������" << this->m_name << endl;
	cout << "ְλ��" << this->getposition() << endl;
	cout << "����������ϰ岼�õ�����\n" << endl;
}
string Manager::getposition()
{
	return string("����");
}