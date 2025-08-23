#pragma once
// 通用的数组类
#include<iostream>
using namespace std;

template<class T>
class myArray
{
public:
	myArray(int capacity)
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_capacity];
	}
	myArray(const myArray& arr)
	{
		this->capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.m_capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	myArray& operator=(const myArray& arr)
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = arr.m_capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.m_capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	~myArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
	void push(const T& val)
	{
		if (this->m_capacity == this->m_size)
		{
			return;
		}
		this->pAddress[this->m_size] = val;
		this->m_size++;
	}
	void pop()
	{
		if (this->m_size == 0)
		{
			return;
		}
		this->m_size--;// 最后析构函数释放
	}
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	int getcapacity()
	{
		return this->m_capacity;
	}
	int getsize()
	{
		return this->m_size;
	}
private:
	T* pAddress;// 指针指向堆区开辟的真实数组
	int m_capacity;
	int m_size;
};