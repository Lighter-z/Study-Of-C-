#include <iostream>

using namespace std;
//函数重载
//1.必须在同一个作用域，函数名相同
//2.函数的参数 个数 或者 类型 或者 顺序不同

void func() {
	cout << "无参数" << endl;
}
void func(int a) {
	cout << "int 参数" << a << endl;
}

void func(double a) {
	cout << "double 参数" << a << endl;
}

//函数返回值类型不同   不能作为函数重载 会报错
//int func() {  
//	
//}

void test01() {
	func();
	func(1);
	func(1.2);
}

//当函数重载 碰到 默认参数 时候注意避免二义性
void func2(int a,int b = 10) {

}

void func2(int a) {
	
}

void test02() {
//	func2(10);  //报错
}

//引用重载
void func3(int &a) {

	cout << "---" << endl;
}

void func3(const int &a) {
	cout << "const" << endl;
}

void test03() {
	int a = 3;
	func3(a);
	func3(10);
}

int main() {
	test01();
	test03();
	return 0;
}
