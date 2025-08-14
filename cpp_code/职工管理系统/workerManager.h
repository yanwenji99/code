#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Worker.h"
#include"Employee.h"
#include"Boss.h"
#include"Manager.h"
#define FILENAME "empfile.txt"
using namespace std;

class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();
	void Shoe_Menu();
	void exitSystem();
	void add_emp();
	void save();
	int getnum();
	void init_emp();
	void show_emp();
	void del_emp();
	int IDexit(int ID);
	void mod_emp();
	void find_emp();
	void sort_emp();
	void clean_file();

	int m_Empnum; // 员工人数
	Worker** m_Emparr; // 员工数组指针
	bool m_fileempty; //  判断是否为空
};