//���μ̳л���� �̳пռ��ظ� ����˷�
//       ����
// ��            ����
//       ����
//�� �� ���� ���̳е��� age 
//���ռ̳�ʱ�� ��̳����� age  ��ɿռ��˷�

//���� �����������̳�   virtual
//�������ǹ����һ������
#include <iostream>
#include "SheepTuo.h"

using namespace std;

void test01() {
	SheepTuo st;
	st.Sheep::age_ = 10;
	st.Tuo::age_ = 20;
	cout << st.Sheep::age_ << endl;
	cout << st.Tuo::age_ << endl;

	//��̳к� û�ж�����������
	//����ֱ�����²���
	cout << st.age_ << endl;

}

int main() {
	test01();
	return 0;
}


