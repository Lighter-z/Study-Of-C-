#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

/*
find�㷨  ����Ԫ��
param beg  ������ʼ������
param end  ��������������
param value  ���ҵ�Ԫ��
return  ���ز���Ԫ�ص�λ��

find_if(iterator beg, iterator end, _callback)
find_if  �㷨 ��������
param beg  ������ʼ������
param end  ��������������
param _callback  �ص�����  ���� ν�ʣ�����ֵΪbool�ĺ�������
return bool  ���ҷ���true  ����  false

adjacent_find(iterator beg, iterator end, _callback)
param beg  ������ʼ������
param end  ��������������
param _callback  �ص�����  ���� ν�ʣ�����ֵΪbool�ĺ�������
return  ��������Ԫ�صĵ�һ��λ�õĵ�����

bool binary_search(iterator beg, iterator end, value)  
binary_search   ���ַ�����    ע�⣺���������в�����!!!
param beg  ������ʼ������
param end  ��������������
param value  ���ҵ�Ԫ��
return bool  ���ҷ���true  ����  false

count  ͳ��Ԫ�س��ִ���
param beg  ������ʼ������
param end  ��������������
param value  ͳ�Ƶ�Ԫ��
return int  ����Ԫ�ظ���

count_if    ������ͳ��Ԫ�ظ���
param beg  ������ʼ������
param end  ��������������
param _callback  �ص���������ν�ʣ�����bool���͵ĺ������� 
return int  ����Ԫ�ظ���

*/

void test01(void) {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end()) {
		cout << "Not find " << endl;
	}
	else {
		cout << "Find num is = " << *it << endl;
	}
}

//find�Զ�����������
class Person {
public:
	Person() {}
	Person(string name, int age) {
		this->name_ = name;
		this->age_ = age;
	}
	bool operator==(const Person & p) {
		if (this->name_ == p.name_ && this->age_ == p.age_) {
			return true;
		}
		return false;
	}
	string name_;
	int age_;
};

void test02() {
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 30);
	Person p3("ccc", 20);
	Person p4("ddd", 50);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	for_each(v.begin(), v.end(), [](Person & p) {cout << "������" << p.name_ << " ���� = " << p.age_ << endl; });

	vector<Person>::iterator pos = find(v.begin(), v.end(), p1);
	if (pos != v.end()) {
		cout << "������" << pos->name_ << " ���� = " << pos->age_ << endl;
	}
	else {
		cout << "Not Find!!!" << endl;
	}
}

class MyCompare03 :public binary_function<Person *, Person *, bool> {
public:
	bool operator()(Person *p1, Person *p2) const {
		if (p1->name_ == p2->name_ && p1->age_ == p2->age_) {
			return true;
		}
		return false;
	}
};

void test03(void) {
	vector<Person *> v;
	Person p1("aaa", 10);
	Person p2("bbb", 30);
	Person p3("ccc", 20);
	Person p4("ddd", 50);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	//vector<Person *>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyCompare03(), &p1));
	Person *p = new Person("aaa", 10);
	vector<Person *>::iterator pos = find_if(v.begin(), v.end(), bind2nd(MyCompare03(), p));
	if (pos != v.end()) {
		cout << "������" << (*pos)->name_ << " ���� = " << (*pos)->age_ << endl;
	}
	else {
		cout << "Not Find!!!" << endl;
	}
}

void test04() {
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);
	v.push_back(6);
	v.push_back(2);

	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos != v.end()) {
		cout << "find first ���� �ظ� value = " << *pos << endl;
	}
	else {
		cout << "Not find" << endl;
	}
}

void test05() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	cout << binary_search(v.begin(), v.end(), 1);    //����true  ����  false
}

class MyCompare {
public:
	bool operator()(int v) {
		return v > 2;
	}
};
void tesst06() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);

	cout << "1 ���ִ��� = " << count(v.begin(), v.end(), 1) << endl;

	cout << "����2�����ָ��� = " << count_if(v.begin(), v.end(), MyCompare());

}

int main() {

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	tesst06();
	return 0;
}
