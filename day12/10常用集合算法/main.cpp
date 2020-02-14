#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

/*
set_intersection(interator beg1, interator end1, interator beg2, interator end2, interator dest) 算法 求两个set集合的交集
set_union(interator beg1, interator end1, interator beg2, interator end2, interator dest)  求两个集合的并集
set_difference(interator beg1, interator end1, interator beg2, interator end2, interator dest)  求两个集合的差集
beg1  容器1开始迭代器
end1  容器2结束迭代器
beg2  容器2开始迭代器
end2  容器2结束迭代器
dest  目标容器开始迭代器
返回值  集合的最后一个值
*/

void test01(void) {
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> vTarget;
	vTarget.resize(min(v1.size(), v2.size()));

	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));    //5 6 7 8 9
	//copy(vTarget.begin(), vTarget.end(), ostream_iterator<int>(cout, " "));  //5 6 7 8 9 0 0 0 0 0
	//因为容器结尾不同  所以打印结果不同   
	//因为在创建时候创建的大  实际得到的集合并没有那么大  所以按原来的vTarget.end()  会打印出来默认值
	//itEnd    是只集合的最后一个值
}

void test02() {
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> vTarget;
	vTarget.resize(v1.size()+ v2.size());

	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));    //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
}

void test03() {
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> vTarget;
	vTarget.resize(max(v1.size(), v2.size()));

	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));    //0 1 2 3 4
}

int main() {

	//test01();
//	test02();
	test03();
	return 0;
}
