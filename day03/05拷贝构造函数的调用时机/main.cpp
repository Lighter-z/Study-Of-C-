#include <iostream>

using namespace std;

//����
//���ղ�������  �޲ι��캯����Ĭ�Ϲ��캯����  �вι��캯��
//�������ͷ���  ��ͨ���캯��    �������캯��

class Person {
public:       //���캯������������������public��
	Person() {
		cout << "Ĭ�Ϲ��캯��--��ͨ���캯��" << endl;
	}

	Person(int a) {
		age = a;
		cout << "�вι��캯��--��ͨ���캯�� age = " << age << endl;
	}
	//�������캯��
	Person(const Person& p) {
		age = p.age;
		cout << "�������캯�� age = " << age << endl;
	}

	~Person() {
		cout << "Ĭ����������" << endl;
	}

	int age;
};

//1.���Ѿ�����õĶ�������ʼ���µĶ���
void test01() {
	Person p1;
	p1.age = 10;
	Person p2(p1);
}

//2.��ֵ���ݵķ�ʽ������������ֵ
void doWork(Person p) {   //Person p = Person(p1)

}
void test02() {
	Person p1;
	p1.age = 10;
	doWork(p1);
}

//3.��ֵ�ķ�ʽ���ؾֲ�����
Person doWork2() {
	Person p1;
	p1.age = 10;
	return p1;
}
void test03() {
	Person p = doWork2();
}

//release ���Ż���ʲô����
/*
Person p  ������Ĭ�Ϲ���
doWork2()�Ż�Ϊ���£�
void doWork2(Person & p){
	Person p1;
	p1.age = 10;
}
	
*/

int main() {
	test03();
	return 0;
}

