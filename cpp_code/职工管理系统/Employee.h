#pragma once
#include"Worker.h"
#include<iostream>
using namespace std;

class Employee :public Worker
{
public:
	Employee(int ID,string name,int depart);
	void showinfo();
	string getposition();
};