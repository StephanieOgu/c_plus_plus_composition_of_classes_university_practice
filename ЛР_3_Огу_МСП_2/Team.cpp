#include "Team.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//конструкторы
Team::Team() {
	name = "Новый отряд";
	DD = Character();
	subDD1 = Character();
	subDD2 = Character();
	support = Character();
}

Team::Team(string n, Character& ch1, Character& ch2, Character& ch3, Character& ch4){
	 name = n;
	 DD = ch1;
	 subDD1 = ch2;
	 subDD2 = ch3;
	 support = ch4;
}

//переименовать
void Team::rename(string a) {
	name = a;
}

//получить элементы отряда
string Team::getElemets() {
	string res = "";
	string res1 = DD.getElement();
	string res2 = subDD1.getElement();
	string res3 = subDD2.getElement();
	string res4 = support.getElement();
	res = res1 + ", " + res2 + ", " + res3 + ", " + res4;
	return res;
}

//Информация об отряде
void Team::info() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
	cout << "Название:" << "	" << name << "\n";
	cout << "Элементы:" << getElemets() << "\n";
	cout << "Атака:" << "				" << getAttack() << "\n";
	cout << "ХП:" << "				" << getHP() << "\n";
	cout << "Мастерство стихий:" << "		" << getEL() << "\n";
	cout << "Защита:" << "				" << getDef() << "\n";
	cout << "Уровень:" << "			" << geteLevel() << "\n";
	cout << "ДД:" << "\n";
	DD.info();
	cout << "СабДД1:" <<"\n";
	subDD1.info();
	cout << "СабДД2:" << "\n";
	subDD2.info();
	cout << "Саппорт:" << "\n";
	support.info();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
}

//Об отряде
int Team::getAttack() {
	return (DD.getAP());
}
int Team::getEL() {
	return(support.getEM());
}
int Team::getDef() {
	return(subDD1.getDef()+subDD2.getDef())/2;
}
int Team::getHP() {
	return(subDD1.getHP() + subDD2.getHP()) / 2;
}
int Team::geteLevel() {
	return(subDD1.getLevel() + subDD2.getLevel()+DD.getLevel()+support.getLevel()) / 4;
}

//изменить персонажей
void Team::DDchange(Character& c) {
	DD = c;
}
void Team::Suppchange(Character& c) {
	support = c;
}
void Team::Subdd1hange(Character& c) {
	subDD1 = c;
}
void Team::Subdd2change(Character& c) {
	subDD2 = c;
}