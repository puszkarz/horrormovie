//
// Created by bartek on 09.01.17.
//

#ifndef HORRORMOVIE_CITIZEN_H
#define HORRORMOVIE_CITIZEN_H

#include "helper.h"

//Klasy Adult, Teenager, Sheriff, w których używane są typy pomocnicze:
//* HealthPoints będący typem przechowującym punkty życia,
//        * Age będący typem reprezentującym wiek,
//        * AttackPower reprezentujący w przypadku szeryfa siłę ataku.
//
//Klasy Adult, Teenager przyjmują w konstruktorze HealthPoints health oraz
//Age age, a Sheriff dodatkowo AttackPower attackPower. Klasy Adult i Sheriff
//mogą przyjmować age w zakresie od 18 do 100, a Teenager w zakresie od 11 do 17.
//
//Klasy Adult, Teenager, Sheriff udostępniają metody publiczne:
//* HealthPoints getHealth() – zwraca liczbę punktów życia mieszkańca,
//* Age getAge() – zwraca wiek mieszkańca,
//* void takeDamage(AttackPower damage) – zmniejsza liczbę punktów życia
//mieszkańca o damage, ale nie więcej niż mieszkaniec ma aktualnie.
//
//Klasa Sheriff ma dodatkowo metodę publiczną:
//* AttackPower getAttackPower() – zwraca siłę ataku szeryfa.
//
//Klasy Adult, Teenager, Sheriff powinny być podklasami ogólniejszego typu
//        Citizen.
//
//Dodatkowo powinny istnieć funkcje fabrykujące dla Adult, Teenager, Sheriff
//        z sygnaturami pasującymi do przykładu.

#endif //HORRORMOVIE_CITIZEN_H
