#include <iostream>

using namespace std;

class Anmials {
public:
	virtual void sepak() {
		cout << "����˵��" << endl;
	}
	//��̬��   ��ͨ�������ǲ�����������������   ���Կ��ܻᵼ���ͷŲ��ɾ�   
	//��������������������
	//~Anmials() {
	//	cout << "Anmials����" << endl;
	//}

	////������
	//virtual ~Anmials() {
	//	cout << "Anmials����" << endl;
	//}

	//��������
	//��������  �� ���麯��  ��ͬ     
	//������Ҫ���� ������Ҫʵ��   ���������� ����ʵ�֣�
 	virtual ~Anmials() = 0;
	//������г��ִ�����������  �����Ҳ�� ������   ���಻��ʵ����
};

//������������  ��������  ����ʵ��
 Anmials :: ~Anmials() {
	 cout << "Anmials ������������" << endl;
}

class Cat :public Anmials {
public:
	char * name_;
	Cat(const char * name) {
		this->name_ = new char[strlen(name) + 1];
		strcpy(this->name_,name);
	}
	virtual void sepak() {
		cout << "Cat˵��" << endl;
	}
	~Cat()
	{
		cout << "Cat ����" << endl;
		if (this->name_ != NULL) {
			delete[] this->name_;
			this->name_ = NULL;
		}
	}
};


void test01(void) {
	Anmials * cat = new Cat("Tom");
	cat->sepak();

	delete cat;   //���õ��� anmials ����  û���ͷŸɾ�  ��ʱ����Ҫ ������

	//������ ����ʵ����
	//Anmials a;
	//Anmials *an = new Anmials;

}

int main(void) {
	test01();
	return 0;
}