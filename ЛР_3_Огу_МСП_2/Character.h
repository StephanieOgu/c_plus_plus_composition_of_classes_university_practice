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
        //����� ��������� ���������
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

        //��� ���������
        string name;
        string element;
        int level;
        Star star; 

        //�����
        int HP;
        int attackPower;
        int def;
        int elementaryMastery;

        //����� MAX
        int maxHP;
        int maxattackPower;
        int maxdef;
        int maxelementaryMastery;

        //������������
        Weapon weapon;
        Artefact artefact1;
        Artefact artefact2;

        //�������� �����
        void updateMStats();

    public:
        //�����������
        Character();
        Character(string n, string el, Weapon& w, Artefact& a1, Artefact& a2, int bHP, int bAP, int bDef, int bElMast);
        
        //����������� �����������
        Character(Character& �1);

        //����������
        ~Character();

        //����������
        Character* operator()() {
            return this;
        }

        //������ �������
        int getLevel();

        //�������� �������� ������
        int getHP();
        int getAP();
        int getDef();
        int getEM();

        //�������� �������� ���� ������
        int getMHP();
        int getMAP();
        int getMDef();
        int getMEM();

        //������ �������
        string getElement();

        //�������� ������
        void changeWeapon(Weapon& w);

        //�������� ��������
        void changeFirstArtefct(Artefact a);
        void changeSecondArtefct(Artefact a);

        //����������
        void info();
        
        //��������� ���������
        void starUp(int how);

        //��������� �������
        void levelUp(int how);

        //�������� ����������
        void upWeapone(int how);
        void upArtefact1(int how);
        void upArtefact2(int how);

};


