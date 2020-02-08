#include <iostream>
/*
myException e  会多开销一份数据 调用拷贝构造
myException *e ，会提前释放对象   使用new的话  需要自己管理delete
myException &e   推荐使用引用   就一份数据 也不需要管理数据
*/

using namespace std;

class myException {
public:
	myException() {
		cout << "myException 默认构造函数" << endl;
	}
	myException(const myException & e) {
		cout << "myException 拷贝构造函数" << endl;
	}
	~myException()
	{
		cout << "myException 析构函数" << endl;
	}
};

void doWork() {
	throw myException();
}

void test01(void) {
	try {
		doWork();
	}
	//catch (myException e) {//这种写法会多开销一份数据    会调用拷贝构造
	catch (myException &e) {//这种写法会多开销一份数据      推荐用 引用
		cout << "捕获异常" << endl;
	}
}

int main(void) {
	test01();
	return 0;
}
