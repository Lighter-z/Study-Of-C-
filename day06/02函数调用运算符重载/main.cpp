#include <iostream>
#include <string>

//��Ҫ���� &&  ||
using namespace std;

class MyPrint {
public:
	void operator()(string text) {
		cout << "hello world" << endl;
		cout << text << endl;
	}
};

void test01(void) {
	MyPrint myPrint;
	myPrint("sss");   //�º���
}

class MyAdd {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};

void test02(void) {
	MyAdd myAdd;
	cout << myAdd(1, 2) << endl;
}

int main(void) {
	test01();
	test02();
	return 0;
}
