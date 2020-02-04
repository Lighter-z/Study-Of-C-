#include <iostream>
using namespace std;

//1.引用基本用法 Type &别名 = 原名
void test01(void) {
	int a = 10;
	int &b = a;  //引用初始化后不可修改
	b = 20;
	cout << "a " << a << endl;
	cout << "b " << b << endl;
}

//2.引用必须初始化
void test02() {
	//int &a;  //引用必须初始化 不初始化会报错
}

void test03(void) {
	int a = 10;
	int &b = a;  //引用初始化后不可修改
	b = 20;
	cout << "a " << a << endl;
	cout << "b " << b << endl;

	int c = 30;
	b = c;  //这叫赋值
}

//3.对数组建立引用
void test04(void) {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}

	//给数组起别名
	int(&ar)[10] = arr;
	for (int i = 0; i < 10; i++) {
		printf("ar[%d] = %d\r\n",i,ar[i]);
	}
}

int main(void) {
	test01();
	test04();
	return 0;
}