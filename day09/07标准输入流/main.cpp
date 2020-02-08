#include <iostream>
/*
cin.get()                //��ȡ������һ���ַ�
cin.get(��������)       //����ȡ���з�
cin.getline()  //��ȡ���з����ӵ�
cin.ignore(n);  ����   //n ������Ե��ַ���  ��д��һ��
cin.peek()   ͵��      //  ͵��һ���ַ���Ȼ������ݷŻػ�����
cin.putback(c);  �Ż�   //���ݷŻػ�����

//����1
//�ж��û�����������ֻ����ַ�����
*/
using namespace std;

void test01(void) {
	char c = cin.get();
	cout << c << endl;
}

//cin.get()   ����ѻ��з�����
void test02() {
	char buf[1024];
	cin.get();
	char c = cin.get();
	if (c == '\n') {
		cout << "���з����ڻ�����" << endl;
	}
	else {
		cout << "���з����ڻ�����" << endl;
	}
	cout << buf << endl;
}

//cin.getline()   ��ѻ��з���ȡ ���ӵ�
void test03() {
	char buf[1024];
	cin.getline(buf,1024);
	char c = cin.get();
	if (c == '\n') {
		cout << "���з����ڻ�����" << endl;
	}
	else {
		cout << "���з����ڻ�����" << endl;
	}
	cout << buf << endl;
}

//cin.ignore(n);  ����   ���ǰ n ����ȡ�����ַ�����
//��������   ����һ��
void test04() {
	cin.ignore();
	char c = cin.get();
	cout << c << endl;
}

//cin.peek()   ͵��
void test05() {
	//����as
	char c = cin.peek();  //��һ���۵�һ������ Ȼ���ְ����ݷŻ� ������ ��
	cout << c << endl;  //  ��ӡ  a
	c = cin.get();  //  �õ��Ż�ȥ�Ǹ�����
	cout << c << endl;  // ��ӡ  a
}

//cin.putback(c);  �Ż�
void test06(void) {
	//���� hello world 
	char c = cin.get();   //�õ� h
	cin.putback(c);   //�ְ� h�Żػ�����

	char buf[1024];
	cin.getline(buf, 1024);   //�õ� hello world 
	cout << buf << endl;
}

//����1
//�ж��û�����������ֻ����ַ�����
void test07(void) {
	cout << "����������" << endl;
	char c = cin.peek();
	if (c > '0' && c < '9') {
		int num;
		cin >> num;
		cout << "�������������:" << num << endl;
	}
	else {
		char buf[1024];
		cin >> buf;
		cout << "����������ַ�����" << buf << endl;
	}
}

int main(void) {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	return 0;
}
