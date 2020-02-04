#include <iostream>

using namespace std;

//定义一个加法
// 宏缺陷：
//1.定义没有作用域 
//2.总要加小括号避免出错
#define MyAdd(x,y) x+y

void test01() {
	//int ret = MyAdd(10, 20)  //20
	int ret = MyAdd(10,20) * 20;  //410   10 + 20 * 20     可以这样子 #define MyAdd(x,y) ((x) + (y))
	cout << ret << endl;
}
//1.内联函数声明
inline void func();//内联函数声明
inline void func() {}
//2.类内部的成员函数 编译器默认加上 inline

int main() {
	test01();
	return 0;
}
