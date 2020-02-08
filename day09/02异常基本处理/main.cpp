#include <iostream>
//ջ���� ��
//�� try��ʼ �� throw �׳��쳣֮ǰ   ����ջ�ϵĶ��󶼻ᱻ�ͷţ�����
using namespace std;

//�Զ����쳣
class myException {
public:
	void printError(void) {
		cout << "�Զ����쳣" << endl;
	}
};

class Person {
public:
	Person() {
		cout << "���캯��" << endl;
	}
	~Person()
	{
		cout << "��������" << endl;
	}
};

int Devide(int a, int b) {
	if (b == 0) {
		//throw - 1;  //�׳�int�����쳣
		//throw 3.14;    //double�����쳣
		//throw 'a';    //char �����쳣

		//ջ���� ��
		//�� try��ʼ �� throw �׳��쳣֮ǰ   ����ջ�ϵĶ��󶼻ᱻ�ͷţ�����
		//p1 �� p2 �Ĺ���������˳���෴   �ȹ���p1  ������p2
		Person p1;
		Person p2;

		throw myException();  // �Զ����쳣       myException()����������
	}
	return a / b;
}

void test01(void) {
	int a = 10;
	int b = 0;
	try {
		cout << Devide(a, b) << endl;
	}
	catch (int) {
		cout << "int���Ͳ����쳣" << endl;
	}
	catch (double) {
		//������봦������쳣 ���Լ��������׳�  ʹ��throw
		throw;
		cout << "double���Ͳ����쳣" << endl;
	}
	catch (myException e) {
		e.printError();
	}
	catch (...) {
		cout << "�������Ͳ����쳣" << endl;
	}
}

//�쳣�ӿ����� ��visual stduio������������
//QT ���� Linux�¿���
void testFunc1() throw() {    //���׳��κ��쳣
	//throw 1;   //������������ ���� visual stduio ����������
}
void testFunc2() throw(int) {    //ֻ���׳�int�쳣
	//throw 3.314;     //������������ ���� visual stduio ����������
	throw 1;
}


void test02() {
	try {
		testFunc2();
	}
	catch (int) {
		cout << "test02 int �쳣" << endl;
	}
	catch (...) {
		cout << "test02 ���� �쳣" << endl;
	}
}

int main(void) {
	try {
		test01();
	}
	catch (double) {  //����쳣��û�д���  ��ô��Աterminate����ʹ�����ж�
		cout << "main double���Ͳ����쳣" << endl;
	}
	test02();
	return 0;
}
