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
private:
	int age;
};

void test01() {
	//���ŷ�����
	/*
	Person p1;
	Person p2(1);
	Person p3(p2);
	*/

	//��ʾ������
	Person p4 = Person(100);
	Person p5 = Person(p4);
	/*
	Person(100)  //��������  �ص㣺������������ֶ����������� ��ô�����д����������ͷ��������
	Person p4 = Person(100)   //����������� p4
	*/

	Person p6 = 200;//�൱�� Person p6 = Person(200);   ��ʽ����ת��
	Person p7 = p6; //  ͬ��
}

int main() {
	test01();
	return 0;
}

