#include <iostream>

using namespace std;

class Base01 {
public:
	int a_;
	Base01() {
		int a_ = 0;
		int b_ = 0;
		int c_ = 0;
	}
protected:
	int b_;
private:
	int c_;
};

class Son1 : public Base01 {
public:

	void fun() {
		cout << a_ << endl;
		cout << b_ << endl;
		//cout << c_ << endl;  //私有不可以继承

	}
};

class Son2 : protected Base01 {
public:
	void func() {
		cout << a_ << endl;    // 现在是protected
		cout << b_ << endl;   // 现在是protected
		//cout << c_ << endl;  //私有不可以继承
	}
};

class Son3 : private Base01 {
public:
	void func() {
		cout << a_ << endl;
		cout << b_ << endl;
		//cout << c_ << endl;  //私有不可以继承
	}
};

void test01() {
	Son1 s1;
	s1.fun();
	s1.a_ = 10;
	//s1.b_;  //  保护在外部不可以调用
	//s1.c_;  //  私有不可以调用

	Son2 s2;
	s2.func();
	//s2.a_; //  保护继承后 变为保护的  保护在外部不可以调用
	//s2.c_;  //  私有不可以调用

	Son3 s3;
	s3.func();
	//s3.a_;//  私有继承后  变为私有的  私有不可以调用	
	//s3.c_;  //  私有不可以调用
}

int main(){
	test01();
	return 0;
}
