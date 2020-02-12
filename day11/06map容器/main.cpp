#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
map赋值操作
map & operator=(const map & mp);  //重载等号运算符
swap(mp);  //交换两个容器

map大小操作
size();  //返回容器中元素的个数
empty();  //判断容器是否为空

map插入数据
map.insert(elem);  //往容器中插入元素  返回值：pair<iterator, iterator>

//例子：
map<int, int> map;
map.insert(pair<int, int>(1, 5));
map.insert(make_pair(2,2));
map.insert(map<int, int>::value_type(3, 3));
map[4] = 4;

map删除操作
clear();  //清空容器
erase(pos);  //删除pos迭代器所指的元素，返回下一个元素的迭代器
erase(beg, end);  //删除区间[beg, end]中的元素，返回下一个元素的迭代器
erase(keyElem);  //删除容器中key = keyElm的对组

map查找操作
find(key);  //查找键key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回map.end()
count(keyElm);  //返回容器中key为keyElem的对组个数。对map来说，要么是0 要么是1   对multimap来说 值可能大于1
lower_bound(keyElm);  //返回第一个Key>=keyElm元素的迭代器
upper_bound(keyElm);  //返回第一个Key>keyElm元素的迭代器
equal_range(keyElm);  //返回容器中key与keyElm相等的上下限的两个迭代器
//
*/

void printMap(map<int, int> & m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "Key = " << it->first << "  Value = " << it->second << endl;
	}
}

void findMap(map<int, int> & m, int key) {
	map<int, int>::iterator pos = m.find(key);
	if (pos != m.end()) {
		cout << "find  key = " << pos->first << "  value = " << pos->second << endl;
	}
	else {
		cout << "not find!" << endl;
	}
}

void test01(void) {
	//自动按照key值从小到大排序
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(make_pair(2, 20));
	m1.insert(map<int, int>::value_type(3, 30));
	m1[4] = 0;
	printMap(m1);

	cout << "m1 size = " << m1.size() << endl;
	
	findMap(m1, 1);

	map<int, int>::iterator ret = m1.lower_bound(3);
	if (ret != m1.end()) {
		cout << "lower_bound  find   key = " << ret->first << "  value = " << ret->second << endl;
	}
	else {
		cout << "not find" << endl;
	}

	map<int, int>::iterator ret1 = m1.upper_bound(3);
	if (ret1 != m1.end()) {
		cout << "upper_bound  find   key = " << ret1->first << "  value = " << ret1->second << endl;
	}
	else {
		cout << "not find" << endl;
	}

	pair<map<int, int>::iterator, map<int, int>::iterator> ret2 = m1.equal_range(3);
	if (ret2.first != m1.end()) {
		cout << "equal_rang  find first  key = " << ret2.first->first << "  value = " << ret2.first->second << endl;
	}
	else {
		cout << "equal_rang not find" << endl;
	}

	if (ret2.second != m1.end()) {
		cout << "equal_rang  find  second  key = " << ret2.second->first << "  value = " << ret2.second->second << endl;
	}
	else {
		cout << "equal_rang not find" << endl;
	}
}

//排序
//从大到小排序
class myCompareMap {
public:
	bool operator()(int v1, int v2) const {
		return v1 > v2;
	}
};

void printMapMyCompare(map<int, int, myCompareMap> & m) {
	for (map<int, int, myCompareMap>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "Key = " << it->first << "  Value = " << it->second << endl;
	}
}

void test02() {
	map<int, int, myCompareMap> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(make_pair(2, 20));
	m1[3] = 30;
	printMapMyCompare(m1);
}

int main() {
	//test01();
	test02();
	return 0;
}
