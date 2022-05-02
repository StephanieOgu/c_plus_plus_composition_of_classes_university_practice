#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Artefact {
private:
    //про артефакт
    string name;
    string about;
    string set;
    int level;    

    //статы
    int maxHP;
    int attackPower;
    int def;
    int elementaryMastery;

    //увеличение показателей
    void power();

public:
    //конструкторы
    Artefact();
    Artefact(string n, string a, int bHP, int bAatt, int bDef, int belMas, string s);

    //конструктор копирования
    Artefact(Artefact& a1);

    //деструктор
    ~Artefact();

    //перегрузка
    Artefact* operator()() {
        return this;
    }

    //сведения
    void info()const;
   

    //получение инфорации из полей
    int getHP();
    int getAttackPower();
    int getDef();
    int getElementaryMastery();
    string getSet();

    //увеличение уровня
    void upLevel(int howMany);
    void lov(int i);


    //Перегрузка +
    const Artefact operator+(const Artefact& other) const {
        Artefact temp;
        temp.name = this->name;
        temp.set = this->set;
        temp.maxHP = this->maxHP + other.maxHP;
        temp.attackPower = this->attackPower + other.attackPower;
        temp.elementaryMastery = this->elementaryMastery + other.elementaryMastery;
        temp.def = this->def + other.def;
        return temp;
    }
};
