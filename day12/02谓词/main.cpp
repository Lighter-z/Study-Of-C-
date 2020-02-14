#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//һԪν��
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

	//����������  ��������   ���Դ��ص�����  Ҳ���Դ��º���
	//���º���  Ҫ��һ�������ȥ
	//1���������ȥ
	//GreaterThen20 GreaterThen;
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen);
	//2�������������ȥ
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen20());
	if (pos != v.end()) {
		cout << "find > 20 num is : " << *pos << endl;
	}
	else {
		cout << "not find" << endl;
	}
}

//��Ԫν��
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

	//��������  lambda���ʽ[](){}
	for_each(v.begin(), v.end(), [](int value) {cout << value << " "; });
}

int main() {

	test01();
	test02();
	return 0;
}
