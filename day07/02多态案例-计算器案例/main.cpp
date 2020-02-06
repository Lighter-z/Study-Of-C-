#include <iostream>
#include <string>

//���������� ����ԭ��
//����չ����  ���޸Ĺر�

//��̬
//�ṹ�Ժ�   ���ں���ά����չ  �ɶ��Ը�
//Ч�ʵ� ������̬ �ڲ��ṹ����

using namespace std;
class Calculator {
private:
	int value1;
	int value2;
public:
	void setValue(int a, int b) {
		this->value1 = a;
		this->value2 = b;
	}
	int getResult(string opera) {
		if (opera == "+") {
			return this->value1 + this->value2;
		}
		else if (opera == "-") {
			return this->value1 - this->value2;
		}
	}
};

void test01(void) {
	Calculator c1;
	c1.setValue(10, 10);
	cout << c1.getResult("+") << endl;
	cout << c1.getResult("-") << endl;

}

//���ö�̬ʵ�֣�
class AbstrictCalculator{
public:
	//�麯��
	//virtual int getResult() { return 0; }

	//���麯����
	//1��������������˴��麯��  ����̳и������ʵ�ִ��麯��������
	//2��������������˴��麯��   ����Ͳ���ʵ�������󣡣�������
	//3����������˴��麯��   �ͳ�Ϊ��  ������   �������಻����ʵ��������
	virtual int getResult() = 0;

	void setValue(int a, int b) {
		this->value1 = a;
		this->value2 = b;
	}
	int getValue1() {
		return value1;
	}
	int getValue2() {
		return value2;
	}
private:
	int value1;
	int value2;
};

class AddCalculator : public AbstrictCalculator {
public:
	//1��������������˴��麯��  ����̳и������ʵ�ִ��麯��������
	virtual int getResult() {        //virtual  ��д�ɲ�д
		
		return getValue1() + getValue2();
	}
};

class SubCalculator : public AbstrictCalculator {
public:
	virtual int getResult() {        //virtual  ��д�ɲ�д

		return getValue1() - getValue2();
	}
};

void test02(void) {
	AbstrictCalculator * abc = new AddCalculator;
	abc->setValue(20,20);
	cout << "��̬" << endl;
	cout << abc->getResult() << endl;

	delete abc;
	abc = new SubCalculator;
	cout << abc->getResult() << endl;

	//2��������������˴��麯��   ����Ͳ���ʵ�������󣡣�������
	//AbstrictCalculator *a = new AbstrictCalculator;
}



int main(void) {
	test01();
	test02();
	return 0;
}