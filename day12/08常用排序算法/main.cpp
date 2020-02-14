#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

/*
merge算法  容器元素合并 并存储到另一个容器中  这两个容器必须都是有序的 并且排列顺序也是相同
使用merge要给目标容器分配存储空间！！！！！
param beg1  容器1开始迭代器
param end1  容器1结束迭代器
param beg2  容器2开始迭代器
param end2  容器2结束迭代器
param dest  目标容器开始迭代器

sort算法  容器元素排序
param beg  容器开始迭代器
param end  容器结束迭代器
param _callback  回调函数或者谓词（返回值为bool的函数对象）

random_shuffle(iterator beg, iterator end)    洗牌  把顺序整乱

reverse(iterator beg, iterator end)  翻转顺序
*/

void test01(void) {
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	
	vector<int> vTrage;
	vTrage.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTrage.begin());

	for_each(vTrage.begin(), vTrage.end(), [](int v) {cout << v << endl; });
}

void test02() {
	vector<int> v;
	v.push_back(50);
	v.push_back(40);
	v.push_back(0);
	v.push_back(90);

	//从小到大
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int v) {cout << v << " "; });
	cout << endl;
	//从大到小
	sort(v.begin(), v.end(), greater<int>());
	for_each(v.begin(), v.end(), [](int v) {cout << v << " "; });
	cout << endl;
}

void test03() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int v) {cout << v << " "; });
	cout << endl;
}

void test04() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int v) {cout << v << " "; });
	cout << endl;
}

int main() {

	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}
