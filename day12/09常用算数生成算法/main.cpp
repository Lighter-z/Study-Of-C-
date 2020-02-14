#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

/*
accumulate(iterator beg, iterator end, value)
accumulate  算法  计算容器元素累计总和
param beg  容器开始迭代器
param end  容器结束迭代器
param value  起始累加值

fill(iterator beg, iterator end, value)
fill  算法  向容器中添加元素    (区间内元素变为填充值)
param beg  容器开始迭代器
param end  容器结束迭代器
param value  填充元素
*/

void test01(void) {
	vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}
	int sum = 0;
	//头文件 #include <numeric>
	sum = accumulate(v.begin(), v.end(), 100);
	cout << sum << endl;  //5150 = 5050 + 100

}

void test02(void) {
	vector<int> v;
	for (int i = 0; i <= 10; i++) {
		v.push_back(i);
	}
	
	fill(v.begin(), v.end(), 90);
	for_each(v.begin(), v.end(), [](int value) {cout << value << endl; });  //全为10

}

int main() {

	//test01();
	test02();
	return 0;
}
