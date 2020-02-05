#include <iostream>

using namespace std;

class Base01 {
public:
	int a_;
	Base01() {
		int a_ = 0;
		int b_ = 0;
		int c_ = 0;
	}
protected:
	int b_;
private:
	int c_;
};

class Son1 : public Base01 {
public:

	void fun() {
		cout << a_ << endl;
		cout << b_ << endl;
		//cout << c_ << endl;  //˽�в����Լ̳�

	}
};

class Son2 : protected Base01 {
public:
	void func() {
		cout << a_ << endl;    // ������protected
		cout << b_ << endl;   // ������protected
		//cout << c_ << endl;  //˽�в����Լ̳�
	}
};

class Son3 : private Base01 {
public:
	void func() {
		cout << a_ << endl;
		cout << b_ << endl;
		//cout << c_ << endl;  //˽�в����Լ̳�
	}
};

void test01() {
	Son1 s1;
	s1.fun();
	s1.a_ = 10;
	//s1.b_;  //  �������ⲿ�����Ե���
	//s1.c_;  //  ˽�в����Ե���

	Son2 s2;
	s2.func();
	//s2.a_; //  �����̳к� ��Ϊ������  �������ⲿ�����Ե���
	//s2.c_;  //  ˽�в����Ե���

	Son3 s3;
	s3.func();
	//s3.a_;//  ˽�м̳к�  ��Ϊ˽�е�  ˽�в����Ե���	
	//s3.c_;  //  ˽�в����Ե���
}

int main(){
	test01();
	return 0;
}
