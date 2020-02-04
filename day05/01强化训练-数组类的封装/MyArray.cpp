#include "MyArray.h"

MyArray::MyArray()
{
	cout << "�޲ι���" << endl;
	this->m_Capacity = 100;
	this->m_Size = 0;
	this->pAddress = new int[this->m_Capacity];
}

MyArray::MyArray(int capacity)
{
	cout << "�вι���" << endl;
	this->m_Capacity = capacity;
	this->m_Size = 0;
	this->pAddress = new int[this->m_Capacity];
}

MyArray::MyArray(const MyArray & array)
{
	cout << "��������" << endl;
	this->m_Capacity = array.m_Capacity;
	this->m_Size = array.m_Size;
	this->pAddress = new int[array.m_Capacity];

	for (int i = 0; i < array.m_Size; i++) {
		this->pAddress[i] = array.pAddress[i];
	}
}

MyArray::~MyArray()
{
	cout << "��������" << endl;
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
