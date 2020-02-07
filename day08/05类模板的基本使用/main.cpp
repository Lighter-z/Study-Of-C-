#include <iostream>
#include <string>

using namespace std;

template<class NameType, class AgeType>
class Person {
public:
	Person(NameType name, AgeType age) {
		this->age_ = age;
		this->name_ = name;
	}

	NameType name_;
	AgeType age_;
};

void test01() {

	//自动类型模板推导 不支持
	//Person p1("张三", 3);   //报错

	//显式指定类型
	Person<string, int> p1("张三", 3);

	cout << p1.name_ << p1.age_ << endl;

}

class Person1 {
public:
	void showPerson1() {
		cout << "Person1调用" << endl;
	}
};

class Person2 {
public:
	void showPerson2() {
		cout << "Person2调用" << endl;
	}
};

template<class T>
class myClass {
public:
	T obj;
	void func1() {
		obj.showPerson1();
	}
	void func2() {
		obj.showPerson2();
	}
};

//成员函数一开始不会创建，运行时候才会创建
//如果一开始就创建了  那么 调用 m1.func2() 时候  已经有func2()函数了   调用应该不会报错
void test02(void) {
	myClass<Person1> m1;
	m1.func1();
	//m1.func2();    //报错 Person1中没有showPerson2
}

int main() {
	test01();
	test02();
	return 0;
}

