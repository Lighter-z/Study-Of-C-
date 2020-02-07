#include <iostream>
#include <string>

//如果普通函数和模板函数一样  会优先调用普通函数
using namespace std;

//让编译器看到 Person声明
template<class T1, class T2>class Person;

//让编译器看到 Show 声明
template<class T1, class T2>void Show(Person<T1, T2> & p);

template<class T1, class T2>
class Person {

	friend void Show<>(Person<T1, T2> & p);

	//友元函数类内实现  利用空参数列表 告诉编译器  模板函数声明
	//friend void Show<>(Person<T1, T2> & p);     //普通函数声明    还是报错


	//friend void Show(Person<T1, T2> & p)     //普通函数声明
	//{
	//	cout << "名字：" << p.name_ << p.age_ << "岁" << endl;
	//}
public:
	Person(T1 a, T2 b) {
		this->age_ = b;
		this->name_ = a;
	}
private:
	T1 name_;
	T2 age_;
};

template<class T1, class T2>
void Show(Person<T1, T2> & p)
{
	cout << "名字：" << p.name_ << p.age_ << "岁" << endl;
}

void test01() {
	Person<string, int> p1("张三", 5);

	Show(p1);
}

int main() {
	test01();
	return 0;
}

