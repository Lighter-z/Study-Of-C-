#include <iostream>

using namespace std;

//�����̳и���ĳ�Ա���� ��Ա����
//���಻��̳� ���๹�캯��  ��������
class Base {
public:
	Base() {
		cout << "Base���캯��" << endl;
	}
	~Base() {
		cout << "Base��������" << endl;
	}
};

class Son1 : public Base {
public:
	Son1() {
		cout << "Son1���캯��" << endl;
	}
	~Son1() {
		cout << "Son1��������" << endl;
	}
};

class Base2 {
public:
	Base2(int a) {
		cout << "Base2�вι��캯��" << endl;
	}

};

class Son2  : public Base2{
public:
	/*Son2() {}*/  //����  Base2 ������ �޲ι���
	Son2(int a):Base2(a){       //������û�� �޲ι���ʱ��  ʹ�����ַ������û��๹�캯��
		cout << "Son2�вι��캯��" << endl;
	}
};

void test01(void) {
	Son1 s1;  //�ȵ��� Base�Ĺ��� �ڵ����Լ��Ĺ���   ������֮��
	/*Son2 s2_1;*/
	Son2 s2(1);
}



int main() {
	test01();
	return 0;
}
