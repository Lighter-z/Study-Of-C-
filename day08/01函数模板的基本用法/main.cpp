#include <iostream>

using namespace std;

void Swap1(int & a, int & b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//���ͱ��  ���Ͳ�����
template<class T> //���߱����� ����������� T  ��Ҫ����T��һ��ͨ������
//template<class T>   �ȼ���  template<typename T>
void Swap2(T & a, T & b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 10;
	int b = 20;
	Swap1(a, b);
	cout << a << endl << b << endl;

	a = 30;
	b = 40;
	//�Զ������Ƶ�   �����в������Ͳſ����Ƶ�
	Swap2(a, b);
	//2.��ʾָ������
	Swap2<int>(a,b);
	cout << a << endl << b << endl;

	double c = 2.3;
	double d = 4.6;
	Swap2(a, b);
	cout << a << endl << b << endl;
}

int main() {
	test01();
	return 0;
}
