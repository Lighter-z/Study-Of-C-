#include <iostream>

using namespace std;

class Person{
public:
	Person() {
		cout << "默认构造函数" << endl;
	}
	Person(int a) {
		cout << "默认构造函数" << endl;
	}
	~Person() {
		cout << "默认析构函数" << endl;
	}
};

void test0() {
	//Person p;  //在栈上创建    函数结束就释放了
	Person *p1 = new Person;  //在堆区创建  函数结束也不会释放
	//所有new出来的对象 都会返回该类型指针
	//malloc 返回 void * 类型    还要强转
	//malloc不会调用构造函数    new会调用
	//new是运算符   malloc是函数

	//释放空间
	//delete 也是运算符  配合 new使用   malloc配合free使用
	delete p1; 
}

void test02() {
	void * p = new Person;
	//当使用void * 时，会出现释放的问题
	delete p;   //无法释放
}

void test03() {
	//在堆上 ：通过new开辟数组   一定会调用默认构造函数  一定要提供
	Person *p = new Person[10];

	//释放数组时候 要加[]
	delete[]p;

	//在堆上：  如果没有无参构造函数  可以指定有参构造函数
	Person p2[2] = {Person(1),Person(2)};
}

int main() {
	
	test0();
	return 0;
}
