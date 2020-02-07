#include <iostream>
#include <string>
using namespace std;
//ģ�岻�ܽ����������
//������ֲ��ܽ�������ͣ�ͨ�����������廯���������
//�﷨��template<> ����ֵ ������<��������>(����)

class Person {
public:
	string name_;
	int age_;
	Person() {}
	Person(int age, string name) {
		this->name_ = name;
		this->age_ = age;
	}
};

//���ܽ�������ж�
template<class T>
bool myCompare(T & a, T & b) {
	if (a == b) {
		return true;
	}
	return false;
}

//ͨ�� ���������廯 �Զ����������ͽ����������
template<>bool myCompare<Person>(Person & a, Person & b) {
	if (a.age_ == b.age_ && a.name_ == b.name_) {
		return true;
	}
	return false;
}

void test01() {
	bool result;
	int a = 10;
	int b = 20;
	result = myCompare(a, b);

	//ͨ�����廯 �Զ����������ͽ����������
	Person p1(4, "����");
	Person p2(4, "����");
	result = myCompare(p1, p2);


	cout << result << endl;

}

int main() {
	test01();
	return 0;
}

