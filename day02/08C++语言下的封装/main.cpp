#include <iostream>
#include <string>
using namespace std;

//c++��װ  �ϸ������ת�����   ����Ϊ�����԰���һ��
//���Ժ���Ϊ��Ϊһ����������ʾ�����е�����
//����Ȩ�� public protected private

typedef struct {
	char name[64];
	int age;

	void PeopleEat() {
		cout << name << "���˷�" << endl;
	}

}Person;

void test01() {
	Person p;
	strcpy(p.name, "����");
	p.PeopleEat();
}

//struct �� class ��һ����˼  Ψһ��ͬ structĬ��Ȩ���� public  ��  class Ĭ��Ȩ����private
/*
public �������ⶼ���Է���
protected ���ڿ��Է��� ���ⲻ���Է��� ������Է���
private ���ڿ��Է��� ���ⲻ���Է���  ���಻���Է���
*/
class Animal {
	//���������Ȩ�� Ĭ��ʹprivate
};

int main() {
	test01();
	return 0;
}
