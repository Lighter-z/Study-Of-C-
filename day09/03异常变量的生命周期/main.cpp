#include <iostream>
/*
myException e  ��࿪��һ������ ���ÿ�������
myException *e ������ǰ�ͷŶ���   ʹ��new�Ļ�  ��Ҫ�Լ�����delete
myException &e   �Ƽ�ʹ������   ��һ������ Ҳ����Ҫ��������
*/

using namespace std;

class myException {
public:
	myException() {
		cout << "myException Ĭ�Ϲ��캯��" << endl;
	}
	myException(const myException & e) {
		cout << "myException �������캯��" << endl;
	}
	~myException()
	{
		cout << "myException ��������" << endl;
	}
};

void doWork() {
	throw myException();
}

void test01(void) {
	try {
		doWork();
	}
	//catch (myException e) {//����д����࿪��һ������    ����ÿ�������
	catch (myException &e) {//����д����࿪��һ������      �Ƽ��� ����
		cout << "�����쳣" << endl;
	}
}

int main(void) {
	test01();
	return 0;
}
