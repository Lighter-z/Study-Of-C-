#include <iostream>

using namespace std;

class Person{
public:
	Person() {
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	Person(int a) {
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	~Person() {
		cout << "Ĭ����������" << endl;
	}
};

void test0() {
	//Person p;  //��ջ�ϴ���    �����������ͷ���
	Person *p1 = new Person;  //�ڶ�������  ��������Ҳ�����ͷ�
	//����new�����Ķ��� ���᷵�ظ�����ָ��
	//malloc ���� void * ����    ��Ҫǿת
	//malloc������ù��캯��    new�����
	//new�������   malloc�Ǻ���

	//�ͷſռ�
	//delete Ҳ�������  ��� newʹ��   malloc���freeʹ��
	delete p1; 
}

void test02() {
	void * p = new Person;
	//��ʹ��void * ʱ��������ͷŵ�����
	delete p;   //�޷��ͷ�
}

void test03() {
	//�ڶ��� ��ͨ��new��������   һ�������Ĭ�Ϲ��캯��  һ��Ҫ�ṩ
	Person *p = new Person[10];

	//�ͷ�����ʱ�� Ҫ��[]
	delete[]p;

	//�ڶ��ϣ�  ���û���޲ι��캯��  ����ָ���вι��캯��
	Person p2[2] = {Person(1),Person(2)};
}

int main() {
	
	test0();
	return 0;
}
