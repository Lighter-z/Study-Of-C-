#include <iostream>

using namespace std;


class Person {
public:
	Person() {
		//�������޸�����
		//this��Զִ�б���
		//Person * const this

		this->m_a = 0;
		this->m_b = 0;
	}

	void showInfo() const {  //������   ��������ָ��ָ���ֵ    //���������ε���thisָ�� const Type *const this
		//this->m_a = 100;  //thisָ�����ֵ�����޸�
		this->m_b = 100;  //���� mutable �� �����޸�
		cout << "m_a = " << m_a << endl;
		cout << "m_b = " << m_b << endl;
	}

	void show2() {
	}
	
	static void show3() {}

	int m_a;
	mutable int m_b;  //�����ǳ����� ҲҪִ���޸�
};

void test01() {
	Person p1;
	p1.showInfo();
	p1.m_a = 10;

	//������
	//�������޸��ڲ�����
	//������������� ��ͨ�ĳ�Ա����
	//��������Ե��� ������
	const Person p2;
	//p2.m_a = 100;  //����
	//p2.show2();   //����
	p2.show3();  //���� ������
	p2.showInfo();//����

}

int main() {
	test01();
	return 0;
}
