#pragma once

#include <iostream>
#include <string>
#include "Character.h"

using std::cout;
using std::endl;
using std::string;

//класс команда
class Team
{
    private:	        
        //об отряде
        string name;   

        //статы отряда
        int AttackPower;
        int HP;
        int elementaryMastery;
        int def; 

    public:
        //состав
        Character DD;
        Character subDD1;
        Character subDD2;
        Character support;

        //конструкторы
        Team(string name, Character& ch1, Character& ch2, Character& ch3, Character& ch4);
        Team();

        //Переименовать 
        void rename(string a);

        //получить элементы отряда
        string getElemets();


        //Информация об отряде
        void info();
                        
        //Об отряде
        int getAttack();
        int getEL();
        int getDef();        
        int getHP();
        int geteLevel();

        //изменить персонажей
        void DDchange(Character& c);
        void Suppchange(Character& c);
        void Subdd1hange(Character& c);
        void Subdd2change(Character& c);
};

