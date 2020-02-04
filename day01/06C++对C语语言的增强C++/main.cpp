#include <iostream>

using namespace std;

//1.全局变量检测增强
//出现a的重定义
//int a;
int a = 10;

//2.函数检测增强，参数类型检测增强，返回值增强
//会出现报错
#if 0
void getRect(w, h) {

}

void test02(void) {
	getRect(1, 2, 3);
}
#else
int getRect(int w, int h) {
	return w * h;
}

void test02(void) {
	getRect(1, 2);
}
#endif

//3.类型转换增强
void test03(void) {
	//char *p = malloc(sizeof(64));//malloc返回值是 void *类型
	char *p = (char *)malloc(sizeof(64));//malloc返回值是 void *类型
}

//4.struct增强
struct Person {
	int m_age;
	void addAge() { m_age++; };//c++语言中能在结构体中增加函数
};

void test04(void) {
	Person p; //可以不使用struct
	p.addAge();
}

//5.bool布尔类型 
bool flage = true;
void test05(void) {
	cout << sizeof(flage) << endl;

	flage = 200;  
	cout << flage << endl;  //布尔类型 非零值都是1
}

//6.三目运算符  \
//c++中返回的是变量
//c返回的是值
void test06(void) {
	int a = 10;
	int b = 20;

	cout << (a > b ? a : b) << endl;
	(a > b ? a : b) = 500;
	cout << a << endl;
	cout << b << endl;

}
//7.const增强   
const int a_07 = 10;
void test07(void) {
	//a_07 = 100;  //报错 不能修改
	cout << "const" << endl;
	const int b = 10; //真正常量     
	int m_b[b]; // 可以初始化数组

	//b = 100;//报错 不能修改

	//绕过编译器 通过指针可以修改  这种方法只能修改局部的
	int *p = (int *)&b;
	*p = 200;
	cout << "*p = " << *p << endl; //200
	cout << "b = " << b << endl;//10
}
int main(void) {
	test05();
	test06();
	test07();
	return 0;
}
