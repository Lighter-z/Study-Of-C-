#include <iostream>
#include <string>

using namespace std;

template<class T>
class Base {
public:
	Base() {}
	Base(T a) {
		this->a_ = a;
	}
	T a_;
};

class Child1: public Base<int> {
public:
	Child1(int a) {
		this->a_ = a;
	}
	void Show(void) {
		cout << this->a_ << endl;
	}
};

template<class T1, class T2>
class Child2 : public Base<T1> {
public:
	Child2() {
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	Child2(T1 a, T2 b) {
		this->a_ = a;
		this->b_ = b;
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	void Show(void) {
		cout << this->a_ << endl;
		cout << this->b_ << endl;
	}
	T2 b_;
};

void test01() {
	Child1 c1(0);
	c1.Show();
	cout << "---Child2---" << endl;
	Child2 <int, double> c2(3, 3.6);
	c2.Show();

}

int main() {
	test01();
	return 0;
}

