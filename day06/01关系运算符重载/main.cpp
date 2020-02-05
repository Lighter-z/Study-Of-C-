#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	string name;
	int age;
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}

	bool operator==(Person & p) {
		if (this->age == p.age && this->name == p.name) {
			return true;
		}
		return false;
	}

	bool operator!=(Person & p) {
		if (this->age != p.age || this->name != p.name) {
			return true;
		}
		return false;
	}
};

void test01(void) {
	Person p1("张三",15);
	Person p2("张三",15);
	Person p3("张4",15);

	if (p1 == p2) {
		cout << "相等" << endl;
	}
	if (p1 != p3) {
		cout << "不相等" << endl;
	}
}

int main(void) {
	test01();
	return 0;
}
