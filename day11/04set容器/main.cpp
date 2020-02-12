#include <iostream>
#include <string>
//set multisetͷ�ļ�
#include <set>
using namespace std;

/*
set�ǹ���ʽ����
���������Զ�����  ����keyֵ

keyֵ =  ����ֵ  ��key = value��   
key��ֵ�����ظ�

set��������
set<T> st;  //setĬ�Ϲ��캯��
mulitset<T> mst;  //Mulitset Ĭ�Ϲ��캯��
set(const set & st);  //�������캯��

set �� mulitset ����
set �����Բ�����ͬ��ֵ
mulitset ���Բ�����ͬ��ֵ

��ֵ����
set & operator=(const set & st);  ///���صȺ������
swap(st);  //����������������

set��С����
size();  //��������Ԫ�ظ���
empty(); //�ж������Ƿ�Ϊ��

set�����ɾ������
insert(elm);  //�������в���Ԫ��  set���뷵��ֵ�� ���� <�������� �����Ƿ�ɹ�����ֵ>
clear();  //�������Ԫ��
erase(pos);  //ɾ��pos��������ָ���Ԫ��  ������һ��Ԫ�صĵ�����
erase(beg, end);  //ɾ������[beg, end]�е�Ԫ��  ������һ��Ԫ�صĵ�����
erase(elem);  //ɾ��������ֵΪelem��Ԫ��

set���Ҳ���
find(key);  //���Ҽ� key�Ƿ���� �����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end()
count(key);  //���Ҽ�key��Ԫ�ظ���  //���set��˵ ����ֵֻ��0 ���� 1  ��Ϊ set�� ������key�ظ�
lower_bound(keyElem);  //���ص�һ��key>=keyElemԪ�صĵ�����
ipper_boumd(keyElem);  //���ص�һ��key>keyElmԪ�صĵ�����
equal_range(keyElem);  //����������key��keyElem��ȵ������޵�����������
*/

void printSet(set<int> s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01(void) {
	//����ʽ����  ���Զ�����
	set<int> s1;
	s1.insert(50);
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	printSet(s1);  //��С��������  10  20  30  40  50
	cout << "s1 size = " << s1.size() << endl;

	s1.erase(40);
	printSet(s1);

	s1.erase(s1.begin());
	printSet(s1);

}

void printMultiset(multiset<int> & m) {
	for (multiset<int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test02() {
	multiset<int> m;

	//���Բ�����ͬ��ֵ
	m.insert(40);
	m.insert(10);
	m.insert(20);
	m.insert(30);
	m.insert(30);
	
	printMultiset(m);  //�Զ�����  ��С����
}

void test03(void) {
	set<int> s1;
	s1.insert(50);
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);

	//����set  û��value  key����value
	set<int>::iterator pos = s1.find(20);
	if (pos != s1.end()) {
		cout << "�ҵ��� ��ֵΪ " << *pos << endl;
	}
	else{
		cout << "û���ҵ�" << endl;
	}

	//count(key)  //���Ҽ� key�ĸ��� ����set���� ����� 0  ���� 1����Ϊ set�� keyֵ�����ظ���
	cout << "10�ĸ��� = " << s1.count(10) << endl;

	set<int>::iterator it1 = s1.lower_bound(20);
	if (it1 != s1.end()) {
		cout << "�ҵ��� ��ֵΪ " << *it1 << endl;
	}
	else {
		cout << "û���ҵ�" << endl;
	}

	set<int>::iterator it2 = s1.upper_bound(20);
	if (it2 != s1.end()) {
		cout << "�ҵ��� ��ֵΪ " << *it2 << endl;
	}
	else {
		cout << "û���ҵ�" << endl;
	}

	//equal_range(keyElem) ����������key��keyElem��ȵ������޵�����������
	//�����޾���lower_bound   upper_bound
	pair<set<int>::iterator, set<int>::iterator> it3 = s1.equal_range(20);
	//��ȡ��һ����ֵ
	if (it3.first != s1.end()) {
		cout << "�ҵ� ��һ�� equal_range ֵ��" << *(it3.first) << endl;
	}
	else {
		cout << "û���ҵ�" << endl;
	}
	//��ȡ�ڶ�����ֵ
	if (it3.second != s1.end()) {
		cout << "�ҵ� ��һ�� equal_range ֵ��" << *(it3.second) << endl;
	}
	else {
		cout << "û���ҵ�" << endl;
	}

}

//set���뷵��ֵ�� ���� <�������� �����Ƿ�ɹ�����ֵ>
void test04(void) {
	set<int> s;
	
	pair<set<int>::iterator, bool> ip = s.insert(10);
	if (ip.second == true) {
		cout << "first insert success" << endl;
	}
	else {
		cout << "first insert fail" << endl;
	}

	ip = s.insert(10);
	if (ip.second == true) {
		cout << "second insert success" << endl;
	}
	else {
		cout << "second insert fail" << endl;
	}
}

//�º���
class myCompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void printSetCompare(set<int, myCompare> s) {
	for (set<int, myCompare>::iterator it = s.begin(); it != s.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;
}

//����
void test05(void) {
	//��С��������
	set<int>s1;
	s1.insert(1);
	s1.insert(7);
	s1.insert(5);
	s1.insert(3);
	printSet(s1);

	//����ǰָ�����������
	//�Ӵ�С
	set<int, myCompare>s2;
	s2.insert(1);
	s2.insert(7);
	s2.insert(5);
	s2.insert(3);
	printSetCompare(s2);

}

class Person {
public:
	int age_;
	string name_;
	Person(string name, int age) {
		this->name_ = name;
		this->age_ = age;
	}
};

class PersonConmare {
public:
	bool operator()(const Person & p1, const Person & p2) {
		if (p1.age_ >= p2.age_) {  //����
			return true;
		}
		else {
			return false;
		}
	}
};

void printPerson(set<Person, PersonConmare> s) {
	for (set<Person, PersonConmare>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "������" << it->name_ << "  ���䣺" << it->age_ << endl;
	}
}

void test06() {
	Person p1("����", 100);
	Person p2("����", 50);
	Person p3("����", 10);
	Person p4("үү", 1000);

	//�Զ����������� �Ų���֮ǰ��Ҫָ���ù���
	set<Person, PersonConmare> s;
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	printPerson(s);
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}
