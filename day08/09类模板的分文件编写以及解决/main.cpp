#include <iostream>
#include <string>
#include "Person.hpp"
using namespace std;

//ģ�岻Ҫ�����ļ���д  ȫ��д�� .hpp�ļ���

void test01() {
	Person<string, int> p1("����", 5);
	p1.ShowPerson();
}

int main() {
	test01();
	return 0;
}

