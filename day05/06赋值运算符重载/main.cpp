#include <iostream>
#include <string>

using namespace std;

//һ����Ĭ�ϴ���  Ĭ�Ϲ��캯��  ��������  �������캯��  operator=��ֵ�����:���м򵥵�ֵ����
class Person {
public:
	int m_A;
	Person(int a) {
		this->m_A = a;
	}

};

void test0(void) {
	Person p1(10);
	Person p2(10);

	p2 = p1;
	cout << "p2.m_A = " << p2.m_A << endl;
}

class Person2 {
public:
	char *pName;
	Person2(char * name) {

		this->pName = new char[strlen(name) + 1];
		strcpy(this->pName, name);
	}

	Person2 & operator= (Person2 & p) {
	/*void operator= (const Person2 & p) {*/
		//�ж�ԭ�������Ѿ�������  ���ͷ�
		if (this->pName != NULL) {
			delete[] this->pName;
			this->pName = NULL;
		}
		//��׼����    c12
		this->pName = new char[strlen(p.pName) + 1];
		strcpy(this->pName, p.pName);

		return *this;
	}

	~Person2()
	{
		if (this->pName != NULL) {
			delete[] this->pName;
			this->pName = NULL;
		}
	}

};

void test02(void) {
	Person2 p1("����");
	Person2 p2("����");
	p2 = p1;
	cout << p1.pName << endl;
	cout << p2.pName << endl;


}

int main(void) {
	test0();
	test02();
	return 0;
}
