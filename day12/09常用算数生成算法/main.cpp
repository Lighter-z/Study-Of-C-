#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

/*
accumulate(iterator beg, iterator end, value)
accumulate  �㷨  ��������Ԫ���ۼ��ܺ�
param beg  ������ʼ������
param end  ��������������
param value  ��ʼ�ۼ�ֵ

fill(iterator beg, iterator end, value)
fill  �㷨  �����������Ԫ��    (������Ԫ�ر�Ϊ���ֵ)
param beg  ������ʼ������
param end  ��������������
param value  ���Ԫ��
*/

void test01(void) {
	vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}
	int sum = 0;
	//ͷ�ļ� #include <numeric>
	sum = accumulate(v.begin(), v.end(), 100);
	cout << sum << endl;  //5150 = 5050 + 100

}

void test02(void) {
	vector<int> v;
	for (int i = 0; i <= 10; i++) {
		v.push_back(i);
	}
	
	fill(v.begin(), v.end(), 90);
	for_each(v.begin(), v.end(), [](int value) {cout << value << endl; });  //ȫΪ10

}

int main() {

	//test01();
	test02();
	return 0;
}
