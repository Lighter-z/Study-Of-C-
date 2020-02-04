#include <iostream>

using namespace std;

class Person {
	int a;
	void func() {};
	static int b;
	static void func1() {};
	double c;  //占8个字节
};

void test01() {
	cout << "空类 Person 大小" << sizeof(Person) << endl;
	//空类大小为1  每个实例对象都有独一无二的地址,char维护这个地址
	//加上 int a;  大小为4
	//加上 void func() {};  还是 4          不属于对象身上
	//加上 static int b;  还是4              不属于对象身上
	//加上 static void func1()  还是4         不属于对象身上

	//所以 只有非静态成员变量才属于对象身上

	//加上 double c;  大小为16    应为字节对齐

}

int main() {
	test01();
	return 0;
}
