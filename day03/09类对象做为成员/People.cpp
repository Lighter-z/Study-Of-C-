#include "People.h"

People::People() {
	cout << "People构造函数" << endl;
}

People::People(string name, string phone, string game) : m_name(name),m_phone(phone),m_game(game)
{
	//m_name = n;
	cout << "People有参构造函数" << endl;
}

void People::playGame(void) {
	cout << m_name << "拿着"<< m_phone.m_name << "手机，玩" << m_game.m_name << endl;
}

//People::~People() {
//	cout << "People析构函数" << endl;
//}

