#ifndef HORRORMOVIE_CITIZEN_H
#define HORRORMOVIE_CITIZEN_H

#include "helper.h"

class Citizen : Damageable {
protected:
    Age age;
public:
    Age getAge() { return age; }
};

//Klasy Adult, Teenager przyjmują w konstruktorze HealthPoints health oraz
//Age age, a Sheriff dodatkowo AttackPower attackPower. Klasy Adult i Sheriff
//mogą przyjmować age w zakresie od 18 do 100, a Teenager w zakresie od 11 do 17.

class Adult : Citizen {

};

class Teenager : Citizen {

};

class Sheriff : Adult, Attacker {

};

//Dodatkowo powinny istnieć funkcje fabrykujące dla Adult, Teenager, Sheriff
//        z sygnaturami pasującymi do przykładu.

#endif //HORRORMOVIE_CITIZEN_H
