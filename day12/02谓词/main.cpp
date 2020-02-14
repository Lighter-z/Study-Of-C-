#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//一元谓词
class GreaterThen20 {
public:
	bool operator()(int value) {
		return value > 20;
	}
};

void test01(void) {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	//第三个参数  函数参数   可以传回调函数  也可以传仿函数
	//传仿函数  要传一个对象进去
	//1、传对象进去
	//GreaterThen20 GreaterThen;
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen);
	//2、传匿名对象进去
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen20());
	if (pos != v.end()) {
		cout << "find > 20 num is : " << *pos << endl;
	}
	else {
		cout << "not find" << endl;
	}
}

//二元谓词
class MyCompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void test02() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	sort(v.begin(), v.end(), MyCompare());

	//匿名函数  lambda表达式[](){}
	for_each(v.begin(), v.end(), [](int value) {cout << value << " "; });
}

int main() {

	test01();
	test02();
	return 0;
}
