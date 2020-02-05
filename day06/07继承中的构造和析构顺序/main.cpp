#include <iostream>

using namespace std;

//子类会继承父类的成员函数 成员属性
//子类不会继承 父类构造函数  析构函数
class Base {
public:
	Base() {
		cout << "Base构造函数" << endl;
	}
	~Base() {
		cout << "Base析构函数" << endl;
	}
};

class Son1 : public Base {
public:
	Son1() {
		cout << "Son1构造函数" << endl;
	}
	~Son1() {
		cout << "Son1析构函数" << endl;
	}
};

class Base2 {
public:
	Base2(int a) {
		cout << "Base2有参构造函数" << endl;
	}

};

class Son2  : public Base2{
public:
	/*Son2() {}*/  //报错  Base2 不存在 无参构造
	Son2(int a):Base2(a){       //当基类没有 无参构造时候  使用这种方法调用基类构造函数
		cout << "Son2有参构造函数" << endl;
	}
};

void test01(void) {
	Son1 s1;  //先调用 Base的构造 在调用自己的构造   析构反之。
	/*Son2 s2_1;*/
	Son2 s2(1);
}



int main() {
	test01();
	return 0;
}
