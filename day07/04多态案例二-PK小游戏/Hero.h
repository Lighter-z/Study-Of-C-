#pragma once
#include "Weapon.h"
#include "Monster.h"
#include <iostream>
#include <string>
using namespace std;

class Monster;

class Hero
{
public:
	Hero();
	void EquipWeapon(Weapon * weapon);//װ������
	void Attack(Monster * monster);

	Weapon * weapon_;
	string name_;//����
	int atk_; //������
	int def_;//������
	int hp_;//Ѫ��


};

