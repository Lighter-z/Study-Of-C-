#include <iostream>

using namespace std;

//1.值传递
void swap(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//2.地址传递
void MySwap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void test02() {
	int a = 1;
	int b = 2;

	MySwap(&a, &b);
	cout << "a" << a << endl;
	cout << "b" << b << endl;
}

//引用传递
void MySwap2(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void test03() {
	int a = 1;
	int b = 2;

	MySwap2(a, b);
	cout << "a" << a << endl;
	cout << "b" << b << endl;
}

//引用注意事项
//1.引用必须引用一块合法的内存空间
void test04() {
	//int &a = 10;//引用必须引用一块合法的内存空间，，这里10没有内存空间，所以报错

	//引用的本质就是指针常量
	int a = 10;
	int &ref = a; //自动转换为int *const ref = &a;          这就说明了为什么引用必须初始化（指针常量必须初始化，并且不能修改）
	ref = 20;//内部发现ref是引用  自动帮我们转换为 *ref = 20;
}

//2.不要返回局部变量的引用
int &getNum() {
	int a = 10;
	return a;

}

void test05() {
	
	int &a = getNum();//局部变量生命周期在函数结束时候就没了
	cout << "1局部变量引用a = " << a << endl;  //第一次打印，编译器做了优化 所以还是10，多次打印数据就变了
	cout << "2局部变量引用a = " << a << endl;
	cout << "3局部变量引用a = " << a << endl;
	cout << "4局部变量引用a = " << a << endl;
	cout << "5局部变量引用a = " << a << endl;
}
//使用static保存
int &getNum06() {
	static int a = 10;
	return a;

}

void test06() {

	int &a = getNum06();
	cout << "1局部变量引用a = " << a << endl; 
	cout << "2局部变量引用a = " << a << endl;
	cout << "3局部变量引用a = " << a << endl;
	cout << "4局部变量引用a = " << a << endl;
	cout << "5局部变量引用a = " << a << endl;
}

//如果函数返回的数值是引用，那么这个函数调用可以作为左值
void test07() {
	int &ret = getNum06();
	getNum06() = 100;  //相当于写了a = 100

}

int main() {
	
	//test03();
	//test05();
	test06();
	return 0;
}

