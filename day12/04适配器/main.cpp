#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//��һ���������� bind2nd
//�ڶ������̳���  binary_function<����1�� ����2�� ����ֵ����>
//���������� const���� operator()
class MyPrint :
	public binary_function<int,int,void>
{
public:
	void operator()(int v, int start) const {
		cout << v + start << endl;
	}
};
void test01(void) {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	cout << "Please write in start value" << endl;
	int num;
	cin >> num;
	for_each(v.begin(), v.end(), bind2nd(MyPrint(), num));
}

//ȡ��������
#if 0
class MyCompareFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};
void test02() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	vector<int> ::iterator pos = find_if(v.begin(), v.end(), MyCompareFive());
	if (pos != v.end()) {
		cout << "find > 5 value = " << *pos << endl;
	}
	else {
		cout << "not find" << endl;
	}
}
#else
//���������δ����Ϊ����С��5����
//�����º���
//unary_function<��������1�� ����ֵ����>
class MyCompareFive : public unary_function<int, bool>{
public:
	bool operator()(int val) const {
		return val > 5;
	}
};
//һԪȡ�������� not1
void test02() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//����һ���Լ�д�º���
	//vector<int> ::iterator pos = find_if(v.begin(), v.end(), not1(MyCompareFive()));
	//�������������ڽ���������
	vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));
	if (pos != v.end()) {
		cout << "find < 5 value = " << *pos << endl;
	}
	else {
		cout << "not find" << endl;
	}
}

#endif

//����ָ��������
void printCompare03(int value, int start) {
	cout << value + start << "  ";
}
void test03() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//������ָ������Ϊ��������
	//ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(printCompare03), 100));
}

//��Ա����������
class Person {
public:
	string name_;
	int age_;
	Person() {};
	Person(string name, int age) {
		this->name_ = name;
		this->age_ = age;
	}

	void showPerson() {
		cout << "Name = " << this->name_ << "  Age = " << this->age_ << endl;
	}

	void plusAge() {
		this->age_ += 100;
	}
};

void printPerson(Person & p) {
	cout << "Name = " << p.name_ << "  Age = " << p.age_ << endl;
}
void test04() {
	vector<Person>v;
	Person p1("ada", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//for_each(v.begin(), v.end(), printPerson);

	//��Ա����������
	//mem_fun_ref
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::plusAge));
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));

}

int main() {

	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}
