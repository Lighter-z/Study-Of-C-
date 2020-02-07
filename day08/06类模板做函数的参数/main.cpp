#include <iostream>
#include <string>
using namespace std;

//类模板做函数参数
//1、显式指定类型
//void doWork(Person<string, int> & p);
//2、参数模板化
//void doWork2(Person<T1, T2> & p);
//3、整体模板化
//void doWork3(T & p);

template<class NameType, class AgeType>
class Person {
public:
	Person(NameType name, AgeType age) {
		this->age_ = age;
		this->name_ = name;
	}
	void showPerson() {
		cout << "姓名：" << this->name_ << "  年龄：" << this->age_ << endl;
	}

	NameType name_;
	AgeType age_;
};

//1、指定传入类型
void doWork(Person<string, int> & p) {
	p.showPerson();
}

//2、参数模板化
template <class T1, class T2>
void doWork2(Person<T1, T2> & p) {
	p.showPerson();
}
//3、整体类型化
template <class T>
void doWork3(T & p) {
	p.showPerson();
}

void test01() {
	Person<string, int> p1("张三", 5);
	doWork(p1);

	doWork2(p1);

	doWork3(p1);
}

int main() {
	test01();
	return 0;
}

