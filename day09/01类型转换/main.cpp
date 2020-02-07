#include <iostream>

using namespace std;

//static_cast<目标对象>(原始对象)

//静态转换
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

	//把 Child 转为 Base 向下转 安全
	Base * b1 = static_cast<Base *>(c);

	//转other    转换无效
	//Other * o = static_cast<Other *>(b);    //报错
}

int main(void) {
	test01();
	return 0;
}
