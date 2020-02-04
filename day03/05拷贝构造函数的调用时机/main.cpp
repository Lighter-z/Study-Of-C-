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

	int age;
};

//1.用已经创造好的对象来初始化新的对象
void test01() {
	Person p1;
	p1.age = 10;
	Person p2(p1);
}

//2.以值传递的方式给函数参数传值
void doWork(Person p) {   //Person p = Person(p1)

}
void test02() {
	Person p1;
	p1.age = 10;
	doWork(p1);
}

//3.以值的方式返回局部对象
Person doWork2() {
	Person p1;
	p1.age = 10;
	return p1;
}
void test03() {
	Person p = doWork2();
}

//release 下优化成什么样？
/*
Person p  不调用默认构造
doWork2()优化为如下：
void doWork2(Person & p){
	Person p1;
	p1.age = 10;
}
	
*/

int main() {
	test03();
	return 0;
}

