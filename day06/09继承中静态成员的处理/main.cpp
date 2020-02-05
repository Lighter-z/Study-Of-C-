#include <iostream>
#include <string>


using namespace std;

//静态成员 类内声明 类外定义
//静态成员 共享数据
class Base {
public:
	static int a_;
	static void func() {
		cout << "Base func" << endl;
	}
	static void func(int a) {
		cout << "Base func int" << endl;
	}
};

int Base::a_ = 10;

class Son1:public Base {
public:
	static int a_;
	static void func() {
		cout << "Son1 func" << endl;
	}
};

int Son1::a_ = 20;

//静态成员属性可以继承下来
//
void test01(void) {
	Son1 s1;
	Son1 s2;
	cout << s1.a_ << endl;
	cout << s1.Base::a_ << endl;
	s2.a_ = 30;
	cout << s1.a_ << endl;
	cout << s2.a_ << endl;
	Son1::func();
	s1.func();
	s1.Base::func();
	/*s1.func(1);*/  //报错  重名时候  子类会隐藏父类
	s1.Base::func(1);

}

int main(void) {
	test01();
	return 0;
}
