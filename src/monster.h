//
// Created by bartek on 09.01.17.
//

#ifndef HORRORMOVIE_MONSTER_H
#define HORRORMOVIE_MONSTER_H

#include "helper.h"

//Klasy Zombie, Vampire, Mummy, w których używane są typy pomocnicze:
//* HealthPoints będący typem przechowującym punkty życia,
//        * AttackPower reprezentujący siłę ataku.
//
//Klasy Zombie, Vampire i Mummy przyjmują w konstruktorze HealthPoints health
//        oraz AttackPower attackPower.
//
//Klasy Vampire, Zombie i Mummy mają metody publiczne:
//        Health getHealth() – zwraca liczbę punktów życia potwora,
//AttackPower getAttackPower() – zwraca siłę ataku potwora,
//void takeDamage(AttackPower damage) – zmniejsza liczbę punktów życia potwora
//        o damage, ale nie więcej niż potwór ma aktualnie.
//
//Klasy Zombie, Vampire i Mummy powinny być podklasami ogólniejszego typu Monster.
//
//W sequelu potwory mogą również atakować grupowo. Należy zaimplementować
//odpowiednią klasę do ataku grupowego GroupOfMonsters, która w konstruktorze
//        przyjmuje wektor (std::vector) albo listę inicjującą (std::initializer_list)
//zawierającą potwory, które są w grupie. GroupOfMonsters mają metody publiczne:
//Health getHealth() – zwraca liczbę punktów życia grupy (suma punktów życia
//żywych potworów),
//AttackPower getAttackPower() – zwraca siłę ataku grupy (suma sił ataku żywych
//        potworów),
//void takeDamage(AttackPower damage) – zmniejsza liczbę punktów życia każdego
//        potwora w grupie o damage, ale nie więcej niż potwór ma aktualnie.
//
//Dodatkowo powinny istnieć funkcje fabrykujące dla Zombie, Vampire, Mummy,
//GroupOfMonsters z sygnaturami pasującymi do przykładu.

#endif //HORRORMOVIE_MONSTER_H
