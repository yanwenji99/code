#pragma once
#include"Worker.h"
#include<iostream>
using namespace std;

class Manager :public Worker
{
public:
	Manager(int ID, string name, int depart);
	void showinfo();
	string getposition();
};