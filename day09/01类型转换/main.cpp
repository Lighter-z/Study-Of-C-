#include <iostream>

using namespace std;

//static_cast<Ŀ�����>(ԭʼ����)

//��̬ת��
//��������
void test01(void) {
	char a = 'a';
	double d = static_cast<double>(a);
	cout << d << endl;
}

class Base {};
class Child :public Base {};
class Other {};

void test02(void) {
	Base * b = NULL;
	Child * c = NULL;
	//�� Base תΪ Child ����ת ����ȫ
	Child * c2 = static_cast<Child *>(b);

	//�� Child תΪ Base ����ת ��ȫ
	Base * b1 = static_cast<Base *>(c);

	//תother    ת����Ч
	//Other * o = static_cast<Other *>(b);    //����
}

int main(void) {
	test01();
	return 0;
}
