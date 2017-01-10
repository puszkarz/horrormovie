#ifndef HORRORMOVIE_CITIZEN_H
#define HORRORMOVIE_CITIZEN_H

#include "helper.h"

class Citizen : public Damageable {
private:
    Age age;
public:
    Citizen(HealthPoints health, Age age) : Damageable(health), age(age) {}
    Age getAge() { return age; }
};

class Adult : public Citizen {
public:
    Adult(HealthPoints health, Age age) : Citizen(health, age) {
        assert(this->getAge() >= 18 && this->getAge() <= 100);
    };
};

class Teenager : public Citizen {
public:
    Teenager(HealthPoints health, Age age) : Citizen(health, age) {
        assert(this->getAge() >= 11 && this->getAge() <= 17);
    };
};

class Sheriff : public Adult, public Attacker {
public:
    Sheriff(HealthPoints health, Age age, AttackPower attackPower) : Adult(health, age), Attacker(attackPower) {};
};

Sheriff* createSheriff(HealthPoints health, Age age, AttackPower attackPower) {
    return new Sheriff(health, age, attackPower);
}

Adult* createAdult(HealthPoints health, Age age) {
    return new Adult(health, age);
}

Teenager* createTeenager(HealthPoints health, Age age) {
    return new Teenager(health, age);
}

#endif //HORRORMOVIE_CITIZEN_H
