#include <iostream>

using namespace std;

class Person {
public:
	int m_a;
	int m_b;
	int m_c;
	/*Person(){}*/
	//�вι����ʼ������
	//Person(int a,int b,int c) {
	//	m_a = a;
	//	m_b = b;
	//	m_c = c;
	//}

	Person() : m_a(10), m_b(20), m_c(30) {}
	//���ó�ʼ���б��ʼ������
	Person(int a, int b, int c) : m_a(a), m_b(b), m_c(c) {
	
	}

};

void test01() {

}

int main() {
	test01();
	return 0;
}

