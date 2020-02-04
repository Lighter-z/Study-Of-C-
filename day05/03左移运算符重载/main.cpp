#include <iostream>
using namespace std;

class Person {
public:
	friend ostream & operator<<(ostream &c, Person &p);
	Person() {}
	Person(int a1, int b1) :a(a1), b(b1) {
	}

	Person operator+(const Person &p) {
		Person temp;
		temp.a = this->a + p.a;
		temp.b = this->b + p.b;
		return temp;
	}
	//重载左移运算符不能写在成员函数中
	//void operator<<() {
	//}
private:
	int a;
	int b;
};

ostream & operator<<(ostream &c, Person &p) {
	cout << p.a;
	cout << p.b << endl;
	return cout;
}

void test01() {
	Person p1(10,10);
	cout << p1 << endl;
}

int main() {
	test01();
	return 0;
}
