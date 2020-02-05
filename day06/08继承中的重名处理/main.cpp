#include <iostream>

using namespace std;

class Base {
public:
	int a_;
	Base() {
		a_ = 100;
	}
	void func() {
		cout << "Base func" << endl;
	}

	void func(int a) {
		cout << "Son1 func  11111111" << endl;
	}
};

class Son1 : public Base {
public:
	int a_;
	Son1() {
		a_ = 200;
	}
	void func() {
		cout << "Son1 func" << endl;
	}

};

//如果 子类与父类 有同名的函数 或者 变量    子类不会覆盖父类   两个都存在
//如果 子类与父类 有同名函数  子类会自动把父类的屏蔽掉  只能通过 s1.Base::func()的方式调用 
void test01() {
	Son1 s1;
	cout << s1.a_ << endl;  //200  重名时候 就近原则
	cout << s1.Base::a_ << endl;   //100

	s1.func();
	s1.Base::func(1);
	s1.Base::func();
}


int main(void) {
	
	test01();
	return 0;
}
