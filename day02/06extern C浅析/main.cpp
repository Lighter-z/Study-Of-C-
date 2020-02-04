#include <iostream>
using namespace std;

//C++中想调用c语言方法
//方法一   不用加头文件
//extern "C" void show();

//方法二 在c语言中去处理
//在 test.h中
#include "test.h"


void test01() {
	show();  //在C++中是有函数重载的  编译器会把这个函数名偷偷变为 _show()
}

int main() {
	test01();
	return 0;
}
