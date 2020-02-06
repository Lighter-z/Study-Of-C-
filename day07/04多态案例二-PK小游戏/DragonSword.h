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
	//�����˺�
	virtual int getBaseDamage();
	//��Ѫ
	virtual int getSuckBlood();
	//����
	virtual bool getHold();
	//����
	virtual bool getCrit();
	//�ж��Ƿ񴥷�����
	bool isTrigger(int rate);

	//��Ѫ��
	int suckRate_;
	//������
	int holdRate_;
	//������
	int critRate_;

};

