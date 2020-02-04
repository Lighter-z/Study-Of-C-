#include <iostream>
#include <string>

using namespace std;

//一个类默认创建  默认构造函数  析构函数  拷贝构造函数  operator=赋值运算符:进行简单的值传递
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
		//判断原来堆区已经有内容  先释放
		if (this->pName != NULL) {
			delete[] this->pName;
			this->pName = NULL;
		}
		//标准变了    c12
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
	Person2 p1("张三");
	Person2 p2("李四");
	p2 = p1;
	cout << p1.pName << endl;
	cout << p2.pName << endl;


}

int main(void) {
	test0();
	test02();
	return 0;
}
