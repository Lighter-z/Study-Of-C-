#include<iterator>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
copy算法  将容器中指定范围的元素拷贝到另一个容器中
param beg   容器开始迭代器
param end   容器结束迭代器
param dest  目标其实迭代器

replace(iterator beg, iterator end, olevalue, newvalue)
replace  算法  将容器中指定范围的旧元素修改为新元素
param beg  容器开始迭代器
param end  容器结束迭代器
param oldvalue  旧元素
param newvalue  新元素

replace_if(iterator beg, iterator end, _callback, newvalue)
replace_if  算法  将容器内指定范围内满足条件的元素换位新元素
param beg  容器开始迭代器
param end  容器结束迭代器
_callback  回调函数或者谓词（返回值为bool类型的函数对象）
param newvalue  新元素

swap(container c1, container c2)
swap  算法  互换两个容器的元素
param c1  容器1
param c2  容器2
*/
void test01() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	vector<int> v2;
	v2.resize(v.size());
	copy(v.begin(), v.end(), v2.begin());

	for_each(v2.begin(), v2.end(), [](int v) {cout << v << " "; });
	cout << endl;
}

class MyCompare {
public:
	bool operator()(int v) {
		return v > 5;
	}
};
void test02() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	//把容器中的3替换为100
	replace(v.begin(), v.end(), 3, 100);
     // ostream_iterator  头文件#include<iterator>
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//把容器中大于5的数替换为3000
	replace_if(v.begin(), v.end(), MyCompare(), 3000);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

void test03() {
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}

	v2.push_back(5);
	v2.push_back(51);
	v2.push_back(0);
	v2.push_back(6);

	swap(v1, v2);
	for_each(v1.begin(), v1.end(), [](int v) {cout << v << " "; });
	cout << endl;
	for_each(v2.begin(), v2.end(), [](int v) {cout << v << " "; });
	cout << endl;
}

int main() {
	//test01();
	//test02();
	test03();
	return 0;
}

