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

	//β�巨
	void pushBack(int value);
	//����������ȡ����
	int getData(int index);
	//����������������
	void setData(int index,int value);
	//[]���������
	int & operator[](int index);

private:
	int * pAddress;  //ָ�������洢���ݵ�ָ��
	int m_Size;//�����С
	int m_Capacity;//��������
};

