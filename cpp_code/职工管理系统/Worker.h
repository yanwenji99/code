#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工抽象基类
class Worker
{
public:
	virtual void showinfo() = 0;
	virtual string getposition() = 0;
	int m_ID;
	string m_name;
	int m_department;
};