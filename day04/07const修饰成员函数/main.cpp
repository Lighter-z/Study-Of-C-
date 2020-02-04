#include <iostream>

using namespace std;


class Person {
public:
	Person() {
		//构造中修改属性
		//this永远执行本体
		//Person * const this

		this->m_a = 0;
		this->m_b = 0;
	}

	void showInfo() const {  //常函数   不允许修指针指向的值    //长函数修饰的是this指针 const Type *const this
		//this->m_a = 100;  //this指向的数值不能修改
		this->m_b = 100;  //加上 mutable 后 可以修改
		cout << "m_a = " << m_a << endl;
		cout << "m_b = " << m_b << endl;
	}

	void show2() {
	}
	
	static void show3() {}

	int m_a;
	mutable int m_b;  //就算是常函数 也要执意修改
};

void test01() {
	Person p1;
	p1.showInfo();
	p1.m_a = 10;

	//常对象
	//不允许修改内部属性
	//常对象不允许调用 普通的成员函数
	//常对象可以调用 常函数
	const Person p2;
	//p2.m_a = 100;  //报错
	//p2.show2();   //报错
	p2.show3();  //可以 不报错
	p2.showInfo();//可以

}

int main() {
	test01();
	return 0;
}
