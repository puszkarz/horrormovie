#ifndef HORRORMOVIE_CITIZEN_H
#define HORRORMOVIE_CITIZEN_H

#include "helper.h"
#include <iostream>
#include <memory>

class Citizen : public Damageable {
private:
    Age _age;
public:
    Citizen(HealthPoints health, Age age);
    Age getAge() const;
    /**
     * Simulate the attack on the citizen.
     */
    virtual void attack(std::shared_ptr<DamageableAttacker> attacker);
};

class Adult : public Citizen {
public:
    Adult(HealthPoints health, Age age);
};

class Teenager : public Citizen {
public:
    Teenager(HealthPoints health, Age age);
};

class Sheriff : public Adult, public Attacker {
public:
    /**
     * Simulate the attack on the sheriff - sheriff also attack the monster.
     */
    Sheriff(HealthPoints health, Age age, AttackPower attackPower);
    void attack(std::shared_ptr<DamageableAttacker> attacker);
};

std::shared_ptr<Sheriff> createSheriff(HealthPoints health, Age age, AttackPower attackPower);

std::shared_ptr<Adult> createAdult(HealthPoints health, Age age);

std::shared_ptr<Teenager> createTeenager(HealthPoints health, Age age);

#endif //HORRORMOVIE_CITIZEN_H
