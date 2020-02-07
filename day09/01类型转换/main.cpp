#include <iostream>
/*
1、静态转换  static_cast<目标对象类型>(原始对象)

2、动态转换  dynamic_cast<目标对象类型>(原始对象)
	2.1、非常严格    失去精度或者不安全都不允许转换
	2.2、基类转换为派生类  不安全 不允许转换  当出现多态时，允许转换

3、常量转换  const_cast<目标对象类型>(原始对象)
	3.1、不能对 非指针 或者 非引用 的变量进行转换

4、重新解释转换 reinterpret_cast   最不安全（用的少  基本用不到）
*/

using namespace std;

//static_cast<目标对象>(原始对象)

//-------------------------------静态转换-------------------------------
//基础类型
void test01(void) {
	char a = 'a';
	double d = static_cast<double>(a);
	cout << d << endl;
}

class Base {};
class Child :public Base {};
class Other {};

void test02(void) {
	Base * b = NULL;
	Child * c = NULL;
	//把 Base 转为 Child 向下转 不安全
	Child * c2 = static_cast<Child *>(b);

	//把 Child 转为 Base 向上转 安全
	Base * b1 = static_cast<Base *>(c);

	//转other    转换无效
	//Other * o = static_cast<Other *>(b);    //报错
}

class Base2 {};
class Child2 :public Base2 {};
class Other2 {};

//-------------------------------动态转换-------------------------------
void test03(void) {
	char c = 'c';
	//报错  基础类型不可以转换
	//dynamic_cast 非常严格    失去精度或者不安全都不允许转换
	//double d = dynamic_cast<double>(c);

	Base2 * b = NULL;
	Child2 * c2 = NULL;
	//把 Child2 转为 Base2 向上转 安全
	Base2 * b2 = dynamic_cast<Base2 *>(c2);

	//把 Base2 转为 Child2 向下转 不安全
	//Child * c3 = dynamic_cast<Child *>(b);
}
//dynamic_cast 如果发生了多态 可以由基类转换为派生类（向下转换）
class Base3 {
public:
	virtual void func(void) {}
};
class Child3 :public Base3 {
public:
	virtual void func(void) {}
};
class Other3 {};

void test04() {
	Base3 * base3 = new Child3;
	
	//发生多态 可以由 基类转换为派生类
	Child * c3 = dynamic_cast<Child *>(base3);
}

//-------------------------------常量转换-------------------------------
void test05(void) {
	//---------------指针---------------
	const int *p = NULL;
	//取出const
	int * s = const_cast<int *>(p);

	int * p2 = NULL;
	//加上const
	const int * s2 = const_cast<const int *>(p2);

	//不能对 非指针 或者 非引用的变量进行转换
	int p3 = 10;
	//报错
	//const int s3 = const_cast<const int>(p3);

	//---------------引用---------------
	int num1 = 10;
	int & numRef1 = num1;
	const int & cnum1 = const_cast<const int &>(numRef1);

	int & cnum2 = const_cast<int &>(cnum1);
}

//-------------------------------重新解释转换-------------------------------

void test06(void) {
	int a = 10;
	int *p = reinterpret_cast<int *>(a);

	Base * base = NULL;
	Other * o = NULL;
	Base * b1 = reinterpret_cast<Base *>(o);

}

int main(void) {
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	return 0;
}
