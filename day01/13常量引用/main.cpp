#include <iostream>

using namespace std;

void test01() {
	//int &ref = 10;  //���� û�кϷ����ڴ�ռ�
	const int &ref = 10;  //�൱�� int temp = 10; const int &ref = temp;
//	ref = 10;  // ����ֱ���޸�

	//ֻҪ�кϷ����ڴ�ռ�Ϳ����޸�
	int *p = (int *)&ref;
	*p = 100;
	cout << ref << endl;

}

int main() {
	test01();


	return 0;
}
