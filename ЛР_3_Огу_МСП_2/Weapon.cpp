#include "Weapon.h"
#define maxLevel 10


//конструкторы
Weapon::Weapon() {
	name = "";
	about = "";
	level = 0;
	type = "";
	baseAttack = 0;
}

Weapon::Weapon(string n, string ab, string t, int baseBaseAt) {
	name = n;
	about = ab;
	level = 1;
	type = t;
	baseAttack = baseBaseAt;
}

//конструктор копирования
Weapon::Weapon(Weapon& w1) {
	name = w1.name;
	about = w1.about;
	level = w1.level;
	type = w1.getType();
	baseAttack = w1.getbaseAttack();
}

//деструктор
Weapon::~Weapon() {
}

//увеличение базовой атаки
void Weapon::encreeseBaseAttack() {
	int res = 10 - level;
	if (res == 0)
		res = 1;
	baseAttack += (baseAttack * 1 / res);	
}

//повышение уровня
void Weapon::upLevel(int howMany) {
	for (int i = 0; i < howMany; i++) {
		if (level == maxLevel) {
			cout << "Вы достигли максимального уровня повышения оружия\n";
			break;
		}else {
			++level;
			encreeseBaseAttack();
		}		
	}
}

//информация об оружии
void Weapon::info() const {
	cout << "_______________________________________________" << "\n";
	cout << "Название:"<<"	"<<name<<"\n";
	cout << "Описание:" << "	" << about << "\n";
	cout << "Тип:" << "		" << type << "\n";
	cout << "Уровень:" << "	" << level << "\n";
	cout << "Атака:" << "		" << baseAttack << "\n";
	cout << "_______________________________________________" << "\n";
}

//получение статов
int Weapon::getbaseAttack() {
	return baseAttack;
}
string Weapon::getType() {
	return type;
}

