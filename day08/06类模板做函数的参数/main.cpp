#include <iostream>
#include <string>
using namespace std;

//��ģ������������
//1����ʽָ������
//void doWork(Person<string, int> & p);
//2������ģ�廯
//void doWork2(Person<T1, T2> & p);
//3������ģ�廯
//void doWork3(T & p);

template<class NameType, class AgeType>
class Person {
public:
	Person(NameType name, AgeType age) {
		this->age_ = age;
		this->name_ = name;
	}
	void showPerson() {
		cout << "������" << this->name_ << "  ���䣺" << this->age_ << endl;
	}

	NameType name_;
	AgeType age_;
};

//1��ָ����������
void doWork(Person<string, int> & p) {
	p.showPerson();
}

//2������ģ�廯
template <class T1, class T2>
void doWork2(Person<T1, T2> & p) {
	p.showPerson();
}
//3���������ͻ�
template <class T>
void doWork3(T & p) {
	p.showPerson();
}

void test01() {
	Person<string, int> p1("����", 5);
	doWork(p1);

	doWork2(p1);

	doWork3(p1);
}

int main() {
	test01();
	return 0;
}

