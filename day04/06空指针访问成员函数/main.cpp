#include <iostream>

using namespace std;


class Person {
public:
	void show() {
		cout << "Person Show" << endl;
	}
	void ageShow() {
		if (this == NULL) {   //���⴫���ָ��
			return;
		}
		cout << m_age << endl;
	}
	int m_age;
};

void test01() {
	Person *p = NULL;
	p->show();  //�ɹ�
	p->ageShow();  //���� this == NULL �жϵĻ�  �ᱨ��
	/*
	void show() �л����ؼ��� Person *this   
	ӦΪshowû���õ������б��� ���Բ�����
	ageShow���õ���  ����ȥ����һ����ָ��  ���Ա���
	���Ժ���Ҫ�����ж�
	if (this == NULL) {   //���⴫���ָ��
			return;
		}

	*/

}

int main() {
	test01();
	return 0;
}
