#include <iostream>
#include "Monster.h"
#include "Hero.h"
#include "Weapon.h"
#include "Knife.h"
#include "DragonSword.h"

using namespace std;

void play(void) {
	int oper;

	Monster * monster = new Monster;
	Hero * hero = new Hero;
	Knife * knife = new Knife;
	DragonSword * dragonSword = new DragonSword;

	cout << "选择武器：" << endl;
	cout << "1.赤手空拳" << endl;
	cout << "2.屠龙刀" << endl;
	cout << "3.小刀" << endl;
	
	cin >> oper;
	switch (oper) {
	case 1:
		cout << "你还是太年轻，敢赤手空拳" << endl;
		break;
	case 2:
		hero->EquipWeapon(dragonSword);
		break;
	case 3:
		hero->EquipWeapon(knife);
		break;
	}

	getchar();//输入缓冲区中有个回车   多获取一个值
	int round = 1;
	while (true) {
		getchar();
		system("cls");
		cout << "------当前是第"<< round << "回合--------" << endl;
		if (hero->hp_ <= 0) {
			cout << "英雄：" << hero->name_ << "死了" << endl;
			break;
		}
		hero->Attack(monster);
		if (monster->hp_ <= 0) {
			cout << "怪兽：" << monster->name_ << "死了" << endl;
			break;
		}
		monster->Attack(hero);
		if (hero->hp_ <= 0) {
			cout << "英雄：" << hero->name_ << "死了" << endl;
			break;
		}
		cout << "英雄：" << hero->name_ << "血量：" << hero->hp_ << endl;
		cout << "怪兽：" << monster->name_ << "血量：" << monster->hp_ << endl;
		round++;
	}

}

int main(void) {
	play();
	return 0;
}