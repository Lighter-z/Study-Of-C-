#pragma once
#include "Weapon.h"
#include <iostream>
#include <string>
#include "Hero.h"
using namespace std;

class Hero;

class Monster
{
public:
	Monster();
	string name_;
	int hp_;
	int atk_;//¹¥»÷
	int def_;//·ÀÓù
	bool hold_;//¶¨Éí
	void Attack(Hero * hero);
};

