#include "Knife.h"

Knife::Knife()
{
	//������
	this->BaseDamage_ = 10;  
	this->WeaponName_ = "С��";
}
//�����˺�
int Knife::getBaseDamage()
{
	return this->BaseDamage_;
}
//��Ѫ
int Knife::getSuckBlood()
{
	return 0;
}
//����
bool Knife::getHold()
{
	return false;
}
//����
bool Knife::getCrit()
{
	return false;
}
