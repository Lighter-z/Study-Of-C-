#include <iostream>

using namespace std;

class Base {
public:
	int a_;
	Base() {
		a_ = 100;
	}
	void func() {
		cout << "Base func" << endl;
	}

	void func(int a) {
		cout << "Son1 func  11111111" << endl;
	}
};

class Son1 : public Base {
public:
	int a_;
	Son1() {
		a_ = 200;
	}
	void func() {
		cout << "Son1 func" << endl;
	}

};

//��� �����븸�� ��ͬ���ĺ��� ���� ����    ���಻�Ḳ�Ǹ���   ����������
//��� �����븸�� ��ͬ������  ������Զ��Ѹ�������ε�  ֻ��ͨ�� s1.Base::func()�ķ�ʽ���� 
void test01() {
	Son1 s1;
	cout << s1.a_ << endl;  //200  ����ʱ�� �ͽ�ԭ��
	cout << s1.Base::a_ << endl;   //100

	s1.func();
	s1.Base::func(1);
	s1.Base::func();
}


int main(void) {
	
	test01();
	return 0;
}
