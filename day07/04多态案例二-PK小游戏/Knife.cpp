#include "Knife.h"

Knife::Knife()
{
	//¹¥»÷Á¦
	this->BaseDamage_ = 10;  
	this->WeaponName_ = "Ğ¡µ¶";
}
//»ù´¡ÉËº¦
int Knife::getBaseDamage()
{
	return this->BaseDamage_;
}
//ÎüÑª
int Knife::getSuckBlood()
{
	return 0;
}
//¶¨Éí
bool Knife::getHold()
{
	return false;
}
//±©»÷
bool Knife::getCrit()
{
	return false;
}
