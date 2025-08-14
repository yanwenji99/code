#pragma once
#include"Worker.h"
#include<iostream>
using namespace std;

class Boss:public Worker
{
public:
	Boss(int ID, string name, int depart);
	void showinfo();
	string getposition();
};