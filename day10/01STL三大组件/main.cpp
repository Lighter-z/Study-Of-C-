#include <iostream>
#include <string>
//vector����
#include <vector>
//ʹ��ϵͳ�㷨ͷ�ļ�
#include <algorithm>
using namespace std;

//������ �������� ��ָ�����
//��ָͨ��Ҳ��һ�ֵ�����
void test01(void) {
	int array[5] = { 1,3,5,7,9 };
	int *p = array;
	
	for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++) {
		//cout << array[i] << endl;
		cout << *(p++) << endl;
	}

}

//for_each()�Ļص�����
void myPrint(int v) {
	cout << v << endl;
}

//vector����
void test02(void) {
	//��������
	vector<int> v; //����һ������   ��������д��int�������� ����������v
	//β�巨  �������в�������
	v.push_back(0);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//������
	vector<int>::iterator itBegin = v.begin();//itBeginָ�� v�����е���ʼλ��
	vector<int>::iterator itEnd = v.end();//itEndָ�� v���������һ��λ�õ���һ��λ��

	//��һ�ֱ�������
	//while (itBegin != itEnd) {
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}
	
	//�ڶ��ֱ�������
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << *it << endl;
	//}

	//������  �����㷨����
	for_each(v.begin(), v.end(), myPrint);  // myPrint�ص�����
}

//-----------------------------------�����Զ�����������
class Person {
public:
	int age_;
	string name_;
	Person() {};
	Person(string name, int age) {
		this->name_ = name;
		this->age_ = age;
	}
};

void myPringPerson(Person & p) {
	cout << p.name_ << " " << p.age_ << endl;
}

void test03(void) {
	vector<Person> vp;
	Person p1("����", 55);
	Person p2("����", 8);
	Person p3("����", 5);

	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);

	//for (vector<Person>::iterator it = vp.begin(); it != vp.end(); it++) {
	//	cout << (*it).name_ << " " << it->age_ << endl;
	//}

	for_each(vp.begin(), vp.end(), myPringPerson);
}

void myPringPerson04(Person * p) {
	cout << p->name_ << " " << p->age_ << endl;
}
void test04(void) {
	vector<Person *> vp;
	Person p1("����", 55);
	Person p2("����", 8);
	Person p3("����", 5);

	vp.push_back(&p1);
	vp.push_back(&p2);
	vp.push_back(&p3);

	//for (vector<Person * >::iterator it = vp.begin(); it != vp.end(); it++) {
	//	cout << (*it)->name_ << " " << (*it)->age_ << endl;
	//}

	for_each(vp.begin(), vp.end(), myPringPerson04);
}

//����Ƕ������
void test05(void) {
	vector<vector<int>> v;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	for (int i = 0; i < 5; i++) {
		v1.push_back(i);
		v2.push_back(i + 10);
		v3.push_back(i + 20);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		for (vector<int>::iterator vit = it->begin(); vit != (*it).end(); vit++) {
			cout << *vit << endl;
		}
	}
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}
