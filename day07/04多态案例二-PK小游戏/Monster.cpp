#include "Monster.h"

Monster::Monster()
{
	this->atk_ = 70;
	this->def_ = 40;
	this->hold_ = false;
	this->hp_ = 300;
	this->name_ = "哥布林";
}

void Monster::Attack(Hero * hero)
{
	int damage = 0;
	int addHp = 0;
	if (this->hold_) {
		cout << "怪物" << this->name_ << "被定身，本回合不能攻击" << endl;
		return;
	}
	damage = (this->atk_ - hero->def_) > 0 ? (this->atk_ - hero->def_) : 1;
	hero->hp_ -= damage;
	cout << "怪物：" << this->name_ << "攻击力英雄：" << hero->name_ << "  " << damage << "伤害" << endl;
}
