#include <iostream>
//¼ÓºÅÔËËã·ûÖØÔØ
using namespace std;

class Person{
public:
	Person() {}
	Person(int a1, int b1) :a(a1), b(b1) {
	}

	Person operator+(const Person &p) {
		Person temp;
		temp.a = this->a + p.a;
		temp.b = this->b + p.b;
		return temp;
	}

	int a;
	int b;
};

void test01() {
	Person p1(10,10);
	Person p2(20,20);
	Person p3 = p1 + p2;
	cout << p3.a << endl;
}

int main() {
	test01();
	return 0;
}
