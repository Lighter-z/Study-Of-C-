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
	//�����˺�
	virtual int getBaseDamage();
	//��Ѫ
	virtual int getSuckBlood();
	//����
	virtual bool getHold();
	//����
	virtual bool getCrit();
};

