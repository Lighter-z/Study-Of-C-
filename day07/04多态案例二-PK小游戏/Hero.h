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
	void EquipWeapon(Weapon * weapon);//装备武器
	void Attack(Monster * monster);

	Weapon * weapon_;
	string name_;//人名
	int atk_; //攻击力
	int def_;//防御力
	int hp_;//血量


};

