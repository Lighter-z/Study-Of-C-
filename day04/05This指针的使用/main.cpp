#include <iostream>

using namespace std;

//this ָ��ǰ����
//*this ָ�������

class Person {
public:
	Person(int age) {
		this->age = age;
	}
	Person & addAge(Person &p) {
		this->age += p.age;
		return *this;    //*this���� ָ����
	}
	int age;
};

void test01() {
	Person p1(10);
	cout << p1.age << endl;
	Person p2(10);
	p1.addAge(p2).addAge(p2);    //��ʽ��̷�ʽ
	cout << p1.age << endl;
}

int main() {
	test01();
	return 0;
}
