#include <iostream>

using namespace std;

class Person {
public:
	//���캯��д����
	//��������ͬ��û�з���ֵ ��дvoid  ���Է������أ������в�����
	Person()  //���캯���ɱ������Զ�����  ֻ����һ��
	{
		cout << "���캯��" << endl;
	}
	Person(int a)  //���캯���ɱ������Զ�����  ֻ����һ��
	{
		cout << "���캯�� a = " << a << endl;
	}

	//��������
	//��������ͬ ������ǰ���~   Ҳû�з���ֵ ��дvoid  ���������أ������в�����
	~Person()  //���������ɱ������Զ�����  ֻ����һ��     �ͷ�ʱ�������������
	{
		cout << "��������" << endl;
	}
};

void test01() {
	Person p1;
	Person p2(2);
}

int main() {
	
	test01();
	return 0;
}

