#include <iostream>

using namespace std;

//1����ͨ�����뺯��ģ�������
template<class T>
T myPlus(T a, T b) {
	return a + b;
}

int myPlus2(int a, int b) {
	return a + b;
}

void test01() {
	int a = 10;
	int b = 20;
	char c = 'c';

	//myPlus(a,c);   //���� �����Ƶ�������
	myPlus2(a, c);    //������   ASIII��   c = 99   �����Խ�����ʽ����ת����

	cout << myPlus(a, b) << endl;

	cout << myPlus2(a, b) << endl;
	cout << myPlus2(a, c) << endl;
}

//2����ͨ�����뺯��ģ��ĵ��ù���
template<class T>
void myPrint(T a, T b) {
	cout << "����ģ����õ�myPrint" << endl;
}
template<class T>
void myPrint(T a, T b, T c) {
	cout << "a,b,c����ģ����õ�myPrint" << endl;
}

void myPrint(int a, int b) {           //���� ������  ������ͬ��������������
	cout << "��ͨ�������õ�myPrint" << endl;
}

void test02(void) {
	int a = 10;
	int b = 20;
	int c = 3;
	//1��������ͨ����myPrint   ��Ϊ ��������   ������ͨ��������һ��ʱ�����ȵ�����ͨ����������
	myPrint(a, b);
	//2��ǿ��ʹ��ģ��
	myPrint<>(a, b);   
	//3������ģ��֮�䷢������
	myPrint<>(a, b, c);
	//4���������ģ����Բ������õ�ƥ�䣬�����ȵ��ú���ģ��
	char d = 'e';
	char e = 'd';
	myPrint(d,e);  // ���������ģ����õ�myPrint  ӦΪ��ͨ������Ҫ����  ��ʽת��  �������ȵ��ú���ģ��
}

int main() {
	test01();
	test02();   
	return 0;
}
