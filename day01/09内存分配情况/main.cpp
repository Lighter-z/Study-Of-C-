#include <iostream>
#include <string>
using namespace std;
//����ֻҪ�Ƿ����ڴ�ı��� ������ʹ��ָ��ȡ��ַ�ķ�ʽ�޸�����ֵ

//1.const�����ڴ�  ȡ��ַʱ��������ʱ�ڴ�
//2.constǰ�� extern  ������Ҳ���const�����ڴ�
void test01(void) {
	const int m_a = 10;
	int *p = (int *)&m_a;//������ʱ�ڴ�
}

//3.ʹ����ͨ������ʼ��const�ı��� Ҳ������ڴ�
void test02(void) {
	int a = 10;
	const int b = a;


	//����ֻҪ�Ƿ����ڴ�ı��� ������ʹ��ָ��ȡ��ַ�ķ�ʽ�޸�����ֵ
	int *p = (int *)&a;
	*p = 1000;
	cout << "test02 *p = " << *p << endl; //1000
	cout << "test02 a = " << a << endl;  //1000

}

//4. �Զ�����������  ��constҲ���Զ������ڴ�
struct Person {
	string m_name;
	int m_age;
};

void test03() {
	const Person p1;
	//p1.m_name = "aa"; //const �����޸� ����

	Person *p = (Person *)&p1;
	p->m_name = "aa";
	(*p).m_age = 19;
	cout << "����" << p->m_age;
	cout << "����" << p->m_name;

}

int main(void) {
	test02();
	test03();
	/*cout << a << endl;*/
	return 0;
}
