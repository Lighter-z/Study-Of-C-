#include "Hero.h"

Hero::Hero()
{
	this->name_ = "����ʦ";
	this->atk_ = 50;
	this->def_ = 50;
	this->hp_ = 500;
}

void Hero::EquipWeapon(Weapon * weapon)
{
	this->weapon_ = weapon;
	cout << "Ӣ�ۣ�" << this->name_ << "װ��������" << this->weapon_->WeaponName_ << endl;
}

void Hero::Attack(Monster * monster)
{
	int damage = 0;
	int trueDamage = 0;
	int addHp = 0;
	bool isHold = false;
	bool isCrit = false;
	if (this->weapon_ == NULL) {
		damage = this->atk_;
	}
	else {
		damage = this->atk_ + this->weapon_->getBaseDamage();
		addHp = this->weapon_->getSuckBlood();
		isHold = this->weapon_->getHold();
		isCrit = this->weapon_->getCrit();
	}

	if (isCrit) {
		damage = damage * 2;
		cout << "Ӣ�������������� �����ܵ�˫���˺� �˺�ֵ��" << damage << endl;
	}

	if (isHold) {
		cout << "Ӣ�������������� ����ֹͣ����һ�غ�" << endl;
	}

	if (addHp > 0) {
		cout << "Ӣ������������ѪЧ��  Ӣ������Ѫ����" << addHp << endl;
		this->hp_ += addHp;
	}

	monster->hold_ = isHold;
	trueDamage = (damage - monster->def_) > 0 ? (damage - monster->def_) : 1;
	monster->hp_ -= trueDamage;

	this->hp_ += addHp;
	cout << "Ӣ�ۣ�" << this->name_ << "���������ˣ�" << monster->name_ << "  " << trueDamage  << "�˺�" << endl;

}
