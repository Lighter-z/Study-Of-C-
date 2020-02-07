#include <iostream>
#include <string>

#include "MyArray.hpp"

using namespace std;

class Person {
public:
	string name_;
	int age_;
	Person() {}
	Person(int age, string name) {
		this->name_ = name;
		this->age_ = age;
	}
};


void PrintArray(MyArray<int> & ma) {
	for (int i = 0; i < ma.GetSize(); i++) {
		cout << ma[i] << endl;
	}
}

void PrintPersonArray(MyArray<Person> & ma) {
	for (int i = 0; i < ma.GetSize(); i++) {
		cout << ma[i].name_ << "  " << ma[i].age_ << endl;
	}
}

void test01() {
	MyArray<int> ma(10);

	for (int i = 0; i < 10; i++) {
		ma.PushBack(i);
	}
	MyArray<int> ma2(ma);

	PrintArray(ma);
	PrintArray(ma2);

	Person p1(10, "M5");
	Person p2(7, "M2");
	Person p3(8, "M3");
	Person p4(9, "M4");

	MyArray<Person> ma3(10);
	ma3.PushBack(p1);
	ma3.PushBack(p2);
	ma3.PushBack(p3);
	ma3.PushBack(p4);
	PrintPersonArray(ma3);
}

int main() {
	test01();
	return 0;
}

