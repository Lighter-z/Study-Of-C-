#include <iostream>

using namespace std;

namespace KingGlory {
	int sunwukongId = 10;
}

void test01(void) {
	int sunwukongId = 20;
	cout << sunwukongId << endl;

	//using����
	//д��using������ �������д���˵���Ժ󿴵���sunwukongId ������KingGlory�µ���ֵ
	//����  ���������оͽ�ԭ��
	//������
	//����ע��������������
	//using KingGlory::sunwukongId;
	cout << sunwukongId << endl;  //�������޷������ˣ����򱨴�������using �������¡�KingGlory::sunwukongId���Ķ������
}

//using����ָ��
namespace LOL {
	int sunwukongId = 40;
}

void test02() {
#if 0
	int sunwukongId = 30;
	//using����ָ��
	//�ͽ�ԭ�� ���� �򿪷���
	using namespace KingGlory;  //�򿪷���
	cout << sunwukongId << endl; 
#else
	//����򿪶�����䣬ҲҪ���������
	using namespace KingGlory;  //�򿪷���
	using namespace LOL;  //�򿪷���
	cout << LOL::sunwukongId << endl;
#endif
}

int main(void) {
	
	test01();
	test02();
	return 0;
}

