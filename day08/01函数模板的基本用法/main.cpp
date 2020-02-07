#include <iostream>

using namespace std;

void Swap1(int & a, int & b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//泛型编程  类型参数化
template<class T> //告诉编译器 下面如果出现 T  不要报错，T是一个通用类型
//template<class T>   等价于  template<typename T>
void Swap2(T & a, T & b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 10;
	int b = 20;
	Swap1(a, b);
	cout << a << endl << b << endl;

	a = 30;
	b = 40;
	//自动类型推导   必须有参数类型才可以推导
	Swap2(a, b);
	//2.显示指定类型
	Swap2<int>(a,b);
	cout << a << endl << b << endl;

	double c = 2.3;
	double d = 4.6;
	Swap2(a, b);
	cout << a << endl << b << endl;
}

int main() {
	test01();
	return 0;
}
