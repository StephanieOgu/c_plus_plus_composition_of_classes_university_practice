#include "Weapon.h"
#define maxLevel 10


//������������
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

//����������� �����������
Weapon::Weapon(Weapon& w1) {
	name = w1.name;
	about = w1.about;
	level = w1.level;
	type = w1.getType();
	baseAttack = w1.getbaseAttack();
}

//����������
Weapon::~Weapon() {
}

//���������� ������� �����
void Weapon::encreeseBaseAttack() {
	int res = 10 - level;
	if (res == 0)
		res = 1;
	baseAttack += (baseAttack * 1 / res);	
}

//��������� ������
void Weapon::upLevel(int howMany) {
	for (int i = 0; i < howMany; i++) {
		if (level == maxLevel) {
			cout << "�� �������� ������������� ������ ��������� ������\n";
			break;
		}else {
			++level;
			encreeseBaseAttack();
		}		
	}
}

//���������� �� ������
void Weapon::info() const {
	cout << "_______________________________________________" << "\n";
	cout << "��������:"<<"	"<<name<<"\n";
	cout << "��������:" << "	" << about << "\n";
	cout << "���:" << "		" << type << "\n";
	cout << "�������:" << "	" << level << "\n";
	cout << "�����:" << "		" << baseAttack << "\n";
	cout << "_______________________________________________" << "\n";
}

//��������� ������
int Weapon::getbaseAttack() {
	return baseAttack;
}
string Weapon::getType() {
	return type;
}

