#include <iostream>

using namespace std;

//����һ���ӷ�
// ��ȱ�ݣ�
//1.����û�������� 
//2.��Ҫ��С���ű������
#define MyAdd(x,y) x+y

void test01() {
	//int ret = MyAdd(10, 20)  //20
	int ret = MyAdd(10,20) * 20;  //410   10 + 20 * 20     ���������� #define MyAdd(x,y) ((x) + (y))
	cout << ret << endl;
}
//1.������������
inline void func();//������������
inline void func() {}
//2.���ڲ��ĳ�Ա���� ������Ĭ�ϼ��� inline

int main() {
	test01();
	return 0;
}
