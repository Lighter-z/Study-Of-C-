#include <iostream>
#include <string>
using namespace std;

//c++封装  严格的类型转换检测   让行为和属性绑定在一起
//属性和行为作为一个整体来表示生活中的事物
//控制权限 public protected private

typedef struct {
	char name[64];
	int age;

	void PeopleEat() {
		cout << name << "吃人饭" << endl;
	}

}Person;

void test01() {
	Person p;
	strcpy(p.name, "张三");
	p.PeopleEat();
}

//struct 与 class 是一个意思  唯一不同 struct默认权限是 public  而  class 默认权限是private
/*
public 类内类外都可以访问
protected 类内可以访问 类外不可以访问 子类可以访问
private 类内可以访问 类外不可以访问  子类不可以访问
*/
class Animal {
	//如果不声明权限 默认使private
};

int main() {
	test01();
	return 0;
}
