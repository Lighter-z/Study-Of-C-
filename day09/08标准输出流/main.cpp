#include <iostream>
#include <iomanip>
/*
cout.flush()//ˢ����������  Linux����Ч
cout.put()   //�򻺳���д�ַ�
cout.write()  //��buf��дnum���ֽڵ���ǰ�������
*/
using namespace std;

void test01(void) {
	cout.put('c');
	cout.put('a') << endl;
	cout.put('a').put('b') << endl;

	char buf[1024] = "hello world";
	cout.write(buf, strlen(buf));
}

void test02(void) {
	int num = 10;
	cout.width(20);//���ӿո�
	cout.fill('/');//�ո��� / ����
	cout.setf(ios::left);//���ø�ʽ  ����������������
	cout.unsetf(ios::dec);//ж��ʮ����
	cout.setf(ios::hex);//��װʮ������
	cout.setf(ios::showbase);//ǿ�������������0  0x


	cout << num << endl;
}

int main(void) {
	//test01();
	test02();
	return 0;
}
