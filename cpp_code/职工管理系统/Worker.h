#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ���������
class Worker
{
public:
	virtual void showinfo() = 0;
	virtual string getposition() = 0;
	int m_ID;
	string m_name;
	int m_department;
};