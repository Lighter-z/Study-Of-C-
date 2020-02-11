#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

/*
deque构造函数
deque<T> deqT;  //默认构造函数
deque(beg, end);  //构造函数将[beg, end]区间中的元素拷贝给本身
deque(n, elem);  //构造函数将n个elem拷贝给本身
deque(const deque & e);  //拷贝构造函数

deque赋值操作
assign(beg, end);  //将[beg, end]区间中的元素赋值给本身
assign(n, elem);  //将n个elem赋值给本身
deque& operqtor=(const deque & e);  //重载等号操作符
swap(deq);  //将deq元素与本身交换

deque大小操作
deque.size();  //返回容器中元素个数
deque.empty();  //判断容器是否为空
deque.resize(num);  //重新指定容器长度为num，若容器变长，则以默认值填充新位置。 若容器变短，则末尾超出容器长度元素被删除
deque.resize(num, elem);  //重新指定容器长度为num，若容器变长，则以elem填充新位置，若容器变短，则末尾超出容器长度的元素被删除
*/

void printDeque(const deque<int> & d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01(void) {
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	printDeque(d1);

	deque<int> d2(d1.begin(), d1.end());
	d2.push_back(100);
	d2.push_front(200);
	printDeque(d2);

	d1.swap(d2);
	printDeque(d1);
	printDeque(d2);

	cout << d1.size() << endl;
	d2.resize(10);
	printDeque(d2);
}

void test02(void) {
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	printDeque(d1);

	d1.pop_back();
	printDeque(d1);

	d1.pop_front();
	printDeque(d1);

	deque<int> d2(d1);
	printDeque(d2);

	cout << d2[2] << endl;
	cout << d2.back() << endl;
	cout << d2.front() << endl;

	d2.insert(d2.begin(), d1.begin(), d1.end());
	printDeque(d2);

	d2.erase(d2.begin());
	printDeque(d2);

}

//排序规则
bool myCompare(int v1, int v2) {
	return v1 > v2;
}

//排序
void test03() {
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(50);
	d1.push_back(52);
	d1.push_back(0);

	//从小到大
	sort(d1.begin(), d1.end());
	printDeque(d1);

	//从大到小
	//仿函数是协助算法改变他的策略
	sort(d1.begin(), d1.end(), myCompare);
	printDeque(d1);
}

/*
初始化四名选手，去除最高最低分计算平均值
*/
class Person {
public:
	string name_;
	int grade_;
	int score_;
	Person() {}
	Person(string name, int grade) {
		this->name_ = name;
		this->grade_ = grade;
		this->score_ = 0;
	}
};

void printPerson(Person & p) {
	cout << "名字：" << p.name_ << " "<< "成绩：" << p.grade_ << endl;
}

void test04() {
	int grade = 0;

	Person p1("张三", 10);
	Person p2("李四", 30);
	Person p3("王五", 20);
	Person p4("老王", 100);
	vector<Person> v1;
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	
	for_each(v1.begin(), v1.end(), printPerson);
	
	cout << "--------deuqe--------" << endl;
	deque<int> d1;
	for (int i = 0; i < v1.size(); i++) {
		d1.push_back(v1[i].grade_);
	}

	printDeque(d1);
	cout << "--------排序--------" << endl;
	sort(d1.begin(), d1.end());
	printDeque(d1);

	cout << "--------去除最大最小值--------" << endl;
	d1.pop_back();
	d1.pop_front();
	printDeque(d1);

	for (int i = 0; i < d1.size(); i++) {
		grade += d1[i];
	}
	p1.score_ = grade / d1.size();
	cout << "平均分："<< p1.score_ << endl;

}

int main() {
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}
