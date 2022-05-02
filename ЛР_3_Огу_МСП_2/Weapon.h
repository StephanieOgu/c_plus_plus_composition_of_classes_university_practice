#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Weapon
{
private:
    //про оружие
    string name;
    string about;
    int level;
    string type;

    //статы 
    int baseAttack;

    //автоувеличение базовой атаки
    void encreeseBaseAttack();    

public:
    //конструкторы
    Weapon();
    Weapon(string n, string ab, string t, int baseBaseAt);      
    
    //конструкторы копирования
    Weapon(Weapon& w1);

    //деструктор
    ~Weapon();

    //перегрузка
    Weapon* operator()() {
        return this;
    }

    //увеличить уровень
    void upLevel(int howMany);
    
    //информация о оружии
    void info()const;

    //получение статов
    int getbaseAttack();
    string getType();     
};

