#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//�ڽ���������ͷ�ļ�
#include <functional>
using namespace std;

//�ټ�������

//template<class T> T plus<T>�ӷ��º���
//template<class T> T negate<T> ȡ���º���
void test01(void) {
	plus<int> p;
	cout << p(1, 1) << endl;

	negate<int> n;
	cout << n(2) << endl;
}

//template<class T> bool greater<T  ����
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
