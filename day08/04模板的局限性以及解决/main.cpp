#include <iostream>
#include <string>
using namespace std;
//模板不能解决所有类型
//如果出现不能解决的类型，通过第三代具体化来解决问题
//语法：template<> 返回值 函数名<具体类型>(参数)

class Person {
public:
	string name_;
	int age_;
	Person() {}
	Person(int age, string name) {
		this->name_ = name;
		this->age_ = age;
	}
};

//不能进行类的判断
template<class T>
bool myCompare(T & a, T & b) {
	if (a == b) {
		return true;
	}
	return false;
}

//通过 第三代具体化 自定义数据类型解决上述问题
template<>bool myCompare<Person>(Person & a, Person & b) {
	if (a.age_ == b.age_ && a.name_ == b.name_) {
		return true;
	}
	return false;
}

void test01() {
	bool result;
	int a = 10;
	int b = 20;
	result = myCompare(a, b);

	//通过具体化 自定义数据类型解决上述问题
	Person p1(4, "张三");
	Person p2(4, "张三");
	result = myCompare(p1, p2);


	cout << result << endl;

}

int main() {
	test01();
	return 0;
}

