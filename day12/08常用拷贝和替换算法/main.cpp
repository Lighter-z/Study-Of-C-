#include<iterator>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
copy�㷨  ��������ָ����Χ��Ԫ�ؿ�������һ��������
param beg   ������ʼ������
param end   ��������������
param dest  Ŀ����ʵ������

replace(iterator beg, iterator end, olevalue, newvalue)
replace  �㷨  ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
param beg  ������ʼ������
param end  ��������������
param oldvalue  ��Ԫ��
param newvalue  ��Ԫ��

replace_if(iterator beg, iterator end, _callback, newvalue)
replace_if  �㷨  ��������ָ����Χ������������Ԫ�ػ�λ��Ԫ��
param beg  ������ʼ������
param end  ��������������
_callback  �ص���������ν�ʣ�����ֵΪbool���͵ĺ�������
param newvalue  ��Ԫ��

swap(container c1, container c2)
swap  �㷨  ��������������Ԫ��
param c1  ����1
param c2  ����2
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

	//�������е�3�滻Ϊ100
	replace(v.begin(), v.end(), 3, 100);
     // ostream_iterator  ͷ�ļ�#include<iterator>
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//�������д���5�����滻Ϊ3000
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

