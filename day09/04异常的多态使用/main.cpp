#include <iostream>
//�쳣�Ķ�̬ʹ��
using namespace std;

//�쳣����
class BaseException {
public:
	virtual void printError() {}
};

class NullPointerExpection :public BaseException {
public:
	virtual void printError(void) {
		cout << "��ָ���쳣" << endl;
	}
};

class OutofRangeExpection:public BaseException {
public:
	virtual void printError(void) {
		cout << "Խ���쳣" << endl;
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
