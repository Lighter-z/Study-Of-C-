#include <iostream>
#include <string>


using namespace std;

class Base {
public:
	int a_;
protected:
	int b_;
private:
	int c_;
};

//������ȷʵ�̳���  c_  ���Ǳ����� ��c_������  ���ʲ���
class Son1 : public Base {
public:
	int d_;
	void func() {
		b_ = 10;
	}

};

void test01(void) {
	cout << sizeof(Son1) << endl;    //��СΪ16   ˽�����Եı���Ҳ����������
}

int main(void) {
	test01();
	return 0;
}
