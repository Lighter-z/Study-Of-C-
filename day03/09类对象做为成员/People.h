#pragma once
#include <iostream>
#include <string>
#include "Phone.h"
#include "Game.h"

using namespace std;

class People
{
public:
	string m_name;
	Phone m_phone;
	Game m_game;
	People();
	People(string name, string phone, string game);
	//People(string n);

	void playGame(void);

	~People() {
			cout << "PeopleÎö¹¹º¯Êý" << endl;
		}
};

