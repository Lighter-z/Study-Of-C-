#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	Person() { }
	Person(char *name, int age) {
		p_name = (char *)malloc(strlen(name) + 1);  //+1  ��ӦΪ�� \0
		strcpy(p_name,name);
		p_age = age;
	}
	/*�������� ϵͳ���ṩĬ�ϵ� ���� �� �򵥵Ŀ�������
	�Լ��ṩ��������    ԭ��򵥵�ǳ�������ͷŶѿռ�����  ���³���ҵ�
	���*/
	Person(const Person & p) {
		p_age = p.p_age;
		p_name = (char *)malloc(strlen(p.p_name) + 1);
		strcpy(p_name, p.p_name);
	}

	~Person()
	{
		cout << "��������" << endl;
		if (p_name != NULL) {
			free(p_name);
			p_name = NULL;
		}
	}

	char *p_name;
	int p_age;
};

void test01() {
	Person p1("�з�",10);

	Person p2(p1);
}

int main() {
	test01();
	return 0;
}

