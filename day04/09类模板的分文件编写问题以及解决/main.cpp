#include <iostream>
//ʹ��Person.h ����ֱ��� �����޷��������ⲿ����
//#include "Person.h"


//#include "Person.cpp"  
//����취  ���� .h
//���� ���.hpp�ļ�  Person.cpp �ļ���ȫ��ɾ��


#include "Person.hpp" 
//����ģ�岻Ҫ�����ļ���д

using namespace std;

void test01() {
	Person<string, int> p("����",5);
	p.showPerson();
}

int main() {

	test01();
	return 0;
}
