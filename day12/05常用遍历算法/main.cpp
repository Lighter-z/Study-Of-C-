#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
/*
for_each(iterator beg, iterator end, _callback);
�����㷨  ��������Ԫ��
param beg  ��ʼ������
param end  ����������
param _callback  �����ص��������ߺ�������
return ��������
*/

/*
transform�㷨 ��ָ����������Ԫ�ذ��˵���һ������
ע�⣺��������
transform�����Ŀ�����������ڴ棬��Ҫ�Լ����ٿռ�
param beg1  ԭ������ʼ������
param end1  ԭ��������������
param beg2  Ŀ��������ʼ������
param _callback  �ص��������ߺ�������
return ����Ŀ������������
*/

void myPring01(int v) {
	cout << v << " ";
}

//class �� struct���� classĬ��ʹ˽��  structĬ���ǹ���

class MyPrint01 {
public:
	void operator()(int v) {
		cout << v << " ";
	}
};

struct MyStructPrint01 {
	void operator()(int v) {
		cout << v << " ";
	}
};

void test01(void) {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//for_each(v.begin(), v.end(), myPring01);
	//for_each(v.begin(), v.end(), MyPrint01());
	for_each(v.begin(), v.end(), MyStructPrint01());

}
//for_each()�����ڲ���¼
struct MyStructPrint02 {
	void operator()(int v) {
		cout << v << " ";
		count++;
	}
	int count = 0;
};

void test02(void) {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	
	MyStructPrint02 print2 = for_each(v.begin(), v.end(), MyStructPrint02());
	cout << endl;
	cout << "count = " << print2.count << endl;
}

//for_each()�󶨲������
struct MyStructPrint03 :public binary_function<int, int, void>{
	void operator()(int v, int start) const {
		cout << v + start << endl;
	}
};

void test03() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), bind2nd(MyStructPrint03(), 100));

}

class MyTransFrom {
public:
	int operator()(int value) {
		return value + 100;
	}
};
void test04() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int> vtran;
	vtran.resize(v.size());
	transform(v.begin(), v.end(), vtran.begin(), MyTransFrom());
	for_each(vtran.begin(), vtran.end(), [](int val) {cout << val << endl; });
}

//transform�ڶ����÷�
//������������Ӱ��˵�Ŀ��������

class MyTransFrom05 {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};
void test05() {
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 100);
	}
	vector<int> vt;
	vt.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), vt.begin(), MyTransFrom05());
	for_each(vt.begin(), vt.end(), [](int v) {cout << v << " "; });
}

int main() {

	//test01();
 	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}
