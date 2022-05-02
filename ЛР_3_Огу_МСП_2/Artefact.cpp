#include "Artefact.h"
#define maxLevel 10

//конструкторы
Artefact::Artefact() {
	name = "";
	about = "";
	level = 1;
	maxHP = 0;
	attackPower = 0;
	def = 0;
	elementaryMastery = 0;
	set = "";
}

Artefact::Artefact(string n, string a, int bHP, int bAatt, int bDef, int belMas, string s) {
	name = n;
	about = a;
	level = 1;
	maxHP = bHP;
	attackPower = bAatt;
	def = bDef;
	elementaryMastery = belMas;
	set = s;
}

//конструктор копирования
Artefact::Artefact(Artefact& a1) {
	name = a1.name;
	about = a1.about;
	level = a1.level;
	maxHP = a1.maxHP;
	attackPower = a1.attackPower;
	def = a1.def;
	elementaryMastery = a1.elementaryMastery;
	set = a1.set;
}


//деструктор
Artefact::~Artefact() {
}


//информация об артефакте
void Artefact::info() const{
	cout << "_______________________________________________" << "\n";
	cout << "Название:" << "		" << name << "\n";
	cout << "Описание:" << "		" << about << "\n";
	cout << "Набор:" << "			" << set << "\n";
	cout << "Уровень:" << "		" << level << "\n";
	cout << "ХП:" << "			" << maxHP << "\n";	
	cout << "Атака:" << "			" << attackPower << "\n";
	cout << "Защита:" << "			" << def << "\n";
	cout << "Мастерство стихий:" << "	" << elementaryMastery << "\n";
	cout << "_______________________________________________" << "\n";

}

//получение поля
int Artefact::getHP() {
	return maxHP;
}
int Artefact::getAttackPower() {
	return attackPower;
}
int Artefact::getDef() {
	return def;
}
int Artefact::getElementaryMastery() {
	return elementaryMastery;
}
string Artefact::getSet() {
	return set;
}

//увеличение уровня
void Artefact::upLevel(int howMany) {

	for (int i = 0; i < howMany; ++i) {
		if (level < maxLevel) {
			++level;
			power();
		}
		else {
			cout << "\nВы достигли максимального уровня повышения артефакта\n";
			break;
		}
	}	
}

//увеличение показателей
void Artefact::power() {
	int res = 10 - level;
	if (res == 0)
		res = 1;
	maxHP += (maxHP*1/ res);
	attackPower += (attackPower * 1 / res);
	def += (def * 1 / res);
	elementaryMastery += (elementaryMastery * 1 / res);
}

void Artefact::lov(int i) {
	maxHP += i;
	attackPower += i;
	def += i;
	elementaryMastery += i;
}


