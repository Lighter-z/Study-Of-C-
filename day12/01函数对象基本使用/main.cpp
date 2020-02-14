#include <iostream>
#include <string>
//仿函数

using namespace std;

class myPrint {
public:
	void operator()(int num) {
		cout << num << endl;
		count++;
	}
	int count = 0;
};

void myPrint2(int num) {
	cout << num << endl;
}

void test01(void) {
	myPrint myPrint1;
	myPrint1(111);  //仿函数调用
	myPrint2(222);  //函数调用
	myPrint()(5000);  //匿名对象调用
}

//函数对象超出普通函数的概念  内部可以保存状态
void test02() {
	myPrint myPrint1;
	myPrint1(111);  //仿函数调用
	myPrint1(111);  //仿函数调用
	myPrint1(111);  //仿函数调用
	myPrint1(111);  //仿函数调用

	cout << "myPrint调用次数：" << myPrint1.count << endl;
}

void doWork(myPrint print, int num) {
	print(num);
}

void test03() { 
	doWork(myPrint(), 6);  //直接传入匿名函数
}

int main() {

	test01();
	test02();
	test03();
	return EXIT_SUCCESS;
}
