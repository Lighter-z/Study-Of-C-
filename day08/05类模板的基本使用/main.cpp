#include <iostream>
#include <string>

using namespace std;

template<class NameType, class AgeType>
class Person {
public:
	Person(NameType name, AgeType age) {
		this->age_ = age;
		this->name_ = name;
	}

	NameType name_;
	AgeType age_;
};

void test01() {

	//�Զ�����ģ���Ƶ� ��֧��
	//Person p1("����", 3);   //����

	//��ʽָ������
	Person<string, int> p1("����", 3);

	cout << p1.name_ << p1.age_ << endl;

}

class Person1 {
public:
	void showPerson1() {
		cout << "Person1����" << endl;
	}
};

class Person2 {
public:
	void showPerson2() {
		cout << "Person2����" << endl;
	}
};

template<class T>
class myClass {
public:
	T obj;
	void func1() {
		obj.showPerson1();
	}
	void func2() {
		obj.showPerson2();
	}
};

//��Ա����һ��ʼ���ᴴ��������ʱ��Żᴴ��
//���һ��ʼ�ʹ�����  ��ô ���� m1.func2() ʱ��  �Ѿ���func2()������   ����Ӧ�ò��ᱨ��
void test02(void) {
	myClass<Person1> m1;
	m1.func1();
	//m1.func2();    //���� Person1��û��showPerson2
}

int main() {
	test01();
	test02();
	return 0;
}

