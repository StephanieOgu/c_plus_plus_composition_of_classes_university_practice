#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Weapon
{
private:
    //��� ������
    string name;
    string about;
    int level;
    string type;

    //����� 
    int baseAttack;

    //�������������� ������� �����
    void encreeseBaseAttack();    

public:
    //������������
    Weapon();
    Weapon(string n, string ab, string t, int baseBaseAt);      
    
    //������������ �����������
    Weapon(Weapon& w1);

    //����������
    ~Weapon();

    //����������
    Weapon* operator()() {
        return this;
    }

    //��������� �������
    void upLevel(int howMany);
    
    //���������� � ������
    void info()const;

    //��������� ������
    int getbaseAttack();
    string getType();     
};

