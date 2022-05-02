#pragma once

#include <iostream>
#include <string>
#include "Character.h"

using std::cout;
using std::endl;
using std::string;

//����� �������
class Team
{
    private:	        
        //�� ������
        string name;   

        //����� ������
        int AttackPower;
        int HP;
        int elementaryMastery;
        int def; 

    public:
        //������
        Character DD;
        Character subDD1;
        Character subDD2;
        Character support;

        //������������
        Team(string name, Character& ch1, Character& ch2, Character& ch3, Character& ch4);
        Team();

        //������������� 
        void rename(string a);

        //�������� �������� ������
        string getElemets();


        //���������� �� ������
        void info();
                        
        //�� ������
        int getAttack();
        int getEL();
        int getDef();        
        int getHP();
        int geteLevel();

        //�������� ����������
        void DDchange(Character& c);
        void Suppchange(Character& c);
        void Subdd1hange(Character& c);
        void Subdd2change(Character& c);
};

