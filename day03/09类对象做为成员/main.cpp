#include <iostream>
#include "People.h"

using namespace std;

//�������Ϊ��Աʱ�򣬹���˳���Ƚ������һһ���� Ȼ�����Լ�  ������˳���෴
void test01() {
	People p("����","����","����");
	//p.m_phone.m_name = "����";
	//p.m_game.m_name = "����";
	p.playGame();
}

int main() {
	test01();
	return 0;
}
