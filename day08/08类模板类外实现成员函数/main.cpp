#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
class Person {
public:
	Person(T1 a, T2 b);
	void ShowPerson(void);
	T1 name_;
	T2 age_;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 a, T2 b) {
	this->name_ = a;
	this->age_ = b;
}

template<class T1, class T2>
void Person<T1, T2>::ShowPerson(void){
	cout << "Ãû×Ö£º" << this->name_ << this->age_ << "Ëê" << endl;
}

void test01() {
	Person<string, int> p1("ÕÅÈý", 4);
	p1.ShowPerson();
}

int main() {
	test01();
	return 0;
}

