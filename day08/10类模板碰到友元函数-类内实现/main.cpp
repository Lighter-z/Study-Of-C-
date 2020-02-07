//写友元函数目的  访问类中私有属性

#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
class Person {
	friend void Show(Person<T1, T2> & p) {
		cout << "名字：" << p.name_ << p.age_ << "岁" << endl;
	}
public:
	Person(T1 a, T2 b) {
		this->age_ = b;
		this->name_ = a;
	}
private:
	T1 name_;
	T2 age_;
};

void test01() {
	Person<string, int> p1("张三", 5);
	
	Show(p1);
}

int main() {
	test01();
	return 0;
}


