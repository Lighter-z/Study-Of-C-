#include <iostream>
#include <string>

using namespace std;

template<class T1, class T2>
class Person {
public:
	T1 name_;
	T2 age_;
	Person(T1 a, T2 b) {
		this->name_ = a;
		this->age_ = b;
	}
	void ShowPerson(void);
};

template<class T1, class T2>
void Person<T1, T2>::ShowPerson(void) {
	cout << "Ãû×Ö£º" << this->name_ << this->age_ << "Ëê" << endl;
}


