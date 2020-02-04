#include <iostream>

using namespace std;

class Person {
public:
	static int age;  //类内声明  类外初始化

	void myFunc() {  //都可以访问
		age = 10;
		other = 20;
		m = 30;
	}

	//静态成员函数不可以访问  普通成员变量
	static void func() {
		//m = 10;  //  报错      //应为静态成员函数是共享的  所以当有多个对象调用时候 无法区分是哪个对象的m变量
		other = 10;//可以//静态成员变量也是共享的 就一份 所以不需要区分是哪个对象（不需要区分是p1还是p2）
		cout << "静态成员函数" << endl;
	}
private:
	static int other;//静态私有权限  不能再类外访问  但可以在类外初始化
	int m;
	static void func2() {
		cout << "私有静态成员函数" << endl;
	}
};

int Person::age = 0;
int Person::other = 1;

void test01() {
	Person p1;
	p1.age = 10;

	Person p2;
	p2.age = 20;

	cout << "p1.a = " << p1.age << endl;  //20
	cout << "p2.a = " << p2.age << endl;  //20   静态变量  共享数据

	//通过类名访问静态数据
	cout << "Person .a = " << Person::age << endl;

	//静态成员函数
	p1.func();
	p2.func();
	Person::func();

	//私有静态成员函数
	//Person::func2();  //报错
}

int main() {

	test01();
	return 0;
}
