#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

/*
merge�㷨  ����Ԫ�غϲ� ���洢����һ��������  �������������붼������� ��������˳��Ҳ����ͬ
ʹ��mergeҪ��Ŀ����������洢�ռ䣡��������
param beg1  ����1��ʼ������
param end1  ����1����������
param beg2  ����2��ʼ������
param end2  ����2����������
param dest  Ŀ��������ʼ������

sort�㷨  ����Ԫ������
param beg  ������ʼ������
param end  ��������������
param _callback  �ص���������ν�ʣ�����ֵΪbool�ĺ�������

random_shuffle(iterator beg, iterator end)    ϴ��  ��˳������

reverse(iterator beg, iterator end)  ��ת˳��
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

	//��С����
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int v) {cout << v << " "; });
	cout << endl;
	//�Ӵ�С
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
