#include <iostream>
#include <string>
//�º���

using namespace std;

class myPrint {
public:
	void operator()(int num) {
		cout << num << endl;
		count++;
	}
	int count = 0;
};

void myPrint2(int num) {
	cout << num << endl;
}

void test01(void) {
	myPrint myPrint1;
	myPrint1(111);  //�º�������
	myPrint2(222);  //��������
	myPrint()(5000);  //�����������
}

//�������󳬳���ͨ�����ĸ���  �ڲ����Ա���״̬
void test02() {
	myPrint myPrint1;
	myPrint1(111);  //�º�������
	myPrint1(111);  //�º�������
	myPrint1(111);  //�º�������
	myPrint1(111);  //�º�������

	cout << "myPrint���ô�����" << myPrint1.count << endl;
}

void doWork(myPrint print, int num) {
	print(num);
}

void test03() { 
	doWork(myPrint(), 6);  //ֱ�Ӵ�����������
}

int main() {

	test01();
	test02();
	test03();
	return EXIT_SUCCESS;
}
