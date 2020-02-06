#pragma once
#include "Weapon.h"
#include <iostream>
#include <string>
using namespace std;

class DragonSword :
	public Weapon
{
public:
	DragonSword();
	//基础伤害
	virtual int getBaseDamage();
	//吸血
	virtual int getSuckBlood();
	//定身
	virtual bool getHold();
	//暴击
	virtual bool getCrit();
	//判断是否触发暴击
	bool isTrigger(int rate);

	//吸血率
	int suckRate_;
	//定身率
	int holdRate_;
	//暴击率
	int critRate_;

};

