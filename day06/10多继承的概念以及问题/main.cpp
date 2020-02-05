#include <iostream>
#include <string>

using namespace std;

class Base1 {
public:
	int a_;
	int ab_;
	Base1() {
		a_ = 10;
		ab_ = 20;
	}
};

class Base2 {
public:
	int b_;
	int ab_;
	Base2() {
		b_ = 10;
		ab_ = 30;
	}
};

//多继承
class Son1 :public Base1, public Base2 {
public:
	int c_;
	int d_;
};

void test01(void) {
	cout << sizeof(Son1) << endl;       //16
	Son1 s1;
	cout << s1.a_ << endl;  
	cout << s1.b_ << endl;
	//多继承中 容易引发 二义性
	//cout << s1.ab_ << endl;  //二义性 报错
	cout << s1.Base1::ab_ << endl;
	cout << s1.Base2::ab_ << endl;
}

int main(void) {
	test01();
	return 0;
}
