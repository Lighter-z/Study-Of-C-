#include <stdio.h>

//1.ȫ�ֱ��������ǿ
int a;
int a = 10;

//2.���������ǿ���������ͼ����ǿ������ֵ��ǿ
//������ֱ���
int getRect(w, h) {
	
}

void test02(void) {
	getRect(1, 2, 3);
}

//3.����ת����ǿ
void test03(void) {
	char *p = malloc(sizeof(64));//malloc����ֵ�� void *����
}

//4.struct��ǿ
struct Person{
	int m_age;
	//void addAge();//c�����в����ڽṹ�������Ӻ���
};

void test04(void) {
	struct Person p; //����ʹ��struct����
}

//5.bool ��������  c��û��
//bool a;

//6.��Ŀ�����
//c++�з��ص��Ǳ���
//c���ص���ֵ
void test06(void) {
	int a = 10;
	int b = 20;
	
	printf("��Ŀ����� %d\r\n", a > b ? a : b);

	//c����ģ��c++
	*(a > b ? &a : &b) = 100;
	printf("c����ģ��c++��Ŀ����� a = %d b = %d\r\n", a,b);
}

//7.const��ǿ   ȫ�ֵ��ܵ�����������ֲ�һ��ȥ�޸�
const int a_07 = 10;
void test07(void) {
	//a_07 = 100;  //���� �����޸�

	const int b = 10;      //α����
	//int m_b[b]; //����������ʼ������

	//b = 100;//���� �����޸�

	//�ƹ������� ͨ��ָ������޸�  ���ַ���ֻ���޸ľֲ���
	int *p = (int *)&b;
	*p = 200;
	printf("*p = %d \r\n  b = %d \r\n",*p,b);
}

int main(void) {
	test06();
	test07();
	return 0;
}
