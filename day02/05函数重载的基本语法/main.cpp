#include <iostream>

using namespace std;
//��������
//1.������ͬһ�������򣬺�������ͬ
//2.�����Ĳ��� ���� ���� ���� ���� ˳��ͬ

void func() {
	cout << "�޲���" << endl;
}
void func(int a) {
	cout << "int ����" << a << endl;
}

void func(double a) {
	cout << "double ����" << a << endl;
}

//��������ֵ���Ͳ�ͬ   ������Ϊ�������� �ᱨ��
//int func() {  
//	
//}

void test01() {
	func();
	func(1);
	func(1.2);
}

//���������� ���� Ĭ�ϲ��� ʱ��ע����������
void func2(int a,int b = 10) {

}

void func2(int a) {
	
}

void test02() {
//	func2(10);  //����
}

//��������
void func3(int &a) {

	cout << "---" << endl;
}

void func3(const int &a) {
	cout << "const" << endl;
}

void test03() {
	int a = 3;
	func3(a);
	func3(10);
}

int main() {
	test01();
	test03();
	return 0;
}
