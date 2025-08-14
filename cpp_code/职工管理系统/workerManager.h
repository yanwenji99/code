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

	int m_Empnum; // Ա������
	Worker** m_Emparr; // Ա������ָ��
	bool m_fileempty; //  �ж��Ƿ�Ϊ��
};