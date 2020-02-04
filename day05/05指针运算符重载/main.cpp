#include <iostream>
using namespace std;

class Person {
public:
	Person() {}
	Person(int age) : m_age(age) {
		
	}
	void showAge() {
		cout << "年龄：" << this->m_age << endl;
	}
	~Person() {
		cout << "析构函数" << endl;
	}
	int m_age;

};

//智能指针
//用来托管自定义类型的对象，让对象进行自动的释放
//作用：
//例如 Person p = new Person(10);
//忘记手动 delete p1 时候，  靠智能指针删除
class smartPointer {
public:
	smartPointer(Person * person) {
		this->person = person;
	}
	//重载->让智能指针对象 像 Person *p一样去使用
	Person * operator->() {
		return this->person;
	}

	Person & operator*() {
		return *this->person;
	}

	~smartPointer() {
		if (this->person != NULL) {
			delete this->person;
			this->person = NULL;
		}
	}
private:
	Person * person;
};

//class p {
//public:
//	p(Person *p) {
//		this->pe = p;
//	}
//	~p() {
//		if (this->pe != NULL) {
//			delete this->pe;
//			this->pe = NULL;
//		}
//	}
//private:
//	Person * pe;
//};

void test01() {
	//Person p1(10);
	//p1.showAge();

	smartPointer sp(new Person(10));   //开辟到栈上  
	sp->showAge();
	(*sp).showAge();
}

int main() {
	test01();
	return 0;
}
