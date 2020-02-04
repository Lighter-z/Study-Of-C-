#include <iostream>
using namespace std;

class Person {
public:
	Person() {}
	Person(int age) : m_age(age) {
		
	}
	void showAge() {
		cout << "���䣺" << this->m_age << endl;
	}
	~Person() {
		cout << "��������" << endl;
	}
	int m_age;

};

//����ָ��
//�����й��Զ������͵Ķ����ö�������Զ����ͷ�
//���ã�
//���� Person p = new Person(10);
//�����ֶ� delete p1 ʱ��  ������ָ��ɾ��
class smartPointer {
public:
	smartPointer(Person * person) {
		this->person = person;
	}
	//����->������ָ����� �� Person *pһ��ȥʹ��
	Person * operator->() {
		return this->person;
	}

	Person & operator*() {
		return *this->person;
	}

	~smartPointer() {
		if (this->person != NULL) {
			delete this->person;
			this->person = NULL;
		}
	}
private:
	Person * person;
};

//class p {
//public:
//	p(Person *p) {
//		this->pe = p;
//	}
//	~p() {
//		if (this->pe != NULL) {
//			delete this->pe;
//			this->pe = NULL;
//		}
//	}
//private:
//	Person * pe;
//};

void test01() {
	//Person p1(10);
	//p1.showAge();

	smartPointer sp(new Person(10));   //���ٵ�ջ��  
	sp->showAge();
	(*sp).showAge();
}

int main() {
	test01();
	return 0;
}
