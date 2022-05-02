#include "Character.h"
#define MaxStar 5
#define MaxLevel 10

#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::string;

//конструкторы
Character::Character() {
	name = "";
	element = "";
	level = 1;

	weapon = Weapon();
	artefact1 = Artefact();
	artefact2 = Artefact();

	HP = 0;
	attackPower = 0;
	def = 0;
	elementaryMastery = 0;
	updateMStats();
}
Character::Character(string n, string el, Weapon &w, Artefact &a1, Artefact &a2, int bHP, int bAP, int bDef, int bElMast){
	name = n;
	element = el;
	level = 1;

	weapon = Weapon(w);
	artefact1 = a1;
	artefact2 = a2;	

	HP = bHP;
	attackPower = bAP;
	def = bDef;
	elementaryMastery = bElMast;
	updateMStats();
}

//конструктор копирования
Character::Character(Character& c1) {

	name = c1.name;
	element = c1.element;
	level = c1.level;

	weapon = c1.weapon;
	artefact1 = c1.artefact1;
	artefact2 = c1.artefact2;

	HP = c1.getHP();
	attackPower = c1.getAP();
	def = c1.getDef();
	elementaryMastery = c1.getEM();
	updateMStats();
}

//деструктор
Character::~Character() {
	weapon()->~Weapon();
	artefact1()->~Artefact();
	artefact2()->~Artefact();
	cout << "Персонажа больше нет\n";
}

//обычные статы
int Character::getHP() {
	return HP;
}
int Character::getAP() {
	return attackPower;
}
int Character::getDef() {
	return def;
}
int Character::getEM() {
	return elementaryMastery;
}

//максимальные статы
int Character::getMHP() {
	int res = artefact1.getHP() + artefact2.getHP();
	return res;
}
int Character::getMAP() {
	int res = artefact1.getAttackPower() + artefact2.getAttackPower() + weapon.getbaseAttack();
	return res;
}
int Character::getMDef() {
	int res = artefact1.getDef() + artefact2.getDef();
	return res;
}
int Character::getMEM() {
	int res = artefact1.getElementaryMastery() + artefact2.getElementaryMastery();
	return res;
}

//обновление максимальных статов
void Character::updateMStats() {
	maxHP = getMHP()+getHP();
	maxdef = getDef() + getMDef();
	maxattackPower = getAP() + getMAP();
	maxelementaryMastery = getMEM() + getEM();
}

//обновить оружие
void Character::changeWeapon(Weapon& w) {
	weapon = w;
	updateMStats();
}

//обновить  артефакт
void Character::changeFirstArtefct(Artefact a) {
	artefact1 = a;
	updateMStats();
}
void Character::changeSecondArtefct(Artefact a) {
	artefact2 = a;
	updateMStats();
}

//информация об отряде
void Character::info() {
	updateMStats();
	cout << "_______________________________________________" << "\n";
	cout << "Имя:" << "				" << name << "\n";
	cout << "Элемент:" << "			" << element << "\n";
	cout << "Уровень:" << "			" << level << "\n";
	cout << "Созведие:" << "			" << star.getStar() << "\n";
	cout << "ХП:" << "				" << maxHP << "\n";
	cout << "Атака:" << "				" << maxattackPower << "\n";
	cout << "Защита:" << "				" << maxdef << "\n";
	cout << "Мастерство стихий:" << "		" << maxelementaryMastery << "\n";
	cout << "Оружие:" << "		" << "\n";
	weapon.info();
	cout << "Артефакт 1:" << "		" << "\n";
	artefact1.info();
	cout << "Артефакт 2:" << "		" << "\n";
	artefact2.info();
	cout << "_______________________________________________" << "\n";
}

//увеличить созвездие
void Character::starUp(int how) {
	for (int i = 0; i < how; ++i) {
		if (star.getStar() < MaxStar) {
			int temp = MaxStar - star.getStar();
			HP += temp / 3;
			attackPower += temp / 3;
			def += temp / 3;
			elementaryMastery += temp / 3;
			star.encreese();
		}
		else {
			cout << "Персонаж получил максимальное созвездие! Поздравляем!\n";
			break;
		}
	}
	updateMStats();
}

//увеличить уровень
void Character::levelUp(int how) {
	for (int i = 0; i < how; ++i) {
		if (level < MaxLevel) {
			int temp = MaxLevel - level;
			HP += temp / 4;
			attackPower += temp/4;
			def += temp/4;
			elementaryMastery += temp/4;
			++level;
		}
		else {
			cout << "Персонаж повышен до максимального уровня! Поздравляем!\n";
			break;
		}
	}		
	updateMStats();
}

//получить элемент
string Character::getElement() {
	return element;
}

//улучшить екипировку
void Character::upWeapone(int how) {
	weapon.upLevel(how);
	updateMStats();
}
void Character::upArtefact1(int how) {
	artefact1.upLevel(how);
	updateMStats();
}
void Character::upArtefact2(int how) {
	artefact2.upLevel(how);
	updateMStats();
}
int Character::getLevel() {
	return level;
}