#include <iostream>
#include <string>
//系统提供标准异常文件
#include <stdexcept>
using namespace std;

class Person {
public:
	string name_;
	int age_;
	Person(string name, int age) {
		this->name_ = name;
		if (age < 0 || age > 200) {
			throw out_of_range("年龄越界");
		}
		this->age_ = age;
	}
};

void test01(void) {
	try {
		Person p("张三", 300);
	}
	catch (out_of_range & ofr) {
		cout << ofr.what() << endl;
	}
}

int main(void) {
	test01();
	return 0;
}
