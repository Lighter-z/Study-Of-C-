#include "Game.h"

Game::Game() {
	cout << "Game构造函数" << endl;
}

Game::Game(string n) {
	m_name = n;
	cout << "Game有参构造函数" << endl;
}

//Game::~Game() {
//	cout << "Game析构函数" << endl;
//}

