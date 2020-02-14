#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

/*
find算法  查找元素
param beg  容器开始迭代器
param end  容器结束迭代器
param value  查找的元素
return  返回查找元素的位置

find_if(iterator beg, iterator end, _callback)
find_if  算法 条件查找
param beg  容器开始迭代器
param end  容器结束迭代器
param _callback  回调函数  或者 谓词（返回值为bool的函数对象）
return bool  查找返回true  或者  false

adjacent_find(iterator beg, iterator end, _callback)
param beg  容器开始迭代器
param end  容器结束迭代器
param _callback  回调函数  或者 谓词（返回值为bool的函数对象）
return  返回相邻元素的第一个位置的迭代器

bool binary_search(iterator beg, iterator end, value)  
binary_search   二分法查找    注意：无序序列中不可用!!!
param beg  容器开始迭代器
param end  容器结束迭代器
param value  查找的元素
return bool  查找返回true  或者  false

count  统计元素出现次数
param beg  容器开始迭代器
param end  容器结束迭代器
param value  统计的元素
return int  返回元素个数

count_if    按条件统计元素个数
param beg  容器开始迭代器
param end  容器结束迭代器
param _callback  回调函数或者谓词（返回bool类型的函数对象） 
return int  返回元素个数

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

//find自定义数据类型
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

	for_each(v.begin(), v.end(), [](Person & p) {cout << "姓名：" << p.name_ << " 年龄 = " << p.age_ << endl; });

	vector<Person>::iterator pos = find(v.begin(), v.end(), p1);
	if (pos != v.end()) {
		cout << "姓名：" << pos->name_ << " 年龄 = " << pos->age_ << endl;
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
		cout << "姓名：" << (*pos)->name_ << " 年龄 = " << (*pos)->age_ << endl;
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
		cout << "find first 相邻 重复 value = " << *pos << endl;
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

	cout << binary_search(v.begin(), v.end(), 1);    //返回true  或者  false
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

	cout << "1 出现次数 = " << count(v.begin(), v.end(), 1) << endl;

	cout << "大于2的数字个数 = " << count_if(v.begin(), v.end(), MyCompare());

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
