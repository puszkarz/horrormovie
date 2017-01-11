#ifndef HORRORMOVIE_CITIZEN_H
#define HORRORMOVIE_CITIZEN_H

#include "helper.h"
#include <iostream>
#include <memory>

class Citizen : public Damageable {
private:
    Age age;
public:
    Citizen(HealthPoints health, Age age) : Damageable(health), age(age) {}
    Age getAge() const { return age; }
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

std::shared_ptr<Sheriff> inline createSheriff(HealthPoints health, Age age, AttackPower attackPower) {
    return std::make_shared<Sheriff>(health, age, attackPower);
}

std::shared_ptr<Adult> inline createAdult(HealthPoints health, Age age) {
    return std::make_shared<Adult>(health, age);
}

std::shared_ptr<Teenager> inline createTeenager(HealthPoints health, Age age) {
    return std::make_shared<Teenager>(health, age);
}

#endif //HORRORMOVIE_CITIZEN_H
