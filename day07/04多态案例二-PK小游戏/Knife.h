#pragma once
#include "Weapon.h"
#include <iostream>
#include <string>
using namespace std;

class Knife :
	public Weapon
{
public:
	Knife();
	//»ù´¡ÉËº¦
	virtual int getBaseDamage();
	//ÎüÑª
	virtual int getSuckBlood();
	//¶¨Éí
	virtual bool getHold();
	//±©»÷
	virtual bool getCrit();
};

