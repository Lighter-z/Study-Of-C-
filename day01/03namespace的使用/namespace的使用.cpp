#include <iostream>
#include "game1.h"
#include "game2.h"

using namespace std;
//1.�����ռ���Է��ú������������ṹ��
//2.�����ռ���붨����ȫ����������
//3.�����ռ����Ƕ�������ռ�
namespace A {
	
	class Person {};
	struct Book {};

	namespace B {
		int a = 10;
	}

}

void test01(void) {
	cout << "�����ռ�A�µ�B�еı���a = " << A::B::a << endl;
}

//4.�����ռ��ǿ��ŵģ�������ʱ��ԭ���������ռ����������
namespace A { //�������ռ��������A�����ռ�ϲ�
	int b = 55;
}

void test02(void) {
	cout << "�����ռ�A�¼ӵı���b = " << A::b << endl;
}

//5.����������  �����ռ�
//��ʱ�൱�� static int m_c = 99;
//ֻ���ڵ�ǰ�ļ���ʹ��
namespace {
	
	int m_c = 99;
}

void test03(void) {
	cout << "���� �����ռ��еı���m_c = " << ::m_c << endl;
	cout << "�ڶ�����ʾ��ʽ ���� �����ռ��еı���m_c = " << m_c << endl;
}

//6.�����ռ����ȡ����
namespace veryLongName {
	int v_a = 44;
}

void test04(void) {
	namespace veryShortName = veryLongName;

	cout << "�����ռ���� v_a = " << veryShortName::v_a << endl;
}

int main(void) {
	
	LOL::showAtk();
	KingGlory::showAtk();
	test01();
	test02();
	test03();
	test04();
	return 0;
}
