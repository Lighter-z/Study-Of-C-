#include "DragonSword.h"

DragonSword::DragonSword()
{
	this->BaseDamage_ = 20;
	this->WeaponName_ = "ÍÀÁúµ¶";
	this->critRate_ = 30;
	this->holdRate_ = 40;
	this->suckRate_ = 20;
}

int DragonSword::getBaseDamage()
{
	return this->BaseDamage_;
}

int DragonSword::getSuckBlood()
{
	if (isTrigger(this->suckRate_)) {
		return this->BaseDamage_ * 0.5;
	}
	return 0;
}

bool DragonSword::getHold()
{
	if (isTrigger(this->holdRate_)) {
		return true;
	}
	return false;
}

bool DragonSword::getCrit()
{
	if (isTrigger(this->critRate_)) {
		return true;
	}
	return false;
}

bool DragonSword::isTrigger(int rate)
{
	//Ëæ»ú1-100µÄÊı×Ö
	int num = rand() % 100 + 1;
	if (num < rate) {
		return true;
	}
	return false;
}
