#pragma once
#include <iostream>
#include <string>
using namespace std;

//������
//����
class Weapon
{
public:
	//�����˺�
	virtual int getBaseDamage() = 0;
	//��Ѫ
	virtual int getSuckBlood() = 0;
	//����
	virtual bool getHold() = 0;
	//����
	virtual bool getCrit() = 0;

	int BaseDamage_;
	string WeaponName_;
};

