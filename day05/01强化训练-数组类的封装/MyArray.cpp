#include "MyArray.h"

MyArray::MyArray()
{
	cout << "无参构造" << endl;
	this->m_Capacity = 100;
	this->m_Size = 0;
	this->pAddress = new int[this->m_Capacity];
}

MyArray::MyArray(int capacity)
{
	cout << "有参构造" << endl;
	this->m_Capacity = capacity;
	this->m_Size = 0;
	this->pAddress = new int[this->m_Capacity];
}

MyArray::MyArray(const MyArray & array)
{
	cout << "拷贝构造" << endl;
	this->m_Capacity = array.m_Capacity;
	this->m_Size = array.m_Size;
	this->pAddress = new int[array.m_Capacity];

	for (int i = 0; i < array.m_Size; i++) {
		this->pAddress[i] = array.pAddress[i];
	}
}

MyArray::~MyArray()
{
	cout << "析构函数" << endl;
	if (this->pAddress != NULL) {
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
}

void MyArray::pushBack(int value)
{
	this->pAddress[this->m_Size] = value;
	this->m_Size++;
}

int MyArray::getData(int index)
{
	return this->pAddress[index];
}

void MyArray::setData(int index,int value)
{
	this->pAddress[index] = value;
}
