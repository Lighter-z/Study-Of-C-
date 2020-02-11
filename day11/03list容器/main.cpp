#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
//list��˫��ѭ���б�

/*
list  //���캯��
list<T> lisT;  //������ģ��ʵ�� Ĭ�Ϲ��캯��
list(begin,end);  //���캯��  ������[begin, end]�е�Ԫ�ؿ���������
list(n, elem);  //���캯��  ��n��elm����������
list(const list & l);  //�������캯��

listԪ�ز����ɾ������
push_back(elem);  //������β������һ��Ԫ��
pop_back();  //ɾ�����������һ��Ԫ��
push_front(elem);  //������ͷ������һ��Ԫ��
pop_front();  //ɾ��������ͷ��һ��Ԫ��
insert(pos, elm);  //�� pos λ�� ����Ԫ��elm ����������λ��
insert(pos, n, elm);  //�� pos λ�ò��� n ��Ԫ��elm  
insert(pos, beg, end);  //�� pos λ�� ��������[begin, end]�е�Ԫ�� �޷���ֵ
clear();  //�Ƴ�����������Ԫ��
erase(begin, end);  //ɾ������[begin, end]�е�Ԫ�� ������һ�����ݵ�λ��
erase(pos);  //ɾ�� pos λ�õ����� ������һ�����ݵ�λ��
remove(elm);  //ɾ��������������elmƥ���Ԫ��

list��С����
size();  //����������Ԫ�ظ���
empty();  //�ж������Ƿ�Ϊ��
resize(num);  //����ָ����������  �������䳤 ����Ĭ��ֵ�����λ��  ��������� �򳬳�ĩβ����ɾ��
resize(num, elm);//����ָ����������  �������䳤 ����elm�����λ��  ��������� �򳬳�ĩβ����ɾ��

list��ֵ����
assign(beg, end);  //������[begin, end]�е�Ԫ�ؿ�����ֵ������
assign(n, elm);  //��n��elm������ֵ������
list & operator=(const list & lst);  //���صȺ������
swap(lst);  //��lstԪ���뱾����

list���ݵĴ�ȡ
front();  //���ص�һ��Ԫ��
back();  //�������һ��Ԫ��

��ת����
reverse();  //��ת���� ���� list ���� 1 2 3Ԫ�� ���д˷����� list�Ͱ��� 3  2  1Ԫ��
sort();  //list����
*/

//��֤list�Ƿ�Ϊѭ������
void test01(void) {
	list<int> myList;
	for (int i = 0; i < 10; i++) {
		myList.push_back(i);
	}
	
	list<int>::_Nodeptr node = myList._Myhead()->_Next;//�ڵ�ָ�� ͷ�ڵ����һ���ڵ�  ��ͷ�ڵ��ǲ��������ݵģ�
	
	for (int i = 0; i < myList._Mysize() * 2; i++) {
		cout << "Node��" << node->_Myval << endl;
		node = node->_Next;
		if (node == myList._Myhead()) {   //ѭ���б�  �ִ�β��ָ����ͷ��  
			node = node->_Next;
		}
	}
}

//�����ӡ
void printList(list<int> & l) {
	for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;
}

//�����ӡ
void printRightList(list<int> & l) {
	for (list<int>::reverse_iterator rit = l.rbegin(); rit != l.rend(); rit++) {
		cout << (*rit) << " ";
	}
	cout << endl;
}

//list API
void test02(void) {
	list<int> l1(10, 20);
	list<int> l2(l1.begin(), l1.end());
	printList(l2);

	list<int>l3(l2);
	printList(l3);

	l3.push_back(10);
	printList(l3);
	l3.push_front(50);
	printList(l3);
	l3.pop_back();
	printList(l3);
	l3.pop_front();
	printList(l3);

	l3.insert(l3.begin(), 9);
	printList(l3);

	l3.insert(l3.begin(), 5, 89);
	printList(l3);

	l3.erase(l3.begin());
	printList(l3);

	l3.remove(20);
	printList(l3);
	printRightList(l3);
}

bool myCompare(int v1, int v2) {
	return v1 > v2;
}

void test03(void) {
	list<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.push_back(i);
	}
	printList(l1);

	list<int> l2(l1);
	printList(l2);

	list<int> l3;
	l3 = l2;
	printList(l3);

	cout << "l1 size = " << l1.size() << endl;

	l2.resize(20);
	printList(l2);

	l2.assign(l3.begin(), l3.end());
	printList(l2);
	l2.push_back(90);

	l2.swap(l3);
	printList(l2);
	printList(l3);

	cout << "l3 header = " << l3.front() << "  l3 end = " << l3.back() << endl;

	if (l3.empty()) {
		cout << " l3 is empty " << endl;
	}
	else {
		cout << " l3 is not empty " << endl;
	}

	//��ת����
	l3.reverse();
	printList(l3);
	l3.push_back(100);
	printList(l3);

	//sort(l3.begin(), l3.end());  //����  ���в�֧��������ʵĵ�����������ʹ����� ϵͳ�ṩ�ķ���
	//���� ������ڲ����ṩ
	l3.sort();  //��С��������
	printList(l3);  

	l3.sort(myCompare);  //�Ӵ�С����
	printList(l3);

}

//�Ӵ�С����

class Person {
public:
	string name_;
	int age_;
	Person() {};
	Person(string name, int age) {
		this->name_ = name;
		this->age_ = age;
	}

	//���� == �� remove ����ɾ���Զ�����������
	bool operator==(const Person & p) {
		if ((this->name_ == p.name_) && (this->age_ == p.age_)) {
			return true;
		}
		return false;
	}
};

//sort �ص�����
bool myComparePerson(Person & p1, Person & p2) {
	if (p1.age_ > p2.age_) {
		return true;
	}
	else {
		return false;
	}
}
void printPerson(list<Person> & lp) {
	for (list<Person>::iterator pit = lp.begin(); pit != lp.end(); pit++) {
		cout << "���֣�" << (*pit).name_ << "  ���䣺" << (*pit).age_ << endl;
	}
}

void test04() {
	list<Person> lp;

	Person p1("����", 50);
	Person p2("����", 90);
	Person p3("����", 58);
	Person p4("������", 30);
	Person p5("����", 20);

	lp.push_back(p1);
	lp.push_back(p2);
	lp.push_back(p3);
	lp.push_back(p4);
	lp.push_back(p5);

	lp.sort(myComparePerson);
	printPerson(lp);

	lp.remove(p5);
	printPerson(lp);

}

int main() {
	//test01();
	//test02();
	//test03();
	test04();
	return EXIT_SUCCESS;
}



