//д��Ԫ����Ŀ��  ��������˽������

#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
class Person {
	friend void Show(Person<T1, T2> & p) {
		cout << "���֣�" << p.name_ << p.age_ << "��" << endl;
	}
public:
	Person(T1 a, T2 b) {
		this->age_ = b;
		this->name_ = a;
	}
private:
	T1 name_;
	T2 age_;
};

void test01() {
	Person<string, int> p1("����", 5);
	
	Show(p1);
}

int main() {
	test01();
	return 0;
}


