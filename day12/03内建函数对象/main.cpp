#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//内建函数对象头文件
#include <functional>
using namespace std;

//举几个例子

//template<class T> T plus<T>加法仿函数
//template<class T> T negate<T> 取反仿函数
void test01(void) {
	plus<int> p;
	cout << p(1, 1) << endl;

	negate<int> n;
	cout << n(2) << endl;
}

//template<class T> bool greater<T  大于
void test02(void) {
	vector<int> v;
	v.push_back(40);
	v.push_back(10);
	v.push_back(80);
	v.push_back(0);

	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int value) {cout << value << " "; });
}

int main() {

	test01();
	test02();
	return 0;
}
