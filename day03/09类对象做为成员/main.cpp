#include <iostream>
#include "People.h"

using namespace std;

//类对象作为成员时候，构造顺序先将类对象一一构造 然后构造自己  析构的顺序相反
void test01() {
	People p("张三","三星","王者");
	//p.m_phone.m_name = "三星";
	//p.m_game.m_name = "王者";
	p.playGame();
}

int main() {
	test01();
	return 0;
}
