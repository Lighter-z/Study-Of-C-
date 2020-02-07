#include <iostream>
#include <string>

//�����ͨ������ģ�庯��һ��  �����ȵ�����ͨ����
using namespace std;

//�ñ��������� Person����
template<class T1, class T2>class Person;

//�ñ��������� Show ����
template<class T1, class T2>void Show(Person<T1, T2> & p);

template<class T1, class T2>
class Person {

	friend void Show<>(Person<T1, T2> & p);

	//��Ԫ��������ʵ��  ���ÿղ����б� ���߱�����  ģ�庯������
	//friend void Show<>(Person<T1, T2> & p);     //��ͨ��������    ���Ǳ���


	//friend void Show(Person<T1, T2> & p)     //��ͨ��������
	//{
	//	cout << "���֣�" << p.name_ << p.age_ << "��" << endl;
	//}
public:
	Person(T1 a, T2 b) {
		this->age_ = b;
		this->name_ = a;
	}
private:
	T1 name_;
	T2 age_;
};

template<class T1, class T2>
void Show(Person<T1, T2> & p)
{
	cout << "���֣�" << p.name_ << p.age_ << "��" << endl;
}

void test01() {
	Person<string, int> p1("����", 5);

	Show(p1);
}

int main() {
	test01();
	return 0;
}

