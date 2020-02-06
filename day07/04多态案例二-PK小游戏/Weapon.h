#pragma once
#include <iostream>
#include <string>
using namespace std;

//抽象类
//武器
class Weapon
{
public:
	//基础伤害
	virtual int getBaseDamage() = 0;
	//吸血
	virtual int getSuckBlood() = 0;
	//定身
	virtual bool getHold() = 0;
	//暴击
	virtual bool getCrit() = 0;

	int BaseDamage_;
	string WeaponName_;
};

