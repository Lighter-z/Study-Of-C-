#include <iostream>
#include <string>
#include "Person.hpp"
using namespace std;

//模板不要做分文件编写  全部写在 .hpp文件中

void test01() {
	Person<string, int> p1("张三", 5);
	p1.ShowPerson();
}

int main() {
	test01();
	return 0;
}

