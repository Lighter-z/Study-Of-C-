#pragma once
#include <iostream>
#include <string>


using namespace std;

class Game
{
public:
	string m_name;
	Game();
	Game(string n);
	~Game() {
	cout << "GameÎö¹¹º¯Êý" << endl;
	}
};

