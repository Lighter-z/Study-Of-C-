#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

/*
set_intersection(interator beg1, interator end1, interator beg2, interator end2, interator dest) �㷨 ������set���ϵĽ���
set_union(interator beg1, interator end1, interator beg2, interator end2, interator dest)  ���������ϵĲ���
set_difference(interator beg1, interator end1, interator beg2, interator end2, interator dest)  ���������ϵĲ
beg1  ����1��ʼ������
end1  ����2����������
beg2  ����2��ʼ������
end2  ����2����������
dest  Ŀ��������ʼ������
����ֵ  ���ϵ����һ��ֵ
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
	//��Ϊ������β��ͬ  ���Դ�ӡ�����ͬ   
	//��Ϊ�ڴ���ʱ�򴴽��Ĵ�  ʵ�ʵõ��ļ��ϲ�û����ô��  ���԰�ԭ����vTarget.end()  ���ӡ����Ĭ��ֵ
	//itEnd    ��ֻ���ϵ����һ��ֵ
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
