#include <iostream>

using namespace std;

//分类
//按照参数分类  无参构造函数（默认构造函数）  有参构造函数
//按照类型分类  普通构造函数    拷贝构造函数

class Person {
public:       //构造函数与析构函数必须在public下
	Person() { 
		cout << "默认构造函数--普通构造函数" << endl;
	}

	Person(int a) {
		age = a;
		cout << "有参构造函数--普通构造函数 age = " << age << endl;
	}
	//拷贝构造函数
	Person(const Person& p) {
		age = p.age;
		cout << "拷贝构造函数 age = " << age << endl;
	}

	~Person() {
		cout << "默认析构函数" << endl;
	}
private:
	int age;
};

void test01() {
	//括号法调用
	/*
	Person p1;
	Person p2(1);
	Person p3(p2);
	*/

	//显示法调用
	Person p4 = Person(100);
	Person p5 = Person(p4);
	/*
	Person(100)  //匿名对象  特点：如果编译器发现对象是匿名的 那么在这行代码结束后就释放这个对象
	Person p4 = Person(100)   //把匿名对象给 p4
	*/

	Person p6 = 200;//相当于 Person p6 = Person(200);   隐式类型转换
	Person p7 = p6; //  同理
}

int main() {
	test01();
	return 0;
}

