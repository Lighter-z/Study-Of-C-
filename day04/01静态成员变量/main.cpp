#include <iostream>

using namespace std;

class Person {
public:
	static int age;  //��������  �����ʼ��

	void myFunc() {  //�����Է���
		age = 10;
		other = 20;
		m = 30;
	}

	//��̬��Ա���������Է���  ��ͨ��Ա����
	static void func() {
		//m = 10;  //  ����      //ӦΪ��̬��Ա�����ǹ����  ���Ե��ж���������ʱ�� �޷��������ĸ������m����
		other = 10;//����//��̬��Ա����Ҳ�ǹ���� ��һ�� ���Բ���Ҫ�������ĸ����󣨲���Ҫ������p1����p2��
		cout << "��̬��Ա����" << endl;
	}
private:
	static int other;//��̬˽��Ȩ��  �������������  �������������ʼ��
	int m;
	static void func2() {
		cout << "˽�о�̬��Ա����" << endl;
	}
};

int Person::age = 0;
int Person::other = 1;

void test01() {
	Person p1;
	p1.age = 10;

	Person p2;
	p2.age = 20;

	cout << "p1.a = " << p1.age << endl;  //20
	cout << "p2.a = " << p2.age << endl;  //20   ��̬����  ��������

	//ͨ���������ʾ�̬����
	cout << "Person .a = " << Person::age << endl;

	//��̬��Ա����
	p1.func();
	p2.func();
	Person::func();

	//˽�о�̬��Ա����
	//Person::func2();  //����
}

int main() {

	test01();
	return 0;
}
