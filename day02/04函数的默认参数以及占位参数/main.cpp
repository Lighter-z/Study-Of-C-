#include <iostream>

using namespace std;

//如果函数有一个位置有了默认参数，则从这个位置开始从左往后开始所有位置都要有默认参数

//函数声明时候如果有默认参数，那么函数实现时候必须没有
void func(int a = 10, int b = 20) {
	cout << a << "-----" << b << endl;
}
void test01() {
	func();
	func(20);
	func(20, 30);

}

//函数占位参数
//如果有了占位参数，函数调用时侯必须提供这个参数，但是用不到这个参数
//占位参数 没有什么用  只有重载 ++符号才有用
void func2(int a, int) {

}
void test02() {
	func2(1,0);
}

int main() {
	test01();
	return 0;
}
