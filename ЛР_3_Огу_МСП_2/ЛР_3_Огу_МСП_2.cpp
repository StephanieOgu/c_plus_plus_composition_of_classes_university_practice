// LR_3_Ogu_MSP_2.cpp: This file contains the "main" function. This is where the program starts and ends.
#include <iostream>
#include "Team.h"
#include "Artefact.h"
#include "Weapon.h"
#include "Character.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    setlocale(LC_ALL, "Russian");
    /*I've sold a lot of cops, but not all of them for print or use. Many methods are used in each other, therefore
    now not everyone is represented on this main running page.Sincerely, Stephanie*/

    /*Also I didn't know what type of nesting to make and implemented two = at me the majority of classes contain objects of other class,
    but there is a class (character)that has an old class (constellation).This constellation class is implemented directly in the character */

    //weapons
    Weapon w1("Лук Фавония", "Волшебный лук нифилима", "Лук", 15);
    Weapon w2("Прототип Архаичный", "Мечи носят, чтобы защищать тех, кто дорог", "Двуручный меч", 20);
    Weapon w3("Небесный атлас", "Поддерживай своих друзей в бою", "Катализатор", 7);
    Weapon w4("Нефритовый коршун", "Не спрашивай ни о чем", "Копье", 22);
    w4.upLevel(11);
    //w1.info();
    //w2.info(); 
    //w3.info();
    //w4.info();
    // w5.info();
    
    //artefacts
    Artefact a1("Корона грешника", "Бремя победы", 10, 10, 10, 10, "Грешник");   
    Artefact a2("Перо грешника", "Бремя победы", 10, 10, 10, 10, "Грешник");

    Artefact a3("Корона святой девы", "Бремя победы", 10, 10, 10, 10, "Слезы юной девы");
    Artefact a4("Перо святой девы", "Бремя победы", 10, 10, 10, 10, "Слезы юной девы");

    Artefact a5("Перо берсерка", "Бремя победы", 12, 13, 11, 10, "Берсерк");
    Artefact a6("Корона берсерка", "Бремя победы", 12, 12, 9, 11, "Берсерк"); 
    Artefact a7();

    //// overloaded equals operator using class member functions
    a6.operator+(a4).info();
    (a2 + a4).info();   

    // a1.info();
    // a2.info();
    //a3.info();
    //a4.info();
    // a5.info();
    //a7.info();
    //w3()->~Weapon();
    //w3.info();
   
    //characters
    Character Xiao ("Сяо", "Воздух", w4, a5, a6, 19, 11, 11, 12);
    Character Tartaglia("Тарталия", "Гидро", w1, a4, a2, 11, 12, 13, 15);
    Character Raizor("Рейзор", "Электро", w2, a3, a5, 19, 12, 15, 132);
    Character Scaramush("Скарамуш", "Электро", w3, a1, a2, 13, 14, 13, 11);  
    Character Rozaria("Розария", "Крио", w4, a4, a3, 13, 14, 13, 11);    
    Team besties("Крутышки", Xiao, Raizor, Tartaglia, Scaramush);
    besties.rename("Любимый отряд");
    besties.Subdd2change(Rozaria);
    besties.subDD1.changeFirstArtefct(a1);
    besties.subDD2.changeWeapon(w2);
    besties.DD.upArtefact1(3);
    besties.DD.levelUp(5);
    besties.subDD1.upWeapone(3);
    besties.support.starUp(4);
    besties.support.starUp(11);
    besties.DD.info();
    besties.info();
    system("pause");
}