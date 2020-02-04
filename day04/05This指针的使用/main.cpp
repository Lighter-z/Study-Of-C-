#include <iostream>

using namespace std;

//this 指向当前对象
//*this 指向对象本体

class Person {
public:
	Person(int age) {
		this->age = age;
	}
	Person & addAge(Person &p) {
		this->age += p.age;
		return *this;    //*this对象 指向本体
	}
	int age;
};

void test01() {
	Person p1(10);
	cout << p1.age << endl;
	Person p2(10);
	p1.addAge(p2).addAge(p2);    //链式编程方式
	cout << p1.age << endl;
}

int main() {
	test01();
	return 0;
}
