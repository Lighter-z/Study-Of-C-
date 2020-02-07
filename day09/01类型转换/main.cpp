#include <iostream>
/*
1����̬ת��  static_cast<Ŀ���������>(ԭʼ����)

2����̬ת��  dynamic_cast<Ŀ���������>(ԭʼ����)
	2.1���ǳ��ϸ�    ʧȥ���Ȼ��߲���ȫ��������ת��
	2.2������ת��Ϊ������  ����ȫ ������ת��  �����ֶ�̬ʱ������ת��

3������ת��  const_cast<Ŀ���������>(ԭʼ����)
	3.1�����ܶ� ��ָ�� ���� ������ �ı�������ת��

4�����½���ת�� reinterpret_cast   ���ȫ���õ���  �����ò�����
*/

using namespace std;

//static_cast<Ŀ�����>(ԭʼ����)

//-------------------------------��̬ת��-------------------------------
//��������
void test01(void) {
	char a = 'a';
	double d = static_cast<double>(a);
	cout << d << endl;
}

class Base {};
class Child :public Base {};
class Other {};

void test02(void) {
	Base * b = NULL;
	Child * c = NULL;
	//�� Base תΪ Child ����ת ����ȫ
	Child * c2 = static_cast<Child *>(b);

	//�� Child תΪ Base ����ת ��ȫ
	Base * b1 = static_cast<Base *>(c);

	//תother    ת����Ч
	//Other * o = static_cast<Other *>(b);    //����
}

class Base2 {};
class Child2 :public Base2 {};
class Other2 {};

//-------------------------------��̬ת��-------------------------------
void test03(void) {
	char c = 'c';
	//����  �������Ͳ�����ת��
	//dynamic_cast �ǳ��ϸ�    ʧȥ���Ȼ��߲���ȫ��������ת��
	//double d = dynamic_cast<double>(c);

	Base2 * b = NULL;
	Child2 * c2 = NULL;
	//�� Child2 תΪ Base2 ����ת ��ȫ
	Base2 * b2 = dynamic_cast<Base2 *>(c2);

	//�� Base2 תΪ Child2 ����ת ����ȫ
	//Child * c3 = dynamic_cast<Child *>(b);
}
//dynamic_cast ��������˶�̬ �����ɻ���ת��Ϊ�����ࣨ����ת����
class Base3 {
public:
	virtual void func(void) {}
};
class Child3 :public Base3 {
public:
	virtual void func(void) {}
};
class Other3 {};

void test04() {
	Base3 * base3 = new Child3;
	
	//������̬ ������ ����ת��Ϊ������
	Child * c3 = dynamic_cast<Child *>(base3);
}

//-------------------------------����ת��-------------------------------
void test05(void) {
	//---------------ָ��---------------
	const int *p = NULL;
	//ȡ��const
	int * s = const_cast<int *>(p);

	int * p2 = NULL;
	//����const
	const int * s2 = const_cast<const int *>(p2);

	//���ܶ� ��ָ�� ���� �����õı�������ת��
	int p3 = 10;
	//����
	//const int s3 = const_cast<const int>(p3);

	//---------------����---------------
	int num1 = 10;
	int & numRef1 = num1;
	const int & cnum1 = const_cast<const int &>(numRef1);

	int & cnum2 = const_cast<int &>(cnum1);
}

//-------------------------------���½���ת��-------------------------------

void test06(void) {
	int a = 10;
	int *p = reinterpret_cast<int *>(a);

	Base * base = NULL;
	Other * o = NULL;
	Base * b1 = reinterpret_cast<Base *>(o);

}

int main(void) {
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	return 0;
}
