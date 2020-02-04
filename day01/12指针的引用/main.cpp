#include <iostream>

using namespace std;

struct Person {
	int m_age;
};

void mallocMemory(Person **p) {
	*p = (Person *)malloc(sizeof(Person));
	(*p)->m_age = 100;
}

void test01(void) {
	Person *p = NULL;
	mallocMemory(&p);
	//p->m_age = 10;   //�д�
	cout << "Person->m_age = " << p->m_age << endl;

}

//��������ָ�뿪�ٿռ�
void allocatMerryByRef(Person* &p) {
	p = (Person *)malloc(sizeof(Person));
	p->m_age = 200;
}
void test02(void) {
	Person *p = NULL;
	allocatMerryByRef(p);
	//p->m_age = 10;   //�д�
	cout << "Person->m_age = " << p->m_age << endl;

}

int main() {
	test01();
	test02();
	return 0;
}
