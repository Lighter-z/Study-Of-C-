#include <iostream>

using namespace std;

class Person {
	int a;
	void func() {};
	static int b;
	static void func1() {};
	double c;  //ռ8���ֽ�
};

void test01() {
	cout << "���� Person ��С" << sizeof(Person) << endl;
	//�����СΪ1  ÿ��ʵ�������ж�һ�޶��ĵ�ַ,charά�������ַ
	//���� int a;  ��СΪ4
	//���� void func() {};  ���� 4          �����ڶ�������
	//���� static int b;  ����4              �����ڶ�������
	//���� static void func1()  ����4         �����ڶ�������

	//���� ֻ�зǾ�̬��Ա���������ڶ�������

	//���� double c;  ��СΪ16    ӦΪ�ֽڶ���

}

int main() {
	test01();
	return 0;
}
