#include <iostream>
using namespace std;

//C++�������c���Է���
//����һ   ���ü�ͷ�ļ�
//extern "C" void show();

//������ ��c������ȥ����
//�� test.h��
#include "test.h"


void test01() {
	show();  //��C++�����к������ص�  ������������������͵͵��Ϊ _show()
}

int main() {
	test01();
	return 0;
}
