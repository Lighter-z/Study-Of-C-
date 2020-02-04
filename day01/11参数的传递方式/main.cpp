#include <iostream>

using namespace std;

//1.ֵ����
void swap(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//2.��ַ����
void MySwap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void test02() {
	int a = 1;
	int b = 2;

	MySwap(&a, &b);
	cout << "a" << a << endl;
	cout << "b" << b << endl;
}

//���ô���
void MySwap2(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void test03() {
	int a = 1;
	int b = 2;

	MySwap2(a, b);
	cout << "a" << a << endl;
	cout << "b" << b << endl;
}

//����ע������
//1.���ñ�������һ��Ϸ����ڴ�ռ�
void test04() {
	//int &a = 10;//���ñ�������һ��Ϸ����ڴ�ռ䣬������10û���ڴ�ռ䣬���Ա���

	//���õı��ʾ���ָ�볣��
	int a = 10;
	int &ref = a; //�Զ�ת��Ϊint *const ref = &a;          ���˵����Ϊʲô���ñ����ʼ����ָ�볣�������ʼ�������Ҳ����޸ģ�
	ref = 20;//�ڲ�����ref������  �Զ�������ת��Ϊ *ref = 20;
}

//2.��Ҫ���ؾֲ�����������
int &getNum() {
	int a = 10;
	return a;

}

void test05() {
	
	int &a = getNum();//�ֲ��������������ں�������ʱ���û��
	cout << "1�ֲ���������a = " << a << endl;  //��һ�δ�ӡ�������������Ż� ���Ի���10����δ�ӡ���ݾͱ���
	cout << "2�ֲ���������a = " << a << endl;
	cout << "3�ֲ���������a = " << a << endl;
	cout << "4�ֲ���������a = " << a << endl;
	cout << "5�ֲ���������a = " << a << endl;
}
//ʹ��static����
int &getNum06() {
	static int a = 10;
	return a;

}

void test06() {

	int &a = getNum06();
	cout << "1�ֲ���������a = " << a << endl; 
	cout << "2�ֲ���������a = " << a << endl;
	cout << "3�ֲ���������a = " << a << endl;
	cout << "4�ֲ���������a = " << a << endl;
	cout << "5�ֲ���������a = " << a << endl;
}

//����������ص���ֵ�����ã���ô����������ÿ�����Ϊ��ֵ
void test07() {
	int &ret = getNum06();
	getNum06() = 100;  //�൱��д��a = 100

}

int main() {
	
	//test03();
	//test05();
	test06();
	return 0;
}

