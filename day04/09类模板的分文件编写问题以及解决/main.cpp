#include <iostream>
//#include "Person.h"
#include "Person.cpp"  
//解决办法  屏蔽 .h
//或者 添加.hpp文件  Person.cpp 文件中全部删除


//#include "Person.hpp" 
//建议模板不要做分文件编写

using namespace std;

void test01() {
	Person<string, int> p("张三",5);
	p.showPerson();
}

int main() {

	test01();
	return 0;
}
