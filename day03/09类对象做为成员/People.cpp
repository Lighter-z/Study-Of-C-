#include "People.h"

People::People() {
	cout << "People���캯��" << endl;
}

People::People(string name, string phone, string game) : m_name(name),m_phone(phone),m_game(game)
{
	//m_name = n;
	cout << "People�вι��캯��" << endl;
}

void People::playGame(void) {
	cout << m_name << "����"<< m_phone.m_name << "�ֻ�����" << m_game.m_name << endl;
}

//People::~People() {
//	cout << "People��������" << endl;
//}

