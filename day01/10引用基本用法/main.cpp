#include <iostream>
using namespace std;

//1.���û����÷� Type &���� = ԭ��
void test01(void) {
	int a = 10;
	int &b = a;  //���ó�ʼ���󲻿��޸�
	b = 20;
	cout << "a " << a << endl;
	cout << "b " << b << endl;
}

//2.���ñ����ʼ��
void test02() {
	//int &a;  //���ñ����ʼ�� ����ʼ���ᱨ��
}

void test03(void) {
	int a = 10;
	int &b = a;  //���ó�ʼ���󲻿��޸�
	b = 20;
	cout << "a " << a << endl;
	cout << "b " << b << endl;

	int c = 30;
	b = c;  //��и�ֵ
}

//3.�����齨������
void test04(void) {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}

	//�����������
	int(&ar)[10] = arr;
	for (int i = 0; i < 10; i++) {
		printf("ar[%d] = %d\r\n",i,ar[i]);
	}
}

int main(void) {
	test01();
	test04();
	return 0;
}