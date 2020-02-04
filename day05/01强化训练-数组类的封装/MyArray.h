#pragma once
#include <iostream>

using namespace std;

class MyArray
{
public:
	MyArray();
	MyArray(int capacity);
	MyArray(const MyArray & array);
	~MyArray();

	//尾插法
	void pushBack(int value);
	//根据索引获取数据
	int getData(int index);
	//根据索引设置数据
	void setData(int index,int value);
	//[]运算符重载
	int & operator[](int index);

private:
	int * pAddress;  //指向真正存储数据的指针
	int m_Size;//数组大小
	int m_Capacity;//数组容量
};

