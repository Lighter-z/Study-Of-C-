#include <iostream>
#include <string>

using namespace std;

class myOutOfRangeException :public exception {
public:
	string error_;
	myOutOfRangeException(string error) {
		this->error_ = error;
	}
	virtual ~myOutOfRangeException() noexcept
	{
	
	}

	virtual char const* what() const
	{
		//string 转 char *
		return this->error_.c_str();
	}
};

class Person {
public:
	string name_;
	int age_;
	Person(string name, int age) {
		this->name_ = name;
		if (age < 0 || age > 200) {
			throw myOutOfRangeException("年龄大了");
		}
		this->age_ = age;
	}
};

void test01(void) {
	try {
		Person p("张三", 300);
	}
	catch (myOutOfRangeException e) {
		cout << e.what() << endl;
	}
}

int main(void) {
	test01();
	return 0;
}
