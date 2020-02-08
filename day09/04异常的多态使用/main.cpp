#include <iostream>
//异常的多态使用
using namespace std;

//异常基类
class BaseException {
public:
	virtual void printError() {}
};

class NullPointerExpection :public BaseException {
public:
	virtual void printError(void) {
		cout << "空指针异常" << endl;
	}
};

class OutofRangeExpection:public BaseException {
public:
	virtual void printError(void) {
		cout << "越界异常" << endl;
	}

};

void doWork1() {
	throw NullPointerExpection();
}

void doWork2() {
	throw OutofRangeExpection();
}

void test01(void) {
	try {
		doWork1();
	}
	catch(BaseException &be){
		be.printError();
	}
	try {
		doWork2();
	}
	catch(BaseException &be){
	be.printError();
	}
}

int main(void) {
	test01();
	return 0;
}
