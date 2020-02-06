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

	cout << "ѡ��������" << endl;
	cout << "1.���ֿ�ȭ" << endl;
	cout << "2.������" << endl;
	cout << "3.С��" << endl;
	
	cin >> oper;
	switch (oper) {
	case 1:
		cout << "�㻹��̫���ᣬ�ҳ��ֿ�ȭ" << endl;
		break;
	case 2:
		hero->EquipWeapon(dragonSword);
		break;
	case 3:
		hero->EquipWeapon(knife);
		break;
	}

	getchar();//���뻺�������и��س�   ���ȡһ��ֵ
	int round = 1;
	while (true) {
		getchar();
		system("cls");
		cout << "------��ǰ�ǵ�"<< round << "�غ�--------" << endl;
		if (hero->hp_ <= 0) {
			cout << "Ӣ�ۣ�" << hero->name_ << "����" << endl;
			break;
		}
		hero->Attack(monster);
		if (monster->hp_ <= 0) {
			cout << "���ޣ�" << monster->name_ << "����" << endl;
			break;
		}
		monster->Attack(hero);
		if (hero->hp_ <= 0) {
			cout << "Ӣ�ۣ�" << hero->name_ << "����" << endl;
			break;
		}
		cout << "Ӣ�ۣ�" << hero->name_ << "Ѫ����" << hero->hp_ << endl;
		cout << "���ޣ�" << monster->name_ << "Ѫ����" << monster->hp_ << endl;
		round++;
	}

}

int main(void) {
	play();
	return 0;
}