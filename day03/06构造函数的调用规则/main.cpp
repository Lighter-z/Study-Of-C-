#include <iostream>

using namespace std;

//����
//���ղ�������  �޲ι��캯����Ĭ�Ϲ��캯����  �вι��캯��
//�������ͷ���  ��ͨ���캯��    �������캯��

class MyClass {
public:
	MyClass() {
		cout << "Ĭ�Ϲ��캯��" << endl;
	}

	MyClass(int a) {
		cout << "�вι��캯��" << endl;
	}

	//MyClass(const MyClass & my) {
	//	
	//}

	int a;

};

//ϵͳ��Ĭ���ṩ Ĭ�Ϲ���  ��������  ��������

//1.�������ṩ�вι��캯��ʱ��ϵͳ�����ٸ������ṩ���캯��  ����ҪдĬ�Ϲ��캯��  ��д�ͻᱨ��
//����ϵͳ���ṩĬ�ϵĿ������캯�������м򵥵�ֵ����  
void test01() {
	MyClass c1;
	c1.a = 10;
	MyClass c2(c1);
	cout << "c2.a = " << c2.a << endl;
}

//2.�������ṩ�������캯�� ϵͳ�����ṩ��������   
//��������Ҫ�Լ�д  ��Ȼ�ᱨ��
class MyClass2 {
public:
	/*MyClass2() {
		cout << "Ĭ�Ϲ��캯��" << endl;
	}

	MyClass2(int a) {
		cout << "�вι��캯��" << endl;
	}*/

	MyClass2(const MyClass & my) {
		
	}

	int a;

};

void test02() {
	MyClass2 c2;
}

int main() {
	test01();
	return 0;
}

