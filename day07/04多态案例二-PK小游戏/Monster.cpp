#include "Monster.h"

Monster::Monster()
{
	this->atk_ = 70;
	this->def_ = 40;
	this->hold_ = false;
	this->hp_ = 300;
	this->name_ = "�粼��";
}

void Monster::Attack(Hero * hero)
{
	int damage = 0;
	int addHp = 0;
	if (this->hold_) {
		cout << "����" << this->name_ << "���������غϲ��ܹ���" << endl;
		return;
	}
	damage = (this->atk_ - hero->def_) > 0 ? (this->atk_ - hero->def_) : 1;
	hero->hp_ -= damage;
	cout << "���" << this->name_ << "������Ӣ�ۣ�" << hero->name_ << "  " << damage << "�˺�" << endl;
}
