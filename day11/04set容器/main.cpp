#include <iostream>
#include <string>
//set multiset头文件
#include <set>
using namespace std;

/*
set是关联式容器
插入数据自动排序  根据key值

key值 =  数据值  （key = value）   
key数值不能重复

set构造容器
set<T> st;  //set默认构造函数
mulitset<T> mst;  //Mulitset 默认构造函数
set(const set & st);  //拷贝构造函数

set 与 mulitset 区别：
set 不可以插入相同的值
mulitset 可以插入相同的值

赋值操作
set & operator=(const set & st);  ///重载等号运算符
swap(st);  //交换两个集合容器

set大小操作
size();  //返回容器元素个数
empty(); //判断容器是否为空

set插入和删除操作
insert(elm);  //在容器中插入元素  set插入返回值是 对组 <迭代器， 插入是否成功返回值>
clear();  //清除所有元素
erase(pos);  //删除pos迭代器所指向的元素  返回下一个元素的迭代器
erase(beg, end);  //删除区间[beg, end]中的元素  返回下一个元素的迭代器
erase(elem);  //删除容器中值为elem的元素

set查找操作
find(key);  //查找键 key是否存在 若存在，返回该键的元素的迭代器；若不存在，返回set.end()
count(key);  //查找键key的元素个数  //针对set来说 返回值只有0 或者 1  因为 set中 不允许key重复
lower_bound(keyElem);  //返回第一个key>=keyElem元素的迭代器
ipper_boumd(keyElem);  //返回第一个key>keyElm元素的迭代器
equal_range(keyElem);  //返回容器中key与keyElem相等的上下限的两个迭代器
*/

void printSet(set<int> s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01(void) {
	//关联式容器  会自动排序
	set<int> s1;
	s1.insert(50);
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	printSet(s1);  //从小到大排序  10  20  30  40  50
	cout << "s1 size = " << s1.size() << endl;

	s1.erase(40);
	printSet(s1);

	s1.erase(s1.begin());
	printSet(s1);

}

void printMultiset(multiset<int> & m) {
	for (multiset<int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test02() {
	multiset<int> m;

	//可以插入相同的值
	m.insert(40);
	m.insert(10);
	m.insert(20);
	m.insert(30);
	m.insert(30);
	
	printMultiset(m);  //自动排序  从小到大
}

void test03(void) {
	set<int> s1;
	s1.insert(50);
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);

	//对于set  没有value  key就是value
	set<int>::iterator pos = s1.find(20);
	if (pos != s1.end()) {
		cout << "找到了 数值为 " << *pos << endl;
	}
	else{
		cout << "没有找到" << endl;
	}

	//count(key)  //查找键 key的个数 对于set而言 结果是 0  或者 1（因为 set中 key值不能重复）
	cout << "10的个数 = " << s1.count(10) << endl;

	set<int>::iterator it1 = s1.lower_bound(20);
	if (it1 != s1.end()) {
		cout << "找到了 数值为 " << *it1 << endl;
	}
	else {
		cout << "没有找到" << endl;
	}

	set<int>::iterator it2 = s1.upper_bound(20);
	if (it2 != s1.end()) {
		cout << "找到了 数值为 " << *it2 << endl;
	}
	else {
		cout << "没有找到" << endl;
	}

	//equal_range(keyElem) 返回容器中key与keyElem相等的上下限的两个迭代器
	//上下限就是lower_bound   upper_bound
	pair<set<int>::iterator, set<int>::iterator> it3 = s1.equal_range(20);
	//获取第一个数值
	if (it3.first != s1.end()) {
		cout << "找到 第一个 equal_range 值：" << *(it3.first) << endl;
	}
	else {
		cout << "没有找到" << endl;
	}
	//获取第二个数值
	if (it3.second != s1.end()) {
		cout << "找到 第一个 equal_range 值：" << *(it3.second) << endl;
	}
	else {
		cout << "没有找到" << endl;
	}

}

//set插入返回值是 对组 <迭代器， 插入是否成功返回值>
void test04(void) {
	set<int> s;
	
	pair<set<int>::iterator, bool> ip = s.insert(10);
	if (ip.second == true) {
		cout << "first insert success" << endl;
	}
	else {
		cout << "first insert fail" << endl;
	}

	ip = s.insert(10);
	if (ip.second == true) {
		cout << "second insert success" << endl;
	}
	else {
		cout << "second insert fail" << endl;
	}
}

//仿函数
class myCompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void printSetCompare(set<int, myCompare> s) {
	for (set<int, myCompare>::iterator it = s.begin(); it != s.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;
}

//排序
void test05(void) {
	//从小到大排序
	set<int>s1;
	s1.insert(1);
	s1.insert(7);
	s1.insert(5);
	s1.insert(3);
	printSet(s1);

	//插入前指定好排序规则
	//从大到小
	set<int, myCompare>s2;
	s2.insert(1);
	s2.insert(7);
	s2.insert(5);
	s2.insert(3);
	printSetCompare(s2);

}

class Person {
public:
	int age_;
	string name_;
	Person(string name, int age) {
		this->name_ = name;
		this->age_ = age;
	}
};

class PersonConmare {
public:
	bool operator()(const Person & p1, const Person & p2) {
		if (p1.age_ >= p2.age_) {  //降序
			return true;
		}
		else {
			return false;
		}
	}
};

void printPerson(set<Person, PersonConmare> s) {
	for (set<Person, PersonConmare>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "姓名：" << it->name_ << "  年龄：" << it->age_ << endl;
	}
}

void test06() {
	Person p1("大娃", 100);
	Person p2("二娃", 50);
	Person p3("三娃", 10);
	Person p4("爷爷", 1000);

	//自定义数据类型 才插入之前需要指定好规则
	set<Person, PersonConmare> s;
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	printPerson(s);
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}
