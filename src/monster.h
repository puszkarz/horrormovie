#ifndef HORRORMOVIE_MONSTER_H
#define HORRORMOVIE_MONSTER_H

#include "helper.h"

//Klasy Zombie, Vampire i Mummy przyjmują w konstruktorze HealthPoints health
//        oraz AttackPower attackPower.
class Monster : Damageable, Attacker {};

class Zombie : Monster {};

class Vampire : Monster {};

class Mummy : Monster {};

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

class GroupOfMonsters : Damageable, Attacker {

};

//Dodatkowo powinny istnieć funkcje fabrykujące dla Zombie, Vampire, Mummy,
//GroupOfMonsters z sygnaturami pasującymi do przykładu.

#endif //HORRORMOVIE_MONSTER_H
