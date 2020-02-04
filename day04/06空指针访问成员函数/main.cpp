#include <iostream>

using namespace std;


class Person {
public:
	void show() {
		cout << "Person Show" << endl;
	}
	void ageShow() {
		if (this == NULL) {   //避免传入空指针
			return;
		}
		cout << m_age << endl;
	}
	int m_age;
};

void test01() {
	Person *p = NULL;
	p->show();  //成功
	p->ageShow();  //不加 this == NULL 判断的话  会报错
	/*
	void show() 中会隐藏加上 Person *this   
	应为show没有用到对象中变量 所以不报错
	ageShow中用到了  传进去的是一个空指针  所以报错
	所以函数要加上判断
	if (this == NULL) {   //避免传入空指针
			return;
		}

	*/

}

int main() {
	test01();
	return 0;
}
