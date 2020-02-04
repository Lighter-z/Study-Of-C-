#include <iostream>
#include <string>
using namespace std;
//！！只要是分配内存的变量 都可以使用指针取地址的方式修改其数值

//1.const分配内存  取地址时候会分配临时内存
//2.const前加 extern  编译器也会给const分配内存
void test01(void) {
	const int m_a = 10;
	int *p = (int *)&m_a;//分配临时内存
}

//3.使用普通变量初始化const的变量 也会分配内存
void test02(void) {
	int a = 10;
	const int b = a;


	//！！只要是分配内存的变量 都可以使用指针取地址的方式修改其数值
	int *p = (int *)&a;
	*p = 1000;
	cout << "test02 *p = " << *p << endl; //1000
	cout << "test02 a = " << a << endl;  //1000

}

//4. 自定义数据类型  加const也会自动分配内存
struct Person {
	string m_name;
	int m_age;
};

void test03() {
	const Person p1;
	//p1.m_name = "aa"; //const 不能修改 报错

	Person *p = (Person *)&p1;
	p->m_name = "aa";
	(*p).m_age = 19;
	cout << "姓名" << p->m_age;
	cout << "年龄" << p->m_name;

}

int main(void) {
	test02();
	test03();
	/*cout << a << endl;*/
	return 0;
}
