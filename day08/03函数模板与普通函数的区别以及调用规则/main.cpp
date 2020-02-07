#include <iostream>

using namespace std;

//1、普通函数与函数模板的区别
template<class T>
T myPlus(T a, T b) {
	return a + b;
}

int myPlus2(int a, int b) {
	return a + b;
}

void test01() {
	int a = 10;
	int b = 20;
	char c = 'c';

	//myPlus(a,c);   //报错 类型推到不出来
	myPlus2(a, c);    //不报错   ASIII码   c = 99   （可以进行隐式类型转换）

	cout << myPlus(a, b) << endl;

	cout << myPlus2(a, b) << endl;
	cout << myPlus2(a, c) << endl;
}

//2、普通函数与函数模板的调用规则
template<class T>
void myPrint(T a, T b) {
	cout << "函数模板调用的myPrint" << endl;
}
template<class T>
void myPrint(T a, T b, T c) {
	cout << "a,b,c函数模板调用的myPrint" << endl;
}

void myPrint(int a, int b) {           //重名 不报错  参数不同，发生函数重载
	cout << "普通函数调用的myPrint" << endl;
}

void test02(void) {
	int a = 10;
	int b = 20;
	int c = 3;
	//1、调用普通函数myPrint   因为 出现重载   （与普通函数类型一致时）优先调用普通函数！！！
	myPrint(a, b);
	//2、强制使用模板
	myPrint<>(a, b);   
	//3、函数模板之间发生重载
	myPrint<>(a, b, c);
	//4、如果函数模板可以产生更好的匹配，会优先调用函数模板
	char d = 'e';
	char e = 'd';
	myPrint(d,e);  // 结果：函数模板调用的myPrint  应为普通函数还要进行  隐式转换  所以优先调用函数模板
}

int main() {
	test01();
	test02();   
	return 0;
}
