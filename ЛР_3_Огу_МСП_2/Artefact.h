#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Artefact {
private:
    //��� ��������
    string name;
    string about;
    string set;
    int level;    

    //�����
    int maxHP;
    int attackPower;
    int def;
    int elementaryMastery;

    //���������� �����������
    void power();

public:
    //������������
    Artefact();
    Artefact(string n, string a, int bHP, int bAatt, int bDef, int belMas, string s);

    //����������� �����������
    Artefact(Artefact& a1);

    //����������
    ~Artefact();

    //����������
    Artefact* operator()() {
        return this;
    }

    //��������
    void info()const;
   

    //��������� ��������� �� �����
    int getHP();
    int getAttackPower();
    int getDef();
    int getElementaryMastery();
    string getSet();

    //���������� ������
    void upLevel(int howMany);
    void lov(int i);


    //���������� +
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
