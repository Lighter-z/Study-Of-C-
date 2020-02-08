#include <iostream>
//栈解旋 ：
//从 try开始 到 throw 抛出异常之前   所有栈上的对象都会被释放！！！
using namespace std;

//自定义异常
class myException {
public:
	void printError(void) {
		cout << "自定义异常" << endl;
	}
};

class Person {
public:
	Person() {
		cout << "构造函数" << endl;
	}
	~Person()
	{
		cout << "析构函数" << endl;
	}
};

int Devide(int a, int b) {
	if (b == 0) {
		//throw - 1;  //抛出int类型异常
		//throw 3.14;    //double类型异常
		//throw 'a';    //char 类型异常

		//栈解旋 ：
		//从 try开始 到 throw 抛出异常之前   所有栈上的对象都会被释放！！！
		//p1 与 p2 的构造与析构顺序相反   先构造p1  先析构p2
		Person p1;
		Person p2;

		throw myException();  // 自定义异常       myException()是匿名函数
	}
	return a / b;
}

void test01(void) {
	int a = 10;
	int b = 0;
	try {
		cout << Devide(a, b) << endl;
	}
	catch (int) {
		cout << "int类型捕获异常" << endl;
	}
	catch (double) {
		//如果不想处理这个异常 可以继续向上抛出  使用throw
		throw;
		cout << "double类型捕获异常" << endl;
	}
	catch (myException e) {
		e.printError();
	}
	catch (...) {
		cout << "其他类型捕获异常" << endl;
	}
}

//异常接口声明 在visual stduio下做不出测试
//QT 或者 Linux下可以
void testFunc1() throw() {    //不抛出任何异常
	//throw 1;   //可以正常运行 所以 visual stduio 做不出测试
}
void testFunc2() throw(int) {    //只能抛出int异常
	//throw 3.314;     //可以正常运行 所以 visual stduio 做不出测试
	throw 1;
}


void test02() {
	try {
		testFunc2();
	}
	catch (int) {
		cout << "test02 int 异常" << endl;
	}
	catch (...) {
		cout << "test02 其他 异常" << endl;
	}
}

int main(void) {
	try {
		test01();
	}
	catch (double) {  //如果异常都没有处理  那么成员terminate函数使程序中断
		cout << "main double类型捕获异常" << endl;
	}
	test02();
	return 0;
}
