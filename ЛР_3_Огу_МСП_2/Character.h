#pragma once
#include <iostream>
#include <string>
#include "Artefact.h"
#include "Weapon.h"

#define MaxStar 5
#define MaxLevel 10

using std::cout;
using std::endl;
using std::string;

class Character
{
    private:  
        //класс созвездия персонажа
        class Star {
        private:
            int quant;
        public: 
            Star(){
                quant = 0;
            }
            void encreese() {
                ++quant;
            }
            int getStar() {
                return quant;
            }
        };

        //про персонажа
        string name;
        string element;
        int level;
        Star star; 

        //статы
        int HP;
        int attackPower;
        int def;
        int elementaryMastery;

        //статы MAX
        int maxHP;
        int maxattackPower;
        int maxdef;
        int maxelementaryMastery;

        //оборудование
        Weapon weapon;
        Artefact artefact1;
        Artefact artefact2;

        //обновить статы
        void updateMStats();

    public:
        //конструктор
        Character();
        Character(string n, string el, Weapon& w, Artefact& a1, Artefact& a2, int bHP, int bAP, int bDef, int bElMast);
        
        //конструктор копирования
        Character(Character& с1);

        //деструктор
        ~Character();

        //перегрузка
        Character* operator()() {
            return this;
        }

        //узнать уровень
        int getLevel();

        //получить значение статов
        int getHP();
        int getAP();
        int getDef();
        int getEM();

        //получить значение макс статов
        int getMHP();
        int getMAP();
        int getMDef();
        int getMEM();

        //узнать элемент
        string getElement();

        //обновить оружие
        void changeWeapon(Weapon& w);

        //обновить артефакт
        void changeFirstArtefct(Artefact a);
        void changeSecondArtefct(Artefact a);

        //информация
        void info();
        
        //увеличить созвездие
        void starUp(int how);

        //увеличить уровень
        void levelUp(int how);

        //улучшить екипировку
        void upWeapone(int how);
        void upArtefact1(int how);
        void upArtefact2(int how);

};


