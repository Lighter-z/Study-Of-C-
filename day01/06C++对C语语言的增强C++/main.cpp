#include <iostream>

using namespace std;

//1.ȫ�ֱ��������ǿ
//����a���ض���
//int a;
int a = 10;

//2.���������ǿ���������ͼ����ǿ������ֵ��ǿ
//����ֱ���
#if 0
void getRect(w, h) {

}

void test02(void) {
	getRect(1, 2, 3);
}
#else
int getRect(int w, int h) {
	return w * h;
}

void test02(void) {
	getRect(1, 2);
}
#endif

//3.����ת����ǿ
void test03(void) {
	//char *p = malloc(sizeof(64));//malloc����ֵ�� void *����
	char *p = (char *)malloc(sizeof(64));//malloc����ֵ�� void *����
}

//4.struct��ǿ
struct Person {
	int m_age;
	void addAge() { m_age++; };//c++���������ڽṹ�������Ӻ���
};

void test04(void) {
	Person p; //���Բ�ʹ��struct
	p.addAge();
}

//5.bool�������� 
bool flage = true;
void test05(void) {
	cout << sizeof(flage) << endl;

	flage = 200;  
	cout << flage << endl;  //�������� ����ֵ����1
}

//6.��Ŀ�����  \
//c++�з��ص��Ǳ���
//c���ص���ֵ
void test06(void) {
	int a = 10;
	int b = 20;

	cout << (a > b ? a : b) << endl;
	(a > b ? a : b) = 500;
	cout << a << endl;
	cout << b << endl;

}
//7.const��ǿ   
const int a_07 = 10;
void test07(void) {
	//a_07 = 100;  //���� �����޸�
	cout << "const" << endl;
	const int b = 10; //��������     
	int m_b[b]; // ���Գ�ʼ������

	//b = 100;//���� �����޸�

	//�ƹ������� ͨ��ָ������޸�  ���ַ���ֻ���޸ľֲ���
	int *p = (int *)&b;
	*p = 200;
	cout << "*p = " << *p << endl; //200
	cout << "b = " << b << endl;//10
}
int main(void) {
	test05();
	test06();
	test07();
	return 0;
}
