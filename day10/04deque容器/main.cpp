#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

/*
deque���캯��
deque<T> deqT;  //Ĭ�Ϲ��캯��
deque(beg, end);  //���캯����[beg, end]�����е�Ԫ�ؿ���������
deque(n, elem);  //���캯����n��elem����������
deque(const deque & e);  //�������캯��

deque��ֵ����
assign(beg, end);  //��[beg, end]�����е�Ԫ�ظ�ֵ������
assign(n, elem);  //��n��elem��ֵ������
deque& operqtor=(const deque & e);  //���صȺŲ�����
swap(deq);  //��deqԪ���뱾����

deque��С����
deque.size();  //����������Ԫ�ظ���
deque.empty();  //�ж������Ƿ�Ϊ��
deque.resize(num);  //����ָ����������Ϊnum���������䳤������Ĭ��ֵ�����λ�á� ��������̣���ĩβ������������Ԫ�ر�ɾ��
deque.resize(num, elem);  //����ָ����������Ϊnum���������䳤������elem�����λ�ã���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
*/

void printDeque(const deque<int> & d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01(void) {
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	printDeque(d1);

	deque<int> d2(d1.begin(), d1.end());
	d2.push_back(100);
	d2.push_front(200);
	printDeque(d2);

	d1.swap(d2);
	printDeque(d1);
	printDeque(d2);

	cout << d1.size() << endl;
	d2.resize(10);
	printDeque(d2);
}

void test02(void) {
	deque<int>d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	printDeque(d1);

	d1.pop_back();
	printDeque(d1);

	d1.pop_front();
	printDeque(d1);

	deque<int> d2(d1);
	printDeque(d2);

	cout << d2[2] << endl;
	cout << d2.back() << endl;
	cout << d2.front() << endl;

	d2.insert(d2.begin(), d1.begin(), d1.end());
	printDeque(d2);

	d2.erase(d2.begin());
	printDeque(d2);

}

//�������
bool myCompare(int v1, int v2) {
	return v1 > v2;
}

//����
void test03() {
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(50);
	d1.push_back(52);
	d1.push_back(0);

	//��С����
	sort(d1.begin(), d1.end());
	printDeque(d1);

	//�Ӵ�С
	//�º�����Э���㷨�ı����Ĳ���
	sort(d1.begin(), d1.end(), myCompare);
	printDeque(d1);
}

/*
��ʼ������ѡ�֣�ȥ�������ͷּ���ƽ��ֵ
*/
class Person {
public:
	string name_;
	int grade_;
	int score_;
	Person() {}
	Person(string name, int grade) {
		this->name_ = name;
		this->grade_ = grade;
		this->score_ = 0;
	}
};

void printPerson(Person & p) {
	cout << "���֣�" << p.name_ << " "<< "�ɼ���" << p.grade_ << endl;
}

void test04() {
	int grade = 0;

	Person p1("����", 10);
	Person p2("����", 30);
	Person p3("����", 20);
	Person p4("����", 100);
	vector<Person> v1;
	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	
	for_each(v1.begin(), v1.end(), printPerson);
	
	cout << "--------deuqe--------" << endl;
	deque<int> d1;
	for (int i = 0; i < v1.size(); i++) {
		d1.push_back(v1[i].grade_);
	}

	printDeque(d1);
	cout << "--------����--------" << endl;
	sort(d1.begin(), d1.end());
	printDeque(d1);

	cout << "--------ȥ�������Сֵ--------" << endl;
	d1.pop_back();
	d1.pop_front();
	printDeque(d1);

	for (int i = 0; i < d1.size(); i++) {
		grade += d1[i];
	}
	p1.score_ = grade / d1.size();
	cout << "ƽ���֣�"<< p1.score_ << endl;

}

int main() {
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}
