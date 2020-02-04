#include <iostream>
#include "game1.h"
#include "game2.h"

using namespace std;
//1.命名空间可以放置函数、变量、结构体
//2.命名空间必须定义在全局作用域下
//3.命名空间可以嵌套命名空间
namespace A {
	
	class Person {};
	struct Book {};

	namespace B {
		int a = 10;
	}

}

void test01(void) {
	cout << "命名空间A下的B中的变量a = " << A::B::a << endl;
}

//4.命名空间是开放的，可以随时往原来的命名空间中添加内容
namespace A { //此命名空间会和上面的A命名空间合并
	int b = 55;
}

void test02(void) {
	cout << "命名空间A新加的变量b = " << A::b << endl;
}

//5.无名，匿名  命名空间
//此时相当于 static int m_c = 99;
//只能在当前文件中使用
namespace {
	
	int m_c = 99;
}

void test03(void) {
	cout << "无名 命名空间中的变量m_c = " << ::m_c << endl;
	cout << "第二种显示方式 无名 命名空间中的变量m_c = " << m_c << endl;
}

//6.命名空间可以取别名
namespace veryLongName {
	int v_a = 44;
}

void test04(void) {
	namespace veryShortName = veryLongName;

	cout << "命名空间别名 v_a = " << veryShortName::v_a << endl;
}

int main(void) {
	
	LOL::showAtk();
	KingGlory::showAtk();
	test01();
	test02();
	test03();
	test04();
	return 0;
}
