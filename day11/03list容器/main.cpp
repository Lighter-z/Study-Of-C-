#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
//list是双向循环列表

/*
list  //构造函数
list<T> lisT;  //采用类模板实现 默认构造函数
list(begin,end);  //构造函数  将区间[begin, end]中的元素拷贝给本身
list(n, elem);  //构造函数  将n个elm拷贝给本身
list(const list & l);  //拷贝构造函数

list元素插入和删除操作
push_back(elem);  //在容器尾部插入一个元素
pop_back();  //删除容器中最后一个元素
push_front(elem);  //在容器头部插入一个元素
pop_front();  //删除容器开头第一个元素
insert(pos, elm);  //在 pos 位置 插入元素elm 返回新数据位置
insert(pos, n, elm);  //在 pos 位置插入 n 个元素elm  
insert(pos, beg, end);  //在 pos 位置 插入区间[begin, end]中的元素 无返回值
clear();  //移除容器中所有元素
erase(begin, end);  //删除区间[begin, end]中的元素 返回下一个数据的位置
erase(pos);  //删除 pos 位置的数据 返回下一个数据的位置
remove(elm);  //删除容器中所有与elm匹配的元素

list大小操作
size();  //返回容器中元素个数
empty();  //判断容器是否为空
resize(num);  //重新指定容器长度  若容器变长 则以默认值填充新位置  若容器变短 则超出末尾部分删除
resize(num, elm);//重新指定容器长度  若容器变长 则以elm填充新位置  若容器变短 则超出末尾部分删除

list赋值操作
assign(beg, end);  //将区间[begin, end]中的元素拷贝赋值给本身
assign(n, elm);  //将n个elm拷贝赋值给本身
list & operator=(const list & lst);  //重载等号运算符
swap(lst);  //将lst元素与本身交换

list数据的存取
front();  //返回第一个元素
back();  //返回最后一个元素

反转排序
reverse();  //反转链表 比如 list 包含 1 2 3元素 运行此方法后 list就包含 3  2  1元素
sort();  //list排序
*/

//验证list是否为循环链表
void test01(void) {
	list<int> myList;
	for (int i = 0; i < 10; i++) {
		myList.push_back(i);
	}
	
	list<int>::_Nodeptr node = myList._Myhead()->_Next;//节点指向 头节点的下一个节点  （头节点是不访问数据的）
	
	for (int i = 0; i < myList._Mysize() * 2; i++) {
		cout << "Node：" << node->_Myval << endl;
		node = node->_Next;
		if (node == myList._Myhead()) {   //循环列表  又从尾部指向了头部  
			node = node->_Next;
		}
	}
}

//正序打印
void printList(list<int> & l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;
}

//逆序打印
void printRightList(list<int> & l) {
	for (list<int>::reverse_iterator rit = l.rbegin(); rit != l.rend(); rit++) {
		cout << (*rit) << " ";
	}
	cout << endl;
}

//list API
void test02(void) {
	list<int> l1(10, 20);
	list<int> l2(l1.begin(), l1.end());
	printList(l2);

	list<int>l3(l2);
	printList(l3);

	l3.push_back(10);
	printList(l3);
	l3.push_front(50);
	printList(l3);
	l3.pop_back();
	printList(l3);
	l3.pop_front();
	printList(l3);

	l3.insert(l3.begin(), 9);
	printList(l3);

	l3.insert(l3.begin(), 5, 89);
	printList(l3);

	l3.erase(l3.begin());
	printList(l3);

	l3.remove(20);
	printList(l3);
	printRightList(l3);
}

bool myCompare(int v1, int v2) {
	return v1 > v2;
}

void test03(void) {
	list<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.push_back(i);
	}
	printList(l1);

	list<int> l2(l1);
	printList(l2);

	list<int> l3;
	l3 = l2;
	printList(l3);

	cout << "l1 size = " << l1.size() << endl;

	l2.resize(20);
	printList(l2);

	l2.assign(l3.begin(), l3.end());
	printList(l2);
	l2.push_back(90);

	l2.swap(l3);
	printList(l2);
	printList(l3);

	cout << "l3 header = " << l3.front() << "  l3 end = " << l3.back() << endl;

	if (l3.empty()) {
		cout << " l3 is empty " << endl;
	}
	else {
		cout << " l3 is not empty " << endl;
	}

	//反转链表
	l3.reverse();
	printList(l3);
	l3.push_back(100);
	printList(l3);

	//sort(l3.begin(), l3.end());  //报错  所有不支持随机访问的迭代器都不能使用这个 系统提供的方法
	//但是 这个类内部会提供
	l3.sort();  //从小到大排序
	printList(l3);  

	l3.sort(myCompare);  //从大到小排序
	printList(l3);

}

//从大到小排序

class Person {
public:
	string name_;
	int age_;
	Person() {};
	Person(string name, int age) {
		this->name_ = name;
		this->age_ = age;
	}

	//重载 == 让 remove 可以删除自定义数据类型
	bool operator==(const Person & p) {
		if ((this->name_ == p.name_) && (this->age_ == p.age_)) {
			return true;
		}
		return false;
	}
};

//sort 回调函数
bool myComparePerson(Person & p1, Person & p2) {
	if (p1.age_ > p2.age_) {
		return true;
	}
	else {
		return false;
	}
}
void printPerson(list<Person> & lp) {
	for (list<Person>::iterator pit = lp.begin(); pit != lp.end(); pit++) {
		cout << "名字：" << (*pit).name_ << "  年龄：" << (*pit).age_ << endl;
	}
}

void test04() {
	list<Person> lp;

	Person p1("张三", 50);
	Person p2("李四", 90);
	Person p3("王五", 58);
	Person p4("张麻子", 30);
	Person p5("老刘", 20);

	lp.push_back(p1);
	lp.push_back(p2);
	lp.push_back(p3);
	lp.push_back(p4);
	lp.push_back(p5);

	lp.sort(myComparePerson);
	printPerson(lp);

	lp.remove(p5);
	printPerson(lp);

}

int main() {
	//test01();
	//test02();
	//test03();
	test04();
	return EXIT_SUCCESS;
}



